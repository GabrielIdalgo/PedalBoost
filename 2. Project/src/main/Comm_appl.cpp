/******************************************************************************************************************************************************************************************************************************************************** 
 * Fish Tank automation project - TCC -  Comm_appl file
 * Developer: Pablo
 * 
 * ToDo[PS] - need to improve the comments
*********************************************************************************************************************************************************************************************************************************************************/


/******************************************************************************************************************************************************************************************************************************************************** 
    ### Headers includes
*********************************************************************************************************************************************************************************************************************************************************/
#include "Comm_appl.h"


/*
 *   ### Global Variables into this scope (this file *.c)
**/
/* Tabela de todos os comandos dispon�veis do ESP para o Slave. Formata��o da tabela: {{SID,TYPE,ID}, byte, callback function} */
#ifdef _MODULE_TYPE_PLUGS
static const Kostia_CmdTable_t CmdTable_FromMasterToSlave[] = {
    {{0x01U, 0x01U, 0x01U}, 0x01U, Comm_appl_QueryID},       /* Query if slave is configured */
    {{0x02U, 0x01U, 0x01U}, 0x01U, Comm_appl_SetID},         /* Set ID to slave */
    {{0x03U, 0x02U, 0x01U}, 0x01U, Comm_appl_ConfigSlave},   /* Config slave command */
    {{0x04U, 0x01U, 0x01U}, 0x01U, Comm_appl_RequestData},   /* Request slave's data */
    {{0x00U, 0x00U, 0x00U}, 0x00U, Comm_appl_CmdTableError}  /* Must be the last element */
};
#endif

#ifdef _MODULE_TYPE_LIGTH
static const Kostia_CmdTable_t CmdTable_FromMasterToSlave[] = {
    {{0x01U, 0x01U, 0x01U}, 0x01U, Comm_appl_QueryID},       /* Query if slave is configured */
    {{0x02U, 0x01U, 0x01U}, 0x01U, Comm_appl_SetID},         /* Set ID to slave */
    {{0x03U, 0x03U, 0x01U}, 0x01U, Comm_appl_ConfigSlave},   /* Config slave command */
    {{0x04U, 0x01U, 0x01U}, 0x01U, Comm_appl_RequestData},   /* Request slave's data */
    {{0x00U, 0x00U, 0x00U}, 0x00U, Comm_appl_CmdTableError}  /* Must be the last element */
};
#endif


/*
*   Fun��o: Frame Send Machine (FSM)
*    Descri��o: Esta fun��o � uma m�quina de estados que controla o envio de frames
*    \Parametros: Uart_t *pUart - estrutura de dados principal
*/
byte Comm_appl_FSM( Uart_t *pUart )
{
    switch (pUart->FSM_State){
        case FSM_State_Idle:
        {
            break;
        }
        case FSM_State_Send:   /* Start execute of frame sending on bus */
        {
            int TxBuff_Length;
            TxBuff_Length = Comm_appl_FrameToBuffer(pUart);
            Comm_protocol_Frame_Send_Request(&pUart->TxBuffer, TxBuff_Length);
            Comm_appl_Request_ChangeOf_FSM_State(pUart, FSM_State_Sending);
            break;
        }
        case FSM_State_Sending:   /* Executing frame sending on bus */
        {
            if(Comm_protocol_Get_TxFIFO_Lenght() == 0){
                Comm_appl_Request_ChangeOf_FSM_State(pUart, FSM_State_Idle);
            }
            break;
        }
        case FSM_State_Error:
        {
            /* ToDo[PENS] - error handler */
            Comm_appl_Request_ChangeOf_FSM_State(pUart, FSM_State_Idle);
            break;
        } 
        default:
        {
            /* ToDo[PENS] - default handler */
        }
    }
    return 0;
}


/*
*    Fun��o: Frame Receive Machine (FRM)
*    Descri��o: Esta fun��o � uma m�quina de estados que controla a recep��o de frames
*/
byte Comm_appl_FRM(Uart_t *pUart)
{
    static int RxBuff_Timeout = 0;
    static int RxBuff_Length = 0;
    static int RxBuff_Length_Previous = 0;
    switch (pUart->FRM_State){
        case FRM_State_Idle:
        {
            if(Comm_protocol_Get_RxFIFO_Lenght() > 0){   /* Verifica a quantidade de bytes armazenados no Rx_Buffer. Se for > 0, então significa que há bytes chegando e é necessário alterar o estado da FRM */
                Comm_appl_Request_ChangeOf_FRM_State(pUart, FRM_State_Receiving);
            }
            break;
        }
        case FRM_State_Receiving:
        {
            RxBuff_Length = Comm_protocol_Get_RxFIFO_Lenght();
            if(RxBuff_Length != RxBuff_Length_Previous){
                RxBuff_Length_Previous = RxBuff_Length;
                RxBuff_Timeout = 0;
            }else{
                RxBuff_Timeout++;
            }
            if(RxBuff_Timeout >= 3){   /* Timeout de 30ms */
                RxBuff_Timeout = 0;
                RxBuff_Length_Previous = 0;
                Comm_appl_Request_ChangeOf_FRM_State(pUart, FRM_State_Received);
            }
            break;                                                                                                                                              
        }
        case FRM_State_Received:  /* This state get datas received in Rx serial buffer and put it in a SW buffer (pUart->RxBuffer) */
        {
            int nDataRead;
            nDataRead = Comm_protocol_Frame_Read_Request(&pUart->RxBuffer, RxBuff_Length);
            if(Comm_appl_Check_Frame_IsEcho(pUart) == FALSE){
                if(Comm_appl_Check_Frame_IsValid(pUart) == TRUE){
                    Comm_appl_Request_ChangeOf_FRM_State(pUart, FRM_State_Idle);
                    Comm_appl_Request_ChangeOf_RHM_State(pUart, RHM_State_Process);
                }else{
                    Comm_appl_Request_ChangeOf_FRM_State(pUart, FRM_State_Error);
                }
            }else{
                Comm_appl_Request_ChangeOf_FRM_State(pUart, FRM_State_Idle);
            }
            break;
        }
        case FRM_State_Error:
        {
            /* ToDo[PENS] error handler */
            Comm_appl_Request_ChangeOf_FRM_State(pUart, FRM_State_Idle);
            break;
        }
        default:
        {
            /* ToDo[PENS] - error handler to FSRM */
        }
    }    
    return 0;
}

