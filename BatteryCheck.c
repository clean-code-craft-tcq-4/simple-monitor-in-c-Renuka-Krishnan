#include "checker.h"
#include "BatteryCheck.h"

int BatterySocLowLimit(float soc)
{	
	if ((soc >= MINIMUM_LOWSOCBREACH) || (soc <= MINIMUM_SOCNORMAL))
	{
		return Check_NOT_OK; 
	}
	else
	{
		/*SOC of Battery is in charging state*/
		return Check_OK; 
	}
}

int BatterySocHighLimit(float soc)
{
	if ((soc >= MINIMUM_HIGHSOCWARNING) || (soc <= MINIMUM_HIGHSOCBREACH))
	{
		return Check_NOT_OK; 
	}
	else 
	{
		return Check_NOT_OK; 
	}
	
}

int checkSocOk(float soc )
{
	int socStatus = Check_OK;
	if((soc >= MINIMUM_LOWSOCBREACH) && (soc <= MINIMUM_HIGHSOCWARNING))
	{
		socStatus = BatterySocLowLimit(soc);
	}
	else
	{
		socStatus = BatterySocHighLimit(soc);
	}
	return socStatus;
}




int BatteryTempLowLimit(float temperature)
{	
	if ((temperature >= MINIMUM_LOWTEMPBREACH) || (temperature <= MINIMUM_TEMPNORMAL))
	{
		return Check_NOT_OK; 
	}
	else
	{
		return Check_OK; 
	}
}

int BatteryTempHighLimit(float temperature, char temperatureUnit)
{
	if ((temperature >= MINIMUM_HIGHTEMPWARNING) || (temperature <= MINIMUM_HIGHTEMPBREACH))
	{
		return Check_NOT_OK; 
	}
	else 
	{
		BatteryConvertTemp(temperature, temperatureUnit);
		return Check_NOT_OK; 
	}
	
}

int checkTempOK(float temperature, char temperatureUnit )
{
	int temperatureStatus = Check_OK;
	if((temperature >= MINIMUM_LOWTEMPBREACH) && (temperature < MINIMUM_HIGHTEMPWARNING))
	{
		temperatureStatus = BatteryTempLowLimit(temperature);
	}
	else
	{
		temperatureStatus = BatteryTempHighLimit(temperature, temperatureUnit);
	}
	return temperatureStatus;
}



float BatteryConvertTemp(float temperature, char temperatureUnit)
{
	float celcius;
	if((temperature > MIXIMUM_HIGHTEMPBREACH) && (temperatureUnit == TEMP_UNIT_FARENHEIT))
	{
		celcius = (temperature - 32) * 5 / 9;
	}
	else
	{
		return temperature;
	}
	return celcius;
}



int BatteryChargeRateLowLimit(float chargeRate)
{	
	if ((chargeRate >= MINIMUM_LOWCHARGERATEBREACH) || (chargeRate <= MINIMUM_CHARGERATENORMAL))
	{
		return Check_NOT_OK; 
	}
	else
	{
		return Check_OK; 
	}
}

int BatteryChargeRateHighLimit(float chargeRate)
{
	if ((chargeRate >= MINIMUM_HIGHCHARGERATEWARNING) || (chargeRate <= MINIMUM_HIGHCHARGERATEBREACH))
	{
		return Check_NOT_OK; 
	}
	else 
	{
		return Check_NOT_OK; 
	}
	
}

int checkchargeRate(float chargeRate )
{
	int chargeRateStatus = Check_OK;
	if((chargeRate >= MINIMUM_LOWCHARGERATEBREACH) && (chargeRate < MINIMUM_HIGHCHARGERATEWARNING))
	{
		chargeRateStatus = BatteryChargeRateLowLimit(chargeRate);
	}
	else
	{
		chargeRateStatus = BatteryChargeRateHighLimit(chargeRate);
	}
	return chargeRateStatus;
}




int BatteryStatusOK ( float temperature, float soc , float ChargeRate, char TemperatureUnit )

{	
	float stateOfCharge = checkSocOk(soc);
	float temperature = checkTempOK(temperature, temperatureUnit);
	float chargerate = checkchargeRate(chargeRate);
	return (stateOfCharge && temperature && chargerate);
}


int BatteryStatusNotOK (float temperature, float soc , float ChargeRate, char TemperatureUnit)
{	
	float stateOfCharge = checkSocOk(soc);
	float temperature = checkTempOK(temperature, temperatureUnit);
	float chargerate = checkchargeRate(chargeRate);
	return (stateOfCharge || temperature || chargerate);
}
