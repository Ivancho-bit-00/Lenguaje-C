# Simulador de Laberintos en C

## 1. Propósito general
Este proyecto implementa un prototipo inicial de la aplicación solicitada en la consigna académica: un programa en C que permite explorar laberintos en una grilla fija de 15×15 celdas, elegir puntos de entrada y salida, y calcular un camino considerando celdas libres, paredes y agua (con costo adicional).

## 2. Descripción funcional
- La interfaz es completamente por consola.
- Al iniciar, el usuario elige uno de los cuatro mapas predefinidos.
- Se solicitan coordenadas de entrada y salida válidas; el programa valida que las celdas estén libres.
- El algoritmo calcula un camino “más eficiente” (ponderando el agua con costo 2) y marca la ruta encontrada en el mapa con `*`.
- Se muestra el mapa antes y después de la planificación, utilizando caracteres ASCII (`#`, `~`, `E`, `S`, `*`).

## 3. Estructura del proyecto
- `labyrinth.c`: Único archivo fuente. Contiene:
  - `chooseMap`: genera los cuatro mapas preestablecidos en una matriz `int map[15][15]`.
  - `chooseEntryAndExit`: interactúa con el usuario para fijar origen y destino dentro del mapa.
  - `findShord`: implementa una búsqueda tipo Dijkstra con selección lineal del nodo de menor costo para considerar celdas de agua (costo 2) y reconstruir el camino óptimo.
  - `printMap` y `showMap`: funciones auxiliares para visualizar la grilla.

**Estructuras de datos actuales**
- Matriz estática de enteros de 15×15 para representar el mapa.
- No se han implementado aún otras estructuras requeridas por la consigna (cola para BFS, pila o lista enlazada).

**Algoritmos implementados**
- Variante sencilla de Dijkstra sin cola de prioridad (selección lineal del mínimo).
- No se han implementado todavía BFS, DFS ni reconstrucciones mediante pila/lista enlazada.

## 4. Instalación y ejecución
1. Clonar el repositorio (reemplazar `<url-del-repo>` por la URL real):
   ```bash
   git clone <url-del-repo>
   cd Lenguaje-C
   ```
2. Compilar con GCC (recomendado por la consigna):
   ```bash
   gcc -std=c11 -Wall -Wextra -pedantic labyrinth.c -o labyrinth
   ```
   En Windows se generará `labyrinth.exe`.
3. Ejecutar el programa:
   ```bash
   ./labyrinth        # Linux / macOS
   .\labyrinth.exe    # Windows PowerShell
   ```
4. Seguir las indicaciones en pantalla para seleccionar mapa y coordenadas.

**Requisitos**
- Compilador C compatible con C11 (por ejemplo, GCC 9+, Clang 11+, MSVC 2019+).
- Sistema operativo con terminal (Windows, Linux o macOS).

## 5. Estado actual del desarrollo
| Tarea | Estado | Comentarios |
| --- | --- | --- |
| Generación de mapas predefinidos | Completada | Cuatro configuraciones fijas en código. |
| Interacción básica por consola | Completada | Lectura de opciones y coordenadas. |
| Algoritmo de planificación | Parcial | Dijkstra sin estructuras avanzadas; falta BFS obligatorio. |
| Estructuras de datos requeridas | Pendiente | No hay cola, pila ni lista enlazada. |
| Modularización por archivos | Pendiente | Todo reside en `labyrinth.c`; falta separar en módulos (`mapa.c/.h`, etc.). |
| Manejo de mapas desde archivos | Pendiente | Solo mapas embebidos; no se cargan `.map`. |
| Animación / simulación paso a paso | Pendiente | Solo impresión estática del resultado. |
| Documentación e informe | En progreso | README agregado; faltan informe, video y mención de IA según consigna. |

## 6. Pruebas y datasets
- No se incluyen aún archivos `.map` de prueba. Las pruebas manuales se realizan con los cuatro mapas internos disponibles desde el menú inicial.
- El ejecutable `output/labyrinth.exe` se puede usar como referencia rápida, pero conviene recompilar tras cada cambio en el código fuente.

## 7. Sugerencias de desarrollo futuro
- Reorganizar el proyecto en módulos (`main.c`, `mapa.c/.h`, `algoritmos.c/.h`, `estructuras.c/.h`, `io.c/.h`) según la consigna.
- Implementar las tres estructuras de datos mínimas: cola para BFS, pila o lista para reconstrucción, y mantener la matriz como representación del mapa.
- Agregar BFS para rutas en grilla sin costos y reutilizarlo para detectar caminos inaccesibles.
- Incorporar lectura/escritura de mapas (`.map`) y generación aleatoria controlada.
- Añadir animación paso a paso o avance manual del robot en consola.
- Crear datasets de prueba con distintos niveles de obstáculos, incluyendo escenarios sin solución.
- Desarrollar un menú más completo con opciones de edición del mapa y validaciones exhaustivas.
- Preparar el informe técnico, README final, video demostrativo y documentación de uso de IA conforme a la consigna.


