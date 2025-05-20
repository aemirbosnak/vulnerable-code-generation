//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct color {
    char *name;
    int red;
    int green;
    int blue;
};

struct color colors[] = {
    {"black", 0, 0, 0},
    {"white", 255, 255, 255},
    {"red", 255, 0, 0},
    {"green", 0, 255, 0},
    {"blue", 0, 0, 255},
    {"yellow", 255, 255, 0},
    {"magenta", 255, 0, 255},
    {"cyan", 0, 255, 255},
    {"orange", 255, 128, 0},
    {"purple", 128, 0, 128},
    {"brown", 165, 42, 42},
    {"gray", 128, 128, 128},
    {"pink", 255, 192, 203},
    {"violet", 238, 130, 238},
    {"indigo", 75, 0, 130},
    {"turquoise", 0, 255, 127},
    {"lime", 0, 255, 0},
    {"navy", 0, 0, 128},
    {"teal", 0, 128, 128},
    {"olive", 128, 128, 0},
    {"maroon", 128, 0, 0},
    {"silver", 192, 192, 192},
    {"gold", 255, 215, 0},
    {"bronze", 205, 127, 50},
    {"beige", 245, 245, 220},
    {"ivory", 255, 255, 240},
    {"wheat", 245, 222, 179},
    {"khaki", 240, 230, 140},
    {"tan", 210, 180, 140},
    {"coral", 255, 127, 80},
    {"salmon", 250, 128, 114},
    {"peach", 255, 218, 185},
    {"apricot", 255, 215, 180},
    {"yellow-green", 154, 205, 50},
    {"blue-green", 0, 191, 255},
    {"aqua", 0, 255, 255},
    {"mint", 189, 252, 201},
    {"sky-blue", 135, 206, 235},
    {"light-blue", 173, 216, 230},
    {"powder-blue", 176, 224, 230},
    {"lavender", 230, 230, 250},
    {"lilac", 200, 191, 231},
    {"magenta", 255, 0, 255},
    {"fuchsia", 255, 0, 255},
    {"rose", 255, 0, 127},
    {"crimson", 220, 20, 60},
    {"ruby", 255, 0, 0},
    {"chocolate", 123, 63, 0},
    {"umber", 99, 49, 21},
    {"sienna", 160, 82, 45},
    {"burnt-orange", 204, 85, 0},
    {"rust", 183, 65, 14},
    {"copper", 184, 115, 51},
    {"bronze", 205, 127, 50},
    {"gold", 255, 215, 0},
    {"silver", 192, 192, 192},
    {"platinum", 229, 228, 226}
};

int color_compare(const void *a, const void *b) {
    struct color *color1 = (struct color *)a;
    struct color *color2 = (struct color *)b;
    return strcmp(color1->name, color2->name);
}

struct color *color_find(char *name) {
    int low = 0;
    int high = sizeof(colors) / sizeof(struct color) - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = strcmp(name, colors[mid].name);

        if (cmp == 0) {
            return &colors[mid];
        } else if (cmp < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <color name>\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];

    struct color *color = color_find(color_name);

    if (color == NULL) {
        printf("Color not found: %s\n", color_name);
        return 1;
    }

    printf("Color: %s\n", color->name);
    printf("Red: %d\n", color->red);
    printf("Green: %d\n", color->green);
    printf("Blue: %d\n", color->blue);

    return 0;
}