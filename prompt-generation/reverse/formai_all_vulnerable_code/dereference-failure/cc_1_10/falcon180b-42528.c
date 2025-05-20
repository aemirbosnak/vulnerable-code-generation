//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

void convert_image_to_ascii(char *image_path, char *output_path) {
    FILE *input_file;
    FILE *output_file;
    unsigned char *buffer;
    int width;
    int height;
    int size;
    int x;
    int y;

    input_file = fopen(image_path, "rb");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    fseek(input_file, 0, SEEK_END);
    size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    buffer = (unsigned char *) malloc(size);
    if (buffer == NULL) {
        printf("Error: could not allocate memory.\n");
        exit(1);
    }

    fread(buffer, size, 1, input_file);
    fclose(input_file);

    output_file = fopen(output_path, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    width = height = 0;
    for (y = 0; y < MAX_WIDTH; y++) {
        for (x = 0; x < MAX_WIDTH; x++) {
            if ((x * MAX_WIDTH + y) < size) {
                if ((y % 8 == 0) && (x % 8 == 0)) {
                    if (buffer[(y * MAX_WIDTH + x)] == 0) {
                        printf("  ");
                    } else {
                        printf("* ");
                    }
                } else {
                    printf("  ");
                }
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    fclose(output_file);
    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    convert_image_to_ascii(argv[1], argv[2]);

    return 0;
}