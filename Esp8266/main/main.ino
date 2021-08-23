#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>


const char* ssid = "CST";
const char* password = "what3v3ryoushoot!";


HTTPClient client;
WiFiClient wifiClient;

const int LED = D6;
const int delayTime = 1000;
void blinkLed()
{
  //1
  digitalWrite(LED, HIGH); 
  delay(delayTime);
  digitalWrite(LED, LOW); 
  delay(delayTime);
  
  //2
  digitalWrite(LED, HIGH); 
  delay(delayTime);
  digitalWrite(LED, LOW); 
  delay(delayTime);

  //3
  digitalWrite(LED, HIGH); 
  delay(delayTime);
  digitalWrite(LED, LOW);
  
}
bool requestIsHuman()
{
  
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password); 
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW); 
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.println("Waiting for connection");
  }
  Serial.println("Connected.");
  blinkLed();
  
 
  Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:
  client.begin(wifiClient, "http://192.168.1.132:5001/test/return-smth");
  client.addHeader("Content-Type", "text/plain");

  int httpResponse = client.GET();
  String payload = client.getString();

  Serial.println(httpResponse);   //Print HTTP return code
  if(httpResponse < 0)
  {
     Serial.printf("[HTTP] GET... failed, error: %s\n", client.errorToString(httpResponse).c_str());
  }

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.println("Waiting for connection");
  }
  Serial.println("Connected.");
  
  Serial.println(payload);    //Print request response payload
 
  client.end();
  delay(10000);
}
