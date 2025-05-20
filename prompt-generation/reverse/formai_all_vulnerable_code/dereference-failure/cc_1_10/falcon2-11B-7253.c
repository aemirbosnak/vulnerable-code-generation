//Falcon2-11B DATASET v1.0 Category: Text to ASCII art generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store the ASCII art
struct ascii_art {
    int width;
    int height;
    char **art;
};

// Function to convert a string to ASCII art
void convert_to_ascii_art(char *text, struct ascii_art *art) {
    // Get the width and height of the ASCII art
    int width = strlen(text);
    int height = 0;
    
    // Create the ASCII art array
    art->art = (char **)malloc(width * sizeof(char *));
    for (int i = 0; i < width; i++) {
        art->art[i] = (char *)malloc(height * sizeof(char));
    }
    
    // Convert the text to ASCII art
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            art->art[i][j] = text[i * height + j];
        }
    }
}

// Function to print the ASCII art
void print_ascii_art(struct ascii_art *art) {
    int width = art->width;
    int height = art->height;
    
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            printf("%c", art->art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Get the text to convert to ASCII art
    char text[100];
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    
    // Convert the text to ASCII art
    struct ascii_art art;
    art.width = 80;
    art.height = 20;
    convert_to_ascii_art(text, &art);
    
    // Print the ASCII art
    print_ascii_art(&art);
    
    return 0;
}