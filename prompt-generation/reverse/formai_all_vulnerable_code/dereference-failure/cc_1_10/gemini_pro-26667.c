//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert a hex color code to RGB values
void hex_to_rgb(char *hex, int *r, int *g, int *b) {
    // Allocate memory for the hex string
    char *hex_str = malloc(strlen(hex) + 1);

    // Copy the hex string to the allocated memory
    strcpy(hex_str, hex);

    // Convert the hex string to lowercase
    for (int i = 0; i < strlen(hex_str); i++) {
        hex_str[i] = tolower(hex_str[i]);
    }

    // Check if the hex string is valid
    if (strlen(hex_str) != 6) {
        printf("Invalid hex color code '%s'\n", hex);
        free(hex_str);
        exit(1);
    }

    // Convert the hex string to RGB values
    *r = strtol(hex_str, NULL, 16);
    *g = strtol(hex_str + 2, NULL, 16);
    *b = strtol(hex_str + 4, NULL, 16);

    // Free the allocated memory
    free(hex_str);
}

// Function to convert RGB values to a hex color code
char *rgb_to_hex(int r, int g, int b) {
    // Allocate memory for the hex string
    char *hex_str = malloc(7);

    // Convert the RGB values to a hex string
    sprintf(hex_str, "#%02x%02x%02x", r, g, b);

    // Return the hex string
    return hex_str;
}

// Main function
int main() {
    // Define the hex color code
    char *hex = "#FF00FF";

    // Convert the hex color code to RGB values
    int r, g, b;
    hex_to_rgb(hex, &r, &g, &b);

    // Print the RGB values
    printf("RGB values: %d, %d, %d\n", r, g, b);

    // Convert the RGB values back to a hex color code
    char *hex_new = rgb_to_hex(r, g, b);

    // Print the new hex color code
    printf("New hex color code: %s\n", hex_new);

    // Free the allocated memory
    free(hex_new);

    return 0;
}