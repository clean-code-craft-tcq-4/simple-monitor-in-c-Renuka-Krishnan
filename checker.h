#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

extern int batteryIsOk(float temperature, float soc, float ChargeRate, char TemperatureUnit);
extern int BatteryIsNotOk(float temperature, float soc , float ChargeRate, char TemperatureUnit);
