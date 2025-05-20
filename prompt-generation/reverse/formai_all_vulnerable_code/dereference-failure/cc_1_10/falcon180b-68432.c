//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    ORANGE,
    PURPLE,
    WHITE,
    BLACK,
    NUM_COLORS
};

struct color_code {
    char *name;
    int value;
};

static struct color_code color_table[] = {
    {"RED", RED},
    {"GREEN", GREEN},
    {"BLUE", BLUE},
    {"YELLOW", YELLOW},
    {"ORANGE", ORANGE},
    {"PURPLE", PURPLE},
    {"WHITE", WHITE},
    {"BLACK", BLACK},
};

static int num_colors = sizeof(color_table) / sizeof(color_table[0]);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];
    int color_value;

    for (int i = 0; i < num_colors; i++) {
        if (strcmp(color_name, color_table[i].name) == 0) {
            color_value = color_table[i].value;
            break;
        }
    }

    if (color_value == 0) {
        printf("Invalid color name.\n");
        return 1;
    }

    printf("Color code for %s: %d\n", color_name, color_value);

    return 0;
}