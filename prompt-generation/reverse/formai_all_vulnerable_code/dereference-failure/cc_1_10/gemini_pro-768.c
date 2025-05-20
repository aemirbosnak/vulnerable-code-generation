//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store ASCII art data
typedef struct {
    char *art;
    int width;
    int height;
} ASCIIArt;

// Function to load ASCII art from a file
ASCIIArt *load_ascii_art(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return NULL;
    }

    // Get the width and height of the ASCII art
    int width, height;
    fscanf(fp, "%d %d", &width, &height);

    // Allocate memory for the ASCII art
    ASCIIArt *art = malloc(sizeof(ASCIIArt));
    art->art = malloc(width * height);
    art->width = width;
    art->height = height;

    // Read the ASCII art from the file
    fread(art->art, sizeof(char), width * height, fp);

    fclose(fp);

    return art;
}

// Function to free the memory allocated for ASCII art
void free_ascii_art(ASCIIArt *art) {
    free(art->art);
    free(art);
}

// Function to print ASCII art to the console
void print_ascii_art(const ASCIIArt *art) {
    for (int i = 0; i < art->height; i++) {
        for (int j = 0; j < art->width; j++) {
            printf("%c", art->art[i * art->width + j]);
        }
        printf("\n");
    }
}

int main() {
    // Load ASCII art from a file
    ASCIIArt *art = load_ascii_art("art.txt");
    if (!art) {
        return 1;
    }

    // Print the ASCII art to the console
    print_ascii_art(art);

    // Free the memory allocated for ASCII art
    free_ascii_art(art);

    return 0;
}