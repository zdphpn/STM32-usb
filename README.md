# STM32-USB

STM32的USB库文件，包括STM32_USB-FS-Device_Lib_V3.3.0原始库、修改过的HID、SDT、COM功能库；STM32_USB-Host-Device_Lib_V2.2.0原始库、修改过的HID、SDT、COM功能库。

使用举例：

1、usb_io.c

    //修改以下宏定义，用于USB上拉
    #define USB_DISCONNECT                      GPIOC
    #define USB_DISCONNECT_PIN                  GPIO_Pin_3
    #define RCC_APB2Periph_GPIO_DISCONNECT      RCC_APB2Periph_GPIOC


2、stm32f10x_it.c

    #include "usb_io.h"

    void OTG_FS_IRQHandler()
    {
        USB_IO_Int();
    }
    或
    void USB_LP_CAN1_RX0_IRQHandler()
    {
        USB_IO_Int();
    }


3、main.c

    #include "usb_io.h"

    void main()
    {

        ...
        USB_IO_Init();
        ...

        while(1)
        {
            if(USB_RecvDataLen>0)
            {
                USB_IO_SendData(USB_RecvData,USB_RecvDataLen);
                USB_RecvDataLen=0;
            }
        }
    }



