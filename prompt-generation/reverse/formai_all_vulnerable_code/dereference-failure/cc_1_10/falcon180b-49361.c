//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to read QR code from file
void read_qr_code(char *filename) {
    FILE *fp;
    int width, height, i, j;
    int **matrix;
    char ch;

    // open file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // read file header
    fscanf(fp, "P%d\n%d %d\n", &width, &height);

    // allocate memory for matrix
    matrix = (int **)malloc(height * sizeof(int *));
    for (i = 0; i < height; i++) {
        matrix[i] = (int *)malloc(width * sizeof(int));
    }

    // read QR code data
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fscanf(fp, "%c", &ch);
            if (ch == '1') {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }

    // close file
    fclose(fp);

    // print QR code data
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (matrix[i][j] == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    // free memory for matrix
    for (i = 0; i < height; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    char filename[100];

    // get QR code file name from user
    printf("Enter QR code file name: ");
    scanf("%s", filename);

    // read QR code from file
    read_qr_code(filename);

    return 0;
}