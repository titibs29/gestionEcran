#include <wiringSerial.h>
#include <string.h>
#include <iostream>
#include "screen.h"

int hmi = 0;

void init(const char *device,int baud) {
	hmi=serialOpen(device, baud);

    bool ret1 = false;
    bool ret2 = false;
    serialPrintf(hmi, "");
    serialPrintf(hmi, "0xFF");
    serialPrintf(hmi, "0xFF");
    serialPrintf(hmi, "0xFF");

    serialPrintf(hmi, "bkcmd=1");
    serialPrintf(hmi, "0xFF");
    serialPrintf(hmi, "0xFF");
    serialPrintf(hmi, "0xFF");

    ret1 = serialGetchar(hmi);
    serialPrintf(hmi, "page 0");
    serialPrintf(hmi, "0xFF");
    serialPrintf(hmi, "0xFF");
    serialPrintf(hmi, "0xFF");

    ret2 = serialGetchar(hmi);
}

void setTemp(int temp) {


}

int getTemp() {
	while (serialDataAvail(hmi)) {
		char data = serialGetchar(hmi);
		std::cout << data << std::endl;
	}
    return 0;
}

