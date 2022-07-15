#define Check_OK 1
#define Check_NOT_OK 0 

int SocCheck(float soc);
int ChargeRateCheck(float chargeRate);
int TemperatureCheck(float temp);
int CheckBatteryStatus(float ActualValue, float minimum, float maximum);
