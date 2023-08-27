#include <HardwareSerial.h>

HardwareSerial SerialPort(2);

char pkt = ' ';
char led = 2; //Led interno esp32-wroom

int rx_pin = 16;
int tx_pin = 17;

int baud_rate = 115200;

bool auto_baud_handshake = false;
bool freq_help = false;
bool baud_help = false;

void setup() {
  /*Na UART0, será utilizada para fazer a comunicação com o computador,
  para poder programar e ler a memoria do ESP*/

  /*E na UART2, será feita a comunicação com a interface que está sendo desenvoldida*/

  Serial.begin(baud_rate); //UART 0
  
  pinMode(led, OUTPUT); //LED para depuração 
}

void loop() {
 while(!auto_baud_handshake){handshake();} //Para estabelecer a conexão

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
  int resp = 0;
  resp = digitalRead(rx_pin);

  if(!freq_help)
  {
    if(resp == HIGH) //FREQ_HELP
    {
      freq_help = true;
    }
    else
    {
      Serial.println("FREQ_HELP sending");
      Serial.println(resp);
      digitalWrite(tx_pin, LOW);
      delayMicroseconds(1000);
      digitalWrite(tx_pin, HIGH);
      delayMicroseconds(10);
    }
  }
  else if(!baud_help) //BAUD_HELP
  {
    if(resp == LOW)
    {
      SerialPort.begin(baud_rate, SERIAL_8N1,rx_pin,tx_pin); //UART 2
      baud_help = true;
      auto_baud_handshake = true;
    }
    else 
    {
      Serial.println("BAUD_HELP sending");
      digitalWrite(tx_pin, LOW);
      delay(1/baud_rate);
      digitalWrite(tx_pin,HIGH);
      delayMicroseconds(10);
    }
  }
}