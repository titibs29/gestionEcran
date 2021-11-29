#pragma once

void init(const char *device = "/dev/ttyS0", int baud=9600);

void setTemp(int temp);
int getTemp();