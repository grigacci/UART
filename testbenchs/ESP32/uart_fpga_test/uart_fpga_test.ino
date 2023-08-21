#include <HardwareSerial.h>

HardwareSerial SerialPort(2);

char pkt = ' ';
char led = 2; //Led interno esp32-wroom 

bool auto_baud_handshake = false;

void setup() {
  /*Na UART0, será utilizada para fazer a comunicação com o computador,
  para poder programar e ler a memoria do ESP*/

  /*E na UART2, será feita a comunicação com a interface que está sendo desenvoldida*/

  Serial.begin(115200); //UART 0
  SerialPort.begin(115200, SERIAL_8N1,16,17); //UART 2
  
  pinMode(led, OUTPUT); //LED para depuração 
}

void loop() {
 while(!auto_baud_handshake)
  {
  handshake(); //Para estabelecer a conexão
  }

  transmit();
  listen();

  delay(50); //Só pra deixar mais legível 
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

void transmit()
{
  digitalWrite(led, LOW);
  SerialPort.print("Hello World.");
}

void handshake()
{
  /*O Handshake será útil para a interface UART que iremos 
  nos comunicar poder definir automaticamente seu baud rate,
  sem necessitar de configuração prévia
  
  Para que isso sejá feito, o ESP irá enviar uma mensagem (0xAA),
  e com essa mensagem a interface irá calcular o baud rate, através 
  do tempo medido entre o Start Bit e o primeiro bit de informação.

  Quando a interface encontrar o baud rate correto, ela irá retornar
  uma mensagem (0xFF), informando o ESP que a comunicação foi estabelecida.
  */

  if(SerialPort.available())
  {
    char pkt = SerialPort.read();
    if(pkt == 0xFF)
    {
      auto_baud_handshake = true;
    }
    else 
    {
      SerialPort.print(0xAA,HEX);
    }
  }
}