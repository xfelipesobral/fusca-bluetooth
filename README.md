# fusca-bluetooth

```
MotorFrente.Speed(150); // A velocidade do motor pode variar de 0 a 255, onde 255 é a velocidade máxima.
MotorTras.Speed(50);

MotorFrente.Forward(); // Comando para o motor ir para frente
MotorTras.Forward();
delay(1000);
MotorFrente.Backward(); // Comando para o motor ir para trás
MotorTras.Backward();
delay(1000);

digitalWrite(FAROLD, HIGH);
digitalWrite(FAROLE, HIGH);
digitalWrite(FAROLT, HIGH);

MotorFrente.Stop(); // Comando para o motor parar
MotorTras.Stop();
delay(500);

// tone(BUZINA, 1000, 500);

digitalWrite(FAROLD, LOW);
digitalWrite(FAROLE, LOW);
digitalWrite(FAROLT, LOW);
```