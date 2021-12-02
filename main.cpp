#include <iostream>
#include <wiringSerial.h>
#include "screen.h"
#include "nextion/Nextion.h"






int main(void) {

    //INIT
    


    int hmi = 0;
    hmi = nexInit(hmi);

    printf("changement de temp_val");
    sendCommand(hmi, "temp_val.val=220");
    //bool ret1 = false;
    //bool ret2 = false;
    //serialPrintf(hmi, "");
    //serialPrintf(hmi, "0xFF");
    //serialPrintf(hmi, "0xFF");
    //serialPrintf(hmi, "0xFF");

    //serialPrintf(hmi, "bkcmd=1");
    //serialPrintf(hmi, "0xFF");
    //serialPrintf(hmi, "0xFF");
    //serialPrintf(hmi, "0xFF");

    //ret1 = serialGetchar(hmi);
    //serialPrintf(hmi, "page 0");
    //serialPrintf(hmi, "0xFF");
    //serialPrintf(hmi, "0xFF");
    //serialPrintf(hmi, "0xFF");

    //ret2 = serialGetchar(hmi);

    //std::cout << ret1 << " & " << ret2 << std::endl;
	
    ////SET
    //serialPrintf(hmi, "temp.val=220");
    //serialPrintf(hmi, "0xFF");
    //serialPrintf(hmi, "0xFF");
    //serialPrintf(hmi, "0xFF");

    ////GET
    //while (1) {
    //    while (serialDataAvail(hmi)) {
    //        int data = serialGetchar(hmi);
    //        std::cout << data << std::endl;
    //    }
    //}

	return 0;

}