#include <AFMotor.h>
AF_DCMotor motor_derecho(4);   //motor derecho
AF_DCMotor motor_izquierdo(3);   //motor izquierdo
// TCS230 color recognition sensor 
// Sensor connection pins to Arduino are shown in comments
/*
Color Sensor1 (derecho)      Arduino
-----------      --------
 VCC               5V
 GND               GND
 s0                31
 s1                33
 s2                35
 s3                37
 OUT               39
                 

Color Sensor2 (izquierdo)     Arduino
-----------      --------
 VCC               5V
 GND               GND
 s0                52
 s1                50
 s2                48
 s3                46
 OUT               44
*/
//VARIABLES DEL SENSOR DE COLORES 
// inicializacion de variables para los pins de sensor 1 
const int s1_0 = 31;  
const int s1_1 = 33;  
const int s1_2 = 35;  
const int s1_3 = 37;  
const int out_1 = 39;   

// inicializacion de variables para los pins de sensor 2 
const int s2_0 = 52;  
const int s2_1 = 50;  
const int s2_2 = 48;  
const int s2_3 = 46;  
const int out_2 = 44;   

// Variables  sensor 1
int red1 = 0;  
int green1 = 0;  
int blue1 = 0;  
    
// Variables  sensor 2
int red2 = 0;  
int green2 = 0;  
int blue2 = 0;  
int des = 1;

// lectura de colores encontrados en sensor 1

int ler_vde_1=7;
int leg_vde_1=6;
int leb_vde_1=5;


// lectura de colores encontrados en sensor 2
int ler_vde_2=8;
int leg_vde_2=7;
int leb_vde_2=7;

// colores encontrados en sensor 1
int enc_vde_1=0;

// colores encontrados en sensor 2
int enc_vde_2=0;



//VARIABLES DEL SENSOR INFRARROJO
//s2
int izq_1=22;
//s3
int izq_2=24;
//s4
int centro_3=26;
//s6
int der_4=28;
//s7
int der_5=30;
// lectura de sensores
int l1=1;
int l2=1;
int l3=1;
int l4=1;
int l5=1;
int l6=1;
int l7=1;
int l8=1;
//colores 
int neg=0;
int bco=1;
//const int trigPin = 34; // Pin disparador. Se puede usar otro pin digital
//const int echoPin = 32; // Pin eco. Se puede usar otro pin digital
//long duration, inches, cm; // Declara variables

void setup() {
  Serial.begin(9600);
  //SENSORES DE COLORES 
  //Pines s0,s1,s2 y s3 como salidas para el sensor1  
  pinMode(s1_0, OUTPUT);  
  pinMode(s1_1, OUTPUT);  
  pinMode(s1_2, OUTPUT);  
  pinMode(s1_3, OUTPUT);
  
  //Pines s0,s1,s2 y s3 como salidas para el sensor2  
  pinMode(s2_0, OUTPUT);  
  pinMode(s2_1, OUTPUT);  
  pinMode(s2_2, OUTPUT);  
  pinMode(s2_3, OUTPUT);
  
  // pin OUT_1 como entrada para el sensor 1  
  pinMode(out_1, INPUT);
  
  // pin OUTT_2 como entrada para el sensor 1  
  pinMode(out_2, INPUT);  
  
  // S0 y S1 en alto color base rojo para sensor 1  
  digitalWrite(s1_0, HIGH);  
  digitalWrite(s1_1, HIGH);
  // S0 y S1 en alto color base rojo para sensor 2  
  digitalWrite(s2_0, HIGH);  
  digitalWrite(s2_1, HIGH);  

  
  //s1
   pinMode(izq_1,INPUT);
   //s2
   pinMode(izq_2,INPUT);
   //s3
   pinMode(centro_3,INPUT);
   //s4
   pinMode(der_4,INPUT);
   //s5
   pinMode(der_5,INPUT);
  //pinMode(echoPin, INPUT); // Establece pin como entrada
  //digitalWrite(trigPin, LOW); // Pone el pin a un estado logico bajo
}
  void loop() { 
   // muestra la intensidad (los milisegunods que tardo en la lectura para el rojo
  Serial.print("R1 Intensity:");  
  Serial.println(red1, DEC);  
  // muestra la intensidad (los milisegunods que tardo en la lectura para el verde
  Serial.print(" G1 Intensity: ");  
  Serial.println(green1, DEC);  
  // muestra la intensidad (los milisegunods que tardo en la lectura para el blue
  Serial.print(" B1 Intensity : ");  
  Serial.println(blue1, DEC);  
  //Serial.println();  

  // determina el color sensor 1
  if (enc_vde_1==1)
     {  
       Serial.println(" -    VERDE sensor derecho ");  
     }

// muestra la intensidad (los milisegunods que tardo en la lectura para el rojo
  Serial.print("R2 Intensity:");  
  Serial.println(red2, DEC);  
  // muestra la intensidad (los milisegunods que tardo en la lectura para el verde
  Serial.print(" G2 Intensity: ");  
  Serial.println(green2, DEC);  
  // muestra la intensidad (los milisegunods que tardo en la lectura para el blue
  Serial.print(" B2 Intensity : ");  
  Serial.println(blue2, DEC);  
  //Serial.println();  

  if (enc_vde_2==1)
     {  
       Serial.println(" -    VERDE sensor izquierdo ");  
     }
     Serial.println("_______________________________________");

  delay(1000);
   l5=digitalRead(izq_1);
   l4=digitalRead(izq_2);
   l3=digitalRead(centro_3);
   l2=digitalRead(der_4);
   l1=digitalRead(der_5);
   
 if(l5==neg ){
       motor_derecho.setSpeed(250);
       motor_derecho.run(BACKWARD);
       motor_izquierdo.setSpeed(200);
       motor_izquierdo.run(FORWARD);
  }
   if(l1==neg ){
        motor_derecho.setSpeed(200);
       motor_derecho.run(FORWARD);
       motor_izquierdo.setSpeed(250);
       motor_izquierdo.run(BACKWARD);
  }
if((l1==bco && l2==bco && l4==bco && l5==bco)){ 
       motor_derecho.setSpeed(100);
       motor_derecho.run(FORWARD);
       motor_izquierdo.setSpeed(100);
       motor_izquierdo.run(FORWARD);
}
   
if (l2==neg && l5==bco && l1==bco ){
       motor_derecho.setSpeed(100);
       motor_derecho.run(FORWARD);
       motor_izquierdo.setSpeed(20);
       motor_izquierdo.run(BACKWARD);
}

if (l4==neg && l1==bco && l5==bco ){
       motor_derecho.setSpeed(20);
       motor_derecho.run(BACKWARD);
       motor_izquierdo.setSpeed(150);
       motor_izquierdo.run(FORWARD);
     }

      
     // INTERSECCION////////////////////////////////////////////////////////////////////////////
 if(l1==neg && l5==neg)
  {
       enc_vde_1=0;
       enc_vde_2=0;
       color();
      
       motor_derecho.setSpeed(100);
       motor_derecho.run(BACKWARD);
       motor_izquierdo.setSpeed(100);
       motor_izquierdo.run(BACKWARD);
        delay(300);
       motor_derecho.setSpeed(0);
       motor_derecho.run(FORWARD);
       motor_izquierdo.setSpeed(0);
       motor_izquierdo.run(BACKWARD);
       delay(500);
       //sensor RGB de la derecha 
      if(enc_vde_1==1)
      {
       enc_vde_1=0;
       enc_vde_2=0;
       color();
      
       motor_derecho.setSpeed(220);
       motor_derecho.run(BACKWARD);
       motor_izquierdo.setSpeed(200);
       motor_izquierdo.run(FORWARD);
      }

//sensor RGB a la izquierda
      if(enc_vde_2==1)
      {
       motor_derecho.setSpeed(200);
       motor_derecho.run(FORWARD);
       motor_izquierdo.setSpeed(220);
       motor_izquierdo.run(BACKWARD);
      }
}
  }
void color()  
{   

    // pin s2 en bajo, s3 en bajo (rojo)
    digitalWrite(s1_2, LOW);  
    digitalWrite(s1_3, LOW);  
    
    //count OUT_1, pRed, RED  
    // pulso en el pin out_1 lee en out_1
    red1 = pulseIn(out_1, digitalRead(out_1) == HIGH ? LOW : HIGH);
    // pin 12 en bajo y pin 11 alto (azul)  
    digitalWrite(s1_3, HIGH);  
    //count OUT, pBLUE, BLUE  
    blue1 = pulseIn(out_1, digitalRead(out_1) == HIGH ? LOW : HIGH);
    // pin 12 en alto y pin 11 en alto (verde)  
    digitalWrite(s1_2, HIGH);  
    //count OUT, pGreen, GREEN  
    green1 = pulseIn(out_1, digitalRead(out_1) == HIGH ? LOW : HIGH);

    // pin s2 en bajo, s3 en bajo (rojo)
    digitalWrite(s2_2, LOW);  
    digitalWrite(s2_3, LOW);  
    
    //count OUT_2, pRed, RED  
    // pulso en el pin out_1 lee en out_1
    red2 = pulseIn(out_2, digitalRead(out_2) == HIGH ? LOW : HIGH);
    // pin 12 en bajo y pin 11 alto (azul)  
    digitalWrite(s2_3, HIGH);  
    //count OUT_2, pBLUE, BLUE  
    blue2 = pulseIn(out_2, digitalRead(out_2) == HIGH ? LOW : HIGH);
    
    // pin 12 en alto y pin 11 en alto (verde)  
    digitalWrite(s2_2, HIGH);  
    //count OUT_2, pGreen, GREEN  
    green2 = pulseIn(out_2, digitalRead(out_2) == HIGH ? LOW : HIGH);
    
    // colores en sensor 1
    if ((red1>=ler_vde_1-des && red1<=ler_vde_1+des) && (green1>=leg_vde_1-des && green1<=leg_vde_1+des) && (blue1>=leb_vde_1-des && blue1<=leb_vde_1+des)){
        enc_vde_1=1;  
      }
    // colores en sensor 2
    if ((red2>=ler_vde_2-des && red2<=ler_vde_2+des) && (green2>=leg_vde_2-des && green2<=leg_vde_2+des) && (blue2>=leb_vde_2-des && blue2<=leb_vde_2+des)){
        enc_vde_2=1;  
      }
 
}
