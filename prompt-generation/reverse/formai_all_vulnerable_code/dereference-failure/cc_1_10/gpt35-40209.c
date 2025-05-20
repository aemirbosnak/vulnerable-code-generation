//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 60
#define MAX_COLOR 255

// Function to convert RGB color to grayscale value
int rgb_to_gray(int r, int g, int b) {
    return 0.21*r + 0.72*g + 0.07*b;
}

// Function to map grayscale value to ASCII character
char gray_to_char(int gray) {
    char ascii_char;
    if (gray >= 230) ascii_char = ' ';
    else if (gray >= 200) ascii_char = '.';
    else if (gray >= 180) ascii_char = '-';
    else if (gray >= 160) ascii_char = '=';
    else if (gray >= 130) ascii_char = '+';
    else if (gray >= 100) ascii_char = '*';
    else if (gray >= 70) ascii_char = '#';
    else if (gray >= 60) ascii_char = '%';
    else ascii_char = '@';
    return ascii_char;
}

// Function to print ASCII art
void print_ascii_art(char ascii_art[HEIGHT][WIDTH]) {
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *img_file;
    char img_path[100];
    printf("Enter path to image file: ");
    scanf("%s", img_path);

    // Open image file
    img_file = fopen(img_path, "rb");
    if (img_file == NULL) {
        printf("Error opening image file.\n");
        return 1;
    }

    // Read image header
    char type[3];
    int width, height, max_color;
    int header_check = fscanf(img_file, "%s\n%d %d\n%d\n", type, &width, &height, &max_color);
    if (header_check != 4 || type[0] != 'P' || type[1] != '3' || max_color != MAX_COLOR) {
        printf("Image file format not supported.\n");
        return 1;
    }

    // Allocate memory for pixel data
    int **r, **g, **b;
    r = (int**) malloc(height * sizeof(int*));
    g = (int**) malloc(height * sizeof(int*));
    b = (int**) malloc(height * sizeof(int*));
    for (int i=0; i<height; i++) {
        r[i] = (int*) malloc(width * sizeof(int));
        g[i] = (int*) malloc(width * sizeof(int));
        b[i] = (int*) malloc(width * sizeof(int));
    }

    // Read pixel data
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            fscanf(img_file, "%d %d %d", &r[i][j], &g[i][j], &b[i][j]);
        }
    }

    // Convert RGB image to grayscale ASCII art
    char ascii_art[HEIGHT][WIDTH];
    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            int gray_value = rgb_to_gray(r[i][j], g[i][j], b[i][j]);
            char ascii_char = gray_to_char(gray_value);
            ascii_art[i][j] = ascii_char;
        }
    }

    // Print ASCII art
    print_ascii_art(ascii_art);

    // Free memory
    for (int i=0; i<height; i++) {
        free(r[i]);
        free(g[i]);
        free(b[i]);
    }
    free(r);
    free(g);
    free(b);

    // Close file
    fclose(img_file);

    return 0;
}