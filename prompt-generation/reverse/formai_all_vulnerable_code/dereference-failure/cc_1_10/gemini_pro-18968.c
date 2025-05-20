//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 20

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    int red;
    int green;
    int blue;
} Color;

Color colors[] = {
    { "black", 0, 0, 0 },
    { "white", 255, 255, 255 },
    { "red", 255, 0, 0 },
    { "green", 0, 255, 0 },
    { "blue", 0, 0, 255 },
    { "yellow", 255, 255, 0 },
    { "cyan", 0, 255, 255 },
    { "magenta", 255, 0, 255 },
    { "orange", 255, 128, 0 },
    { "purple", 128, 0, 128 }
};

const int num_colors = sizeof(colors) / sizeof(Color);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <color name>\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];

    Color *color = NULL;

    for (int i = 0; i < num_colors; i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        fprintf(stderr, "Invalid color name: %s\n", color_name);
        return 1;
    }

    printf("Color code: #%02x%02x%02x\n", color->red, color->green, color->blue);

    return 0;
}