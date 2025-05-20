//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: real-life
// C program to convert an image to ASCII art
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

void printASCII(char* filename, int width, int height, uint8_t* data) {
    FILE* fp = fopen(filename, "w");
    uint8_t* ptr = data;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            uint8_t val = *(ptr++);
            char c = ' ';
            if (val < 64) {
                c = '@';
            } else if(val < 128) {
                c = 'X';
            } else if(val < 192) {
                c = '*';
            } else if(val < 255) {
                c = '.';
            }
            fputc(c, fp);
        }
        fputc('\n', fp);
    }
    fclose(fp);
}

void convertToASCII(char* filename, char* outfile, int width, int height) {
    FILE* fp = fopen(filename, "rb");
    uint8_t* data = malloc(width * height);
    fread(data, 1, width * height, fp);
    fclose(fp);
    printASCII(outfile, width, height, data);
    free(data);
}

int main(int argc, char* argv[]) {
    if(argc != 4) {
        printf("Usage: image2ascii <infile> <outfile> <width>\n");
        exit(1);
    }
    char* infile = argv[1];
    char* outfile = argv[2];
    int width = atoi(argv[3]);
    int height = 0;
    FILE* fp = fopen(infile, "rb");
    fseek(fp, 0, SEEK_END);
    long pos = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    if(pos > width) {
        height = pos / width; 
    } else {
        printf("Error: image width is greater than input width\n");
        exit(1);
    }
    convertToASCII(infile, outfile, width, height);
    return 0;
}