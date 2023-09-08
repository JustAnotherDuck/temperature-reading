#define BLYNK_TEMPLATE_ID "TMPL3KaX6X0O8"
#define BLYNK_TEMPLATE_NAME "DHT IOT SENSOR"
#define BLYNK_AUTH_TOKEN "CJB5iAJAR3-uHAniUNyJGC0-Axs-FXkx"
#define DHTPIN 4 //data pin is conected to D2 on esp 
#define DHTTYPE DHT11 //Name the sensor as an object 

#include <DHT.h>
#include <BlynkSimpleEsp8266.h>


char auth[] = "CJB5iAJAR3-uHAniUNyJGC0-Axs-FXkx";
char ssid[] = "mygalaxy";
char pass[] = "raveshbhan";
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); // no pin mode to specify as a esp already knows the purpose of the pin
Serial.println("DHT Test Sucessful");
WiFi.begin(ssid,pass);
Blynk.config(auth);
//Blynk.begin(auth,ssid,pass);
Serial.println("Blynk Connected Successfully");
dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
 float h = dht.readHumidity();
 float t = dht.readTemperature();
 float f = dht.readTemperature(true);
 if (isnan(h) || isnan(t) || isnan(f)); //isnan, is NAN , Not A Number , to check for garbage value or error 
 {
  Serial.println("Something is not working as intended.");
  return; //Exit the code 
 }
 Serial.print("Humidity: ");
 Serial.print(h);
 Serial.println(" %");
 Serial.print("Temperature: ");
 Serial.print(t);
 Serial.print(" degrees celcius.");
 Blynk.virtualWrite(V0,t);
 Blynk.virtualWrite(V1,h);
 delay(2000);
}
