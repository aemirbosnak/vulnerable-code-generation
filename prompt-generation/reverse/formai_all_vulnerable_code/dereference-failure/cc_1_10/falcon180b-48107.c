//Falcon-180B DATASET v1.0 Category: QR code generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10
#define MAX_VALUE 10
#define MIN_VALUE 1
#define BLACK 0
#define WHITE 1
#define ERROR -1

typedef struct {
    int width;
    int height;
    int **data;
} QrCode;

int **createQrCode(int width, int height) {
    int **data = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        data[i] = (int *)malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            data[i][j] = WHITE;
        }
    }
    return data;
}

int **generateQrCode(int width, int height, int **data) {
    int **result = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        result[i] = (int *)malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            result[i][j] = BLACK;
        }
    }

    int value = 1;
    int x = 0;
    int y = 0;
    int count = 0;

    while (count < MAX_VALUE) {
        if (value == MIN_VALUE) {
            value = MAX_VALUE;
        } else {
            value--;
        }

        if (x == 0) {
            y += 2;
        } else {
            x--;
        }

        result[y][x] = WHITE;
        count++;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (result[i][j] == BLACK) {
                result[i][j] = BLACK;
            } else {
                result[i][j] = WHITE;
            }
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            data[i][j] = result[i][j];
        }
    }

    free(result);
    return data;
}

void printQrCode(int width, int height, int **data) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (data[i][j] == BLACK) {
                printf("  ");
            } else {
                printf("██");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int width = WIDTH;
    int height = HEIGHT;
    QrCode qrCode = {width, height, NULL};
    int **data = createQrCode(width, height);
    generateQrCode(width, height, data);
    printQrCode(width, height, data);
    return 0;
}