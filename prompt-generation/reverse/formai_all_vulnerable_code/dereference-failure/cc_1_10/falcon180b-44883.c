//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1024
#define KEY_SIZE 16
#define BLOCK_SIZE 8

void encrypt(unsigned char* data, int size, unsigned char* key) {
    int i, j;
    for (i = 0; i < size; i++) {
        if (i % BLOCK_SIZE == 0) {
            srand(time(NULL));
            key[i / BLOCK_SIZE] = rand() % 256;
        }
        data[i] ^= key[i / BLOCK_SIZE];
    }
}

void decrypt(unsigned char* data, int size, unsigned char* key) {
    int i, j;
    for (i = 0; i < size; i++) {
        if (i % BLOCK_SIZE == 0) {
            key[i / BLOCK_SIZE] = rand() % 256;
        }
        data[i] ^= key[i / BLOCK_SIZE];
    }
}

int main() {
    FILE* fp;
    char filename[50];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char* data = (unsigned char*) malloc(size);
    fread(data, 1, size, fp);
    fclose(fp);

    unsigned char* key = (unsigned char*) malloc(KEY_SIZE);
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }

    encrypt(data, size, key);

    fp = fopen("encrypted.bmp", "wb");
    if (fp == NULL) {
        printf("Error: Cannot create output file.\n");
        exit(1);
    }

    fwrite(data, 1, size, fp);
    fclose(fp);

    printf("Steganography complete.\n");

    free(data);
    free(key);

    return 0;
}