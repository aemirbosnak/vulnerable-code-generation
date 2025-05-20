//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function prototypes
char* hex_to_rgb(char* hex);
char* rgb_to_hex(char* rgb);

int main() {
    char input[MAX_LENGTH];
    char* hex = NULL;
    char* rgb = NULL;

    // Prompt user for input
    printf("Enter a color code (e.g. #FF0000 or FF0000): ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = '\0';

    // Convert input to uppercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // Check if input is a hexadecimal color code
    if (strlen(input) == 7 && input[0] == '#') {
        hex = strdup(input);
    } else if (strlen(input) == 6) {
        hex = malloc(8 * sizeof(char));
        sprintf(hex, "#%s", input);
    } else {
        printf("Invalid input.\n");
        return 1;
    }

    // Convert hexadecimal color code to RGB
    rgb = hex_to_rgb(hex);

    // Print RGB color code
    printf("RGB color code: %s\n", rgb);

    // Convert RGB color code to hexadecimal
    hex = rgb_to_hex(rgb);

    // Print hexadecimal color code
    printf("Hexadecimal color code: %s\n", hex);

    return 0;
}

// Converts a hexadecimal color code to RGB
char* hex_to_rgb(char* hex) {
    char* rgb = malloc(8 * sizeof(char));
    sprintf(rgb, "%.2X%.2X%.2X", hex[1], hex[2], hex[3]);
    return rgb;
}

// Converts an RGB color code to hexadecimal
char* rgb_to_hex(char* rgb) {
    char* hex = malloc(9 * sizeof(char));
    sprintf(hex, "#%02X%02X%02X", rgb[0], rgb[1], rgb[2]);
    return hex;
}