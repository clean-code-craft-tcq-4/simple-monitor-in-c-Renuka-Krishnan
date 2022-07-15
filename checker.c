#include "checker.h"
#include "BatteryChecker.h"

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
int  TempResult = TemperatureCheck (temperature);
int SocResult = SocCheck(soc);
int chargeRateResult = ChargeRateCheck(chargeRate); 
return (TempResult && SocResult && chargeRateResult);


}

int main() 
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
  assert(!batteryIsOk(-1, 100, 0.9));
}
