//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the RGB color struct
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} color_t;

// Define the pixel struct
typedef struct {
    color_t color;
    char symbol;
} pixel_t;

// Define the pixel art struct
typedef struct {
    int width;
    int height;
    pixel_t pixels[MAX_WIDTH][MAX_HEIGHT];
} pixel_art_t;

// Create a new pixel art object
pixel_art_t *pixel_art_new(int width, int height) {
    pixel_art_t *art = malloc(sizeof(pixel_art_t));
    if (art == NULL) {
        return NULL;
    }

    art->width = width;
    art->height = height;

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            art->pixels[i][j].color.r = 0;
            art->pixels[i][j].color.g = 0;
            art->pixels[i][j].color.b = 0;
            art->pixels[i][j].symbol = ' ';
        }
    }

    return art;
}

// Free the memory allocated for a pixel art object
void pixel_art_free(pixel_art_t *art) {
    free(art);
}

// Set the color of a pixel
void pixel_art_set_color(pixel_art_t *art, int x, int y, color_t color) {
    art->pixels[x][y].color = color;
}

// Set the symbol of a pixel
void pixel_art_set_symbol(pixel_art_t *art, int x, int y, char symbol) {
    art->pixels[x][y].symbol = symbol;
}

// Save the pixel art to a PPM file
void pixel_art_save_ppm(pixel_art_t *art, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    fprintf(fp, "P3\n");
    fprintf(fp, "%d %d\n", art->width, art->height);
    fprintf(fp, "255\n");

    for (int i = 0; i < art->width; i++) {
        for (int j = 0; j < art->height; j++) {
            fprintf(fp, "%d %d %d ", art->pixels[i][j].color.r, art->pixels[i][j].color.g, art->pixels[i][j].color.b);
        }
    }

    fclose(fp);
}

// Save the pixel art to a text file
void pixel_art_save_txt(pixel_art_t *art, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return;
    }

    for (int i = 0; i < art->width; i++) {
        for (int j = 0; j < art->height; j++) {
            fprintf(fp, "%c", art->pixels[i][j].symbol);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

// Load a pixel art from a PPM file
pixel_art_t *pixel_art_load_ppm(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return NULL;
    }

    char buffer[1024];
    int width, height, max_value;

    fscanf(fp, "%s", buffer); // Read the magic number
    if (strcmp(buffer, "P3") != 0) {
        return NULL; // Not a PPM file
    }

    fscanf(fp, "%d %d", &width, &height); // Read the width and height
    fscanf(fp, "%d", &max_value); // Read the maximum value

    pixel_art_t *art = pixel_art_new(width, height);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            unsigned char r, g, b;
            fscanf(fp, "%hhu %hhu %hhu", &r, &g, &b); // Read the color
            art->pixels[i][j].color.r = r;
            art->pixels[i][j].color.g = g;
            art->pixels[i][j].color.b = b;
        }
    }

    fclose(fp);

    return art;
}

// Load a pixel art from a text file
pixel_art_t *pixel_art_load_txt(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char buffer[1024];
    int width, height;

    fscanf(fp, "%s", buffer); // Read the first line
    width = strlen(buffer); // Get the width

    height = 0; // Count the number of lines
    while (fscanf(fp, "%s", buffer) != EOF) {
        height++;
    }

    pixel_art_t *art = pixel_art_new(width, height);

    rewind(fp); // Go back to the beginning of the file

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            fscanf(fp, "%c", &art->pixels[i][j].symbol); // Read the symbol
        }
    }

    fclose(fp);

    return art;
}

// Print the pixel art to the console
void pixel_art_print(pixel_art_t *art) {
    for (int i = 0; i < art->width; i++) {
        for (int j = 0; j < art->height; j++) {
            printf("%c", art->pixels[i][j].symbol);
        }
        printf("\n");
    }
}

int main() {
    // Create a new pixel art object
    pixel_art_t *art = pixel_art_new(100, 100);

    // Set the color of some pixels
    pixel_art_set_color(art, 0, 0, (color_t){255, 0, 0});
    pixel_art_set_color(art, 1, 0, (color_t){0, 255, 0});
    pixel_art_set_color(art, 2, 0, (color_t){0, 0, 255});

    // Set the symbol of some pixels
    pixel_art_set_symbol(art, 0, 0, 'R');
    pixel_art_set_symbol(art, 1, 0, 'G');
    pixel_art_set_symbol(art, 2, 0, 'B');

    // Save the pixel art to a PPM file
    pixel_art_save_ppm(art, "test.ppm");

    // Save the pixel art to a text file
    pixel_art_save_txt(art, "test.txt");

    // Print the pixel art to the console
    pixel_art_print(art);

    // Free the memory allocated for the pixel art object
    pixel_art_free(art);

    return 0;
}