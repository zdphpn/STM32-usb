/**
  ******************************************************************************
  * @file    usbio.h
  * $Author: wdluo $
  * $Revision: 67 $
  * $Date:: 2012-08-15 19:00:29 +0800 #$
  * @brief   USB上层函数声明.
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

#include  "usbd_customhid_core.h"


#define USB_MAXDATASIZE 0x40                                //一包长度

/* Exported Functions --------------------------------------------------------*/
extern uint8_t USB_RecvData[512];                           //接收到的数据
extern uint16_t USB_RecvDataLen;                            //数据长度
extern USB_OTG_CORE_HANDLE USB_OTG_dev;


void USB_IO_DeInit(void);                                   //USB反初始化
void USB_IO_Init(void);                                     //USB初始化
void USB_IO_Int(void);                                      //USB中断

void USB_IO_SendData(uint8_t *dat, uint16_t len);           //发送数据
void USB_IO_SendInt(uint8_t hasCard);                       //发送中断数据

void USB_IO_SendDataC(void);                                //发送数据实现
void USB_IO_RecvDataC(uint16_t rcvCount);                   //接收数据实现

void USB_TIMxInt(void);                                     //数据包超时判断


#endif //_USBIO_H_
