// Le dados dos sensores e retorna se existe algo na frente
int leUltrassonico(Ultrasonic frente, Ultrasonic tras) {
  int distanciaMin = 15; // Distancia minima em centimetros
  
  // Recebe medida em microsengudos dos sensores
  long msecFrente = frente.timing(); 
  long msecAtras = tras.timing();

  // Converte microsengudos em centimetros
  float cmFrente = frente.convert(msecFrente, Ultrasonic::CM);
  float cmAtras = tras.convert(msecAtras, Ultrasonic::CM);

  // Se ha objeto a menos que 15cm retorna valor 1 (no sensor da frente) ou -1 (no sensor de tras)
  if (cmFrente < distanciaMin) {
    return 1;
  }

  if (cmAtras < distanciaMin) {
    return -1; 
  }

  // Nao tem nenhum objeto a menos que 15cm dos sensores
  return 0;
}
