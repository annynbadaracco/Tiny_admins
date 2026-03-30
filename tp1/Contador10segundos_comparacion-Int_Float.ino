#include <Arduino.h>

volatile uint32_t dummy = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Forzar CPU a 160 MHz
  setCpuFrequencyMhz(160);

  Serial.print("Frecuencia CPU: ");
  Serial.print(getCpuFrequencyMhz());
  Serial.println(" MHz");

  // =============================
  // Contador 10 segundos
  // =============================

  int iteraciones10segundos = 14000000; //regla de 3

  Serial.println("Inicio del contador usando int...");

  unsigned long inicio = micros();

  for (uint32_t i = 0; i < iteraciones10segundos; i++) {
    for (uint32_t j = 0; j < 10; j++) {
      dummy++;
    }
  }

  unsigned long fin = micros();

  double tiempo_real_int = (fin - inicio) / 1e6;

  // =============================
  // Resultados
  // =============================
  Serial.print("Tiempo real para int: ");
  Serial.print(tiempo_real_int, 6);
  Serial.println(" segundos");

  Serial.println("Inicio del contador usando float...");

  unsigned long inicio2 = micros();

  for (float k = 0; k < iteraciones10segundos; k++) {
    for (float l = 0; l < 10; l++) {
      dummy++;
    }
  }

  unsigned long fin2 = micros();

  double tiempo_real_float = (fin2 - inicio2) / 1e6;

  // =============================
  // Resultados
  // =============================
  Serial.print("Tiempo real para float: ");
  Serial.print(tiempo_real_float, 6);
  Serial.println(" segundos");
}

void loop() {
  // nada
}
