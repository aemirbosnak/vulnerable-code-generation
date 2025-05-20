//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum size of the output image
#define MAX_SIZE 1000

// define the ASCII characters to use for the conversion
char ascii_chars[] = " .,-:;i1tfLCG08@";
int num_chars = sizeof(ascii_chars) - 1;

// function to convert an image to ASCII art recursively
void image_to_ascii(char img[MAX_SIZE][MAX_SIZE], int width, int height, char ascii[MAX_SIZE][MAX_SIZE], int x, int y, int scale) {
    // check if we've reached the end of the image
    if (x >= width || y >= height) {
        return;
    }
    
    // calculate the average pixel value in the current area
    int sum = 0;
    for (int i = x; i < x + scale && i < width; i++) {
        for (int j = y; j < y + scale && j < height; j++) {
            sum += img[j][i];
        }
    }
    int average = sum / (scale * scale);
    
    // calculate the appropriate ASCII character for the pixel
    int char_index = (num_chars - 1) * average / 255;
    ascii[y][x] = ascii_chars[char_index];
    
    // recursively convert the rest of the image
    image_to_ascii(img, width, height, ascii, x + scale, y, scale);
    image_to_ascii(img, width, height, ascii, x, y + scale, scale);
    image_to_ascii(img, width, height, ascii, x + scale, y + scale, scale);
}

int main() {
    // define the input and output file paths
    char input_path[100];
    char output_path[100];
    printf("Enter the path of the input image: ");
    scanf("%s", input_path);
    printf("Enter the path of the output file: ");
    scanf("%s", output_path);
    
    // load the input image
    FILE* fp = fopen(input_path, "rb");
    if (!fp) {
        printf("Error: unable to open input file.\n");
        return 1;
    }
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);
    int width = *(int*)&header[18];
    int height = abs(*(int*)&header[22]);
    int depth = *(int*)&header[28];
    if (depth != 24) {
        printf("Error: invalid input image format.\n");
        return 1;
    }
    char img[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char pixel[3];
            fread(pixel, sizeof(unsigned char), 3, fp);
            img[i][j] = 0.3 * pixel[0] + 0.59 * pixel[1] + 0.11 * pixel[2];
        }
    }
    fclose(fp);
    
    // convert the image to ASCII art
    char ascii[MAX_SIZE][MAX_SIZE];
    int scale = 8;
    image_to_ascii(img, width, height, ascii, 0, 0, scale);
    
    // save the output file
    FILE* output = fopen(output_path, "w");
    if (!output) {
        printf("Error: unable to open output file.\n");
        return 1;
    }
    for (int i = 0; i < height / scale; i++) {
        for (int j = 0; j < width / scale; j++) {
            fputc(ascii[i * scale][j * scale], output);
        }
        fputc('\n', output);
    }
    fclose(output);
    
    printf("Image conversion complete.\n");
    return 0;
}