//Falcon-180B DATASET v1.0 Category: QR code reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024 // maximum size of QR code image
#define BLACK 0 // black color
#define WHITE 1 // white color

// function to read QR code image and return decoded data
char* readQRCode(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    unsigned char* buffer = (unsigned char*) malloc(MAX_SIZE);
    unsigned char* p = buffer;
    unsigned int size = 0;

    while (fread(p, 1, 1, fp) == 1) {
        if (size >= MAX_SIZE) {
            printf("Error: QR code image too large\n");
            exit(1);
        }
        if (*p == 0) { // black pixel
            if (size > 0 && buffer[size - 1] == WHITE) {
                buffer[size - 1] = BLACK;
            }
        } else { // white pixel
            if (size > 0 && buffer[size - 1] == BLACK) {
                buffer[size - 1] = WHITE;
            }
        }
        p++;
        size++;
    }

    fclose(fp);

    char* data = (char*) malloc(MAX_SIZE);
    size = 0;
    int i, j;

    for (i = 0; i < size; i++) {
        if (buffer[i] == BLACK) {
            for (j = 0; j < 8; j++) {
                data[size] = (buffer[i + j] == BLACK)? 1 : 0;
                size++;
            }
        }
    }

    return data;
}

// main function
int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <QR code image file>\n", argv[0]);
        exit(1);
    }

    char* data = readQRCode(argv[1]);
    printf("Decoded data: %s\n", data);

    free(data);
    return 0;
}