#include <stdbool.h>

#define Check_OK                       0
#define Check_NOT_OK                   1

#define TEMP_UNIT_CELCIUS         'C'
#define TEMP_UNIT_FARENHEIT       'F'

#define MINIMUM_LOWTEMPBREACH        0
#define MINIMUM_LOWTEMPWARNING       5
#define MINIMUM_TEMPNORMAL           10
#define MINIMUM_HIGHTEMPWARNING      40
#define MINIMUM_HIGHTEMPBREACH       45
#define MIXIMUM_HIGHTEMPBREACH       80

#define MINIMUM_LOWSOCBREACH          0
#define MINIMUM_LOWSOCWARNING        20
#define MINIMUM_SOCNORMAL		         24
#define MINIMUM_HIGHSOCWARNING 	     75
#define MINIMUM_HIGHSOCBREACH        80
#define MIXIMUM_HIGHOCBREACH         100


#define MINIMUM_LOWCHARGERATEBREACH   0
#define MINIMUM_LOWCHARGERATEWARNING  0.2
#define MINIMUM_CHARGERATENORMAL      0.3
#define MINIMUM_HIGHCHARGERATEWARNING 0.7
#define MINIMUM_HIGHCHARGERATEBREACH  0.8
#define MIXIMUM_HIGHCHARGERATEBREACH  1.0

extern int BatteryStatusOK( float temperature, float soc , float ChargeRate, char TemperatureUnit);
extern int BatteryStatusNotOK ( float temperature, float soc , float ChargeRate,char TemperatureUnit);

extern int BatterySocLowLimit(float soc);
extern int BatterySocHighLimit(float soc);
extern int checkSocOk(float soc );
extern int BatteryTempLowLimit(float temperature);
extern int BatteryTempHighLimit(float temperature , char TemperatureUnit);
extern int checkTempOK(float temp , char TemperatureUnit );
extern int BatteryChargeRateLowLimit(float chargeRate);
extern int BatteryChargeRateHighLimit(float chargeRate);
extern int checkchargeRate(float chargeRate );
extern bool BatteryTempUnit(char cel);
extern float BatteryConvertTemp(float temperature, char TemperatureUnit);

