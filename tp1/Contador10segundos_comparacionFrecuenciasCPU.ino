#include <Arduino.h>

volatile uint32_t dummy = 0;

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Forzar CPU a 40 MHz
  setCpuFrequencyMhz(40);

  Serial.println("________________________________________________________________");

  Serial.print("Frecuencia CPU: ");
  Serial.print(getCpuFrequencyMhz());
  Serial.println(" MHz");

  // =============================
  // Contador 10 segundos
  // =============================

  int iteraciones10segundos = 140000000; //regla de 3

  Serial.println("Inicio del contador...");

  unsigned long inicio = micros();

  for (uint32_t i = 0; i < iteraciones10segundos; i++) {
    dummy++;
  }

  unsigned long fin = micros();

  double tiempo_real = (fin - inicio) / 1e6;

  // =============================
  // 3. Resultados
  // =============================
  Serial.print("Tiempo real: ");
  Serial.print(tiempo_real, 6);
  Serial.println(" segundos");
}

void loop() {
  // nada
}
