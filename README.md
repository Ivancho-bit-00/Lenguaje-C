# Simulador de Navegación de Robot en Laberintos

## 1. Propósito general
Este proyecto implementa un **prototipo inicial** de la aplicación solicitada en la consigna académica del Trabajo Final Integrador de Algoritmos y Estructuras de Datos. El programa permite a un robot virtual explorar laberintos en una grilla de 15×15 celdas, calcular rutas considerando obstáculos (paredes) y terrenos difíciles (agua), y visualizar el camino óptimo encontrado.

**Estado:** 🟡 En desarrollo activo - Funcionalidad base implementada, pendiente refactorización y completar requisitos estructurales.

## 2. Descripción funcional

### Funcionalidades implementadas ✅
- **Interfaz por consola**: Interacción completa mediante terminal ASCII.
- **Selección de mapas**: Cuatro configuraciones predefinidas con diferentes niveles de complejidad.
- **Validación de coordenadas**: El programa valida que origen y destino sean celdas libres dentro de los límites.
- **Cálculo de ruta con costos**: Algoritmo tipo Dijkstra que considera agua (costo 2) y celdas libres (costo 1).
- **Visualización ASCII**: Representación clara del mapa usando caracteres: ` ` (libre), `#` (pared), `~` (agua), `E` (entrada), `S` (salida), `.` (camino óptimo).
- **Detección de inaccesibilidad**: Informa cuando no existe camino posible al destino.

### Funcionalidades pendientes ❌
- **Carga de mapas desde archivo**: No lee archivos `.map` externos.
- **Generación aleatoria de mapas**: No implementada (opcional).
- **Animación paso a paso**: Solo muestra resultado final, no movimiento del robot.
- **Menú completo**: Falta menú interactivo con múltiples opciones.
- **Edición de mapa**: No permite agregar/quitar obstáculos dinámicamente.

## 3. Arquitectura del código

### Estructura actual (monolítica)
```
Lenguaje-C/
├── labyrinth.c          # ⚠️ Todo el código en un solo archivo (224 líneas)
├── output/
│   └── labyrinth.exe    # Ejecutable compilado
├── docs/
│   ├── consigna.md      # Especificación del proyecto
│   └── plan_de_trabajo.md  # Plan de desarrollo
└── README.md            # Este archivo
```

**⚠️ Problema**: La consigna requiere modularización en múltiples archivos (`main.c`, `mapa.c/.h`, `algoritmos.c/.h`, `estructuras.c/.h`).

### Funciones principales en `labyrinth.c`

| Función | Líneas | Descripción |
|---------|--------|-------------|
| `showMap()` | 9-19 | Convierte valor numérico a carácter para visualización |
| `chooseMap()` | 22-88 | Genera uno de 4 mapas predefinidos en matriz 15×15 |
| `printMap()` | 91-98 | Imprime el mapa en consola usando ASCII |
| `chooseEntryAndExit()` | 101-126 | Solicita y valida coordenadas de origen y destino |
| `findShord()` | 135-195 | Implementa Dijkstra con selección lineal + reconstrucción de camino |
| `main()` | 198-224 | Función principal con flujo de ejecución |

## 4. Estructuras de datos y algoritmos

### Estructuras de datos implementadas

| Estructura | Estado | Cumplimiento |
|------------|--------|--------------|
| **Matriz 2D** (mapa) | ✅ Implementada | `int map[15][15]` - Representa el entorno |
| **Cola (FIFO)** | ❌ **Faltante** | Requerida para BFS |
| **Lista Enlazada** | ❌ **Faltante** | Requerida para almacenar caminos |
| **Pila (LIFO)** | ❌ Faltante | Opcional para DFS |

**⚠️ Estado crítico**: Solo **1 de 3 estructuras mínimas** requeridas por la consigna.

### Algoritmos implementados

**✅ Dijkstra con selección lineal** (`findShord()`)
- **Complejidad**: O(V²) donde V = número de celdas
- **Características**:
  - Considera costos diferenciados (agua=2, libre=1)
  - Usa matrices `dist[][]`, `visited[][]`, `parentX[][]`, `parentY[][]`
  - Reconstruye camino desde destino a origen usando padres
  - Detecta destinos inaccesibles (distancia = INT_MAX)
- **Limitación**: No usa estructuras de datos propias (cola, heap)

**❌ BFS (Breadth-First Search)**: **NO IMPLEMENTADO**
- **Problema crítico**: La consigna **exige BFS explícito** con cola implementada manualmente
- Pendiente de desarrollo

**❌ DFS (Depth-First Search)**: No implementado (opcional)

## 5. Instalación y ejecución

### Requisitos previos
- **Compilador C**: Compatible con C11 (GCC 9+, Clang 11+, o MSVC 2019+)
- **Sistema operativo**: Windows, Linux o macOS con terminal
- **Git**: Para clonar el repositorio

### Pasos de instalación

1. **Clonar el repositorio**:
   ```bash
   git clone <url-del-repo>
   cd Lenguaje-C
   ```

2. **Compilar el programa**:
   ```bash
   gcc -std=c11 -Wall -Wextra -pedantic labyrinth.c -o labyrinth
   ```
   - En Windows se generará `labyrinth.exe`
   - En Linux/macOS se generará `labyrinth`

3. **Ejecutar el programa**:
   ```bash
   # Linux / macOS
   ./labyrinth
   
   # Windows PowerShell
   .\output\labyrinth.exe
   ```

### Ejemplo de uso

```
Elige el mapa que quieres probar:
1. Mapa simple
2. Camino serpenteante
3. Camino Verticales
4. El laberinto de los tres caminos
Opcion: 1

[Mapa se muestra en pantalla]

--- Elección de entrada ---
Ingrese coordenada de entrada (fila y columna entre 0 y 14): 1 1

--- Eleccion de salida ---
Ingrese coordenada de salida (fila y columna entre 0 y 14): 13 13

Buscando el camino más eficiente (considerando agua con costo 2)...

Costo total del camino: 24

✅ Camino optimo encontrado:
[Mapa con camino marcado con '.' se muestra en pantalla]
```

## 6. Estado de desarrollo y cumplimiento de consigna

### Tabla de progreso del desarrollo

| Componente | Estado | Prioridad | Avance |
|------------|--------|-----------|--------|
| **Estructuras de datos** | 🔴 Crítico | Alta | 33% (1/3) |
| Matriz 2D para mapa | ✅ Completo | - | 100% |
| Cola (FIFO) para BFS | ❌ Pendiente | Alta | 0% |
| Lista enlazada para caminos | ❌ Pendiente | Alta | 0% |
| **Algoritmos** | 🟡 Parcial | Alta | 40% |
| BFS (obligatorio) | ❌ Pendiente | Alta | 0% |
| Dijkstra con costos | ✅ Completo | Media | 100% |
| **Funcionalidades básicas** | 🟢 Operacional | Media | 60% |
| Generación de mapas predefinidos | ✅ Completo | - | 100% |
| Interacción por consola | ✅ Completo | - | 100% |
| Validación de coordenadas | ✅ Completo | - | 100% |
| Visualización ASCII | ✅ Completo | - | 100% |
| Detección de inaccesibilidad | ✅ Completo | - | 100% |
| Carga de mapas desde archivo | ❌ Pendiente | Alta | 0% |
| Menú completo interactivo | ❌ Pendiente | Media | 0% |
| Animación paso a paso | ❌ Pendiente | Baja | 0% |
| **Arquitectura** | 🔴 Crítico | Alta | 0% |
| Modularización en archivos separados | ❌ Pendiente | Alta | 0% |
| Makefile | ❌ Pendiente | Alta | 0% |
| **Entregables** | 🟡 Parcial | Alta | 30% |
| Código fuente | 🟡 Parcial | - | 60% |
| Dataset (3 archivos .map) | ❌ Pendiente | Alta | 0% |
| README.md | ✅ Completo | - | 100% |
| Informe técnico | ❌ Pendiente | Alta | 0% |
| Video explicativo (5 min) | ❌ Pendiente | Alta | 0% |

### Cumplimiento de requisitos obligatorios de la consigna

| Requisito | Cumple | Observaciones |
|-----------|--------|---------------|
| Lenguaje C99/C11 | ✅ Sí | Código compatible, falta flag explícito en compilación |
| Interfaz por consola | ✅ Sí | Implementación completa ASCII |
| ≥3 estructuras de datos | ❌ **NO** | **Solo 1/3 implementadas** (crítico) |
| Algoritmo de búsqueda de ruta | 🟡 Parcial | Dijkstra funciona, **falta BFS obligatorio** |
| Leer/generar mapa del entorno | 🟡 Parcial | Genera mapas fijos, **falta lectura de archivos** |
| Ingresar destinos por usuario | ✅ Sí | Con validación completa |
| Mostrar ruta visualmente | ✅ Sí | Marcado con '.' en mapa ASCII |
| Manejar errores | 🟡 Parcial | Básico, falta robustez en archivos/malloc |
| Código fuente + ejecutable | ✅ Sí | Disponible y funcional |
| Dataset de 3 mapas .map | ❌ NO | No hay archivos externos |
| Informe técnico | ❌ NO | Pendiente de redacción |
| Video de 5 minutos | ❌ NO | Pendiente de grabación |
| Modularización por archivos | ❌ NO | Todo en un archivo monolítico |

**Cumplimiento global estimado: ~27%** ⚠️

### Análisis de brecha (Gap Analysis)

**Fortalezas del código actual:**
- ✅ Algoritmo de búsqueda de caminos funcional y correcto
- ✅ Visualización clara y efectiva
- ✅ Validaciones básicas implementadas
- ✅ Código limpio y legible, fácil de refactorizar

**Brechas críticas que bloquean la entrega:**
1. 🔴 **Faltan 2 de 3 estructuras de datos obligatorias** (cola y lista enlazada)
2. 🔴 **No hay implementación de BFS** (algoritmo obligatorio)
3. 🔴 **Código no modularizado** (debe separarse en múltiples archivos)
4. 🔴 **Sin dataset de prueba** (se requieren 3 archivos `.map`)
5. 🔴 **Falta documentación formal** (informe técnico y video)

## 7. Pruebas y validación

### Mapas disponibles para pruebas

**Mapas internos (hardcoded):**
1. **Mapa 1 - Simple**: Laberinto básico con pasillos rectos
2. **Mapa 2 - Serpenteante**: Camino en zigzag con zonas de agua
3. **Mapa 3 - Verticales**: Paredes verticales espaciadas
4. **Mapa 4 - Tres caminos**: Laberinto complejo con múltiples rutas y agua

**⚠️ Limitación**: No hay archivos `.map` externos. Las pruebas se realizan solo con mapas embebidos en el código.

### Pruebas manuales realizadas

✅ **Casos probados exitosamente:**
- Cálculo de ruta en mapas sin agua (costo uniforme)
- Cálculo de ruta considerando zonas de agua (costo 2)
- Detección de destinos inaccesibles
- Validación de coordenadas fuera de límites
- Validación de celdas ocupadas

❌ **Casos no probados:**
- Carga de mapas desde archivo (funcionalidad no implementada)
- Mapas con múltiples robots (no soportado)
- Reconfiguración dinámica del entorno

## 8. Próximos pasos (Roadmap)

### Fase 1: Estructuras fundamentales (Prioridad ALTA) 🔴
**Tiempo estimado: 1-2 semanas**

1. **Crear módulo `estructuras.c/.h`**
   - Implementar Cola (FIFO) con array circular o lineal
   - Implementar Lista Enlazada simple para caminos
   - Documentar cada función con propósito y complejidad
   - Validar todos los `malloc()` con manejo de errores

2. **Modularizar código existente**
   - Separar en: `main.c`, `mapa.c/.h`, `algoritmos.c/.h`, `estructuras.c/.h`
   - Migrar funciones de `labyrinth.c` a módulos correspondientes
   - Crear Makefile con objetivos `all`, `clean`, `run`

### Fase 2: Algoritmo BFS y mapas (Prioridad ALTA) 🔴
**Tiempo estimado: 1 semana**

3. **Implementar BFS en `algoritmos.c`**
   - Usar la cola implementada en Fase 1
   - Implementar matriz de visitados y matriz de padres
   - Reconstruir camino usando lista enlazada
   - Documentar complejidad y funcionamiento

4. **Sistema de carga de mapas**
   - Implementar función `cargar_mapa()` para leer archivos `.map`
   - Crear 3 archivos `.map` de prueba en carpeta `mapas/`:
     - `simple.map`: 10×10, camino directo
     - `laberinto.map`: 15×15, múltiples obstáculos
     - `imposible.map`: destino bloqueado
   - Validar formato y dimensiones al cargar

### Fase 3: Interfaz y menú completo (Prioridad MEDIA) 🟡
**Tiempo estimado: 3-5 días**

5. **Crear menú interactivo en `main.c`**
   - Opción 1: Cargar mapa desde archivo
   - Opción 2: Mostrar mapa actual
   - Opción 3: Establecer origen/destino
   - Opción 4: Calcular ruta con BFS
   - Opción 5: Reconfigurar celda (toggle obstáculo)
   - Opción 0: Salir

### Fase 4: Documentación y entrega (Prioridad ALTA) 🔴
**Tiempo estimado: 1 semana**

6. **Documentación técnica**
   - Redactar `docs/informe.md`:
     - Título y contexto del proyecto
     - Descripción de estructuras elegidas y justificación
     - Explicación de algoritmos (BFS y Dijkstra)
     - Análisis de complejidad
     - Obstáculos encontrados y soluciones
     - Referencias y recursos consultados
     - Mención de uso de IA generativa (si aplica)
     - Conclusiones del equipo

7. **Video explicativo**
   - Estructura de 5 minutos:
     - 0:00-0:30: Presentación de integrantes
     - 0:30-2:00: Demostración del programa
     - 2:00-4:00: Explicación de estructuras y BFS
     - 4:00-5:00: Justificación de eficiencia y conclusiones
   - Subir a YouTube (puede ser no listado)
   - Agregar enlace en README

8. **Empaquetar y entregar**
   - Verificar compilación sin warnings (`-Wall -Wextra`)
   - Probar con los 3 mapas `.map`
   - Crear archivo `.zip` con todo el proyecto
   - Subir al aula virtual

### Fase 5: Mejoras opcionales (Prioridad BAJA) 🟢
**Solo si hay tiempo disponible**

- Animación paso a paso del robot
- Generación aleatoria de mapas
- Implementación de DFS
- Múltiples robots
- Obstáculos dinámicos

## 9. Recursos y referencias

### Para implementar estructuras de datos
- [GeeksforGeeks - Queue](https://www.geeksforgeeks.org/queue-data-structure/)
- [GeeksforGeeks - Linked List](https://www.geeksforgeeks.org/data-structures/linked-list/)
- [Programiz - C Data Structures](https://www.programiz.com/dsa/data-structure-types)

### Para algoritmo BFS
- [VisuAlgo - BFS Visualization](https://visualgo.net/en/dfsbfs)
- [GeeksforGeeks - BFS in Grid](https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/)
- Complejidad teórica: O(V + E) donde V=celdas, E=conexiones

### Para manejo de archivos en C
- [TutorialsPoint - File I/O](https://www.tutorialspoint.com/cprogramming/c_file_io.htm)
- [Programiz - File Handling](https://www.programiz.com/c-programming/c-file-input-output)

### Para compilación modular
- [Makefile Tutorial](https://makefiletutorial.com/)
- [YouTube: Multi-file C Projects](https://www.youtube.com/results?search_query=c+multi+file+projects)

---

## 📞 Contacto y colaboración

Este proyecto es desarrollado como parte del Trabajo Final Integrador de la asignatura Algoritmos y Estructuras de Datos.

**Estado del proyecto**: 🟡 En desarrollo activo  
**Última actualización**: Noviembre 2025  
**Cumplimiento de consigna**: ~27% (en progreso hacia 100%)


