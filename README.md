# UART
Esse é um projeto focado na implementação do circuito lógico da interface UART(Universal asynchronous receiver/transmitter)

# TESTES
Para fazer os testes iremos usar uma FPGA, nesse caso está sendo usada a NEXYS 4 DDR, e um dispositivo com a interface UART já implementada, um ESP32-WROOM que nos permite alcançar até 115200 de baudrate e vários padrões de comunicação serial, permitindo variar o número de bits de parada e se há um bit de paridade ou não.

Com os equipamentos em mãos, a FPGA foi configurada para receber os dados em sua porta RX e transmitir esses mesmos dados de entrada para a porta de saída TX. Dessa maneira, testando tanto a porta de entrada quando a de saida. Assim, quando enviamos uma mensagem pela interface, gerada pelo ESP32, é esperado obtermos de volta no ESP32 a mesma mensagem enviada.

Abaixo, podemos ver uma imagem mostrando o setup para se testar o funcionamento da interface.

Clique no video 
[![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/EZUalvDFWBs/0.jpg)](https://www.youtube.com/watch?v=EZUalvDFWBs)



![alt text](https://github.com/grigacci/UART/blob/main/Docs/test_setup.jpg)

Como podemos ver, há uma conexão entre ambos os dispositivos que nos permite a transmissão de dados. 

Temos como o esperado, a mensagem recebida de volta no ESP32.

![alt text](https://github.com/grigacci/UART/blob/main/Docs/arduino_screenshot.jpg)

Além disso, foi adicionado um arquivo para testar o funcionamento da interface UART no ESP32, onde é feita a comunição serial entre dois ESP32, para assim garantir seu funcionamento pleno.
