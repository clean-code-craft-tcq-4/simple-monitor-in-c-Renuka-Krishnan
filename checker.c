#include "checker.h"
#include "BatteryChecker.h"

int batteryIsOk(float temperature, float soc, float ChargeRate, char TemperatureUnit) 
{
int Result = BatteryStatusOK(temperature,soc,ChargeRate,TemperatureUnit); 
return Result;
}

 int BatteryIsNotOk(float temperature, float soc , float ChargeRate, char TemperatureUnit)
{	
	int Result = BatteryStatusNotOK(temperature,soc,ChargeRate,TemperatureUnit);
	return Result;
} 

int main() 
  
  {
    assert(!batteryIsOk(-1, 100, 0.9));
    assert(BatteryIsOk(25,37,0.7,'C'));
    assert(BatteryIsOk(39,280,0.6,'F'));
    assert(BatteryIsNotOk(78,-1,1.0,'N')); 
	  assert(BatteryIsNotOk(89,48,0.9,'C')); 
 }
