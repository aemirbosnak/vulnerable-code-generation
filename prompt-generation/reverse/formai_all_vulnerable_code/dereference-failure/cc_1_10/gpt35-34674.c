//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_PIXEL_VALUE 255

// Function to find the closest ASCII character for a given pixel value
char get_ascii_char(int pixel_value) {
    int ascii_char = pixel_value / (MAX_PIXEL_VALUE / 69);
    return "@%#*+=-:. "[ascii_char];
}

int main(int argc, char *argv[]) {
    // Check if correct number of arguments are provided
    if (argc < 2) {
        printf("Invalid arguments. Usage: ./ascii_art_converter input_file\n");
        return -1;
    }

    // Open input file
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    // Allocate memory for image data
    int **image_data = (int**)malloc(sizeof(int*) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        image_data[i] = (int*)malloc(sizeof(int) * WIDTH);
    }

    // Read image data from file
    char line[WIDTH * 4];
    for (int i = 0; i < HEIGHT; i++) {
        fgets(line, sizeof(line), input_file);
        int pixel_value = 0;
        char *token = strtok(line, " ");
        int j = 0;
        while (token != NULL) {
            pixel_value = atoi(token);
            image_data[i][j] = pixel_value;
            token = strtok(NULL, " ");
            j++;
        }
    }

    // Close input file
    fclose(input_file);

    // Generate ASCII art
    char ascii_art[HEIGHT + 1][WIDTH + 1];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            ascii_art[i][j] = get_ascii_char(image_data[i][j]);
        }
        ascii_art[i][WIDTH] = '\n';
    }
    ascii_art[HEIGHT][0] = '\0';

    // Print ASCII art
    printf("%s\n", ascii_art);

    // Free memory
    for (int i = 0; i < HEIGHT; i++) {
        free(image_data[i]);
    }
    free(image_data);

    return 0;
}