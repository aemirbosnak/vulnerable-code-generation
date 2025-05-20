//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLOR_COUNT 16
#define COLOR_NAMES "black,blue,green,cyan,red,magenta,brown,yellow,white,gray,light blue,light green,light cyan,light red,light magenta,light yellow"

typedef struct {
    char *name;
    int r, g, b;
} Color;

Color colors[COLOR_COUNT] = {
    { "black", 0, 0, 0 },
    { "blue", 0, 0, 255 },
    { "green", 0, 128, 0 },
    { "cyan", 0, 255, 255 },
    { "red", 255, 0, 0 },
    { "magenta", 255, 0, 255 },
    { "brown", 165, 42, 42 },
    { "yellow", 255, 255, 0 },
    { "white", 255, 255, 255 },
    { "gray", 128, 128, 128 },
    { "light blue", 173, 216, 230 },
    { "light green", 144, 238, 144 },
    { "light cyan", 224, 255, 255 },
    { "light red", 255, 192, 203 },
    { "light magenta", 255, 204, 255 },
    { "light yellow", 255, 255, 224 }
};

void print_color_names() {
    printf("Available colors:\n");
    for (int i = 0; i < COLOR_COUNT; i++) {
        printf("%s\n", colors[i].name);
    }
}

Color *get_color_by_name(char *name) {
    for (int i = 0; i < COLOR_COUNT; i++) {
        if (strcmp(colors[i].name, name) == 0) {
            return &colors[i];
        }
    }
    return NULL;
}

void print_color_code(Color *color) {
    printf("Color code: #%02x%02x%02x\n", color->r, color->g, color->b);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <color name>\n", argv[0]);
        print_color_names();
        return 1;
    }

    Color *color = get_color_by_name(argv[1]);
    if (color == NULL) {
        printf("Invalid color name\n");
        print_color_names();
        return 1;
    }

    print_color_code(color);

    return 0;
}