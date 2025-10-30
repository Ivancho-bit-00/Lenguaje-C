#include <stdio.h>

 /* Función que convierte número a carácter para imprimir*/
char showMap(int tipo){
    switch(tipo) {
        case 0: return ' ';  // libre
        case 1: return '#';  // pared
        case 2: return '~';  // agua, por ejemplo
        default: return '?'; // desconocido
    }
}


void chooseMap(int eleccion, int map[15][15]){
    int i, j;
    switch (eleccion)
    {
        
        case 1:  //Mapa 1
            /* Inicializar los bordes del mapa como paredes (1) y el resto como libre (0) */
            for(i=0; i<15; i++){
                for(j=0; j<15; j++){
                    if(j==0 || i == 0 || j==14 || i==14){
                        map[i][j] = 1;
                    }
                    else if((i>=3 && i<=11) && (j==1 || j==3 || j==4 || j==6 || j==7 || j==8 || j==10 || j==11 || j==13)){
                        map[i][j] = 1;
                    }
                    else map[i][j] = 0;
                }
            }
            map[3][2] = 1; map[3][12] = 1;
            break;

        case 2:  //Mapa 2
            for(i=0; i<15; i++){
                for(j=0; j<15; j++){
                    if(i==0 || j==0 || i==14 || j==14) map[i][j] = 1; // bordes
                    else map[i][j] = 0;
                }
            }

            // paredes internas
            for(i=2; i<13; i++) map[i][3] = 1;
            for(i=1; i<12; i++) map[i][7] = 1;
            for(i=3; i<14; i++) map[i][10] = 1;

            // huecos (pasadizos)
            map[4][3] = 0;
            map[7][7] = 0;
            map[10][10] = 0;

            // agua (atajos difíciles)
            map[2][5] = 2;
            map[8][6] = 2;
            map[11][9] = 2;

            // entrada y salida
            map[1][0] = 0; // entrada izquierda
            map[13][14] = 0; // salida derecha
            break;
            
        case 3:  // Camino Verticales
            for (i = 0; i < 15; i++) {
                for (j = 0; j < 15; j++) {
                    if (i == 0 || j == 0 || i == 14 || j == 14)
                        map[i][j] = 1; // bordes
                    else if ((i >= 3 && i <= 11) && (j == 3 || j == 6 || j == 9 || j == 12))
                        map[i][j] = 1; // columnas de paredes internas
                    else
                        map[i][j] = 0;
                }
            }
            // Entrada y salida
            map[7][0] = 0;   // entrada izquierda
            map[7][14] = 0;  // salida derecha
            break;

        case 4:
            for (i = 0; i < 15; i++) {
                for (j = 0; j < 15; j++) {
                    // Bordes del mapa
                    if (i == 0 || j == 0 || i == 14 || j == 14)
                        map[i][j] = 1;
                    else
                        map[i][j] = 0;
                }
            }

            // Bloques de paredes para formar zonas
            for (j = 2; j <= 12; j++) map[2][j] = 1;
            for (j = 3; j <= 13; j++) map[4][j] = 1;
            for (j = 1; j <= 11; j++) map[6][j] = 1;
            for (j = 2; j <= 12; j++) map[8][j] = 1;
            for (j = 3; j <= 13; j++) map[10][j] = 1;
            for (j = 1; j <= 11; j++) map[12][j] = 1;

            // Aberturas para los pasadizos
            map[2][3] = 0; map[2][8] = 0; map[2][12] = 0;
            map[4][5] = 0; map[4][10] = 0; 
            map[6][2] = 0; map[6][7] = 0; map[6][11] = 0;
            map[8][4] = 0; map[8][9] = 0; map[8][12] = 0;
            map[10][6] = 0; map[10][10] = 0;
            map[12][3] = 0; map[12][8] = 0; map[12][12] = 0;

            // Zonas de agua (atajos)
            map[5][7] = 2;
            map[7][5] = 2;
            map[9][9] = 2;
            map[11][4] = 2;

            // Entrada y salida
            map[7][0] = 0;   // entrada izquierda
            map[7][14] = 0;  // salida derecha        
            break;
    }
}
int main(){

    int map[15][15];
    int i, j, opc;
    printf("Elige el mapa que quieres probar: \n");
    printf("1_Mapa simple \n");
    printf("2_Camino serpenteante \n");
    printf("3_Camino Verticales \n");
    printf("4_El laberinto de los tres caminos \n");
    scanf("%d", &opc);
    chooseMap(opc, map);
    


    printf("Mapa ( ' '= libre, '#'= pared, '~'= agua):\n");
    for(i = 0; i < 15; ++i){
        for(j = 0; j < 15; ++j){
            /* usar formato "%d" para imprimir un entero */
            printf("%c ", showMap(map[i][j]));
        }
        printf("\n");
    }

    return(0);
}