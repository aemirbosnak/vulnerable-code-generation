//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void generate_watermark(char* watermark, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        watermark[i] = rand() % 26 + 'a';
    }
    watermark[size] = '\0';
}

void apply_watermark(char* image, char* watermark, int size) {
    for (int i = 0; i < strlen(image); i++) {
        if (i % size == 0) {
            image[i] = watermark[i / size];
        }
    }
}

void detect_watermark(char* image, char* watermark, int size) {
    for (int i = 0; i < strlen(image); i++) {
        if (i % size == 0) {
            if (image[i]!= watermark[i / size]) {
                printf("Watermark not found!\n");
                exit(1);
            }
        }
    }
    printf("Watermark found!\n");
}

int main() {
    char* image = (char*)malloc(MAX_SIZE * sizeof(char));
    char* watermark = (char*)malloc(MAX_SIZE * sizeof(char));

    printf("Enter image data: ");
    fgets(image, MAX_SIZE, stdin);

    printf("Enter watermark: ");
    fgets(watermark, MAX_SIZE, stdin);

    int size = strlen(image) / strlen(watermark);

    generate_watermark(watermark, size);
    apply_watermark(image, watermark, size);

    printf("Watermarked image: %s\n", image);

    detect_watermark(image, watermark, size);

    free(image);
    free(watermark);

    return 0;
}