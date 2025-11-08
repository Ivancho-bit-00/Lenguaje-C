#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 15
#define M 15

/* Convierte número a carácter para imprimir */
char showMap(int tipo) {
    switch (tipo) {
        case 0: return ' ';  // libre
        case 1: return '#';  // pared
        case 2: return '~';  // agua
        case 3: return 'E';  // entrada
        case 4: return 'S';  // salida
        case 5: return '.';  // camino óptimo
        default: return '?';
    }
}

/* Crea el mapa según la elección del usuario */
void chooseMap(int eleccion, int map[N][M]) {
    int i, j;
    switch (eleccion) {
        case 1:
            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {
                    if (j == 0 || i == 0 || j == M-1 || i == N-1) map[i][j] = 1;
                    else if ((i >= 3 && i <= 11) && (j == 1 || j == 3 || j == 4 || j == 6 || j == 7 || j == 8 || j == 10 || j == 11 || j == 13))
                        map[i][j] = 1;
                    else map[i][j] = 0;
                }
            }
            map[3][2] = 1; map[3][12] = 1;
            break;

        case 2:
            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {
                    if (i == 0 || j == 0 || i == N-1 || j == M-1) map[i][j] = 1;
                    else map[i][j] = 0;
                }
            }
            for (i = 2; i < 13; i++) map[i][3] = 1;
            for (i = 1; i < 12; i++) map[i][7] = 1;
            for (i = 3; i < 14; i++) map[i][10] = 1;
            map[4][3] = 0; map[7][7] = 0; map[10][10] = 0;
            map[2][5] = 2; map[8][6] = 2; map[11][9] = 2;
            break;

        case 3:
            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {
                    if (i == 0 || j == 0 || i == N-1 || j == M-1)
                        map[i][j] = 1;
                    else if ((i >= 3 && i <= 11) && (j == 3 || j == 6 || j == 9 || j == 12))
                        map[i][j] = 1;
                    else map[i][j] = 0;
                }
            }
            break;

        case 4:
            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {
                    if (i == 0 || j == 0 || i == N-1 || j == M-1)
                        map[i][j] = 1;
                    else map[i][j] = 0;
                }
            }
            for (j = 2; j <= 12; j++) map[2][j] = 1;
            for (j = 3; j <= 13; j++) map[4][j] = 1;
            for (j = 1; j <= 11; j++) map[6][j] = 1;
            for (j = 2; j <= 12; j++) map[8][j] = 1;
            for (j = 3; j <= 13; j++) map[10][j] = 1;
            for (j = 1; j <= 11; j++) map[12][j] = 1;

            map[2][3] = 0; map[2][8] = 0; map[2][12] = 0;
            map[4][5] = 0; map[4][10] = 0;
            map[6][2] = 0; map[6][7] = 0; map[6][11] = 0;
            map[8][4] = 0; map[8][9] = 0; map[8][12] = 0;
            map[10][6] = 0; map[10][10] = 0;
            map[12][3] = 0; map[12][8] = 0; map[12][12] = 0;

            map[5][7] = 2; map[7][5] = 2; map[9][9] = 2; map[11][4] = 2;
            break;
    }
}

/* Muestra el mapa */
void printMap(int map[N][M]) {
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            printf("%c ", showMap(map[i][j]));
        printf("\n");
    }
}

/* Permite al usuario elegir entrada y salida válidas */
void chooseEntryAndExit(int map[N][M], int *entradax, int *entraday, int *salidax, int *saliday) {
    int x, y;
    printf("\n--- Elección de entrada ---\n");
    while (1) {
        printf("Ingrese coordenada de entrada (fila y columna entre 0 y 14): ");
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < N && y >= 0 && y < M && map[x][y] == 0) {
            *entradax = x; *entraday = y;
            map[x][y] = 3;
            break;
        } else printf("❌ Posicion invalida. Debe ser una celda libre.\n");
    }

    printMap(map);

    printf("\n--- Eleccion de salida ---\n");
    while (1) {
        printf("Ingrese coordenada de salida (fila y columna entre 0 y 14): ");
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < N && y >= 0 && y < M && map[x][y] == 0) {
            *salidax = x; *saliday = y;
            map[x][y] = 4;
            break;
        } else printf("❌ Posición invalida. Debe ser una celda libre.\n");
    }
}

/* Estructura para Dijkstra */
typedef struct {
    int x, y;
    int dist;
} Node;

/* Distancia para encontrar el camino más corto considerando agua (costo 2) */
int findShord(int map[N][M], int ex, int ey, int sx, int sy) {
    int dist[N][M];
    int visited[N][M] = {0};
    int parentX[N][M], parentY[N][M];
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // Inicializar distancias
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            dist[i][j] = INT_MAX, parentX[i][j] = parentY[i][j] = -1;

    dist[ex][ey] = 0;

    while (1) {
        int minDist = INT_MAX, ux = -1, uy = -1;

        // Encontrar el nodo no visitado con menor distancia
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && dist[i][j] < minDist) {
                    minDist = dist[i][j];
                    ux = i; uy = j;
                }
            }
        }

        if (ux == -1) break; // no hay más nodos alcanzables
        visited[ux][uy] = 1;

        if (ux == sx && uy == sy) break; // llegada

        for (int k = 0; k < 4; k++) {
            int vx = ux + dx[k];
            int vy = uy + dy[k];
            if (vx >= 0 && vx < N && vy >= 0 && vy < M && map[vx][vy] != 1) {
                int cost = (map[vx][vy] == 2) ? 2 : 1;
                if (dist[ux][uy] + cost < dist[vx][vy]) {
                    dist[vx][vy] = dist[ux][uy] + cost;
                    parentX[vx][vy] = ux;
                    parentY[vx][vy] = uy;
                }
            }
        }
    }

    if (dist[sx][sy] == INT_MAX) return 0; // no hay camino

    // reconstruir el camino
    int cx = sx, cy = sy;
    while (!(cx == ex && cy == ey)) {
        if (map[cx][cy] == 0 || map[cx][cy] == 2)
            map[cx][cy] = 5;
        int px = parentX[cx][cy];
        int py = parentY[cx][cy];
        cx = px; cy = py;
    }

    printf("\nCosto total del camino: %d\n", dist[sx][sy]);
    return 1;
}

/* Programa principal */
int main() {
    int map[N][M];
    int opc, ex, ey, sx, sy;

    printf("Elige el mapa que quieres probar:\n");
    printf("1. Mapa simple\n");
    printf("2. Camino serpenteante\n");
    printf("3. Camino Verticales\n");
    printf("4. El laberinto de los tres caminos\n");
    printf("Opcion: ");
    scanf("%d", &opc);

    chooseMap(opc, map);
    printMap(map);

    chooseEntryAndExit(map, &ex, &ey, &sx, &sy);
    printf("\nBuscando el camino mqs eficiente (considerando agua con costo 2)...\n");

    if (findShord(map, ex, ey, sx, sy))
        printf("\n✅ Camino optimo encontrado:\n");
    else
        printf("\n❌ No hay camino posible.\n");

    printMap(map);
    return 0;
}
