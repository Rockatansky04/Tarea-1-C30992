#include <stdio.h>
#include <stdlib.h>

int DiagonalMasLarga(int n, int Matriz[][100]) {  
    int Max = 0;

    for (int Cols = 0; Cols < n; Cols++) {
        int i = 0, j = Cols;
        int ColsCont = 0;
        while (i < n && j >= 0) {
            if (Matriz[i][j] == 1) {
                ColsCont++;
                if (ColsCont > Max) Max = ColsCont;
            } else {
                ColsCont= 0;
            }
            i++;
            j--;
        }
    }

    for (int Fila = 1; Fila < n; Fila++) {
        int i = Fila, j = n - 1;
        int FilaCont = 0;
        while (i < n && j >= 0) {
            if (Matriz[i][j] == 1) {
                FilaCont++;
                if (FilaCont> Max) Max= FilaCont;
            } else {
                FilaCont = 0;
            }
            i++;
            j--;
        }
    }

    return Max;
}

int main() {    
    FILE *File = fopen("matriz.txt", "r"); 
    
    if (File == NULL) {
        printf("ERROR: hay problemas la abrir el archivo\n");
        return 1; 
    }

    int Matriz[100][100];
    int Rows = 0, Cols = 0;
    char Ch;
    int ColActual = 0;

    while ((Ch = fgetc(File)) != EOF) { 
        if (Ch == '0' || Ch == '1') {
            int Valor = Ch - '0'; 
            if (Valor != 0 && Valor != 1) {
                printf("Ay... la matriz no es binaria\n");
                fclose(File); 
                return 1;
            }
            Matriz[Rows][ColActual++] = Valor;
        } else if (Ch == ',' || Ch == ' ') {
            continue;
        } else if (Ch == '\n') {
            if (Rows == 0) {
                Cols = ColActual;
            } else if (ColActual != Cols) {
                printf("UPS..la matriz no es cuadrada\n");
                fclose(File);
                return 1;
            }
            Rows++;
            ColActual = 0;
        }
    }
    
    fclose(File);  

    int resultado = DiagonalMasLarga(Rows, Matriz);
    printf("La secuencia de 1s más grande es: %d\n", resultado);

    return 0;
}