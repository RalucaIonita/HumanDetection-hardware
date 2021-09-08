#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>


//const char* ssid = "CST";
//const char* password = "what3v3ryoushoot!";

const char* ssid = "ThePandaCrib";
const char* password = "NamPleaca01";

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

bool requestIsHuman(String image)
{
  client.begin(wifiClient, "http://192.168.1.132:5001/main/recognize-human");
  client.addHeader("Content-Type", "text/plain");

  int httpResponse = client.POST(image);
  String payload = client.getString();
  if(httpResponse == 200)
    return true;
  return false;
}

String readAllSerial()
{
  String result = "";
  while(Serial.available() > 0)
  {
    char t = Serial.read();
    result.concat(t);
  }
  return result;
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
//  client.begin(wifiClient, "http://192.168.1.132:5001/test/return-smth");
//  client.addHeader("Content-Type", "text/plain");
//
//  int httpResponse = client.GET();
//  String payload = client.getString();
//
//  Serial.println(httpResponse);   //Print HTTP return code
//
//  requestIsHuman("25");
//  
//  if(httpResponse < 0)
//  {
//     Serial.printf("[HTTP] GET... failed, error: %s\n", client.errorToString(httpResponse).c_str());
//  }
//
//  while (WiFi.status() != WL_CONNECTED) 
//  {
//    delay(500);
//    Serial.println("Waiting for connection");
//  }
//  Serial.println("Connected.");
//  
//  Serial.println(payload);    //Print request response payload
// 
//  client.end();
//  delay(10000);

  String smth = readAllSerial();
  delay(2000);
  Serial.print("Am citit");
  Serial.println(smth);

  Serial.print(requestIsHuman(smth));
  delay(3000);
}
