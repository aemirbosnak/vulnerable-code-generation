//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_COLOR_NAME_LENGTH 20

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char hex[8];
} Color;

Color colors[] = {
    {"red", "#FF0000"},
    {"green", "#00FF00"},
    {"blue", "#0000FF"},
    {"yellow", "#FFFF00"},
    {"cyan", "#00FFFF"},
    {"magenta", "#FF00FF"},
    {"black", "#000000"},
    {"white", "#FFFFFF"}
};

int color_count = sizeof(colors) / sizeof(Color);

void print_usage() {
    printf("Usage:./program <color_name>\n");
    printf("Color names: red, green, blue, yellow, cyan, magenta, black, white\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        print_usage();
        return 1;
    }

    char *color_name = argv[1];
    int color_index = -1;

    for (int i = 0; i < color_count; i++) {
        if (strcmp(colors[i].name, color_name) == 0) {
            color_index = i;
            break;
        }
    }

    if (color_index == -1) {
        printf("Invalid color name\n");
        return 1;
    }

    printf("Color name: %s\n", colors[color_index].name);
    printf("Hex code: #%s\n", colors[color_index].hex);

    return 0;
}