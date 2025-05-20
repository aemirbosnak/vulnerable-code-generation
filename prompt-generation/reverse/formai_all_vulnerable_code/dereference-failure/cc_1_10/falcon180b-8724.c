//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Define the maximum width and height of the image
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the characters used to represent different colors
char color_characters[] = "@%#*+=-:. ";

// Function to print a character with the specified foreground and background colors
void print_char(char c, char fg_color, char bg_color) {
    printf("\e[38;5;%dm\e[48;5;%dm%c\e[0m", fg_color + 1, bg_color + 1, c);
}

// Function to print a line of ASCII art
void print_line(char *line, int width, int fg_color, int bg_color) {
    int i;
    for (i = 0; i < width; i++) {
        print_char(line[i], fg_color, bg_color);
    }
}

// Function to convert an image to ASCII art
void image_to_ascii(char *filename, int width, int height, int fg_color, int bg_color) {
    FILE *fp;
    int i, j;
    char line[MAX_WIDTH + 1];
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'.\n", filename);
        exit(1);
    }
    for (i = 0; i < height; i++) {
        fread(line, 1, width, fp);
        for (j = 0; j < width; j++) {
            int gray = line[j] / 4; // Convert RGB to grayscale
            int color_index = gray % 8; // Map grayscale to color character
            print_char(color_characters[color_index], fg_color, bg_color);
        }
        printf("\n");
    }
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 6) {
        printf("Usage: %s <filename> <width> <height> <foreground color> <background color>\n", argv[0]);
        return 1;
    }
    char *filename = argv[1];
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);
    int fg_color = atoi(argv[4]) % 8;
    int bg_color = atoi(argv[5]) % 8;
    image_to_ascii(filename, width, height, fg_color, bg_color);
    return 0;
}