//Falcon2-11B DATASET v1.0 Category: Text to ASCII art generator ; Style: complete
#include <stdio.h>
#include <string.h>

// Function to convert text to ASCII art
void textToAscii(const char* input, int* rows, int* cols) {
    int i, j, k;
    int width, height, total_characters;
    int* char_array;
    char buffer[100];

    // Calculate the number of rows and columns in the ASCII art
    width = strlen(input);
    total_characters = 0;
    for (i = 0; i < width; i++) {
        total_characters += input[i];
    }
    height = total_characters / width;
    if (total_characters % width!= 0) {
        height++;
    }

    // Allocate memory for the ASCII art
    char_array = (int*)malloc(sizeof(int) * height * width);

    // Generate the ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i < height - 1) {
                sprintf(buffer, "%c", input[j]);
                char_array[i * width + j] = strlen(buffer);
            } else {
                char_array[i * width + j] = 0;
            }
        }
    }

    // Print the ASCII art
    *rows = height;
    *cols = width;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (char_array[i * width + j] == 0) {
                printf(" ");
            } else {
                printf("%s", input + j);
            }
        }
        printf("\n");
    }

    // Free memory
    free(char_array);
}

int main() {
    const char* input = "Hello, World!";
    int rows, cols;
    textToAscii(input, &rows, &cols);
    printf("Rows: %d\nColumns: %d\n", rows, cols);
    return 0;
}