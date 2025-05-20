//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 4 // the size of each block
#define MAX_PIXEL_VALUE 255 // the maximum pixel value
#define ASCII_CHARS "@#8%*o=:.- " // list of ASCII characters sorted by intensity

// function to convert the brightness value of a pixel to an ASCII character
char brightness_to_char(int brightness) {
    int char_index = (int)(brightness / (MAX_PIXEL_VALUE / strlen(ASCII_CHARS)));
    return ASCII_CHARS[char_index];
}

// function to convert an image to ASCII art
void image_to_ascii(char *input_filename, char *output_filename) {
    // open the input file
    FILE *input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error: can't open input file.\n");
        exit(EXIT_FAILURE);
    }

    // open the output file
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: can't open output file.\n");
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    // read the dimensions of the image
    char header[50];
    fgets(header, 50, input_file);
    int width, height;
    sscanf(header, "P6\n%d %d\n%d", &width, &height);

    // allocate memory for the image data
    unsigned char *data = (unsigned char *)malloc(width * height * 3);

    // read the image data
    fread(data, sizeof(unsigned char), width * height * 3, input_file);

    // convert the image to ASCII art
    for (int y = 0; y < height; y += BLOCK_SIZE) {
        for (int x = 0; x < width; x += BLOCK_SIZE) {
            // calculate the average brightness value of the block
            int sum_brightness = 0;
            for (int dy = 0; dy < BLOCK_SIZE; dy++) {
                for (int dx = 0; dx < BLOCK_SIZE; dx++) {
                    int index = ((y + dy) * width + (x + dx)) * 3;
                    sum_brightness += (int)data[index];
                }
            }
            int avg_brightness = sum_brightness / (BLOCK_SIZE * BLOCK_SIZE);

            // convert the brightness value to an ASCII character
            char ascii_char = brightness_to_char(avg_brightness);

            // write the ASCII character to the output file
            fputc(ascii_char, output_file);
        }
        fputc('\n', output_file);
    }

    // free the memory and close the files
    free(data);
    fclose(input_file);
    fclose(output_file);
}

int main() {
    // convert an image to ASCII art
    char *input_filename = "input_image.ppm";
    char *output_filename = "output_image.txt";
    image_to_ascii(input_filename, output_filename);
    printf("Image converted to ASCII art.\n");

    return 0;
}