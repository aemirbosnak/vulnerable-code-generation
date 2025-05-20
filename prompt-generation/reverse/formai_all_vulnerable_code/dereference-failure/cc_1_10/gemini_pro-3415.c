//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the color code structure
typedef struct color_code {
    char *name;
    int red;
    int green;
    int blue;
} color_code;

// Define an array of color codes
color_code colors[] = {
    {"black", 0, 0, 0},
    {"white", 255, 255, 255},
    {"red", 255, 0, 0},
    {"green", 0, 255, 0},
    {"blue", 0, 0, 255},
    {"cyan", 0, 255, 255},
    {"magenta", 255, 0, 255},
    {"yellow", 255, 255, 0}
};

// The main function
int main(int argc, char *argv[]) {
    // Check if the user has provided a color name
    if (argc != 2) {
        printf("Usage: %s <color name>\n", argv[0]);
        return 1;
    }

    // Get the color name from the user
    char *color_name = argv[1];

    // Find the color code for the given color name
    color_code *color_code = NULL;
    for (int i = 0; i < sizeof(colors) / sizeof(color_code); i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            color_code = &colors[i];
            break;
        }
    }

    // Check if the color code was found
    if (color_code == NULL) {
        printf("Invalid color name: %s\n", color_name);
        return 1;
    }

    // Print the color code
    printf("Color code for %s: %d %d %d\n", color_code->name, color_code->red, color_code->green, color_code->blue);

    return 0;
}