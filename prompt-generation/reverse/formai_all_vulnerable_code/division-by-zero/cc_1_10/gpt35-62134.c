//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char asc_chars[] = {'@', '#', 'S', '%', '?', '*', '+', '^', ':', ',', '.', ' ', '\0'};
int MAXCHARS = 12; // number of different ASCII characters used

int compute_average_value(char* img, int width, int height);
void convert_to_ascii(char* img, int width, int height, char** ascii_img, int* ascii_width, int* ascii_height);
void print_ascii(char** ascii_img, int ascii_width, int ascii_height);

int main(int argc, char *argv[]) {
    if (argc < 2) {
      printf("USAGE: %s [image filename] \n", argv[0]);
      exit(1);
    }

    FILE *fptr;
    char ch;
    int width = 0, height = 0;
    char *img = (char*) malloc(sizeof(char));
    char temp;

    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // read image dimensions from PGM header
    while(1) {
        ch = fgetc(fptr);
        if(ch == '\n') break;
        if(ch == ' ') continue;
        temp = ch - '0';
        width = width * 10 + (int)temp;
    }

    while(1) {
        ch = fgetc(fptr);
        if(ch == '\n') break;
        if(ch == ' ') continue;
        temp = ch - '0';
        height = height * 10 + (int)temp;
    }

    // discard max grey value
    fgets(img, 1000, fptr);

    // read image data
    img = (char*) malloc(sizeof(char) * width * height);
    fread(img, sizeof(char), width * height, fptr);
    fclose(fptr);

    int avg_value = compute_average_value(img, width, height);

    char** ascii_img = (char**) malloc(sizeof(char*) * height);
    int ascii_width, ascii_height;

    convert_to_ascii(img, width, height, ascii_img, &ascii_width, &ascii_height);

    print_ascii(ascii_img, ascii_width, ascii_height);

    return 0;
}

int compute_average_value(char* img, int width, int height) {
    int sum_value = 0;

    for (int i = 0; i < width * height; i++) {
        sum_value += (int) img[i];
    }

    int avg_value = sum_value / (width * height);

    return avg_value;
}

void convert_to_ascii(char* img, int width, int height, char** ascii_img, int* ascii_width, int* ascii_height) {
    *ascii_width = width / 4; // 4 pixels will correspond to 1 ASCII character
    *ascii_height = height / 8;

    // allocate memory for the ASCII image
    for (int i = 0; i < *ascii_height; i++) {
        ascii_img[i] = (char*) malloc(sizeof(char) * (*ascii_width));
    }

    // convert each 4x8 block of pixels to an ASCII character
    int avg_value;
    int index = 0;
    for (int i = 0; i < height; i += 8) {
        for (int j = 0; j < width; j += 4) {
            avg_value = 0;
            for (int k = i; k < i + 8; k++) {
                for (int l = j; l < j + 4; l++) {
                    avg_value += (int) img[k * width + l];
                }
            }
            avg_value /= 32;
            ascii_img[i / 8][j / 4] = asc_chars[(MAXCHARS - 1) * avg_value / 255];
        }
    }
}

void print_ascii(char** ascii_img, int ascii_width, int ascii_height) {
    for (int i = 0; i < ascii_height; i++) {
        for (int j = 0; j < ascii_width; j++) {
            printf("%c", ascii_img[i][j]);
        }
        printf("\n");
    }
}