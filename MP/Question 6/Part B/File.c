#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvUART.h"
#include "Driver\DrvSYS.h"
int main (void)
{
	UNLOCKREG();
	DrvSYS_Open(48000000);
	LOCKREG();
	DrvGPIO_Open(E_GPC, 15, E_IO_OUTPUT);
	DrvGPIO_Open(E_GPC, 14, E_IO_OUTPUT);
	DrvGPIO_Open(E_GPC, 13, E_IO_OUTPUT);
	DrvGPIO_Open(E_GPC, 12, E_IO_OUTPUT);
	DrvGPIO_SetBit(E_GPC, 15);
	DrvGPIO_SetBit(E_GPC, 14);
	DrvGPIO_SetBit(E_GPC, 13);
	DrvGPIO_SetBit(E_GPC, 12);
	while(1)
	{
		DrvGPIO_ClrBit(E_GPC, 15);
		DrvSYS_Delay(100000);
		DrvGPIO_SetBit(E_GPC, 15);
		//DrvSYS_Delay(100000);			not sure if delay is required to work like a ring counter 
		DrvGPIO_ClrBit(E_GPC, 14);
		DrvSYS_Delay(100000);
		DrvGPIO_SetBit(E_GPC, 14);
		//DrvSYS_Delay(100000);			check if required while execution			
		DrvGPIO_ClrBit(E_GPC, 13);
		DrvSYS_Delay(100000);
		DrvGPIO_SetBit(E_GPC, 13);
		//DrvSYS_Delay(100000);			ring counter is same like digital lab
		DrvGPIO_ClrBit(E_GPC, 12);
		DrvSYS_Delay(100000);
		DrvGPIO_SetBit(E_GPC, 12);
		//DrvSYS_Delay(100000);			each led glows once and comes back to the starting one and cycles
	}
}
