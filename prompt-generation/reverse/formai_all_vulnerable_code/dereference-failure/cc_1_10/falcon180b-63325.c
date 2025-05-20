//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 16
#define MAX_COLOR_NAME_LEN 7

typedef struct {
    char *name;
    int value;
} Color;

Color color_table[MAX_COLOR_NAMES] = {
    {"black", 0},
    {"red", 1},
    {"green", 2},
    {"yellow", 3},
    {"blue", 4},
    {"magenta", 5},
    {"cyan", 6},
    {"white", 7},
    {"gray", 8},
    {"light_red", 9},
    {"light_green", 10},
    {"light_yellow", 11},
    {"light_blue", 12},
    {"light_magenta", 13},
    {"light_cyan", 14},
    {"light_white", 15}
};

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];
    int color_value = -1;

    for (int i = 0; i < MAX_COLOR_NAMES; i++) {
        if (strcmp(color_name, color_table[i].name) == 0) {
            color_value = color_table[i].value;
            break;
        }
    }

    if (color_value == -1) {
        printf("Invalid color name.\n");
        return 1;
    }

    printf("Color code for %s is %d.\n", color_name, color_value);

    return 0;
}