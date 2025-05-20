//Falcon2-11B DATASET v1.0 Category: QR code generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 8
#define HEIGHT 8

void generate_qrcode(char *data, int width, int height) {
    int i, j;
    char buffer[HEIGHT][WIDTH];
    char *ptr;

    // fill black
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            buffer[i][j] = '0';
        }
    }

    // fill data
    for (i = 0; i < height; i++) {
        ptr = &data[i * width];
        for (j = 0; j < width; j++) {
            buffer[i][j] = *ptr;
            ptr++;
        }
    }

    // draw white
    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            buffer[i][j] = '1';
            buffer[i][j + width / 2] = '1';
        }
    }

    // print qrcode
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", buffer[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char data[] = "Hello World";
    int width = WIDTH;
    int height = HEIGHT;

    generate_qrcode(data, width, height);

    return 0;
}