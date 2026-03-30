# Sistemas de Computación
## Trabajo Practico # 1: Rendimiento

Integrantes:

* María Clara Gonzalez Leahy
* Anna Nuñez
* Ignacio J. Vigezzi  

**Profesores:** Miguel Ángel Solinas y Javier Alejandro Jorge

**Universidad Nacional de Córdoba**  
**Facultad de Ciencias Exactas, Físicas y Naturales**

## Objetivo  
Poner en práctica los conocimientos sobre performance y rendimiento de los computadores.

### Benchmarks
En el ámbito de la computación, es fundamental evaluar el rendimiento de un sistema al ejecutar las tareas y funciones que se esperan de él. Para ello se emplean los benchmarks o pruebas de rendimiento, que consisten en tareas reproducibles diseñadas para reflejar la actividad normal del sistema. Estas pruebas permiten obtener métricas cuantificables que sirven como referencia para analizar el impacto de cambios en el hardware, modificaciones de procesos o mejoras en la configuración. De esta manera, los benchmarks permiten comparar resultados y tomar decisiones sobre optimización y desempeño.

Ejemplos de benchmarks basados en tareas que realizamos a diario son:

| Benchmark | Tarea | Medición|
|------------|--------|--------|
| Speedometer 3.1| Navegacíon web<br> Uso de aplicaciones online | rendimiento de navegadores,<br> paginas y aplicaciones web |
| Speedtest.net| Videollamadas<br> Streaming de video<br> Descarga de archivos  | Velocidad y estabilidad de la conexión a internet |
| Geekbench CPU | Programación y compilación de codigo<br> | Rendimiento de CPU en cálculos y multitarea |
| 3DMark| Jugar videojuegos | Rendimiento de CPU y GPU en graficos 3D |
| CrystalDiskMark| Trabajo con archivos grandes | Velocidad de lectura y escritura en almacenamiento |


### Compilación del kernel de linux

| Procesador | Puesto (desc) | Tiempo | Rendimiento |
|------------|--------|----------|----------|
| AMD Ryzen 9 7950X 16-Core | 71 | 52<sup> +/- 3</sup> | 0.019 |
| Intel Core i5-13600K | 52 | 83<sup> +/- 3</sup> | 0.012 |
| AMD Ryzen 9 5900X 12-Core | 47 | 97<sup> +/- 6</sup> | 0.010 |

$$ Aceleración = \frac{Rendimiento \ mejorado}{rendimiento \ original} $$
$$ 1.58 = \frac{0.019}{0.012} $$

Tomando como referencia es procesador Intel Core i5-13600K, un Ryzen 9 7950X 16-Core tendra una aceleracion o speedup del 58%

## Time Profiling
## 1)
<img width="681" height="254" alt="image" src="https://github.com/user-attachments/assets/0603c6cd-745d-4ff5-a0b0-c72fa678a010" />

Compilado de test_gprof.c y test_gprof_new.c con soporte para perfilado o profiling via gprof

## 2)

<img width="695" height="439" alt="image" src="https://github.com/user-attachments/assets/4dd4c9b0-618a-41f7-a791-1471f908cddd" />

La ejecución del programa provoca la generación del archivo gmon.out con la información del perfil obtenido.

## 3)

<img width="669" height="618" alt="image" src="https://github.com/user-attachments/assets/c2a9862e-99ad-4fbf-987d-6cbd2a469057" />

Gprof produce un archivo con toda la información del perfil del programa. (Ver analysis_(full).txt)

### Personalización del archivo generado por gprof

#### 1)

<img width="661" height="448" alt="image" src="https://github.com/user-attachments/assets/fbfcaa9e-b499-4a39-a7b8-3ea2b836ee7b" />

El argumento -a suprime la impresion de funciones privadas (static).

#### 2)

<img width="656" height="765" alt="image" src="https://github.com/user-attachments/assets/b81da6a6-19a5-41e1-ac14-78263139c117" />

El argumento -b omite los textos con informacion detallada de los datos (short).

#### 3)

<img width="661" height="270" alt="image" src="https://github.com/user-attachments/assets/ffd70264-3324-410f-a34f-e888c7852a28" />

El argumento -p genera un perfil plano (flat).

#### 3)

<img width="666" height="245" alt="image" src="https://github.com/user-attachments/assets/89d72e02-b84d-483a-8c57-732b4c9a6ed1" />

Si se ejecuta gprof con el nombre de una funcion, genera solamente el perfil de la misma (func1).

### Generación de grafico con gprof2dot

<img width="657" height="596" alt="image" src="https://github.com/user-attachments/assets/410d3d9a-24a6-4860-a314-0a909110cf69" />


## Profiling con linux perf

<img width="672" height="255" alt="image" src="https://github.com/user-attachments/assets/c37a7587-4321-404f-80ea-093f7c69b056" />

<img width="703" height="193" alt="image" src="https://github.com/user-attachments/assets/170e3654-2fc9-45d6-8df2-492eba059f8c" />

## Práctico  
Conseguir un esp32 o cualquier procesador al que se le pueda cambiar la frecuencia.
Ejecutar un código que demore alrededor de 10 segundos. Puede ser un bucle for con sumas de enteros por un lado y otro con suma de floats por otro lado.
¿Qué sucede con el tiempo del programa al duplicar (variar) la frecuencia ? 

### Materiales 
- ESP32 C3 Super mini.
- Arduino IDE.
<img width="400" alt="image" src="https://github.com/user-attachments/assets/a075764c-b9fe-482f-9b09-cc183a6d93aa" />

### Experiencia
Se ejecutaron 2 códigos. El primero con un bucle for que duraba unos 10.56 segundos al que se le fue disminuyendo la frecuencia del CPU a la mitad. En este bucle las variables del contador eran de tipo int.
Se realizaron 3 ejecuciones:
- 160 MHz
- 80 MHz
- 40 MHz

El segundo código era muy parecido al primero solo que habían dos contadores, uno con variables tipo int y otro con variables tipo float. El programa comparaba los tiempos de ejecución de ambos a una frecuencia del CPU de 160Mhz.

### Inferencias
Para el primer programa uno esperaría que el tiempo de ejecución se fuera duplicando a medida que la frecuencia de la CPU se diminuye a la mitad, ya que son inversamente proporcionales.
Y para el segundo programa el contador de tipo float debería ser más lento que el de tipo int por la naturaleza de cada tipo de dato.

### Resultados
![frecuencias](https://github.com/user-attachments/assets/6a5b48cf-4960-477e-9a0c-aeecc83fe963)
![064a6406-ef26-4610-bc5f-1b1e8af79abb](https://github.com/user-attachments/assets/10e4cc66-c6b6-452b-bc85-c0d11bc420c3)

### Conclusión
Las inferencias fueron correctas y se pudo comprobar que tanto el tipo de dato como la frecuencia de la CPU elegida para la ejecución de los progrmas afecta el tiempo de ejecución y en consecuencia el rendimiento.

## Conclusión final del TP1
En este trabajo logramos comparar el rendimiento de distintos procesadores frente a un kernel de linux. Además, permitió comprobar que el rendimiento de un sistema depende directamente de la frecuencia del CPU y del tipo de datos utilizados. Al reducir la frecuencia, el tiempo de ejecución aumenta, y las operaciones con float resultan más lentas que con int. En conclusión, tanto el hardware como las decisiones de programación influyen significativamente en el rendimiento.

Por último, también pudimos identificar distintos benchmarch para medir el rendimiento según las tareas que vayamos a realizar.
