# Plan de Trabajo Simplificado - Simulador de Navegación de Robot

Este documento presenta un plan **simplificado y directo** para completar el proyecto según la consigna académica. Se divide en **4 grupos de trabajo concurrentes** (máximo 4 actividades cada uno) más **1 grupo de integración final**.

**Principio:** Implementar lo mínimo necesario para cumplir con la consigna, evitando complejidad innecesaria.

---

## Dependencias entre Programadores

Para evitar bloqueos, seguir este orden:

1. Programadores 1 y 2 trabajan en paralelo (no tienen dependencias entre sí)
2. Programador 3 comienza cuando P1 y P2 terminen (necesita estructuras y mapas)
3. Programador 4 integra todo cuando los demás terminen
4. Grupo conjunto (documentación y entrega)

**Comunicación:** Crear grupo de WhatsApp/Discord para consultas diarias. Los programadores 1 y 2 deben compartir sus archivos `.h` apenas los tengan listos, así el Programador 3 puede empezar a planificar.

---

## PROGRAMADOR 1: Estructuras de Datos Básicas

**Objetivo:** Implementar las 3 estructuras de datos mínimas requeridas (cola, pila, lista enlazada) de forma simple y funcional.

### Actividades:

1. **Crear archivos `estructuras.h` y `estructuras.c`**
   - Definir estructura básica de posición: `typedef struct { int x, y; } Posicion;`

2. **Implementar Cola (FIFO) con array simple y contadores**
   - **Simplificación para principiantes:** usar array lineal con índices `frente` y `final`
   - Estructura global o estática: `Posicion cola[1000]; int frente = 0; int final = 0;`
   - Funciones mínimas: `cola_init()`, `cola_enqueue(Posicion p)`, `cola_dequeue()`, `cola_is_empty()`
   - `enqueue`: agregar en posición `final++`
   - `dequeue`: leer en posición `frente++`
   - Comentar propósito: "Para BFS - búsqueda por anchura"
   - **Nota:** No hace falta `free()` si usamos array estático

3. **Implementar Lista Enlazada simple para almacenar caminos**
   - Estructura: `struct NodoCamino { int x; int y; struct NodoCamino *next; };`
   - **Funciones básicas sin complejidad:**
     - `lista_crear()`: retorna NULL (lista vacía)
     - `lista_agregar_al_final(struct NodoCamino **cabeza, int x, int y)`: agrega nodo al final
     - `lista_liberar(struct NodoCamino *cabeza)`: libera toda la lista
     - `lista_longitud(struct NodoCamino *cabeza)`: cuenta nodos
   - Validar cada `malloc()`: `if (nuevo == NULL) { printf("Error de memoria\n"); exit(1); }`
   - **Guía:** Proveer pseudocódigo o ejemplo comentado para `lista_agregar_al_final`

4. **Documentar cada función con comentario simple**
   - Formato: `/* Qué hace / Parámetros / Qué retorna */`
   - Incluir ejemplo de uso en comentarios

**Entregables:** `estructuras.h`, `estructuras.c`

**Recursos de apoyo:** Incluir en comentarios enlaces a tutoriales de listas enlazadas en C (ej. GeeksforGeeks)

---

## PROGRAMADOR 2: Módulo de Mapas

**Objetivo:** Separar la lógica del mapa en módulo independiente, agregar carga desde archivo y crear 3 mapas de prueba.

### Actividades:

1. **Crear archivos `mapa.h` y `mapa.c`**
   - Definir estructura: `typedef struct { int rows; int cols; char cells[MAX_ROWS][MAX_COLS]; } Mapa;`
   - Constantes: `#define MAX_ROWS 50`, `#define MAX_COLS 50`

2. **Migrar funciones existentes de `labyrinth.c` (copiar y adaptar)**
   - Copiar `showMap()` → renombrar a `mapa_char(int tipo)`: convierte número a carácter
   - Copiar `printMap()` → renombrar a `mostrar_mapa(const Mapa *m)`: imprime el mapa en pantalla
   - Copiar `chooseMap()` → renombrar a `generar_mapa_predefinido(Mapa *m, int numero)`: genera uno de los 4 mapas
   - **Simplificación:** Mantener la lógica exactamente igual, solo cambiar nombres

3. **Implementar carga simple de archivos `.map` paso a paso**
   - Función: `int cargar_mapa(Mapa *m, const char *archivo)`
   - **Pasos guiados para principiantes:**
     - Abrir archivo: `FILE *f = fopen(archivo, "r");`
     - Verificar: `if (f == NULL) { printf("Error al abrir archivo\n"); return 0; }`
     - Leer primera línea: `fscanf(f, "%d %d", &m->rows, &m->cols);`
     - Leer cada línea del mapa con un bucle `for` y `fgets()` o `fscanf()`
     - Cerrar archivo: `fclose(f);`
     - Retornar 1 si todo OK
   - **Ejemplo comentado:** Incluir código de ejemplo completo en comentarios

4. **Crear 3 archivos de prueba en carpeta `mapas/` manualmente**
   - `mapas/simple.map`: 10×10, pocos obstáculos, camino directo
   - `mapas/laberinto.map`: 15×15, múltiples obstáculos
   - `mapas/imposible.map`: destino completamente bloqueado por `#`
   - **Ayuda:** Usar editor de texto simple (Notepad, nano, vim)

**Entregables:** `mapa.h`, `mapa.c`, carpeta `mapas/` con 3 archivos `.map`

**Consejo:** Probar `cargar_mapa()` con prints intermedios para verificar cada paso

---

## PROGRAMADOR 3: Algoritmo BFS

**Objetivo:** Implementar BFS (búsqueda por anchura) obligatorio para encontrar el camino más corto en pasos, usando la cola del Programador 1. **Versión simplificada para principiantes.**

### Actividades:

1. **Crear archivos `algoritmos.h` y `algoritmos.c`**
   - Incluir dependencias: `#include "mapa.h"` y `#include "estructuras.h"`
   - Incluir `#include <stdbool.h>` para usar `bool`

2. **Implementar BFS paso a paso con pseudocódigo guiado**
   - Función simplificada: `int bfs_ruta(Mapa *m, int ox, int oy, int dx, int dy)`
   - **Nota:** Modificar el mapa directamente, sin retornar lista (más simple para principiantes)
   - **Algoritmo guiado:**
     - Crear arrays: `bool visitado[MAX_ROWS][MAX_COLS] = {false};`
     - Crear arrays de padres: `int padre_x[MAX_ROWS][MAX_COLS];` y `padre_y[MAX_ROWS][MAX_COLS];`
     - Inicializar padres con -1
     - Usar cola del Programador 1: encolar posición origen (ox, oy)
     - Marcar origen como visitado
     - **Bucle while** mientras cola no esté vacía:
       - Desencolar posición actual
       - Si es el destino: terminar búsqueda
       - Revisar 4 vecinos (arriba, abajo, izq, der) con arrays de direcciones:
         ```c
         int dx[4] = {-1, 1, 0, 0};  // movimientos en fila
         int dy[4] = {0, 0, -1, 1};  // movimientos en columna
         ```
       - Para cada vecino válido y no visitado: encolar, marcar visitado, guardar padre
   - Retornar 1 si encontró destino, 0 si no

3. **Reconstruir camino de forma simple (sin invertir lista)**
   - Desde el destino, retroceder usando matriz de padres
   - Guardar coordenadas en un array temporal: `Posicion camino[1000];`
   - Contar cuántas posiciones tiene el camino
   - Recorrer el array en orden inverso y marcar en el mapa con `'*'`
   - **Alternativa aún más simple:** marcar directamente durante el retroceso

4. **Documentar con comentarios abundantes**
   - Explicar qué es BFS en palabras simples: "Explora nivel por nivel desde el origen"
   - Comentar cada sección del código
   - Incluir ejemplo de ejecución en comentario

**Entregables:** `algoritmos.h`, `algoritmos.c` con BFS funcional

**Recursos de apoyo:** Incluir pseudocódigo completo de BFS en comentarios, enlace a visualización online de BFS

**Nota:** El Dijkstra existente en `labyrinth.c` puede mantenerse como funcionalidad extra, pero **BFS es obligatorio**.

---

## PROGRAMADOR 4: Menú Principal y Main

**Objetivo:** Crear menú interactivo simple que integre todos los módulos y permita al usuario cargar mapas, elegir origen/destino, calcular ruta y visualizarla.

### Actividades:

1. **Crear `main.c` con menú simple usando switch-case**
   - Incluir todos los headers: `mapa.h`, `estructuras.h`, `algoritmos.h`
   - Variables globales simples para facilitar (aceptable para principiantes):
     ```c
     Mapa mapa_actual;
     int mapa_cargado = 0;  // bandera: 0=no, 1=si
     int origen_x, origen_y, origen_definido = 0;
     int destino_x, destino_y, destino_definido = 0;
     ```
   - Menú con 6 opciones en un `do-while`:
     ```
     1. Cargar mapa desde archivo
     2. Mostrar mapa actual
     3. Establecer origen (robot)
     4. Establecer destino
     5. Calcular y mostrar ruta (BFS)
     0. Salir
     ```
   - Usar `switch(opcion)` con `case` para cada opción

2. **Implementar cada caso del menú de forma directa**
   - **Caso 1:** Pedir nombre de archivo, llamar `cargar_mapa(&mapa_actual, nombre)`, poner `mapa_cargado = 1`
   - **Caso 2:** Verificar `mapa_cargado`, llamar `mostrar_mapa(&mapa_actual)`
   - **Caso 3:** Pedir coordenadas con `scanf`, validar límites y que celda sea libre, guardar en `origen_x/y`
   - **Caso 4:** Igual que caso 3, para destino
   - **Caso 5:** Verificar banderas, llamar `bfs_ruta()`, mostrar resultado
   - **Simplificación:** Todo en `main()`, sin funciones auxiliares complejas

3. **Validaciones básicas con if simples**
   - Antes de opciones 2-5: `if (!mapa_cargado) { printf("Primero carga un mapa\n"); continue; }`
   - Antes de opción 5: verificar también `origen_definido` y `destino_definido`
   - Para coordenadas: `if (x < 0 || x >= mapa.rows || y < 0 || y >= mapa.cols) { ... }`
   - **Sin bucles de reintento complejos:** mostrar error y volver al menú

4. **Mostrar resultados de forma clara**
   - Después de BFS exitoso: `printf("✓ Camino encontrado!\n");` y llamar `mostrar_mapa()`
   - Si BFS retorna 0: `printf("✗ No hay camino posible\n");`
   - Usar `printf` con mensajes simples y claros

**Entregables:** `main.c` completo y funcional

**Consejo:** Probar cada opción del menú de forma individual antes de integrar todo

---

## GRUPO CONJUNTO: Integración y Documentación Final

**Responsables:** Los 4 programadores en conjunto

**Objetivo:** Integrar módulos, crear `Makefile`, probar con los 3 mapas, completar documentación (README, informe, video) para entregar.

### Actividades:

1. **Integración y compilación**
   - Verificar que todos los módulos compilen juntos sin errores
   - Crear `Makefile` simple:
     ```makefile
     CC = gcc
     CFLAGS = -std=c11 -Wall -Wextra -pedantic
     SOURCES = main.c mapa.c estructuras.c algoritmos.c
     TARGET = robot
     
     all:
         $(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)
     
     clean:
         rm -f $(TARGET)
     
     run: all
         ./$(TARGET)
     ```
   - Compilar y corregir warnings/errores

2. **Pruebas manuales con los 3 mapas**
   - Probar cada mapa: cargar → establecer origen/destino → calcular ruta
   - Verificar que `simple.map` encuentre camino
   - Verificar que `laberinto.map` encuentre camino correcto
   - Verificar que `imposible.map` reporte "inaccesible"
   - Documentar resultados en tabla simple

3. **Completar README.md y redactar informe técnico**
   - Actualizar README con:
     - Cómo compilar: `make` o `gcc -std=c11 -Wall -Wextra -pedantic main.c mapa.c estructuras.c algoritmos.c -o robot`
     - Cómo ejecutar: `./robot` (Linux/Mac) o `robot.exe` (Windows)
     - Descripción de archivos: `main.c`, `mapa.c/h`, `estructuras.c/h`, `algoritmos.c/h`
   - Crear `docs/informe.md` con:
     - Título del proyecto
     - Problema (ej. "Robot navegando en almacén")
     - Solución: BFS para camino mínimo, 3 estructuras (matriz, cola, lista)
     - Estructuras elegidas y justificación
     - Algoritmo BFS: por qué es adecuado (camino en pasos mínimos)
     - Referencias consultadas
     - **Mención de uso de IA** si aplica
     - Conclusiones del equipo

4. **Grabar video de 5 minutos y preparar entrega**
   - Estructura del video:
     - 0:00-0:30: Presentación de integrantes (nombres en pantalla)
     - 0:30-2:00: Demo del programa (cargar mapa, calcular ruta)
     - 2:00-4:00: Explicar estructuras (cola, lista) y BFS
     - 4:00-5:00: Justificar eficiencia y conclusiones
   - Subir a YouTube (puede ser "no listado")
   - Agregar enlace en README
   - Empaquetar proyecto completo (código, mapas, docs, README) en `.zip`
   - Subir al aula virtual

**Entregables finales:**
- Código fuente completo y compilable
- `Makefile`
- 3 archivos `.map` en carpeta `mapas/`
- `README.md` actualizado
- `docs/informe.md`
- Video en YouTube (enlace en README)
- Paquete `.zip` para entrega

---

## Checklist Mínimo de la Consigna

- ✅ Lenguaje C estándar (C11)
- ✅ Interfaz por consola (menú de texto)
- ✅ Al menos 3 estructuras de datos: **Matriz** (mapa), **Cola** (BFS), **Lista enlazada** (camino)
- ✅ Algoritmo de búsqueda de ruta: **BFS implementado manualmente**
- ✅ Leer mapa del entorno (desde archivo `.map`)
- ✅ Ingresar destino por coordenadas
- ✅ Mostrar ruta planificada visualmente (con `*`)
- ✅ Manejar errores: destino inaccesible, coordenadas inválidas
- ✅ Al menos 3 mapas de prueba con diferentes configuraciones
- ✅ Código fuente + ejecutable
- ✅ Informe técnico completo
- ✅ Video explicativo de 5 minutos

---

## Notas Finales

**Este plan prioriza simplicidad para programadores principiantes:**

### Simplificaciones aplicadas:
- ✅ **Cola con array lineal** en vez de circular (más fácil de entender)
- ✅ **Variables globales** permitidas en `main.c` (evita punteros complejos)
- ✅ **BFS modifica el mapa directamente** (sin retornar punteros dobles a listas)
- ✅ **Reconstrucción de camino con array temporal** (sin invertir listas enlazadas)
- ✅ **Código guiado paso a paso** con pseudocódigo en comentarios
- ✅ **Sin funciones auxiliares complejas** en el menú (todo en `switch-case`)

### Características NO incluidas (no obligatorias):
- ❌ Sin generación aleatoria de mapas
- ❌ Sin animación paso a paso
- ❌ Sin edición interactiva de celdas
- ❌ Sin Dijkstra adicional (BFS cumple el requisito)
- ❌ Sin DFS
- ❌ Sin validaciones exhaustivas de archivos

### Recursos de apoyo recomendados:
- Tutoriales de listas enlazadas: GeeksforGeeks, Programiz
- Visualización de BFS: VisuAlgo.net
- Manejo de archivos en C: tutorialspoint.com
- Compilación modular: YouTube "C multi-file projects"

**El objetivo es cumplir la consigna de forma directa y funcional, sin características extras que consuman tiempo innecesario, adaptado a estudiantes con conocimientos básicos de C.**

