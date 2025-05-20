//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 32
#define COLOR_CODE_LENGTH 7

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char hex[COLOR_CODE_LENGTH];
} Color;

Color colors[] = {
    {"black", "#000000"},
    {"white", "#FFFFFF"},
    {"red", "#FF0000"},
    {"green", "#00FF00"},
    {"blue", "#0000FF"},
    {"yellow", "#FFFF00"},
    {"cyan", "#00FFFF"},
    {"magenta", "#FF00FF"},
    {"gray", "#808080"},
    {"darkred", "#8B0000"},
    {"darkgreen", "#006400"},
    {"darkblue", "#00008B"},
    {"darkyellow", "#8B8B00"},
    {"darkcyan", "#008B8B"},
    {"darkmagenta", "#8B008B"},
    {"darkgray", "#A9A9A9"}
};

int num_colors = sizeof(colors) / sizeof(Color);

void print_usage() {
    printf("Usage:./color_code_converter [color_name]\n");
    printf("Available color names:\n");
    for (int i = 0; i < num_colors; i++) {
        printf("  %s\n", colors[i].name);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        print_usage();
        return 1;
    }

    Color *color = NULL;
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, argv[1]) == 0) {
            color = &colors[i];
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color name\n");
        print_usage();
        return 1;
    }

    printf("Color name: %s\n", color->name);
    printf("Color code: %s\n", color->hex);

    return 0;
}