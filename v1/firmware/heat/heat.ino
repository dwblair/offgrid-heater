// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 12

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

#define HEATPIN 7
/*
 * The setup function. We only start the sensors here
 */

int pwm = 255; // start full


void setup(void)
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin();
    pinMode(HEATPIN, OUTPUT);

}

/*
 * Main function, get and show the temperature
 */
void loop(void)
{ 

  analogWrite(HEATPIN,pwm);
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.print(pwm);
  Serial.print(",");
  Serial.println(sensors.getTempCByIndex(0));  
  delay(1000);
  
}
