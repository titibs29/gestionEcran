#include "screen.h"

void sendCommand(int hmi, const char* cmd)
{
    while (serialDataAvail(hmi))
    {
        serialGetchar(hmi);
    }

    serialPrintf(hmi, cmd);
    serialPutchar(hmi, 0xFF);
    serialPutchar(hmi, 0xFF);
    serialPutchar(hmi, 0xFF);
}

int Init(int hmi)
{
    int ret1 = 0;
    int ret2 = 0;

    const char* device = "/dev/ttyS0";
    int baud = 9600;
    hmi = serialOpen(device, baud);

    sendCommand(hmi, "");
    sendCommand(hmi, "bkcmd=1");
    while (serialDataAvail(hmi))
    {
        ret1 = serialGetchar(hmi);
    }

    sendCommand(hmi, "page 0");
    while (serialDataAvail(hmi))
    {
        ret2 = serialGetchar(hmi);
    }
    printf(ret1 + " " + ret2);
    return hmi;
}

void setTemp(float input) {
    int 

}

void setPwr(int pwr)
{
}

void setLatitude(int lat)
{
}

void setLongitude(int lon)
{
}

void setSignal(int signal)
{
}

int getTemp() {
	
    return 0;
}

