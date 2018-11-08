#ifndef _CCID_CORE_H
#define _CCID_CORE_H

#include "stm32f10x.h"

/***********Command code****************************************/
#define PC_to_RDR_IccPowerOn                                0x62
#define PC_to_RDR_IccPowerOff                               0x63
#define PC_to_RDR_GetSlotStatus                             0x65
#define PC_to_RDR_XfrBlock                                  0x6F
#define PC_to_RDR_GetParamenters                            0x6C
#define PC_to_RDR_ResetParamenters                          0x6D
#define PC_to_RDR_SetParamenters                            0x61
#define PC_to_RDR_Escape                                    0x6B
#define PC_to_RDR_IccClock                                  0x6E
#define PC_to_RDR_T0APDU                                    0x6A
#define PC_to_RDR_Secure                                    0x69
#define PC_to_RDR_Mechanical                                0x71
#define PC_to_RDR_Abort                                     0x72
#define PC_to_RDR_SetDataRateAndClockFrequency              0x73



void RDR_to_PC_DataBlock(uint8_t *data,uint16_t dataLen);
void RDR_to_PC_SlotStatus(void);
void RDR_to_PC_Parameters(void);
void RDR_to_PC_Escape(void);
void RDR_to_PC_DataRateAndClockFrequency(void);


#endif

