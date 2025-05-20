//FormAI DATASET v1.0 Category: Color Code Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX 256 // Maximum length of the RGB code string

// Function to convert RGB color code to HEX color code
char* rgb_to_hex(char* rgb_code) {

    char* hex_code = (char*)malloc(7 * sizeof(char)); // Allocate memory for the HEX code string 

    // Parse the RGB code string into individual color values
    int r, g, b;
    if (sscanf(rgb_code, "%d,%d,%d", &r, &g, &b) != 3) {
        fprintf(stderr, "Invalid RGB color code: %s\n", rgb_code);
        exit(1);
    }

    // Convert each color value to its corresponding HEX value
    sprintf(hex_code, "#%02X%02X%02X", r, g, b);

    return hex_code; // Return the HEX code string
}

// Function to convert HEX color code to RGB color code
char* hex_to_rgb(char* hex_code) {

    char* rgb_code = (char*)malloc(MAX * sizeof(char)); // Allocate memory for the RGB code string 

     // Obtain the individual HEX values for red, green, and blue
    unsigned int r, g, b;
    if (sscanf(hex_code, "#%02X%02X%02X", &r, &g, &b) != 3) {
        fprintf(stderr, "Invalid HEX color code: %s\n", hex_code);
        exit(1);
    }

    // Convert each HEX value to its corresponding RGB value
    sprintf(rgb_code, "%d,%d,%d", r, g, b);

    return rgb_code; // Return the RGB code string
}

int main() {

    char* code;
    char choice;
    char* result;

    // Prompt user for input
    printf("Enter color code (RGB or HEX): ");
    code = (char*)malloc(MAX * sizeof(char));
    fgets(code, MAX, stdin);

    // Determine if the input is a RGB or HEX code
    if (code[0] == '#') {
        choice = 'h';
    }
    else {
        choice = 'r';
    }

    // Convert the color code to the other format
    if (choice == 'r') {
        result = rgb_to_hex(code);
        printf("HEX code: %s\n", result);
    }
    else {
        result = hex_to_rgb(code);
        printf("RGB code: %s\n", result);
    }

    free(code); // Free memory allocated for code
    free(result); // Free memory allocated for result

    return 0;
}