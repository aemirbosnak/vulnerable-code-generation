//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_STR_LEN 64

typedef struct {
    char* name;
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Color;

Color colors[] = {
    {"white", 255, 255, 255},
    {"black", 0, 0, 0},
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
    {"lime", 191, 255, 0},
    {"navy blue", 0, 0, 128},
    {"teal", 0, 128, 128},
    {"olive", 128, 128, 0},
    {"maroon", 128, 0, 0},
    {"silver", 192, 192, 192},
    {"gold", 255, 215, 0}
};

const int num_colors = sizeof(colors) / sizeof(Color);

void print_help() {
    printf("Usage: color_code_converter <color name>\n");
    printf("Available colors:\n");
    for (int i = 0; i < num_colors; i++) {
        printf("  - %s\n", colors[i].name);
    }
}

Color* find_color_by_name(char* name) {
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, name) == 0) {
            return &colors[i];
        }
    }
    return NULL;
}

void print_color_code(Color* color) {
    printf("Color: %s (%d, %d, %d)\n", color->name, color->r, color->g, color->b);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        print_help();
        return 0;
    }
    char* color_name = argv[1];
    Color* color = find_color_by_name(color_name);
    if (color == NULL) {
        printf("Invalid color name: %s\n", color_name);
        return 1;
    }
    print_color_code(color);
    return 0;
}