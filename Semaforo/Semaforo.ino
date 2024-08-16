// Projeto de desenvolvimento de semáforo //
// Autor: Bruno Alves //
// Data: 29/07/2024 //
/* Objetivo: Aplicar e revisitar conceitos e conhecimentos de programação na plataforma arduino
 subindo projeto ao github, junto com modelo esquematico, simulador do tinkercad
 e video do projeto fisico */

// Definição das portas dos leds do semáforo de veículos
const byte Led_Vm_Car = 3, byte Led_Am_Car = 4;
const byte Led_Am_Car = 4;
const byte Led_Vd_Car = 5;

// Definição das portas dos leds do semáforo de pedestres
const byte Led_Vm_Ped = 6;
const byte Led_Vd_Ped = 7;

// Definição das portas do botão de solicitação de parada do pedestre
const byte btn_request_Ped = 2;

volatile bool interruptFlag = false;  // Variável para indicar a interrupção

void setup() 
{
    // Define leds do semáforo como saidas
    pinMode(Led_Vm_Car, OUTPUT); pinMode(Led_Am_Car, OUTPUT); pinMode(Led_Vd_Car, OUTPUT);
    // Define leds do semáforo como saidas
    pinMode(Led_Vm_Ped, OUTPUT); pinMode(Led_Vd_Ped, OUTPUT); 
    // Define botão como pino
    pinMode(btn_request_Ped, INPUT);
    // Configura a interrupção
    attachInterrupt(digitalPinToInterrupt(btn_request_Ped), handleInterrupt, FALLING);
}

void loop() 
{

  if (interruptFlag) {
        interruptFlag = false;  // Reseta a flag
        parada();  // Chama a função de parada
    }
  // Led verde de veículos aceso demais apagados
  digitalWrite(Led_Vm_Car, LOW);  digitalWrite(Led_Am_Car, LOW);  digitalWrite(Led_Vd_Car, HIGH); 
  // Led Vermelho de pedestre aceso,verde apagado
  digitalWrite(Led_Vd_Ped, LOW);  digitalWrite(Led_Vm_Ped, HIGH); delay(5000);


  // Led amarelo de veículos aceso demais apagados
  digitalWrite(Led_Vm_Car, LOW);  digitalWrite(Led_Am_Car, HIGH);  digitalWrite(Led_Vd_Car, LOW); 
  // Led Vermelho de pedestre aceso,verde apagado
  digitalWrite(Led_Vd_Ped, LOW);  digitalWrite(Led_Vm_Ped, HIGH); delay(2500);


  // Led amarelo de veículos aceso demais apagados
  digitalWrite(Led_Vm_Car, HIGH);  digitalWrite(Led_Am_Car, LOW);  digitalWrite(Led_Vd_Car, LOW); 
  // Led Vermelho de pedestre aceso,verde apagado
  digitalWrite(Led_Vd_Ped, HIGH);  digitalWrite(Led_Vm_Ped, LOW); delay(5000);  digitalWrite(Led_Vd_Ped, LOW);


for(i = 0, i < 5, i++)
{
  digitalWrite(Led_Vm_Ped, HIGH);  delay(500);  
  digitalWrite(Led_Vm_Ped, LOW); delay(500);
}

// Jeito estagiário de fazer:
  /* 
  // Após os 5 segundos, led vermelho oscila durante mais 5 segundos
  digitalWrite(Led_Vm_Ped, HIGH);  delay(500);  digitalWrite(Led_Vm_Ped, LOW); delay(500);
  digitalWrite(Led_Vm_Ped, HIGH);  delay(500);  digitalWrite(Led_Vm_Ped, LOW); delay(500);
  digitalWrite(Led_Vm_Ped, HIGH);  delay(500);  digitalWrite(Led_Vm_Ped, LOW); delay(500);
  digitalWrite(Led_Vm_Ped, HIGH);  delay(500);  digitalWrite(Led_Vm_Ped, LOW); delay(500);
  digitalWrite(Led_Vm_Ped, HIGH);  delay(500);  digitalWrite(Led_Vm_Ped, LOW); delay(500);
*/

}

void handleInterrupt() {
    interruptFlag = true;  // Seta a flag quando a interrupção ocorre
}

void parada()
{
  // Led vermelho de veículos aceso demais apagados
  digitalWrite(Led_Vm_Car, HIGH);  digitalWrite(Led_Am_Car, LOW);  digitalWrite(Led_Vd_Car, LOW); 
  // Led verde pedestre aceso, vermelho off e aguarda 5 segundos
  digitalWrite(Led_Vd_Ped, HIGH);  digitalWrite(Led_Vm_Ped, LOW); delay(5000); digitalWrite(Led_Vd_Ped, LOW);



for(i = 0, i < 5, i++)
{
  digitalWrite(Led_Vm_Ped, HIGH);  delay(500);  
  digitalWrite(Led_Vm_Ped, LOW); delay(500);
}
  // Após os 5 segundos, led vermelho oscila durante mais 5 segundos
 /* digitalWrite(Led_Vm_Ped, HIGH);  delay(500);  digitalWrite(Led_Vm_Ped, LOW); delay(500);
  digitalWrite(Led_Vm_Ped, HIGH);  delay(500);  digitalWrite(Led_Vm_Ped, LOW); delay(500);
  digitalWrite(Led_Vm_Ped, HIGH);  delay(500);  digitalWrite(Led_Vm_Ped, LOW); delay(500);
  digitalWrite(Led_Vm_Ped, HIGH);  delay(500);  digitalWrite(Led_Vm_Ped, LOW); delay(500);
  digitalWrite(Led_Vm_Ped, HIGH);  delay(500);  digitalWrite(Led_Vm_Ped, LOW); delay(500);
*/
  // Led verde de veículos aceso demais apagados
  digitalWrite(Led_Vm_Car, LOW);  digitalWrite(Led_Am_Car, LOW);  digitalWrite(Led_Vd_Car, HIGH); 
  digitalWrite(Led_Vd_Ped, LOW);  digitalWrite(Led_Vm_Ped, HIGH);
}
