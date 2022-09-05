#include <SoftwareSerial.h>
#include <Ultrasonic.h>

// Constantes
const int BUZINA = A0;
const int FAROLD = 13;
const int FAROLE = 12;
const int FAROLT = 11;

// Objetos
SoftwareSerial bluetoothSerial(3, 2); // RX, TX

Ultrasonic ultrassonicoFrente(A2, A3);
Ultrasonic ultrassonicoAtras(A4, A5);

// Controlador do motor
class DCMotor {
    // Declara variaveis
    int vel = 150, pin1, pin2;

    void positivo() {
      analogWrite(pin1, vel);
      digitalWrite(pin2, LOW);
    }

    void negativo() {
      digitalWrite(pin1, LOW);
      analogWrite(pin2, vel);
    }

  public:
    // Declara os pinos que irao controlar o objeto motor
    void pinos(int in1, int in2) {
      pin1 = in1;
      pin2 = in2;
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);
    }

    // Salva a velocidade de atuacao do motor. Velocidade de 0 a 255
    void velocidade(int i) {
      if (i > 255) {
        vel = 255;
        return;
      }

      if (i < 0) {
        vel = 0;
        return;
      }

      vel = i;
    }

    // Faz motor girar no sentido horario
    void frente() {
      positivo();
    }

    void direita() {
      positivo();
    }

    // Faz motor girar no sentido anti-horario
    void atras() {
      negativo();
    }

    void esquerda() {
      negativo();
    }

    // Desliga motor
    void parar() {
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
    }
};

DCMotor MotorDianteiro, MotorTraseiro;

// Liga fusca
void setup() {
  Serial.begin(9600);
  bluetoothSerial.begin(9600);

  delay(100);

  pinMode(BUZINA, OUTPUT);

  pinMode(FAROLD, OUTPUT);
  pinMode(FAROLE, OUTPUT);
  pinMode(FAROLT, OUTPUT);

  MotorDianteiro.pinos(5, 6);
  MotorTraseiro.pinos(9, 10);

  MotorDianteiro.velocidade(200); // 80% da forca maxima
  MotorTraseiro.velocidade(200); // 80% da forca maxima
}

void loop() {  
  // Recebe dados do bluetooth
  if (bluetoothSerial.available()) {
    char comando = bluetoothSerial.read();

    Serial.println(comando);
    
    // Le dados dos sensores ultrassonicos
    int sensorAtivo = leUltrassonico(ultrassonicoFrente, ultrassonicoAtras); 

    // Liga farois
    controlaLuzes(FAROLD, FAROLE, FAROLT, comando);
  
    // Controla motores
    controlaMotores(MotorDianteiro, MotorTraseiro, comando);
  }
}
