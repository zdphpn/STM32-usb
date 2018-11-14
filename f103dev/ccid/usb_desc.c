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
    0x12,			//	length
    0x01,			//	Fixed device
    0x10, 0x01,		//	USB 1.1
    0x00,
    0x00,
    0x00,
    0x40,		//	Default max ep0 packet length
    0xff, 0xff,		//	VID
    0xff, 0xf5,		//	PID
    0x00, 0x01,		//	Device release number
    0x01,			//	Index of string descriptor describing manufacturer
    0x02,			//	Index of string descriptor describing product
    0x03,			//	Index of string descriptor describing the device¡¯s serial number
    0x01,			//	Number of possible configurations
};

const u8 Virtual_Com_Port_ConfigDescriptor[] =
{
    0x09, USB_CONFIGURATION_DESCRIPTOR_TYPE, VIRTUAL_COM_PORT_SIZ_CONFIG_DESC, 0x00, 0x01, 0x01, 0x00, 0x80, 0x32,


    0x09, 					//	length
    0x04,					//	Fixed interface
    0x00,					//	Interface  Number is 0
    0x00,					//	Alternate Setting is 0
    0x03,					//	Ep number is 3,they are 1,2,3
    0x0B,					//	Smart Card Device Class
    0x00,					//	Subclass code
    0x00,					//	CCID Protocol
    0x00,					//	Index of string descriptor describing this interface

    0x36,		   			//	length
    0x21,		   			//	Functional S/C Device Class descriptor type
    0x00, 0x01,	   			//	CCID1.0(CCID1.1)
    0x00,		   			//	1 Slot numbered 0x00
    0x07,		   			//	01H-5.0V,02H-3.0V,03H-1.8V
    0x03, 0x00, 0x00, 0x00,	//	Little Endian,Upper u16 is RFU = 0x0000,Lower u16:0001H-T=0,0002H-T=1
    0xa0, 0x0f, 0x00, 0x00,	//	3.58MHz=3580KHz=0x0DFC
    0xa0, 0x0f, 0x00, 0x00,	//	14.32MHz
    0x00,
    0x00, 0x2a, 0x00, 0x00,	//	9600bps
    0x16, 0x40, 0x05, 0x00,	//	115200bps
    0x00,
    0xfe, 0x00, 0x00, 0x00,	//	IFSD (T=1)
    0x00, 0x00, 0x00, 0x00,	//	Upper u16 is RFU = 0x0000,Lower u8 encodes the supported protocol type
    0x00, 0x00, 0x00, 0x00,	//	No spefcial characteristics
    0x80, 0x00, 0x04, 0x00,
    //0x00,0x00,0x00,0x00,
    0x0f, 0x01, 0x00, 0x00,	//	271B = 10B Header + 5B CMD + 256B data
    0x00,
    0x00,
    0x00, 0x00,				//	No LCD
    0x00,
    0x01, 					//	1 slot can be simultaneously busy



    /*Endpoint 2 Descriptor*/
    0x07,   /* bLength: Endpoint Descriptor size */
    USB_ENDPOINT_DESCRIPTOR_TYPE,   /* bDescriptorType: Endpoint */
    0x82,   /* bEndpointAddress: (IN2) */
    0x03,   /* bmAttributes: Interrupt */
    //VIRTUAL_COM_PORT_INT_SIZE,      /* wMaxPacketSize: */
    0x10,
    0x00,
    0xFF,   /* bInterval: */

    /*Endpoint 3 Descriptor*/
    0x07,   /* bLength: Endpoint Descriptor size */
    USB_ENDPOINT_DESCRIPTOR_TYPE,   /* bDescriptorType: Endpoint */
    0x03,   /* bEndpointAddress: (OUT3) */
    0x02,   /* bmAttributes: Bulk */

    VIRTUAL_COM_PORT_DATA_SIZE,             /* wMaxPacketSize: */
    0x00,
    0x00,   /* bInterval: ignore for Bulk transfer */


    /*Endpoint 1 Descriptor*/
    0x07,   /* bLength: Endpoint Descriptor size */
    USB_ENDPOINT_DESCRIPTOR_TYPE,   /* bDescriptorType: Endpoint */
    0x81,   /* bEndpointAddress: (IN1) */
    0x02,   /* bmAttributes: Bulk */
    VIRTUAL_COM_PORT_DATA_SIZE,             /* wMaxPacketSize: */
    0x00,
    0x00    /* bInterval */
    /*32*/
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
