/**
  ******************************************************************************
  * @file    usbio.h
  * $Author: wdluo $
  * $Revision: 67 $
  * $Date:: 2012-08-15 19:00:29 +0800 #$
  * @brief   USBÉÏ²ãº¯ÊýÉùÃ÷.
  ******************************************************************************
  * @attention
  *
  *<h3><center>&copy; Copyright 2009-2012, ViewTool</center>
  *<center><a href="http:\\www.viewtool.com">http://www.viewtool.com</a></center>
  *<center>All Rights Reserved</center></h3>
  * 
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _USBIO_H_
#define _USBIO_H_

#include "stm32f10x.h"


#define USB_MAXDATASIZE 0x40

/* Exported Functions --------------------------------------------------------*/
extern uint8_t USB_RecvData[512];
extern uint16_t USB_RecvDataLen;



void USB_IO_Init(void);
void USB_IO_Int(void);

void USB_IO_SendData(uint8_t *dat, uint16_t len);
void USB_IO_SendDataC(void);
void USB_IO_RecvDataC(void);

void USB_IO_SendInt(uint8_t inter);

#endif //_USBIO_H_
