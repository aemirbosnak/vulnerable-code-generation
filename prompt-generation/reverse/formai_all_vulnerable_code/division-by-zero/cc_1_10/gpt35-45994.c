//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum width and height of the ASCII art
#define MAX_WIDTH 80
#define MAX_HEIGHT 25

// Define the maximum length of the input string
#define MAX_INPUT_LENGTH 100

// The ASCII art characters to be used
char ASCII_CHARS[] = {'#', '?', '%', '.', 'S', '+', '.', '*', ':', ',', '@'};

// The grayscale values corresponding to each ASCII character
int GRAYSCALE_VALUES[] = {0, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200};

// Declare the function prototypes
int get_grayscale_value(char c);
void generate_ascii_art(char input_string[], int width, int height);
void clear_screen();

int main() {
    char input_string[MAX_INPUT_LENGTH];
    int width, height;

    // Get the input string and the dimensions of the ASCII art
    printf("Enter the input string: ");
    fgets(input_string, MAX_INPUT_LENGTH, stdin);
    printf("Enter the width of the ASCII art (maximum %d): ", MAX_WIDTH);
    scanf("%d", &width);
    printf("Enter the height of the ASCII art (maximum %d): ", MAX_HEIGHT);
    scanf("%d", &height);

    // Clear the input buffer
    char c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Generate the ASCII art and display it
    generate_ascii_art(input_string, width, height);

    return 0;
}

// Returns the grayscale value corresponding to the given character
int get_grayscale_value(char c) {
    int i;
    for (i = 0; i < sizeof(ASCII_CHARS); i++) {
        if (c == ASCII_CHARS[i])
            return GRAYSCALE_VALUES[i];
    }
    return 0;
}

// Generates the ASCII art for the given input string, width, and height
void generate_ascii_art(char input_string[], int width, int height) {
    // Calculate the number of characters that can fit in each row and column
    int input_length = strlen(input_string) - 1; // Remove the newline character
    int num_columns = width / 7; // Each character is 7 pixels wide
    int num_rows = height / 11; // Each character is 11 pixels high
    
    // Ensure that there is at least one column and row
    if (num_columns < 1)
        num_columns = 1;
    if (num_rows < 1)
        num_rows = 1;
    
    // Calculate the actual width and height of the ASCII art, based on the number of characters that can fit
    int actual_width = num_columns * 7;
    int actual_height = num_rows * 11;
    
    // Calculate the spacing between characters
    int horizontal_spacing = (width - actual_width) / (num_columns - 1);
    int vertical_spacing = (height - actual_height) / (num_rows - 1);
    
    // Create an array to hold the grayscale values of each pixel in the ASCII art
    int grayscale_values[actual_height][actual_width];
    
    // Fill in the grayscale values for each pixel in the ASCII art
    int i, j, k, l;
    for (i = 0; i < input_length; i++) {
        // Get the grayscale values for the current character
        int character_grayscale_values[11][7];
        for (j = 0; j < 11; j++) {
            for (k = 0; k < 7; k++) {
                int index = j * 7 + k;
                character_grayscale_values[j][k] = get_grayscale_value(input_string[i]) * (index % 2 == 0 ? 1 : 3) / 4; // Apply a dither pattern to simulate gray shades
            }
        }
        
        // Paste the grayscale values for the current character into the ASCII art array
        int column_offset = (i % num_columns) * (7 + horizontal_spacing);
        int row_offset = (i / num_columns) * (11 + vertical_spacing);
        for (j = 0; j < 11; j++) {
            for (k = 0; k < 7; k++) {
                grayscale_values[row_offset + j][column_offset + k] = character_grayscale_values[j][k];
            }
        }
    }
    
    // Print out the ASCII art
    clear_screen();
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int grayscale_value = grayscale_values[i / 11][j / 7];
            int index = 0;
            while (index < sizeof(GRAYSCALE_VALUES) && grayscale_value > GRAYSCALE_VALUES[index]) {
                index++;
            }
            printf("%c", ASCII_CHARS[index-1]);
        }
        printf("\n");
    }
}

// Clears the screen by printing out a bunch of newlines
void clear_screen() {
    int i;
    for (i = 0; i < 100; i++) {
        printf("\n");
    }
}