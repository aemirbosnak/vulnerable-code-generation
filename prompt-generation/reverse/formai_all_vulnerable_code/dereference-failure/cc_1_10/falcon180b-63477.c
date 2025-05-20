//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define CHAR_SET ".:*#@"

void draw_ascii(char *image_data, int width, int height) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            printf("%c", CHAR_SET[(int)image_data[y * width + x] / 32]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    long file_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);

    char *image_data = malloc(file_size);
    if (image_data == NULL) {
        printf("Error allocating memory.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    size_t bytes_read = fread(image_data, 1, file_size, input_file);
    if (bytes_read!= file_size) {
        printf("Error reading input file.\n");
        free(image_data);
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    draw_ascii(image_data, WIDTH, HEIGHT);

    fwrite(image_data, 1, file_size, output_file);

    free(image_data);
    fclose(input_file);
    fclose(output_file);

    return 0;
}