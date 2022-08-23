#include <SoftwareSerial.h>

const int BUZINA = A0;
const int FAROLD = 13;
const int FAROLE = 12;
const int FAROLT = 11;

SoftwareSerial bluetoothSerial(3, 2); // RX, TX
String comando = "";

class DCMotor {
    int spd = 255, pin1, pin2;

  public:

    void Pinout(int in1, int in2) { // Pinout é o método para a declaração dos pinos que vão controlar o objeto motor
      pin1 = in1;
      pin2 = in2;
      pinMode(pin1, OUTPUT);
      pinMode(pin2, OUTPUT);
    }
    void Speed(int in1) { // Speed é o método que irá ser responsável por salvar a velocidade de atuação do motor
      spd = in1;
    }
    void Forward() { // Forward é o método para fazer o motor girar para frente
      analogWrite(pin1, spd);
      digitalWrite(pin2, LOW);
    }
    void Backward() { // Backward é o método para fazer o motor girar para trás
      digitalWrite(pin1, LOW);
      analogWrite(pin2, spd);
    }
    void Stop() { // Stop é o metodo para fazer o motor ficar parado.
      digitalWrite(pin1, LOW);
      digitalWrite(pin2, LOW);
    }
};

DCMotor Motor1, Motor2; // Criação de dois objetos motores, já que usaremos dois motores, e eles já estão prontos para receber os comandos já configurados acima.

void setup() {
  Serial.begin(9600);
  Serial.println("Digite os comandos AT: ");

  pinMode(BUZINA, OUTPUT);

  pinMode(FAROLD, OUTPUT);
  pinMode(FAROLE, OUTPUT);
  pinMode(FAROLT, OUTPUT);

  bluetoothSerial.begin(9600);

  Motor1.Pinout(5, 6); // Seleção dos pinos que cada motor usará, como descrito na classe.
  Motor2.Pinout(9, 10);
}

void loop() {
  if (bluetoothSerial.available()) {
    char r = bluetoothSerial.read();
    Serial.println(r);
  }

  

  Motor1.Speed(255); // A velocidade do motor pode variar de 0 a 255, onde 255 é a velocidade máxima.
  Motor2.Speed(255);

  Motor1.Forward(); // Comando para o motor ir para frente
  Motor2.Forward();
  delay(1000);
  Motor1.Backward(); // Comando para o motor ir para trás
  Motor2.Backward();
  delay(1000);

  digitalWrite(FAROLD, HIGH);
  digitalWrite(FAROLE, HIGH);
  digitalWrite(FAROLT, HIGH);
  
  Motor1.Stop(); // Comando para o motor parar
  Motor2.Stop();
  delay(500);

  tone(BUZINA, 1000, 500);

  digitalWrite(FAROLD, LOW);
  digitalWrite(FAROLE, LOW);
  digitalWrite(FAROLT, LOW);
}
