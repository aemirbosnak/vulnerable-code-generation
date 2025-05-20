//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int value;
} Color;

Color colors[] = {
    {"black", 0},
    {"white", 7},
    {"red", 31},
    {"green", 32},
    {"yellow", 33},
    {"blue", 34},
    {"magenta", 35},
    {"cyan", 36},
    {"gray", 37},
    {"light_red", 91},
    {"light_green", 92},
    {"light_yellow", 93},
    {"light_blue", 94},
    {"light_magenta", 95},
    {"light_cyan", 96},
    {"white", 97}
};

int num_colors = sizeof(colors) / sizeof(Color);

char *get_color_name(int value) {
    for (int i = 0; i < num_colors; i++) {
        if (colors[i].value == value) {
            return colors[i].name;
        }
    }
    return "unknown";
}

int get_color_value(char *name) {
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, name) == 0) {
            return colors[i].value;
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <color_name|color_value>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    int value = -1;

    if (isdigit(input[0])) {
        value = atoi(input);
        char *name = get_color_name(value);
        printf("Value: %d\nName: %s\n", value, name);
    } else {
        value = get_color_value(input);
        if (value == -1) {
            printf("Invalid color name.\n");
        } else {
            printf("Value: %d\nName: %s\n", value, input);
        }
    }

    return 0;
}