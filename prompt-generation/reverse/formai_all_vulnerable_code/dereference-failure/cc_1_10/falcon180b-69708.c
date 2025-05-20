//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_NAMES 256
#define MAX_COLOR_NAME_LEN 32

typedef struct {
    char *name;
    int value;
} Color;

Color color_table[] = {
    {"black", 0},
    {"red", 1},
    {"green", 2},
    {"yellow", 3},
    {"blue", 4},
    {"magenta", 5},
    {"cyan", 6},
    {"white", 7}
};

int num_colors = sizeof(color_table) / sizeof(color_table[0]);

int main(int argc, char **argv) {
    int i, j, len, found = 0;
    char str[MAX_COLOR_NAME_LEN + 1];
    Color *color;

    if (argc < 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    for (i = 0; i < num_colors; i++) {
        if (strcmp(argv[1], color_table[i].name) == 0) {
            printf("%s -> %d\n", color_table[i].name, color_table[i].value);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Invalid color name.\n");
        return 1;
    }

    return 0;
}