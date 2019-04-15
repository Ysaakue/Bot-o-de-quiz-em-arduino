/*
PROJETO:______SENSOR COM INTERRUPÇÃO PARA INDICAR QUAL BOTÃO FOI PRESSIONADO PRIMEIRO
MCU:__________ARDUINO UNO
VERSÃO IDE:___1.8.5 
AUTOR:________ISAAC GONDIM GERALDO

REFERENCIA: https://www.arduino.cc/reference/pt/language/functions/external-interrupts/attachinterrupt/
*/

volatile byte state = LOW;
// DECLARAÇÃO DE FUNÇÕES ==============================================================================================================================================

void blink();

void setup() 
{
  pinMode(2,INPUT_PULLUP);	//Pino do botão do lado direito
  pinMode(3,INPUT_PULLUP);	//Pino do botão do lado esquerdo
  attachInterrupt(digitalPinToInterrupt(2), blinkdireita, LOW);		//Define a função de interrupção do botão do lado direito
  attachInterrupt(digitalPinToInterrupt(3), blinkesquerda, LOW);	//Define a função de interrupção do botão do lado esquerdo
  pinMode(4,OUTPUT);	//Pino do LED para o botão do lado direito
  pinMode(5,OUTPUT);	//Pino do LED para o botão do lado esquerdo
}

void loop() 
{
  
}
// FUNÇÕES AUXILIARES =================================================================================================================================================

void blinkdireita()
{
  digitalWrite(4, HIGH);	//Acende LED
  int cont;
  for(cont=0;cont<500;cont++)	//Função para passar tempo
  {
    delayMicroseconds(10000);
  }
  digitalWrite(4, LOW);		//Desliga LED
}


void blinkesquerda() 
{
  digitalWrite(5, HIGH);	//Acende LED
  int cont;
  for(cont=0;cont<500;cont++)	//Função para passar tempo
  {
    delayMicroseconds(10000);
  }
  digitalWrite(5, LOW);		//Desliga LED
}
