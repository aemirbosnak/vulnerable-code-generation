//GEMINI-pro DATASET v1.0 Category: QR code generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Mind-bending constants
#define MATRIX_SIZE 21
#define PIXEL_PRECISION 10000
#define PIXEL_SIZE 1
#define MAX_CODE_LENGTH 100

// QR code modules
typedef struct QRModule {
    int x;
    int y;
    int state; // 0 = white, 1 = black
} QRModule;

// QR code data
typedef struct QRData {
    char *text;
    int length;
} QRData;

// Function prototypes
QRModule **createMatrix(int size);
void destroyMatrix(QRModule **matrix, int size);
void printMatrix(QRModule **matrix, int size);
QRData *createData(char *text);
void destroyData(QRData *data);
void encodeData(QRModule **matrix, int size, QRData *data);
void drawQRCode(QRModule **matrix, int size);

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the QR code matrix
    QRModule **matrix = createMatrix(MATRIX_SIZE);

    // Create the QR code data
    QRData *data = createData("Hello, world!");

    // Encode the data into the matrix
    encodeData(matrix, MATRIX_SIZE, data);

    // Draw the QR code
    drawQRCode(matrix, MATRIX_SIZE);

    // Destroy the QR code matrix and data
    destroyMatrix(matrix, MATRIX_SIZE);
    destroyData(data);

    return 0;
}

// Function to create a QR code matrix
QRModule **createMatrix(int size) {
    QRModule **matrix = (QRModule **)malloc(sizeof(QRModule *) * size);
    for (int i = 0; i < size; i++) {
        matrix[i] = (QRModule *)malloc(sizeof(QRModule) * size);
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j].x = i;
            matrix[i][j].y = j;
            matrix[i][j].state = 0;
        }
    }
    return matrix;
}

// Function to destroy a QR code matrix
void destroyMatrix(QRModule **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to print a QR code matrix
void printMatrix(QRModule **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j].state);
        }
        printf("\n");
    }
}

// Function to create QR code data
QRData *createData(char *text) {
    QRData *data = (QRData *)malloc(sizeof(QRData));
    data->text = (char *)malloc(sizeof(char) * (strlen(text) + 1));
    strcpy(data->text, text);
    data->length = strlen(text);
    return data;
}

// Function to destroy QR code data
void destroyData(QRData *data) {
    free(data->text);
    free(data);
}

// Function to encode data into a QR code matrix
void encodeData(QRModule **matrix, int size, QRData *data) {
    // Check if the data is too long
    if (data->length > MAX_CODE_LENGTH) {
        printf("Error: data is too long\n");
        exit(1);
    }

    // Convert the data to a bitstream
    int bitstream[data->length * 8];
    for (int i = 0; i < data->length; i++) {
        for (int j = 0; j < 8; j++) {
            bitstream[i * 8 + j] = (data->text[i] >> j) & 1;
        }
    }

    // Encode the bitstream into the matrix
    int x = size - 1;
    int y = size - 1;
    int direction = -1;
    for (int i = 0; i < data->length * 8; i++) {
        // Place the bit in the matrix
        matrix[x][y].state = bitstream[i];

        // Move to the next position
        if (direction == -1) {
            x--;
        } else if (direction == 1) {
            x++;
        } else if (direction == 2) {
            y--;
        } else if (direction == 3) {
            y++;
        }

        // Change direction if necessary
        if (x < 0 || x >= size || y < 0 || y >= size || matrix[x][y].state != 0) {
            direction = (direction + 1) % 4;
            if (direction == 0) {
                x++;
            } else if (direction == 2) {
                y++;
            }
        }
    }

    // Add finder patterns
    for (int i = 0; i < 7; i++) {
        matrix[i][i].state = 1;
        matrix[i][size - 1 - i].state = 1;
        matrix[size - 1 - i][i].state = 1;
    }

    // Add alignment patterns
    for (int i = 0; i < size; i += 10) {
        for (int j = 0; j < size; j += 10) {
            matrix[i][j].state = 1;
            matrix[i][j + 1].state = 1;
            matrix[i][j + 2].state = 1;
            matrix[i + 1][j].state = 1;
            matrix[i + 1][j + 1].state = 0;
            matrix[i + 1][j + 2].state = 1;
            matrix[i + 2][j].state = 1;
            matrix[i + 2][j + 1].state = 1;
            matrix[i + 2][j + 2].state = 1;
        }
    }

    // Add timing patterns
    for (int i = 8; i < size - 8; i++) {
        matrix[i][6].state = 1;
        matrix[6][i].state = 1;
    }

    // Add version information
    for (int i = 0; i < 6; i++) {
        matrix[i][8].state = 1;
        matrix[i][8 + 1].state = 1;
        matrix[i][8 + 2].state = 1;
        matrix[8][i].state = 1;
        matrix[8 + 1][i].state = 1;
        matrix[8 + 2][i].state = 1;
    }

    // Add format information
    for (int i = 0; i < 5; i++) {
        matrix[i][9].state = 1;
        matrix[i][9 + 1].state = 1;
        matrix[i][9 + 2].state = 1;
        matrix[9][i].state = 1;
        matrix[9 + 1][i].state = 1;
        matrix[9 + 2][i].state = 1;
    }
}

// Function to draw a QR code
void drawQRCode(QRModule **matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j].state == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}