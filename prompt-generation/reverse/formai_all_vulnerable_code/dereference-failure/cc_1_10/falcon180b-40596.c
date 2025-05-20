//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ARRAY_SIZE 1024

char *convert_to_ascii(char *input_file, char *output_file) {
    FILE *input_stream = fopen(input_file, "rb");
    FILE *output_stream = fopen(output_file, "w");

    if (input_stream == NULL || output_stream == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int image_size = 0;
    char *image_data = NULL;

    fseek(input_stream, 0, SEEK_END);
    image_size = ftell(input_stream);
    rewind(input_stream);

    image_data = malloc(image_size);

    if (fread(image_data, image_size, 1, input_stream)!= 1) {
        printf("Error reading file.\n");
        exit(1);
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < image_size) {
        if (j == ARRAY_SIZE) {
            fprintf(output_stream, "\n");
            j = 0;
        }

        if (image_data[i] == 0) {
            fprintf(output_stream, " ");
        } else {
            fprintf(output_stream, "#");
        }

        i++;
        j++;
    }

    fclose(input_stream);
    fclose(output_stream);

    return output_file;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    char *output_file = convert_to_ascii(argv[1], argv[2]);

    printf("Conversion complete.\n");
    printf("Output file: %s\n", output_file);

    return 0;
}