char c_read_usart();
void logic_gate();
static int counter;
char buffer;
void main() {
counter = 0;
CMCON = 0x07;               //Desabilita Comparadores
TRISB = 0x0F;               // Configura as direções dos pinos
PORTB = 0x00;               // Inicializa todos em lOW
RCSTA = 0x90;               // Configura o registrador de recive da usart
SPBRG = 25;                 // Configura o bound rate para 9600
INTCON = 0xC0;              // Habilita as interrupções globais e de perifericos
PIE1 = 0x20;                // Configura a interrupção da USART

while(1){

}


}

char c_read_usart(){

     return RCREG;
}

void interrupt(){

     if(PIR1.B5 == 0x01){
          buffer = c_read_usart();     //Carregar o byte da uart na variavel buffer
          logic_gate();                // Chamar a função de acionamento.
     }



}



void logic_gate(){
     switch(counter){
       case 0:
            PORTB.B4 = 0x01;                //Motor no sentido 1.
            PORTB.B5 = 0x00;
            counter++;
            break;
       case 1:
            PORTB.B4 = 0x00;               //Motor Parado.
            PORTB.B5 = 0x00;
            counter++;
            break;
       case 2:
            PORTB.B4 = 0x00;              //Motor no sentido 2.
            PORTB.B5 = 0x01;
            counter++;
            break;
       case 3:
            PORTB.B4 = 0x00;              //Motor parado.
            PORTB.B5 = 0x00;
            counter = 0;
            break;

     
     
     
     }


}