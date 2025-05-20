//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 256
#define MAX_COLORS 256

typedef struct {
    char *name;
    int value;
} Color;

Color colors[MAX_COLORS];
int num_colors = 0;

void add_color(char *name, int value) {
    if (num_colors >= MAX_COLORS) {
        printf("Error: Too many colors defined.\n");
        exit(1);
    }
    colors[num_colors].name = strdup(name);
    colors[num_colors].value = value;
    num_colors++;
}

int get_color_value(char *name) {
    for (int i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, name) == 0) {
            return colors[i].value;
        }
    }
    printf("Error: Color '%s' not found.\n", name);
    exit(1);
}

char *get_color_name(int value) {
    for (int i = 0; i < num_colors; i++) {
        if (colors[i].value == value) {
            return colors[i].name;
        }
    }
    printf("Error: Color value %d not found.\n", value);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <color_name> <color_value>\n", argv[0]);
        exit(1);
    }

    add_color(argv[1], atoi(argv[2]));

    return 0;
}