//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int red;
    int green;
    int blue;
} color_t;

color_t colors[] = {
    {"black", 0, 0, 0},
    {"white", 255, 255, 255},
    {"red", 255, 0, 0},
    {"green", 0, 255, 0},
    {"blue", 0, 0, 255},
    {"yellow", 255, 255, 0},
    {"magenta", 255, 0, 255},
    {"cyan", 0, 255, 255},
    {"orange", 255, 165, 0},
    {"purple", 128, 0, 128},
    {"brown", 165, 42, 42},
    {"gray", 128, 128, 128},
    {"pink", 255, 192, 203},
    {"lime", 0, 255, 127},
    {"teal", 0, 128, 128},
    {"navy", 0, 0, 128},
    {"maroon", 128, 0, 0},
    {"olive", 128, 128, 0},
    {"silver", 192, 192, 192},
    {"gold", 255, 215, 0},
    {"wheat", 245, 222, 179},
    {"honeydew", 240, 255, 240},
    {"cornflowerblue", 100, 149, 237},
    {"darkblue", 0, 0, 139},
    {"chocolate", 210, 105, 30},
    {"crimson", 220, 20, 60},
    {"deeppink", 255, 20, 147},
    {"fuchsia", 255, 0, 255},
    {"hotpink", 255, 105, 180},
    {"indigo", 75, 0, 130},
    {"lavender", 230, 230, 250},
    {"magenta", 255, 0, 255},
    {"orchid", 218, 112, 214},
    {"peachpuff", 255, 218, 185},
    {"periwinkle", 204, 204, 255},
    {"plum", 221, 160, 221},
    {"turquoise", 64, 224, 208},
    {"violet", 238, 130, 238},
    {"yellowgreen", 154, 205, 50}
};

const int num_colors = sizeof(colors) / sizeof(color_t);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <color>\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];

    for (int i = 0; i < num_colors; i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            printf("The color code for %s is (%d, %d, %d).\n", color_name, colors[i].red, colors[i].green, colors[i].blue);
            return 0;
        }
    }

    printf("Invalid color name: %s\n", color_name);
    return 1;
}