#include "screen.h"
#include <iostream>
#include <wiringSerial.h>
//#include "nextion/NexText.h"
#include "nextion/Nextion.h"


int main(void) {

    int hmi = 0;
    const char *device = "/dev/ttyS0";
    int baud = 9600;
    hmi = serialOpen(device, baud);
    hmi = nexInit(hmi);
    bool ret1 = false;
    bool ret2 = false;
    serialPrintf(hmi, "");
    serialPrintf(hmi, "0xFF");
    serialPrintf(hmi, "0xFF");
    serialPrintf(hmi, "0xFF");
    //serialPrintf(hmi, "0xFF");
    serialPrintf(hmi, "bkcmd=1");
    serialPrintf(hmi, "0xFF");
    serialPrintf(hmi, "0xFF");
    serialPrintf(hmi, "0xFF");
    //serialPrintf(hmi, "0xFF");
    ret1 = serialGetchar(hmi);
    serialPrintf(hmi, "page 0");
    serialPrintf(hmi, "0xFF");
    serialPrintf(hmi, "0xFF");
    serialPrintf(hmi, "0xFF");

    ret2 = serialGetchar(hmi);
    //serialPrintf(hmi, "0xFF");
    std::cout << ret1 << " & " << ret2 << std::endl;
	
    //SET
    serialPrintf(hmi, "temp.val=220");
    serialPrintf(hmi, "0xFF");
    serialPrintf(hmi, "0xFF");
    serialPrintf(hmi, "0xFF");
    //serialPrintf(hmi, "0xFF");
    //GET
    while (1) {
        while (serialDataAvail(hmi)) {
            int data = serialGetchar(hmi);
            std::cout << data << std::endl;
        }
    }
    //        std::cout << data << std::endl;
    //    }
    //}

	return 0;

}