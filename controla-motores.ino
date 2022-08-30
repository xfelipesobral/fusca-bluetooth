// Funcao que controla motores
void controlaMotores(DCMotor MotorDianteiro, DCMotor MotorTraseiro, char comando) {
  switch (comando) {
    // Frente
    case 'F':
      MotorTraseiro.frente();
      break;

    // Tras
    case 'B':
      MotorTraseiro.atras();
      break;

    // Esquerda
    case 'L':
      MotorDianteiro.esquerda();
      break;

    // Direita
    case 'R':
      MotorDianteiro.direita();
      break;

    // Frente + Esquerda
    case 'I':
      MotorTraseiro.frente();
      MotorDianteiro.esquerda();
      break;

    // Frente + Direita
    case 'G':
      MotorTraseiro.frente();
      MotorDianteiro.direita();
      break;

    // Tras + Esquerda
    case 'J':
      MotorTraseiro.atras();
      MotorDianteiro.esquerda();
      break;

    // Tras + Direita
    case 'H':
      MotorTraseiro.atras();
      MotorDianteiro.direita();
      break;

    // Para motores
    default:
      MotorTraseiro.parar();
      MotorDianteiro.parar();
      break;
  }
}
