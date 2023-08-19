#include <HardwareSerial.h>

HardwareSerial SerialPort(2);

char pkt = ' ';
char led = 2; //internal esp32-wroom led

void setup() {
  Serial.begin(115200); // uart 0
  SerialPort.begin(115200, SERIAL_8N1,16,17); //uart 2
  
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, LOW);
  SerialPort.print("Hello World.");
  listen();
  delay(50); //just to make things more readable 
}

void listen()
{
   if(SerialPort.available())
  {
    char pkt = SerialPort.read();
    Serial.print(pkt);
    digitalWrite(led, HIGH);
  }
}