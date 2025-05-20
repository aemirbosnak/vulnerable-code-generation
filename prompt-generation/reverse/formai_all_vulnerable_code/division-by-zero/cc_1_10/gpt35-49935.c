//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200
#define ASCII_RANGE 256
#define CHAR_WIDTH_RATIO 0.5
#define CHAR_HEIGHT_RATIO 0.8

const char ascii_chars[ASCII_RANGE+1] = " .:-=+*#%@";

typedef struct rgb_color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} RGBColor;

int get_gray_value(RGBColor color) {
    return (int) round(0.299 * color.r + 0.587 * color.g + 0.114 * color.b);
}

int get_ascii_char_index(int gray_value) {
    int ascii_index = (int) round(gray_value * (ASCII_RANGE - 1) / 255.0);
    return ascii_index;
}

char get_ascii_char(int index) {
    return ascii_chars[index];
}

void print_ascii_art(char ascii_art[MAX_HEIGHT][MAX_WIDTH+1], int height, int width) {
    for (int i = 0; i < height; i++) {
        printf("%s\n", ascii_art[i]);
    }
}

void convert_image_to_ascii_art(RGBColor image[MAX_HEIGHT][MAX_WIDTH], char ascii_art[MAX_HEIGHT][MAX_WIDTH+1], 
                                 int height, int width, float char_width, float char_height) {
    int cell_width = (int) round(char_width);
    int cell_height = (int) round(char_height);
    
    for (int i = 0; i < height; i += cell_height) {
        for (int j = 0; j < width; j += cell_width) {
            int gray_value_sum = 0;
            for (int x = i; x < i+cell_height && x < height; x++) {
                for (int y = j; y < j+cell_width && y < width; y++) {
                    gray_value_sum += get_gray_value(image[x][y]);
                }
            }
            int gray_value_avg = (int) round(gray_value_sum / (float) (cell_width * cell_height));
            int ascii_char_index = get_ascii_char_index(gray_value_avg);
            ascii_art[i/cell_height][j/cell_width] = get_ascii_char(ascii_char_index);
        }
        ascii_art[i/cell_height][width/cell_width] = '\0';
    }
    ascii_art[height/cell_height][0] = '\0';
}

int main() {
    char filename[100];
    printf("Enter the name of the image file you would like to convert to ascii art (with .bmp extension): ");
    scanf("%s", filename);
    
    FILE* file_ptr = fopen(filename, "rb");
    if (file_ptr == NULL) {
        printf("Error: cannot open file %s\n", filename);
        return 1;
    }
    
    unsigned char* header = (unsigned char*) malloc(54);
    if (header == NULL) {
        printf("Error: cannot allocate memory for header\n");
        return 1;
    }
    
    fread(header, sizeof(unsigned char), 54, file_ptr);
    
    int width = *(int*) &header[18];
    int height = *(int*) &header[22];
    
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: image is too large\n");
        free(header);
        fclose(file_ptr);
        return 1;
    }
    
    unsigned char padding[3] = {0, 0, 0};
    int padding_size = (4 - (width * 3) % 4) % 4;
    
    RGBColor image[MAX_HEIGHT][MAX_WIDTH];
    unsigned char pixel[3];
    for (int i = height-1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            fread(pixel, sizeof(unsigned char), 3, file_ptr);
            image[i][j].b = pixel[0];
            image[i][j].g = pixel[1];
            image[i][j].r = pixel[2];
        }
        fseek(file_ptr, padding_size, SEEK_CUR);
    }
    
    fclose(file_ptr);
    free(header);
    
    char ascii_art[MAX_HEIGHT][MAX_WIDTH+1];
    memset(ascii_art, ' ', sizeof(ascii_art));
    
    float char_width = CHAR_WIDTH_RATIO * width / MAX_WIDTH;
    float char_height = CHAR_HEIGHT_RATIO * height / MAX_HEIGHT;
    
    convert_image_to_ascii_art(image, ascii_art, height, width, char_width, char_height);
    
    print_ascii_art(ascii_art, height/round(char_height), width/round(char_width));
    
    return 0;
}