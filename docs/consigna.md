# Consigna - Trabajo Final Integrador

En la era de la automatización y la robótica, la capacidad de planificar rutas eficientes en entornos estructurados es una habilidad fundamental en múltiples aplicaciones: desde robots de limpieza domésticos, pasando por vehículos autónomos en almacenes logísticos e incluso drones de mapeo 3D. Este Trabajo Final Integrador tiene como objetivo que los estudiantes apliquen los conocimientos adquiridos en la asignatura **Algoritmos y Estructuras de Datos** para desarrollar una aplicación en lenguaje C que simule la navegación inteligente de un robot en un entorno bidimensional previamente mapeado. El proyecto busca integrar conceptos teóricos y prácticos, promoviendo el pensamiento algorítmico, la elección adecuada de estructuras de datos y la resolución de problemas reales mediante programación en C. Se busca además promover el desarrollo de habilidades blandas como ser la capacidad de trabajar en equipo, gestionar tiempos y comunicar soluciones de forma clara y profesional.  

## Objetivo General

Desarrollar una aplicación en lenguaje C que simule la navegación autónoma de un robot en un entorno mapeado, capaz de recibir comandos de destino, detectar obstáculos y planificar la ruta más corta o eficiente hacia su objetivo, aplicando algoritmos y estructuras de datos estudiados en la asignatura. 

## Objetivos Específicos

Diseñar algoritmos que permitan descubrir rutas.

- Utilizar **al menos tres estructuras de datos distintas**, trabajadas en clase, (por ejemplo: colas, pilas, listas enlazadas, matrices) de forma adecuada al problema.
- Modelar un entorno con **obstáculos dinámicos o estáticos** que el robot deba evitar.
- Procesar **comandos de usuario** (destino, reconfiguración del entorno, etc.) de forma robusta.
- **Documentar y presentar** el desarrollo mediante un informe técnico y un video explicativo. 

## Requisitos del Proyecto

### 1. Formación de Grupos
- Grupos de **2 a 4 integrantes**.
- Deberán registrarse en el Aula Virtual antes del **17/10** 

### 2. Descripción del Escenario
El entorno será una cuadrícula bidimensional o tridimensional, según se necesite, donde:
- Cada celda puede estar **libre**, **ocupada por un obstáculo**, o ser el **punto de inicio/destino** del robot. 
- El robot comienza en una posición fija o definida por el usuario
- El usuario podrá ingresar uno o más destinos (mediante coordenadas o identificadores).
- El robot debe calcular y ejecutar la **ruta óptima** (mínima en distancia, en pasos, en costo, etc) evitando obstáculos.
- _Opcional_ (recomendado para mayor puntaje): incluir obstáculos móviles, zonas de alto costo (como terrenos difíciles), o múltiples robots que coordinen rutas.

### 3. Desarrollo de la Aplicación
- **Lenguaje obligatorio:** C estándar (C99 o C11).
- **Interfaz:** por consola (texto/ASCII art)
- El programa debe cumplir con los siguientes requisitos:
	- Leer o generar un mapa del entorno. 
- Permitir al usuario ingresar destinos.
- Mostrar visualmente la ruta planificada y el recorrido del robot.
- Manejar errores (destino inaccesible, coordenadas inválidas, etc.).

### 4. Entrega de Productos
Se deberán subir al aula virtual los siguientes entregables:

#### A. Código fuente y ejecutable subidos al aula virtual

#### B. Dataset de prueba
Al menos 3 mapas distintos con diferentes configuraciones de obstáculos, que puedan ser visualizados y modificados por los profesores.

#### C. Video explicativo (máximo 5 minutos) subido a YouTube, donde:
- a. Se muestre el funcionamiento del programa.
- b. Se explique la elección de estructuras de datos y algoritmos.
- c. Se argumente por qué la solución es eficiente y escalable.
- d. Se evidencia la participación de cada integrante. Deben aparecer todos los integrantes del grupo en el video, ya sea a través de una foto, identificándose con su nombre, etc.

#### D. Informe técnico que incluya:
- a. Título del proyecto
- b. Problema que buscan resolver. Deben elaborar el escenario.
- c. Solución propuesta
- d. Descripción de obstáculos técnicos y cómo se resolvieron.
- e. Referencias a librerías, documentación o recursos consultados. f. Mención explícita si se utilizó IA generativa (y en qué etapas).
- g. Conclusiones y aprendizajes del equipo. 