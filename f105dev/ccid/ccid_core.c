#include "ccid_core.h"
#include "string.h"
#include "usb_io.h"


uint8_t sendTemp[USB_MAXDATASIZE];
uint16_t lenTemp;


void RDR_to_PC_DataBlock(uint8_t *data,uint16_t dataLen)
{
    lenTemp=USB_MAXDATASIZE-10;
    if(lenTemp>dataLen)
    {
        lenTemp=dataLen;
    }
    memcpy(sendTemp+10,data,lenTemp);
	
    sendTemp[0]=0x80;
    sendTemp[1]=dataLen&0x00FF;
    sendTemp[2]=(dataLen>>8)&0x00FF;
    sendTemp[3]=0x00;
    sendTemp[4]=0x00;
    sendTemp[5]=USB_RecvData[5];
    sendTemp[6]=USB_RecvData[6];
    sendTemp[7]=USB_RecvData[7];	
    sendTemp[8]=0x00;
    sendTemp[9]=0x00;
	
    USB_IO_SendData(sendTemp,lenTemp+10);                   //先发送CCID头和一部分数据
    if(dataLen>lenTemp)
    {
        USB_IO_SendData(data+lenTemp,dataLen-lenTemp);      //发送其他数据
    }
    
}
void RDR_to_PC_SlotStatus(void)
{
    sendTemp[0]=0x81;                                       //固定为0x81
    sendTemp[1]=0x00;                                       //长度
    sendTemp[2]=0x00;
    sendTemp[3]=0x00;
    sendTemp[4]=0x00;
    sendTemp[5]=USB_RecvData[5];                            //与接收相同
    sendTemp[6]=USB_RecvData[6];
    sendTemp[7]=0x00;                                       //			
    sendTemp[8]=0x00;                                       //无错误
    sendTemp[9]=0x00;                                       //数据是完整的
	
    USB_IO_SendData(sendTemp,0x0A);
}
void RDR_to_PC_Parameters(void)
{
    sendTemp[0]=0x82;                                       //固定为0x82
    sendTemp[1]=0x05;                                       //长度
    sendTemp[2]=0x00;
    sendTemp[3]=0x00;
    sendTemp[4]=0x00;
    sendTemp[5]=USB_RecvData[5];                            //与接收相同
    sendTemp[6]=USB_RecvData[6];
    sendTemp[7]=0x00;                                       //		
    sendTemp[8]=0x00;                                       //无错误
    sendTemp[9]=0x00;                                       //T=0协议
	
    sendTemp[10]=USB_RecvData[10];			
    sendTemp[11]=USB_RecvData[11];			
    sendTemp[12]=USB_RecvData[12];			
    sendTemp[13]=USB_RecvData[13];			
    sendTemp[14]=USB_RecvData[14];			
	
    USB_IO_SendData(sendTemp,0x0F);
}
void RDR_to_PC_Escape(void)
{
    sendTemp[0]=0x83;                                       //固定为0x83
    sendTemp[1]=0x00;                                       //长度
    sendTemp[2]=0x00;
    sendTemp[3]=0x00;
    sendTemp[4]=0x00;
    sendTemp[5]=USB_RecvData[5];                            //与接收相同
    sendTemp[6]=USB_RecvData[6];
    sendTemp[7]=0x00;                                       //		
    sendTemp[8]=0x00;                                       //无错误
    sendTemp[9]=0x00;                                       //
	
    USB_IO_SendData(sendTemp,0x0A);
}
void RDR_to_PC_DataRateAndClockFrequency(void)
{
    sendTemp[0]=0x84;                                       //固定为0x84
    sendTemp[1]=0x08;                                       //长度0x08
    sendTemp[2]=0x00;
    sendTemp[3]=0x00;
    sendTemp[4]=0x00;
    sendTemp[5]=USB_RecvData[5];                            //与接收相同
    sendTemp[6]=USB_RecvData[6];
    sendTemp[7]=0x00;                                       //		
    sendTemp[8]=0x00;                                       //无错误
    sendTemp[9]=0x00;                                       //
	
    sendTemp[10]=USB_RecvData[10];			
    sendTemp[11]=USB_RecvData[11];			
    sendTemp[12]=USB_RecvData[12];			
    sendTemp[13]=USB_RecvData[13];			
    sendTemp[14]=USB_RecvData[14];			
    sendTemp[15]=USB_RecvData[15];			
    sendTemp[16]=USB_RecvData[16];			
    sendTemp[17]=USB_RecvData[17];			
	
    USB_IO_SendData(sendTemp,0x12);
}
