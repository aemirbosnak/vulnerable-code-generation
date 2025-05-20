//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the ASCII art characters
char *chars = " .:-=+*#%@"
            " .:-=+*#%@"
            " .:-=+*#%@"
            " .:-=+*#%@"
            " .:-=+*#%@";

// Define the maximum width and height of the ASCII art
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the structure of an ASCII art image
typedef struct {
    int width;
    int height;
    char *data;
} ASCIIArtImage;

// Create a new ASCII art image
ASCIIArtImage *new_ascii_art_image(int width, int height) {
    ASCIIArtImage *image = malloc(sizeof(ASCIIArtImage));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height);
    return image;
}

// Free an ASCII art image
void free_ascii_art_image(ASCIIArtImage *image) {
    free(image->data);
    free(image);
}

// Set the pixel at the given coordinates to the given character
void set_pixel(ASCIIArtImage *image, int x, int y, char c) {
    image->data[y * image->width + x] = c;
}

// Get the pixel at the given coordinates
char get_pixel(ASCIIArtImage *image, int x, int y) {
    return image->data[y * image->width + x];
}

// Generate ASCII art from a string
ASCIIArtImage *generate_ascii_art(char *text) {
    // Create a new ASCII art image
    ASCIIArtImage *image = new_ascii_art_image(strlen(text), 5);

    // Set the pixels of the image
    for (int i = 0; i < strlen(text); i++) {
        for (int j = 0; j < 5; j++) {
            set_pixel(image, i, j, chars[(int)text[i] % strlen(chars)]);
        }
    }

    // Return the image
    return image;
}

// Print an ASCII art image to the console
void print_ascii_art(ASCIIArtImage *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            printf("%c", get_pixel(image, j, i));
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Get the text to convert to ASCII art
    char *text = "Hello, world!";

    // Generate the ASCII art
    ASCIIArtImage *image = generate_ascii_art(text);

    // Print the ASCII art
    print_ascii_art(image);

    // Free the ASCII art image
    free_ascii_art_image(image);

    return 0;
}