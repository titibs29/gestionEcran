#include <wiringSerial.h>
#include <string.h>
#include <iostream>
#include "screen.h"

void sendCommand(int hmi, const char* cmd)
{
    while (serialDataAvail(hmi))
    {
        serialGetchar(hmi);
    }

    bool ret1 = false;
    bool ret2 = false;
    serialPrintf(hmi, "");
    serialPrintf(hmi, "0xFF");
    serialPrintf(hmi, "0xFF");
    serialPrintf(hmi, "0xFF");
}

    void Init()
{
    int ret1 = 0;
    int ret2 = 0;

    const char* device = "/dev/ttyS0";  //dossier de serial0, vor 'ls /dev -l'
    int baud = 9600;
    hmi = serialOpen(device, baud);

    sendCommand("");
    sendCommand("bkcmd=1");
    while (serialDataAvail(hmi))
    {
        ret1 = serialGetchar(hmi);
    }

    sendCommand("page 0");
    while (serialDataAvail(hmi))
    {
        ret2 = serialGetchar(hmi);
    }
    return ret1 & ret2;
}

void setTemp(double temp)
{
    int temperature = int(temp*10);
    sendCommand("temp_val.val=" + temperature);
}

void setPwr(double pwr)
{
    int power = int(pwr * 10);
    sendCommand("pwr_val.val=" + power);
}

void setLatitude(int lat)
{
    sendCommand("lat_val.val=" + lat);
}

void setLongitude(int lon)
{
    sendCommand("lon_val.val=" + lon);
}

void setPosition(double lat,double lon)
{
    int latitude = int(lat * 1000000);
    int longitude = int(lon * 1000000);

    setLatitude(latitude);
    setLongitude(longitude);
}

void setSignal(int signal)
{
    sendCommand("sig_val.val=" + signal);
}

int getTemp() {
    ////GET
    //while (1) {
    //    while (serialDataAvail(hmi)) {
    //        int data = serialGetchar(hmi);
    //        std::cout << data << std::endl;
    //    }
    //}
    return 0;
}

