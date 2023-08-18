#include <HardwareSerial.h>

HardwareSerial SerialPort(2);

char number = ' ';
char led = 2; //internal esp32-wroom led

void setup() {
  SerialPort.begin(115200, SERIAL_8N1,16,17);
  pinMode(led, OUTPUT);
}

void loop() {
  SerialPort.print(1,BIN);
  listen();
  delay(1000);
  
  SerialPort.print(0,BIN);
  listen();
  delay(1000);
}

void listen()
{
   if(SerialPort.available())
  {
    char number = SerialPort.read();
    if (number == '0')
    {
      digitalWrite(led, LOW);
    }
    else if (number = '1')
    {
      digitalWrite(led, HIGH);
    }
  }
}