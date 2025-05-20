//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80

// FUNCTION PROTOTYPES
char calculate_pixel_char(unsigned char*, int, int, int);
void convert_image_to_ascii(char*, unsigned char*, int, int, int, int, int);
void print_ascii_image(char*, int);

int main(int argc, char* argv[]) {
    // INPUT VALIDATION
    if(argc != 7) {
        printf("USAGE: ./asciiconverter [input image] [image width] [image height] [color channels] [background color] [foreground color]\n");
        exit(EXIT_FAILURE);
    }

    // PARSE COMMAND-LINE ARGUMENTS
    char* input_file = argv[1];
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);
    int channels = atoi(argv[4]);
    char* bg_color = argv[5];
    char* fg_color = argv[6];

    // OPEN INPUT FILE
    FILE *fp = fopen(input_file, "rb");
    if(fp == NULL) {
        printf("ERROR: Failed to open input file.\n");
        exit(EXIT_FAILURE);
    }

    // DETERMINE SIZE OF INPUT FILE
    fseek(fp, 0L, SEEK_END);
    long int file_size = ftell(fp);
    rewind(fp);

    // READ IMAGE DATA FROM INPUT FILE
    unsigned char *image_data = (unsigned char*) malloc(file_size);
    fread(image_data, sizeof(unsigned char), file_size, fp);
    fclose(fp);

    // CONVERT IMAGE TO ASCII ART
    char ascii_image[MAX_WIDTH * height];
    convert_image_to_ascii(ascii_image, image_data, width, height, channels, bg_color, fg_color);
    free(image_data);

    // PRINT ASCII ART IN CONSOLE
    print_ascii_image(ascii_image, height);

    return 0;
}

// FUNCTION TO CALCULATE CHARACTER FOR A GIVEN PIXEL
char calculate_pixel_char(unsigned char* image_data, int width, int x, int y) {
    unsigned char r,g,b;
    switch(width) {
        case 3:
            r = image_data[y * width + x * 3 + 0];
            g = image_data[y * width + x * 3 + 1];
            b = image_data[y * width + x * 3 + 2];
            break;
        case 4:
            r = image_data[y * width + x * 4 + 1];
            g = image_data[y * width + x * 4 + 2];
            b = image_data[y * width + x * 4 + 3];
            break;
        default:
            printf("ERROR: Unexpected number of color channels.\n");
            exit(EXIT_FAILURE);
    }

    // STATISTICAL CONVERSION TO ASCII CHARACTERS
    int avg_value = (r + g + b) / 3;
    if(avg_value < 25) return '@';
    else if(avg_value < 50) return '#';
    else if(avg_value < 75) return '8';
    else if(avg_value < 100) return '&';
    else if(avg_value < 125) return 'o';
    else if(avg_value < 150) return ':';
    else if(avg_value < 175) return '*';
    else if(avg_value < 200) return '.';
    else if(avg_value < 225) return ' ';
    else return ' ';
}

// FUNCTION TO CONVERT IMAGE DATA TO ASCII ART
void convert_image_to_ascii(char* ascii_image, unsigned char* image_data, int width, int height, int channels, int bg_color, int fg_color) {
    int x,y;
    for(y=0;y<height;y++) {
        for(x=0;x<MAX_WIDTH;x++) {
            if(x < width) {
                char pixel_char = calculate_pixel_char(image_data, channels, x, y);
                ascii_image[y * MAX_WIDTH + x] = pixel_char;
            } else {
                ascii_image[y * MAX_WIDTH + x] = '\n';
            }
        }
    }
}

// FUNCTION TO PRINT ASCII ART IMAGE TO CONSOLE
void print_ascii_image(char* ascii_image, int height) {
    int x,y;
    for(y=0;y<height;y++) {
        for(x=0;x<MAX_WIDTH;x++) {
            printf("%c", ascii_image[y * MAX_WIDTH + x]);
        }
    }
}