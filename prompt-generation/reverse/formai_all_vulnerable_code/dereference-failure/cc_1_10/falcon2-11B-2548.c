//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert an image to ASCII art
void imageToAscii(const char *filename) {
    // open the image file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening image file: %s\n", filename);
        return;
    }

    // read the image file into memory
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    char *image = (char *)malloc(size + 1);
    fread(image, 1, size, file);
    image[size] = '\0';

    // close the image file
    fclose(file);

    // convert the image to ASCII art
    printf("Converting image to ASCII art...\n");
    int rows = strlen(image) / 80;
    int cols = 80;
    char *ascii = (char *)malloc(rows * cols * sizeof(char));
    int row = 0, col = 0;
    for (int i = 0; i < size; i++) {
        if (image[i]!= '\n') {
            ascii[row * cols + col++] = image[i];
        }
        else {
            for (int j = 0; j < cols; j++) {
                ascii[row * cols + j] = '\n';
            }
            row++;
            col = 0;
        }
    }
    ascii[row * cols] = '\0';

    // print the ASCII art
    printf("ASCII art:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", ascii[i * cols + j]);
        }
        printf("\n");
    }

    // free the memory
    free(image);
    free(ascii);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }
    imageToAscii(argv[1]);
    return 0;
}