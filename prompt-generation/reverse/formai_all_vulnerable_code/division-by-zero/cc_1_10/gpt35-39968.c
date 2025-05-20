//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: inquisitive
// Welcome to the Image to ASCII art converter program!
// This program takes in an image file and converts it into ASCII art.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the size of the ASCII art output (adjust to your liking)
#define WIDTH 120
#define HEIGHT 60

// Define the brightness threshold for each ASCII character (adjust to your liking)
#define THRESHOLD_1 25
#define THRESHOLD_2 50
#define THRESHOLD_3 75
#define THRESHOLD_4 100

// Define the ASCII characters to use (adjust to your liking)
const char ASCIIS[] = ".:-=+*#%@";

// Function to load image file
unsigned char* load_image(char* filename, int* width, int* height) {
    FILE* f = fopen(filename, "rb");
    if (!f) {
        perror("Error opening file.");
        exit(1);
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, f);
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    int padding = 0;
    while ((*width * 3 + padding) % 4 != 0) {
        padding++;
    }

    int size = (*width * 3 + padding) * *height;
    unsigned char* data = (unsigned char*)malloc(size);
    fread(data, sizeof(unsigned char), size, f);
    fclose(f);

    return data;
}

// Function to convert RGB to grayscale
unsigned char* to_grayscale(unsigned char* data, int width, int height) {
    int i, j, k;
    unsigned char* grayscale = (unsigned char*)malloc(width * height);
    unsigned char r, g, b;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            k = (i * width + j) * 3;
            r = data[k];
            g = data[k + 1];
            b = data[k + 2];
            grayscale[i * width + j] = 0.2126 * r + 0.7152 * g + 0.0722 * b;
        }
    }

    free(data);
    return grayscale;
}

// Function to create ASCII art from grayscale image data
char* to_ascii(unsigned char* grayscale, int width, int height) {
    int i, j, index;
    char* ascii = (char*)malloc(WIDTH * HEIGHT);
    int x_scale = ceil((float)width / WIDTH);
    int y_scale = ceil((float)height / HEIGHT);

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            index = (i * WIDTH + j);
            int x = j * x_scale;
            int y = i * y_scale;
            int sum = 0;

            for (int k = 0; k < y_scale; k++) {
                for (int l = 0; l < x_scale; l++) {
                    int grayscale_index = ((y + k) * width + (x + l));
                    if (grayscale_index < width * height) {
                        sum += grayscale[grayscale_index];
                    }
                }
            }

            int average = sum / (x_scale * y_scale);
            if (average < THRESHOLD_1) {
                ascii[index] = ASCIIS[0];
            }
            else if (average < THRESHOLD_2) {
                ascii[index] = ASCIIS[1];
            }
            else if (average < THRESHOLD_3) {
                ascii[index] = ASCIIS[2];
            }
            else if (average < THRESHOLD_4) {
                ascii[index] = ASCIIS[3];
            }
            else if (average < 125) {
                ascii[index] = ASCIIS[4];
            }
            else if (average < 150) {
                ascii[index] = ASCIIS[5];
            }
            else if (average < 175) {
                ascii[index] = ASCIIS[6];
            }
            else if (average < 200) {
                ascii[index] = ASCIIS[7];
            }
            else if (average < 225) {
                ascii[index] = ASCIIS[8];
            }
            else if (average < THRESHOLD_4) {
                ascii[index] = ASCIIS[9];
            }
            else {
                ascii[index] = ASCIIS[10];
            }
        }
        ascii[(i + 1) * WIDTH - 1] = '\n';
    }

    ascii[WIDTH * HEIGHT - 1] = '\0';
    free(grayscale);
    return ascii;
}

int main(int argc, char** argv) {
    // Check command line arguments
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    // Load image file
    int width, height;
    unsigned char* data = load_image(argv[1], &width, &height);
    printf("Successfully loaded image file %s with size %dx%d.\n", argv[1], width, height);

    // Convert to grayscale
    unsigned char* grayscale = to_grayscale(data, width, height);
    printf("Successfully converted image to grayscale.\n");

    // Convert to ASCII art
    char* ascii = to_ascii(grayscale, width, height);
    printf("Successfully converted image to ASCII art:\n%s", ascii);

    free(ascii);
    return 0;
}