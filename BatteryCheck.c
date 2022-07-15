#include <checker.h>
#include <BatteryCheck.h>

int CheckBatteryStatus(float ActualValue, float minimum, float maximum)
{
  if (ActualValue < minimum || ActualValue > maximum)
  {
  return Check_NOT_OK;
  } 
else
  {
  return Check_OK;
  }
  
}


int TemperatureCheck(float temp)
{
int val = CheckBatteryStatus(temperature, 0, 45);
if(val == Check_NOT_OK)
{
printf("Temperature value not in range!\n");
return Check_NOT_OK;
}
else 
{
return Check_OK;
} 
} 

int SocCheck(float soc)
{
    int val = CheckBatteryStatus(soc, 20, 80);
    if(val == Check_NOT_OK)
    {
         printf("State of Charge out of range!\n");
        return Check_NOT_OK;
    }
    else 
    {
         return Check_OK;
    }      
}

int ChargeRateCheck(float chargeRate)
{
   int val = CheckBatteryStatus(chargeRate, 0, 0.8);
    if(val == Check_NOT_OK)
    {
        printf("State of Charge out of range!\n");
        return Check_NOT_OK;
    }
    else 
    {
         return Check_OK;
    }      
}

