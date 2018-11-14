/**
  ******************************************************************************
  * @file    usbio.c
  * $Author: wdluo $
  * $Revision: 67 $
  * $Date:: 2012-08-15 19:00:29 +0800 #$
  * @brief   USB上层函数.
  ******************************************************************************
  * @attention
  *
  *<h3><center>&copy; Copyright 2009-2012, ViewTool</center>
  *<center><a href="http:\\www.viewtool.com">http://www.viewtool.com</a></center>
  *<center>All Rights Reserved</center></h3>
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "usb_desc.h"
#include "usb_lib.h"
#include "usb_istr.h"

#include "usb_io.h"
#include "string.h"


#define USB_DISCONNECT                      GPIOC
#define USB_DISCONNECT_PIN                  GPIO_Pin_3
#define RCC_APB2Periph_GPIO_DISCONNECT      RCC_APB2Periph_GPIOC


uint8_t USB_RecvData[512] = {0x00};
uint16_t USB_RecvDataLen = 0;

uint8_t *USB_SendData = 0;
uint16_t USB_SendDataLen = 0;

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/


void USB_IO_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    //相关时钟初始化
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIO_DISCONNECT, ENABLE);
    RCC_USBCLKConfig(RCC_USBCLKSource_PLLCLK_1Div5);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_USB, ENABLE);
    
    //USB上拉引脚初始化
    GPIO_InitStructure.GPIO_Pin = USB_DISCONNECT_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(USB_DISCONNECT, &GPIO_InitStructure);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
    NVIC_InitStructure.NVIC_IRQChannel = USB_LP_CAN1_RX0_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 5;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    
    //USB设备初始化
    USB_Init();
    
    GPIO_SetBits(USB_DISCONNECT, USB_DISCONNECT_PIN);
  
}

void USB_IO_Int(void)
{
    USB_Istr();
}


static uint16_t usbSendCount = 0;

void USB_IO_SendData(uint8_t *dat, uint16_t len)
{
    USB_SendData = dat;
    USB_SendDataLen = len;
    usbSendCount = 0;

    USB_IO_SendDataC();
}

/* Private functions ---------------------------------------------------------*/
void USB_IO_SendDataC()
{
    if(USB_SendDataLen > USB_MAXDATASIZE)
    {
        USB_SendDataLen = USB_SendDataLen - USB_MAXDATASIZE;
        USB_SIL_Write(ENDP1, (USB_SendData + (usbSendCount * USB_MAXDATASIZE)), USB_MAXDATASIZE);
        usbSendCount++;
        SetEPTxCount(ENDP1, USB_MAXDATASIZE);
        SetEPTxValid(ENDP1);
    }
    else
    {
        if(USB_SendDataLen > 0)
        {
            USB_SIL_Write(ENDP1, (USB_SendData + (usbSendCount * USB_MAXDATASIZE)), USB_SendDataLen);
            SetEPTxCount(ENDP1, USB_SendDataLen);
            SetEPTxValid(ENDP1);
            USB_SendDataLen = 0;
            usbSendCount = 0;
        }
    }
}

void USB_IO_RecvDataC()
{
    uint16_t countOne;
    static uint16_t countAll = 0, countNow = 0;

    countOne = USB_SIL_Read(ENDP3, USB_RecvData + countNow);
    SetEPRxValid(ENDP3);
    if(!countNow)
    {
        countAll = USB_RecvData[2];
        countAll = ((countAll << 8) & 0xff00) + USB_RecvData[1] + 10;
        if(countAll > sizeof(USB_RecvData))
        {
            countAll = 10;
        }
    }
    countNow = countOne + countNow;
    if(countOne == USB_MAXDATASIZE)
    {
        if(countNow >= countAll)
        {
            USB_RecvDataLen = countNow;
            countNow = 0;
        }
    }
    else
    {
        USB_RecvDataLen = countNow;
        countNow = 0;
    }
}

void USB_IO_SendInt(uint8_t inter)   //
{
    uint8_t send[2];
    send[0] = 0x50;
    if(inter == 1)
    {
        send[1] = 0x03;
    }
    else
    {
        send[1] = 0x02;
    }

    USB_SIL_Write(ENDP2, send, 2);
    SetEPTxCount(ENDP2, 2);
    SetEPTxValid(ENDP2);
}

/*********************************END OF FILE**********************************/

