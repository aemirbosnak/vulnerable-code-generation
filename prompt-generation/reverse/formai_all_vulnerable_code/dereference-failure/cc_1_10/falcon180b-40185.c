//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    char *hex;
    char *rgb;
    char *name;
} Color;

Color colors[] = {
    { "#FF0000", "rgb(255,0,0)", "red" },
    { "#00FF00", "rgb(0,255,0)", "lime" },
    { "#0000FF", "rgb(0,0,255)", "blue" },
    { "#FFFF00", "rgb(255,255,0)", "yellow" },
    { "#00FFFF", "rgb(0,255,255)", "cyan" },
    { "#FF00FF", "rgb(255,0,255)", "magenta" },
    { "#000000", "rgb(0,0,0)", "black" },
    { "#FFFFFF", "rgb(255,255,255)", "white" }
};

int main() {
    int numColors = sizeof(colors) / sizeof(Color);

    printf("Enter a color code (hex, rgb, or name): ");
    char input[MAX_LENGTH];
    fgets(input, MAX_LENGTH, stdin);

    char *colorCode = strtok(input, " ");
    Color *color = NULL;

    for (int i = 0; i < numColors; i++) {
        if (strcmp(colorCode, colors[i].hex) == 0 || strcmp(colorCode, colors[i].rgb) == 0 || strcmp(colorCode, colors[i].name) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color code\n");
        return 1;
    }

    printf("Color code: %s\n", color->hex);
    printf("RGB value: %s\n", color->rgb);
    printf("Color name: %s\n", color->name);

    return 0;
}