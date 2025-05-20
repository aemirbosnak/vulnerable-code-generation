//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the RGB color code structure
typedef struct rgb_color_code {
    int red;
    int green;
    int blue;
} rgb_color_code;

// Define the hex color code structure
typedef struct hex_color_code {
    char *hex_code;
} hex_color_code;

// Function to convert a hex color code to an RGB color code
rgb_color_code hex_to_rgb(hex_color_code hex_code) {
    rgb_color_code rgb_code;

    // Check if the hex code is valid
    if (strlen(hex_code.hex_code) != 6) {
        fprintf(stderr, "Invalid hex color code: %s\n", hex_code.hex_code);
        exit(EXIT_FAILURE);
    }

    // Convert the hex code to an RGB color code
    sscanf(hex_code.hex_code, "%02x%02x%02x", &rgb_code.red, &rgb_code.green, &rgb_code.blue);

    // Return the RGB color code
    return rgb_code;
}

// Function to convert an RGB color code to a hex color code
hex_color_code rgb_to_hex(rgb_color_code rgb_code) {
    hex_color_code hex_code;

    // Allocate memory for the hex code
    hex_code.hex_code = malloc(7);

    // Convert the RGB color code to a hex code
    sprintf(hex_code.hex_code, "#%02x%02x%02x", rgb_code.red, rgb_code.green, rgb_code.blue);

    // Return the hex color code
    return hex_code;
}

// Function to print a color code
void print_color_code(rgb_color_code rgb_code, hex_color_code hex_code) {
    printf("RGB color code: (%d, %d, %d)\n", rgb_code.red, rgb_code.green, rgb_code.blue);
    printf("Hex color code: %s\n", hex_code.hex_code);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided a hex color code
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hex color code>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Convert the hex color code to an RGB color code
    rgb_color_code rgb_code = hex_to_rgb((hex_color_code) { .hex_code = argv[1] });

    // Convert the RGB color code to a hex color code
    hex_color_code hex_code = rgb_to_hex(rgb_code);

    // Print the color codes
    print_color_code(rgb_code, hex_code);

    // Free the memory allocated for the hex color code
    free(hex_code.hex_code);

    return EXIT_SUCCESS;
}