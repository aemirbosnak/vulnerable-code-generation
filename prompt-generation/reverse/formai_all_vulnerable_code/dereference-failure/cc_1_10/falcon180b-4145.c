//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COLOR_NAME_LENGTH 20

typedef struct {
    char *name;
    char hex[7];
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
    {"lightgray", "#A9A9A9"},
    {"darkgray", "#333333"},
    {"lightred", "#FF5555"},
    {"lightgreen", "#55FF55"},
    {"lightblue", "#5555FF"},
    {"lightyellow", "#FFFF55"},
    {"lightcyan", "#55FFFF"},
    {"lightmagenta", "#FF55FF"},
    {"lightgray", "#D3D3D3"},
    {"orange", "#FFA500"},
    {"pink", "#FFC0CB"},
    {"purple", "#800080"},
    {"violet", "#EE82EE"},
    {"wheat", "#F5DEB3"},
    {"yellowgreen", "#9ACD32"}
};

int num_colors = sizeof(colors) / sizeof(Color);

char *get_color_name(char *color_hex) {
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].hex, color_hex) == 0) {
            return colors[i].name;
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <color_name_or_hex>\n", argv[0]);
        return 1;
    }

    char *color_str = argv[1];
    char *color_name = get_color_name(color_str);

    if (color_name == NULL) {
        printf("Invalid color name or hex value.\n");
        return 1;
    }

    printf("Color name: %s\n", color_name);
    printf("Hex value: #%s\n", color_str);

    return 0;
}