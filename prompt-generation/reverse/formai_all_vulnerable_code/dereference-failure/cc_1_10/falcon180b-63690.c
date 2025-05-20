//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_COLORS 16

typedef struct {
    char name[MAX_LINE_LENGTH];
    int value;
} Color;

Color colors[MAX_COLORS] = {
    {"black", 0},
    {"white", 7},
    {"red", 1},
    {"green", 2},
    {"blue", 4},
    {"yellow", 6},
    {"magenta", 5},
    {"cyan", 3},
    {"gray", 8},
    {"light_red", 9},
    {"light_green", 10},
    {"light_blue", 12},
    {"light_yellow", 14},
    {"light_magenta", 13},
    {"light_cyan", 11},
    {"light_gray", 7}
};

int get_color_value(char *color_name) {
    int i;
    for (i = 0; i < MAX_COLORS; i++) {
        if (strcmp(color_name, colors[i].name) == 0) {
            return colors[i].value;
        }
    }
    return -1;
}

void print_color_table() {
    int i;
    printf("Color Value\n");
    for (i = 0; i < MAX_COLORS; i++) {
        printf("%-15s %d\n", colors[i].name, colors[i].value);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    int color_value = get_color_value(argv[1]);

    if (color_value == -1) {
        printf("Invalid color name.\n");
        return 1;
    }

    printf("Color value for '%s': %d\n", argv[1], color_value);

    return 0;
}