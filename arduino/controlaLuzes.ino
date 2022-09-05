// Contra luzes
void controlaLuzes(int FAROLD, int FAROLE, int LUZTETO, char comando) {
  if (comando == "" || comando == "?" || comando == "S" || comando == "&") {
    digitalWrite(LUZTETO, LOW);
  } else {
    digitalWrite(LUZTETO, HIGH);
  }
  
  
  switch (comando) {
    // Liga farol
    case 'W':
      digitalWrite(FAROLD, HIGH);
      digitalWrite(FAROLE, HIGH);
      break;

    // Desliga farol
    case 'w':
      digitalWrite(FAROLD, LOW);
      digitalWrite(FAROLE, LOW);
      break;
  }
}
