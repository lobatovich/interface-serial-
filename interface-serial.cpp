#include <mbed.h>

PwmOut _led(LED1);

Serial placa(USBTX, USBRX, 9600);

char x = '\0';

void get_char(){
  x = placa.getc();
}

int main(){
    placa.attach(&get_char);
    while (1){
        if (x != '\0'){
            if(x == '+'){
                if (luminosidade >= 1.0) luminosidade = 1.0;
                else luminosidade += 0.05;
            }
            else if(x == '-'){
                if (luminosidade <= 0.0) luminosidade = 0.0;
                else luminosidade -= 0.05;
            }
            else if(x == '*'){
                luminosidade = 1.0;
            }
            else if(x == '/'){
                luminosidade = 0.0;
            }
            else placa.printf("Error\n");
        }
        float luminosidade = _led.read();
        wait_ms(100);
    }
}