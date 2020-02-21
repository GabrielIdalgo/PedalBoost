/*
 * Fish Tank automation project - TCC -  Comm_protocol file
 * Developer: Pablo
 * 
 * ToDo[PS] - need to improve the comments
*/


/*
*    ### Headers includes
*/
#include "Comm_protocol.h"


/*
*    Função: Frame Send Machine (FSM)
*    Descrição: Esta função é uma máquina de estados que controla o envio de frames
*/
int Comm_protocol_Frame_Send_Request(TxBuffer_t *pTxBuffer, int lenght)
{
  return Serial1.write((byte *)pTxBuffer, lenght);
}


/*
*    Função: Frame Send Machine (FSM)
*    Descrição: Esta função é uma máquina de estados que controla o envio de frames
*/
int Comm_protocol_Frame_Read_Request(RxBuffer_t *pRxBuffer, int RxBuff_Length)
{
    return Serial1.readBytes((byte *)pRxBuffer, RxBuff_Length);
}


/*
*    Função: Frame Send Machine (FSM)
*    Descrição: Esta função é uma máquina de estados que controla o envio de frames
*/
int Comm_protocol_Get_TxFIFO_Lenght()
{
  return Serial1.availableForWrite();
}


/*
*    Função: Frame Send Machine (FSM)
*    Descrição: Esta função é uma máquina de estados que controla o envio de frames
*/
int Comm_protocol_Get_RxFIFO_Lenght()
{
  return Serial1.available();
}
