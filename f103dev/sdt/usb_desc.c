/******************** (C) COPYRIGHT 2008 STMicroelectronics ********************
* File Name          : usb_desc.c
* Author             : MCD Application Team
* Version            : V2.2.1
* Date               : 09/22/2008
* Description        : Descriptors for Virtual Com Port Demo
********************************************************************************
* THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
* WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
* AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
* INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
* CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
* INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/

#include "usb_desc.h"
/* USB Standard Device Descriptor */
const u8 Virtual_Com_Port_DeviceDescriptor[] =
{
    0x12,                       /*bLength */
    0x01, 											/*bDescriptorType*/
    0x00,                       /*bcdUSB */
    0x01,
    0x00,                       /*bDeviceClass*/
    0x00,                       /*bDeviceSubClass*/
    0x00,                       /*bDeviceProtocol*/
    0x08,                       /*bMaxPacketSize40*/
    0x00,                       /*idVendor (0x0483)*/
    0x04,
    0x5a,                       /*idProduct = 0x5750*/
    0xc3,
    0x63,                       /*bcdDevice rel. 2.00*/
    0x00,
    0,                          /*Index of string descriptor describing manufacturer */
    0,                          /*Index of string descriptor describing product*/
    0,                          /*Index of string descriptor describing the device serial number */
    0x01                        /*bNumConfigurations*/
};

const u8 Virtual_Com_Port_ConfigDescriptor[] =
{
    0x09, 0x02, 0x20, 0x00, 0x01, 0x01, 0x00, 0x40, 0x00,
    0x09, 0x04, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,
    0x07, 0x05, 0x81, 0x02, 0x40, 0x00, 0xff,
    0x07, 0x05, 0x02, 0x02, 0x40, 0x00, 0xff,
};

/* USB String Descriptors */
const u8 Virtual_Com_Port_StringLangID[VIRTUAL_COM_PORT_SIZ_STRING_LANGID] =
{
    VIRTUAL_COM_PORT_SIZ_STRING_LANGID,
    USB_STRING_DESCRIPTOR_TYPE,
    0x09,
    0x04 /* LangID = 0x0409: U.S. English */
};

const u8 Virtual_Com_Port_StringVendor[VIRTUAL_COM_PORT_SIZ_STRING_VENDOR] =
{
    VIRTUAL_COM_PORT_SIZ_STRING_VENDOR,     /* Size of Vendor string */
    USB_STRING_DESCRIPTOR_TYPE,             /* bDescriptorType*/
    /* Manufacturer: "STMicroelectronics" */
    'S', 0, 'T', 0, 'M', 0, '3', 0, '2', 0, 'F', 0, '1', 0, '0', 0,
    '3', 0, 'x', 0, 'x', 0
};

const u8 Virtual_Com_Port_StringProduct[VIRTUAL_COM_PORT_SIZ_STRING_PRODUCT] =
{
    VIRTUAL_COM_PORT_SIZ_STRING_PRODUCT,          /* bLength */
    USB_STRING_DESCRIPTOR_TYPE,        /* bDescriptorType */
    /* Product name: "STM32 Virtual COM Port" */
    'S', 0, 'T', 0, 'M', 0, '3', 0, '2', 0, 'F', 0, '1', 0, '0', 0,
    '3', 0, 'x', 0, 'x', 0, 'x', 0, 'x', 0
};

u8 Virtual_Com_Port_StringSerial[VIRTUAL_COM_PORT_SIZ_STRING_SERIAL] =
{
    VIRTUAL_COM_PORT_SIZ_STRING_SERIAL,           /* bLength */
    USB_STRING_DESCRIPTOR_TYPE,                   /* bDescriptorType */
    'S', 0, 'T', 0, 'M', 0, '3', 0, '2', 0, '1', 0, '0', 0
}
;/******************* (C) COPYRIGHT 2008 STMicroelectronics *****END OF FILE****/
