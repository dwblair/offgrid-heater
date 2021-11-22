// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 12

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

#define timedelay_ms 1000*60*30 // 30 minutes
//#define timedelay_ms 10000
#define pwm_step 80
#define HEATPIN 7
#define write_delay_ms 5000 //write out every 5 seconds
/*
 * The setup function. We only start the sensors here
 */

float time_sec=0;
int pwm = 255; // start full

int lastReading = millis();

void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  while(!Serial)
  ;
  // Start up the library
  sensors.begin();
    pinMode(HEATPIN, OUTPUT);

}

/*
 * Main function, get and show the temperature
 */
void loop(void)
{ 

  time_sec=time_sec+write_delay_ms/1000.;
  analogWrite(HEATPIN,pwm);
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.print(time_sec);
  Serial.print(",");
  Serial.print(pwm);
  Serial.print(",");
  Serial.println(sensors.getTempCByIndex(0));  

  //wait
  delay(write_delay_ms);

  if ((millis()-lastReading)>timedelay_ms) {
  //increment pwm
  pwm=pwm-pwm_step;
  if (pwm<=0) pwm = 255;
  lastReading=millis();
  }
}
