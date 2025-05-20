//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
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
    { "magenta", 255, 0, 255 },
    { "cyan", 0, 255, 255 },
    { "orange", 255, 128, 0 },
    { "purple", 128, 0, 255 },
    { "brown", 165, 42, 42 },
    { "gray", 128, 128, 128 },
    { "pink", 255, 192, 203 },
    { "teal", 0, 128, 128 },
    { "navy", 0, 0, 128 },
    { "olive", 128, 128, 0 },
    { "maroon", 128, 0, 0 },
    { "lime", 0, 255, 0 },
    { "aqua", 0, 255, 255 },
    { "fuchsia", 255, 0, 255 },
    { "silver", 192, 192, 192 },
    { "gold", 255, 215, 0 },
    { "chocolate", 210, 105, 30 },
    { "coral", 255, 127, 80 },
    { "khaki", 240, 230, 140 },
    { "lavender", 230, 230, 250 },
    { "mint", 189, 252, 201 },
    { "peach", 255, 218, 185 },
    { "plum", 221, 160, 221 },
    { "salmon", 250, 128, 114 },
    { "tan", 210, 180, 140 },
    { "turquoise", 64, 224, 208 },
    { "violet", 238, 130, 238 },
    { "wheat", 245, 222, 179 }
};

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s color_name\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *color_name = argv[1];

    Color *color = NULL;

    for (int i = 0; i < sizeof(colors) / sizeof(Color); i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        fprintf(stderr, "Invalid color name: %s\n", color_name);
        return EXIT_FAILURE;
    }

    printf("Color: %s\n", color->name);
    printf("Red: %d\n", color->red);
    printf("Green: %d\n", color->green);
    printf("Blue: %d\n", color->blue);

    return EXIT_SUCCESS;
}