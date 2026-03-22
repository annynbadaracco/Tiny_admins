# Sistemas de Computación
## Trabajo Practico # 1: Rendimiento

Integrantes:

*
*
* Ignacio J. Vigezzi  

**Profesores:** Miguel Ángel Solinas y Javier Alejandro Jorge

**Universidad Nacional de Córdoba**  
**Facultad de Ciencias Exactas, Físicas y Naturales**

## Objetivo  
Poner en práctica los conocimientos sobre performance y rendimiento de los computadores.




### Compilación del kernel de linux

| Procesador | Tiempo | Rendimiento |
|------------|--------|--------------------|
| AMD Ryzen 9 7950X 16-Core | 50 | 0.0200 |
| Intel Core i5-13600K | 72 | 0.0139 |
| AMD Ryzen 9 5900X 12-Core | 76 | 0.0132 |

$$ Aceleración = \frac{Rendimiento \ mejorado}{rendimiento \ original} $$
$$ 1.44 = \frac{0.0200}{0.0132} $$

Tomando como referencia es procesador Intel Core i5-13600K, un Ryzen 9 7950X 16-Core tendra una aceleracion o speedup del 44%

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







