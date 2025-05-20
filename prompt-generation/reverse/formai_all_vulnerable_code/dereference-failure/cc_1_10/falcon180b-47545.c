//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 24
#define CHAR_SET "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+-={}[];:,.<>?/|\\"

// Function to print the ASCII art
void print_ascii_art(char *ascii_art) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", ascii_art[i * WIDTH + j]);
        }
        printf("\n");
    }
}

// Function to convert image to ASCII art
void image_to_ascii_art(char *filename, char *ascii_art) {
    FILE *fp;
    int i, j, k, l;
    unsigned char pixel;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }
    fseek(fp, 54, SEEK_SET); // Skip header
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            k = 0;
            l = 0;
            fread(&pixel, 1, 1, fp);
            while (pixel == 0) {
                fread(&pixel, 1, 1, fp);
                k++;
            }
            while (pixel == 255) {
                fread(&pixel, 1, 1, fp);
                l++;
            }
            ascii_art[i * WIDTH + j] = CHAR_SET[k % 62];
        }
    }
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }
    char input_filename[100], output_filename[100];
    strcpy(input_filename, argv[1]);
    strcpy(output_filename, argv[2]);
    char *ascii_art = malloc(HEIGHT * WIDTH);
    image_to_ascii_art(input_filename, ascii_art);
    FILE *fp;
    fp = fopen(output_filename, "wb");
    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", output_filename);
        exit(1);
    }
    fwrite(ascii_art, 1, HEIGHT * WIDTH, fp);
    fclose(fp);
    printf("ASCII art saved to %s\n", output_filename);
    return 0;
}