//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

char ascii_art[HEIGHT][WIDTH];

void generate_ascii_art(char* image_data) {
    int x = 0, y = 0, i = 0;
    while (image_data[i]!= '\0') {
        if (image_data[i] == '\n') {
            x = 0;
            y++;
        } else {
            ascii_art[y][x] = image_data[i];
            x++;
        }
        i++;
    }
}

void print_ascii_art() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <image_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error: Unable to open image file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char* image_data = (char*) malloc(file_size + 1);
    if (image_data == NULL) {
        printf("Error: Unable to allocate memory for image data.\n");
        fclose(fp);
        return 1;
    }

    fread(image_data, file_size, 1, fp);
    image_data[file_size] = '\0';
    fclose(fp);

    generate_ascii_art(image_data);

    FILE* output_fp = fopen(argv[2], "w");
    if (output_fp == NULL) {
        printf("Error: Unable to open output file.\n");
        free(image_data);
        return 1;
    }

    fprintf(output_fp, "%s", ascii_art[0]);
    for (int i = 1; i < HEIGHT; i++) {
        fprintf(output_fp, "\n%s", ascii_art[i]);
    }

    fclose(output_fp);
    free(image_data);

    printf("ASCII art generated successfully!\n");

    return 0;
}