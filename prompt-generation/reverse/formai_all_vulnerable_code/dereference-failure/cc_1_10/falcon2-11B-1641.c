//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_IMAGE_SIZE 1000

char* read_image(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char* image = (char*)malloc(MAX_IMAGE_SIZE);
    if (image == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    fread(image, 1, MAX_IMAGE_SIZE, fp);
    fclose(fp);

    return image;
}

void convert_to_ascii(char* image) {
    for (int i = 0; i < MAX_IMAGE_SIZE; i++) {
        for (int j = 0; j < MAX_IMAGE_SIZE; j++) {
            if (image[i * MAX_IMAGE_SIZE + j] == '1') {
                printf(".");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        exit(1);
    }

    char* image = read_image(argv[1]);
    convert_to_ascii(image);

    free(image);
    return 0;
}