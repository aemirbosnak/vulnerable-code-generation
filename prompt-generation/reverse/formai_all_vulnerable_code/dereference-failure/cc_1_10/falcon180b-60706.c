//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_CHARS 1000

char input_file[100] = "input.bmp";
char output_file[100] = "output.txt";

unsigned char header[54];
unsigned char* data;
int width, height, size, channels;

void read_bmp(char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'.\n", filename);
        exit(1);
    }

    fread(header, 1, 54, fp);

    width = *(int*)&header[18];
    height = *(int*)&header[22];
    size = width * height;
    channels = *(int*)&header[28];

    if (channels!= 3) {
        printf("Error: unsupported number of channels (%d).\n", channels);
        exit(1);
    }

    data = (unsigned char*)malloc(size * channels);
    if (data == NULL) {
        printf("Error: could not allocate memory.\n");
        exit(1);
    }

    fseek(fp, 54, SEEK_SET);
    fread(data, size * channels, 1, fp);

    fclose(fp);
}

void write_ascii(char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file '%s'.\n", filename);
        exit(1);
    }

    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int index = i * width + j;
            int grey = (data[index * channels] + data[index * channels + 1] + data[index * channels + 2]) / 3;
            if (grey < 128) {
                fprintf(fp, " ");
            } else {
                fprintf(fp, "#");
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main() {
    read_bmp(input_file);
    write_ascii(output_file);

    printf("Conversion done.\n");
    return 0;
}