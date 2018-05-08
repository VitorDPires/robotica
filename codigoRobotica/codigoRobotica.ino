int ENA = 6; //Habilita PWM motor A
int IN1 = 10; 
int IN2 = 11;

int ENB = 9; //Habilita PWM motor B
int IN3 = 12;
int IN4 = 13;

//Velocidade dos motores
#define forwardSpeed 80 
#define turningSpeed 60

//Pinos dos Sensores
int Sensor1 = 1;
int Sensor2 = 3;
int Sensor3 = 4;
int Sensor4 = 5;

//Valores na leitura do sensor
int value1 = 0;
int value2 = 0;
int value3 = 0;
int value4 = 0;

//Contador encoder
int encoder = 0;

//Função interrupt do encoder
void encoderInterrupt(){
 encoder++;
 }

void setup() {

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(Sensor1, INPUT);
  pinMode(Sensor2, INPUT);
  pinMode(Sensor3, INPUT);
  pinMode(Sensor4, INPUT);

  attachInterrupt(0,encoderInterrupt,RISING);  
}

void loop(){
  //if para controle de distancia
  if(encoder<960){
  value1 = digitalRead(Sensor1);
  value2 = digitalRead(Sensor2);
  value3 = digitalRead(Sensor3);
  value4 = digitalRead(Sensor4);

  //Condições para curvas

  if((value4 == LOW || value3 == LOW) && (value2 == HIGH || value1 == HIGH)){
    //Ajuste de velocidade
    analogWrite(ENA, 45);
    analogWrite(ENB, 50);
    //Vira para esquerda
    //motor A para frente
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    //motor B para trás
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
  else if ((value4 == HIGH || value3 == HIGH) && (value2 == LOW || value1 == LOW)){
    //Ajuste de velocidade
    analogWrite(ENA, 45);
    analogWrite(ENB, 50);
    //Vira pra direita
    //motor A para trás
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    //motor B para frente
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  }
  else{
    //Ajuste de velocidade
    analogWrite(ENA, 57);
    analogWrite(ENB, 60);
    //Anda em linha reta
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  }
}else{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}

