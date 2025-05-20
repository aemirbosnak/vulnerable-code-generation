//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define GRAYSCALE_LEVELS 10

// Define the grayscale characters
char grayscale_chars[] = {' ', '.', '*', ':', 'o', '&', '8', '#', '@'};

// Function to convert an image to ASCII art
void img_to_ascii(char *filename){
    FILE *image_file = fopen(filename, "rb");
    if (image_file == NULL){
        printf("Error opening image file!\n");
        return;
    }

    // Read image header
    char type[3];
    int width, height, max_val;
    fscanf(image_file, "%s\n%d %d\n%d\n", type, &width, &height, &max_val);

    // Allocate memory for image
    char **image = calloc(height, sizeof(char *));
    for (int i = 0; i < height; i++){
        image[i] = calloc(width, sizeof(char));
    }

    // Read image data
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            int pixel;
            fscanf(image_file, "%d", &pixel);
            image[i][j] = (char)((pixel / (max_val / GRAYSCALE_LEVELS)) % GRAYSCALE_LEVELS);
        }
    }

    // Close the image file
    fclose(image_file);

    // Print the ASCII art
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            printf("%c", grayscale_chars[image[i][j]]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < height; i++){
        free(image[i]);
    }
    free(image);
}

int main(){
    char filename[100];

    printf("Enter image file name: ");
    scanf("%s", filename);

    img_to_ascii(filename);

    return 0;
}