#include <stdio.h>

/* Convierte número a carácter para imprimir */
char showMap(int tipo) {
    switch (tipo) {
        case 0: return ' ';  // libre
        case 1: return '#';  // pared
        case 2: return '~';  // agua
        default: return '?';
    }
}

/* Crea el mapa según la elección del usuario */
void chooseMap(int eleccion, int map[15][15]) {
    int i, j;
    switch (eleccion) {
        case 1:  //Mapa 1
            for (i = 0; i < 15; i++) {
                for (j = 0; j < 15; j++) {
                    if (j == 0 || i == 0 || j == 14 || i == 14) map[i][j] = 1;
                    else if ((i >= 3 && i <= 11) && (j == 1 || j == 3 || j == 4 || j == 6 || j == 7 || j == 8 || j == 10 || j == 11 || j == 13))
                        map[i][j] = 1;
                    else map[i][j] = 0;
                }
            }
            map[3][2] = 1; map[3][12] = 1;
            break;

        case 2:  //Mapa 2
            for (i = 0; i < 15; i++) {
                for (j = 0; j < 15; j++) {
                    if (i == 0 || j == 0 || i == 14 || j == 14) map[i][j] = 1;
                    else map[i][j] = 0;
                }
            }
            for (i = 2; i < 13; i++) map[i][3] = 1;
            for (i = 1; i < 12; i++) map[i][7] = 1;
            for (i = 3; i < 14; i++) map[i][10] = 1;
            map[4][3] = 0; map[7][7] = 0; map[10][10] = 0;
            map[2][5] = 2; map[8][6] = 2; map[11][9] = 2;
            break;

        case 3:  //Camino Verticales
            for (i = 0; i < 15; i++) {
                for (j = 0; j < 15; j++) {
                    if (i == 0 || j == 0 || i == 14 || j == 14)
                        map[i][j] = 1;
                    else if ((i >= 3 && i <= 11) && (j == 3 || j == 6 || j == 9 || j == 12))
                        map[i][j] = 1;
                    else map[i][j] = 0;
                }
            }
            break;

        case 4: //Laberinto de los tres caminos
            for (i = 0; i < 15; i++) {
                for (j = 0; j < 15; j++) {
                    if (i == 0 || j == 0 || i == 14 || j == 14)
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

/* Muestra el mapa en pantalla */
void printMap(int map[15][15]) {
    printf("\nMapa (' '=libre, '#'=pared, '~'=agua):\n\n");
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            printf("%c ", showMap(map[i][j]));
        }
        printf("\n");
    }
}

/* Permite al usuario elegir entrada y salida válidas */
void chooseEntryAndExit(int map[15][15], int *entradax, int *entraday, int *salidax, int *saliday) {
    int x, y;
    
    printf("\n--- Elección de entrada ---\n");
    while (1) {
        printf("Ingrese coordenada de entrada (fila y columna entre 0 y 14): ");
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < 15 && y >= 0 && y < 15 && map[x][y] == 0) {
            *entradax = x;
            *entraday = y;
            map[x][y] = 3; // marcar entrada
            break;
        } else {
            printf("❌ Posición inválida. Debe ser una celda libre.\n");
        }
    }

    printMap(map);

    printf("\n--- Elección de salida ---\n");
    while (1) {
        printf("Ingrese coordenada de salida (fila y columna entre 0 y 14): ");
        scanf("%d %d", &x, &y);
        if (x >= 0 && x < 15 && y >= 0 && y < 15 && map[x][y] == 0) {
            *salidax = x;
            *saliday = y;
            map[x][y] = 4; // marcar salida
            break;
        } else {
            printf("❌ Posición inválida. Debe ser una celda libre.\n");
        }
    }
}

/* Programa principal */
int main() {
    int map[15][15];
    int i, j, opc;
    int ex, ey, sx, sy;

    printf("Elige el mapa que quieres probar:\n");
    printf("1. Mapa simple\n");
    printf("2. Camino serpenteante\n");
    printf("3. Camino Verticales\n");
    printf("4. El laberinto de los tres caminos\n");
    printf("Opción: ");
    scanf("%d", &opc);

    chooseMap(opc, map);
    printMap(map);

    chooseEntryAndExit(map, &ex, &ey, &sx, &sy);
    printf("\nMapa final con entrada (E) y salida (S):\n\n");

    // Reemplazamos los marcadores 3 y 4 por caracteres visibles
    for (i = 0; i < 15; i++) {
        for (j = 0; j < 15; j++) {
            if (map[i][j] == 3) printf("E ");
            else if (map[i][j] == 4) printf("S ");
            else printf("%c ", showMap(map[i][j]));
        }
        printf("\n");
    }

    printf("\nEntrada: (%d, %d)\nSalida: (%d, %d)\n", ex, ey, sx, sy);
    return 0;
}
