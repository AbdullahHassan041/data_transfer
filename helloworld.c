/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xtop.h"
#include "xparameters.h"
#include "xil_cache.h"
XTop top_instance;
XTop_Config *top_config;


int main()
{

	//////////////////////////////Initializations/////////////////////////////////////////////////////
	init_platform();
	////////////////////////////////
	u32 array1[16]={6,15,55,25,15,55,225,70,55,225,979,90,25,70,90,1000};
	u32 array2[16]={0};
	//u32 array4[16]={0};
	///////////////
	u32 *TxBufferPtr;
	u32 *RxBufferPtr;

	TxBufferPtr = array1;
	RxBufferPtr = array2;
    ////////////////////////////////

	top_config= XTop_LookupConfig(XPAR_TOP_0_DEVICE_ID);
	XTop_CfgInitialize(&top_instance, top_config);

	//////////////////////////////////start/////////////////////////////////////////////////////////////////

	XTop_Set_B(&top_instance, (UINTPTR)TxBufferPtr);
	XTop_Set_C(&top_instance, (UINTPTR)RxBufferPtr);


    ////////////////////////////////////process/////////////////////////////////////////////////////////////
	XTop_Start(&top_instance);
   while(!XTop_IsDone(&top_instance));
    //array3= XTop_Get_C(&top_instance);

    for(int i=0;i<16;i++)
    {
    	//array4[i]=array2[i];
    	printf("value of array2 is %lu\n",array2[i]);

    }


    ////////////////////////////////////outputs/////////////////////////////////////////////////
    print("Hello World\n\r");
    print("Successfully ran Hello World application");
    cleanup_platform();
    return 0;
}
