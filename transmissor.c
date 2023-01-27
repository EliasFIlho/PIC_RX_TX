
char key = 0x00;

void codification(){

     if(RA3_bit) key |= (1 << 7);
     else        key |= (0 << 7);
     
     if(RB4_bit) key |= (1 << 6);
     else        key |= (0 << 6);
     
     if(RB5_bit) key |= (1 << 5);
     else        key |= (0 << 5);
     
     if(RB6_bit) key |= (1 << 4);
     else        key |= (0 << 4);
     
     if(RB7_bit) key |= (1 << 3);
     else        key |= (0 << 3);
     
     if(RA0_bit) key |= (1 << 2);
     else        key |= (0 << 2);
     
     if(RA1_bit) key |= (1 << 1);
     else        key |= (0 << 1);
     
     if(RA2_bit) key |= (1 << 0);
     else        key |= (0 << 0);


}




void init_uart(){
   TRMT_bit = 0x00; // Shift Register full
   BRGH_bit = 0x01; // Habilita o modo High Speed
   SYNC_bit = 0x00; // Configura como assincrono
   SPEN_bit = 0x01;
   TXEN_bit = 0x01; //Habilita a transmissão
   TX9_bit = 0x00; //Transmissão de 1 byte
   CSRC_bit = 0x00; // DONT CARE
   SPBRG = 25;
}

void send_uart(char str){
     TXREG = str;
}

void interrupt(){

     if(INTF_bit){
       RA4_bit = 0x01;
       codification();
       send_uart(key);
       RA4_bit = 0x00;
       INTF_bit = 0x00;
     }

}

void main() {

NOT_RBPU_bit = 0x01;   // Desabilitar resistores de pull-up
INTEDG_bit = 0x01;
CMCON = 0x07;
TRISB = 0xFF;
TRISA = 0x0F;
RA4_bit = 0x00;
PORTB = 0xFF;
INTCON = 0xD8;
init_uart();
      while(1){
       asm sleep;
      }

}