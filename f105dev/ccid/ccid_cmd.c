#include "ccid_cmd.h"
#include "ccid_core.h"
#include "usb_io.h"



uint8_t* Apdu=0;
uint16_t ApduLen=0;
uint8_t Rpdu[260];
uint16_t RpduLen=0;

                                                            //模拟ATR3B B2 11 00 81 31 20 01 48 58 22
uint8_t exm_ATRData[0x0B]={0x3b,0xb2,0x11,0x00,0x81,0x31,0x20,0x01,0x48,0x58,0x22};
uint8_t exm_AtrLen=0x0B;                                    //模拟ATR长度

void ccid_cmd(void)
{
    switch(USB_RecvData[0])                                 //判断CCID数据类型
    {
        case PC_to_RDR_IccPowerOn:
            RDR_to_PC_DataBlock(exm_ATRData,exm_AtrLen);
            break;
        case PC_to_RDR_IccPowerOff:
            RDR_to_PC_SlotStatus();
            break;
        case PC_to_RDR_GetSlotStatus:
            RDR_to_PC_SlotStatus();
            break;
        case PC_to_RDR_XfrBlock:
        {
            Apdu=USB_RecvData+10;
            ApduLen=USB_RecvDataLen-10;
            if(ApduLen>256)ApduLen=0;
            
            RpduLen=2;
            Rpdu[0]=0x6E;
            Rpdu[1]=0x00;
            
			
            RDR_to_PC_DataBlock(Rpdu,RpduLen);
            break;
        }
        case PC_to_RDR_GetParamenters:
            RDR_to_PC_Parameters();
            break;
        case PC_to_RDR_ResetParamenters:
            RDR_to_PC_Parameters();
            break;
        case PC_to_RDR_SetParamenters:
            RDR_to_PC_Parameters();
            break;
        case PC_to_RDR_Escape:
            RDR_to_PC_Escape();
            break;
        case PC_to_RDR_IccClock:
            RDR_to_PC_SlotStatus();
            break;
        case PC_to_RDR_T0APDU:
            RDR_to_PC_SlotStatus();
            break;
        case PC_to_RDR_Secure:
            {
                uint8_t exm_Data[0x02]={0x90,0x00};
                uint8_t exm_Len=0x02;
				
                RDR_to_PC_DataBlock(exm_Data,exm_Len);
                break;
			}
        case PC_to_RDR_Mechanical:
            RDR_to_PC_SlotStatus();
            break;
        case PC_to_RDR_Abort:
            RDR_to_PC_SlotStatus();
            break;
        case PC_to_RDR_SetDataRateAndClockFrequency:
            RDR_to_PC_DataRateAndClockFrequency();
            break;
    }
}
