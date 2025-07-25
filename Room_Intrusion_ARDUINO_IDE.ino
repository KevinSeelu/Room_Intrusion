#include <ESP8266WiFi.h>                       //Defining Libraries
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>


const char* ssid = "WiFi SSID";          
const char* password = "WiFi Password";     
const char* botToken = "BOT API"; 
const int64_t chat_id = CHAT ID;   
#define TRIG_PIN D6
#define ECHO_PIN D5
#define LED_PIN  D1


WiFiClientSecure client;
UniversalTelegramBot bot(botToken, client);


void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected!");
  client.setInsecure(); // For simple SSL
}


void loop() {
  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  float distance_cm = duration * 0.0343 / 2;

  // Your LED logic as before...
  if (duration == 0) {
    Serial.println("Out of range or wiring error.");
    digitalWrite(LED_PIN, HIGH);
  } else {
    Serial.print("Distance: "); Serial.println(distance_cm);

    bool intrusion = (distance_cm < 103);
    digitalWrite(LED_PIN, intrusion ? HIGH : LOW);

    // Telegram alert: send only on intrusion, delay to avoid spam
    static unsigned long lastAlert = 0;
    if (intrusion && millis() - lastAlert > 10000) { // 10s anti-spam
      String msg = "INTRUSION detected! Distance: ";
      msg += String(distance_cm);
      msg += " cm.";
      bot.sendMessage(String(chat_id), msg, "");
      lastAlert = millis();
    }
  }
  delay(500);
}
