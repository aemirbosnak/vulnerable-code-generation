//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define WIDTH 120

int get_avg_pixel_value(char *pixels);
char get_ascii_value(int pixel_value);

int main(int argc, char *argv[]) {

    if(argc < 2) {
        printf("Error: Please provide the file name of the image as argument.");
        return -1;
    }

    FILE *fp = NULL;
    fp = fopen(argv[1], "r");
    if(fp == NULL) {
        printf("Error: The file could not be opened.\n");
        return -1;
    }

    fseek(fp, 0L, SEEK_END);
    int file_size = ftell(fp);
    rewind(fp);

    if(file_size == 0) {
        printf("Error: Empty file.\n");
        return -1;
    }

    char *file_buffer = (char*) malloc(file_size+1);
    if(file_buffer == NULL) {
        printf("Error: Memory allocation error.\n");
        return -1;
    }

    int bytes_read = fread(file_buffer, sizeof(char), file_size, fp);
    fclose(fp);

    if(bytes_read < file_size) {
        printf("Error: Unable to read file.\n");
        free(file_buffer);
        return -1;
    }

    int n_pixels = file_size/3;
    char *pixels = (char*) malloc(n_pixels);
    if(pixels == NULL) {
        printf("Error: Memory allocation error.\n");
        free(file_buffer);
        return -1;
    }

    int index = 0;
    for(int i=0; i<file_size; i+=3) {
        pixels[index++] = get_avg_pixel_value(&file_buffer[i]);
    }

    free(file_buffer);

    for(int i=0; i<n_pixels; i+=WIDTH) {
        for(int j=0; j<WIDTH && i+j<n_pixels; j++) {
            printf("%c", get_ascii_value(pixels[i+j]));
        }
        printf("\n");
    }

    free(pixels);

    return 0;

}

int get_avg_pixel_value(char *pixels) {
    int red = (int)*pixels;
    int green = (int)(*(pixels+1));
    int blue = (int)(*(pixels+2));
    return (red+green+blue)/3;
}

char get_ascii_value(int pixel_value) {
    char ascii[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int score = (pixel_value*10)/256;
    return ascii[score];
}