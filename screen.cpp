#include "screen.h"

int hmi = 0;

void sendCommand(const char* cmd)
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

void Init()
{
    int ret1 = 0;
    int ret2 = 0;

    const char* device = "/dev/ttyS0";  //dossier de serial0, voir serial0 avec 'ls /dev -l'
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
    printf(ret1 + " " + ret2);
    
}

void setTemp(double temp)
{
    int temperature = int(temp*10);
    sendCommand("temp_val.val=" + temperature);
}

void setPwr(double pwr)
{
    int power = int(pwr * 10);
    sendCommand("pow_val.val=" + power);
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

