//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

struct color {
    char name[20];
    int red;
    int green;
    int blue;
};

int main() {
    struct color colors[MAX_COLORS];
    int num_colors = 0;

    // Initialize colors array with standard colors
    colors[num_colors++] = (struct color) {"black", 0, 0, 0};
    colors[num_colors++] = (struct color) {"white", 255, 255, 255};
    colors[num_colors++] = (struct color) {"red", 255, 0, 0};
    colors[num_colors++] = (struct color) {"green", 0, 255, 0};
    colors[num_colors++] = (struct color) {"blue", 0, 0, 255};

    // Read in additional colors from user
    char input[50];
    printf("Enter additional colors (name followed by RGB values, press enter when done):\n");
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        if (num_colors >= MAX_COLORS) {
            printf("Error: Maximum number of colors (%d) reached.\n", MAX_COLORS);
            exit(1);
        }
        char *name = strtok(input, " ");
        int red = atoi(strtok(NULL, " "));
        int green = atoi(strtok(NULL, " "));
        int blue = atoi(strtok(NULL, " "));
        colors[num_colors++] = (struct color) {name, red, green, blue};
    }

    // Convert RGB values to hexadecimal
    for (int i = 0; i < num_colors; i++) {
        int r = colors[i].red;
        int g = colors[i].green;
        int b = colors[i].blue;
        int hex = (r << 16) | (g << 8) | b;
        sprintf(colors[i].name, "#%06X", hex);
    }

    // Print out color names and hexadecimal values
    printf("Color Name\tHexadecimal\n");
    for (int i = 0; i < num_colors; i++) {
        printf("%s\t\t%s\n", colors[i].name, colors[i].name);
    }

    return 0;
}