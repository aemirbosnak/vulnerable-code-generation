//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000 // maximum size of input image file
#define ASCII_CHARS "@B%8WM#*oahkbdpwmZO0QRYCLc1J" // list of ASCII characters

char to_ascii_pixels(int r, int g, int b, int alpha);
void convert_image_to_ascii(char *input_image, char *output_file, int width, int height);
void remove_newline(char *str);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./ascii_converter input_file output_file width\n");
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    int width = atoi(argv[3]);
    int height = 0;

    FILE *fp = fopen(input_file, "rb");

    if (fp == NULL) {
        printf("Error: unable to open file '%s'", input_file);
        return 1;
    }

    fseek(fp, 0L, SEEK_END);

    int file_size = ftell(fp);

    if (file_size > MAX_SIZE) {
        printf("Error: file size too large (max size %d bytes)", MAX_SIZE);
        fclose(fp);
        return 1;
    }

    fseek(fp, 0L, SEEK_SET);

    char image_data[MAX_SIZE];

    fread(image_data, sizeof(char), MAX_SIZE, fp);

    fclose(fp);

    height = (file_size / width) + 1;

    convert_image_to_ascii(image_data, output_file, width, height);

    return 0;
}

char to_ascii_pixels(int r, int g, int b, int alpha) {
    int gray_scale = (r + g + b) / 3;
    int num_chars = strlen(ASCII_CHARS);
    int index = ((num_chars - 1) * gray_scale) / 255;
    return ASCII_CHARS[index];
}

void convert_image_to_ascii(char *input_image, char *output_file, int width, int height) {
    FILE *fp = fopen(output_file, "w");

    if (fp == NULL) {
        printf("Error: unable to open file '%s'", output_file);
        return;
    }

    for (int h = 0; h < height; h++) {
        for (int w = 0; w < width; w++) {
            int index = (h * width * 4) + (w * 4);
            int r = input_image[index];
            int g = input_image[index + 1];
            int b = input_image[index + 2];
            int alpha = input_image[index + 3];

            char pixel = to_ascii_pixels(r, g, b, alpha);
            fprintf(fp, "%c", pixel);
        }

        fprintf(fp, "\n");
    }

    fclose(fp);

    printf("Converted image to ASCII art and saved to '%s'\n", output_file);
}

void remove_newline(char *str) {
    char *pos = strchr(str, '\n');
    if (pos != NULL)
        *pos = '\0';
}