//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

typedef struct {
    char *name;
    int value;
} Color;

Color colors[MAX_COLORS];
int num_colors = 0;

void add_color(char *name, int value) {
    if (num_colors >= MAX_COLORS) {
        fprintf(stderr, "Error: Too many colors defined.\n");
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

    fprintf(stderr, "Error: Color '%s' not found.\n", name);
    exit(1);
}

int main() {
    add_color("red", 0xff0000);
    add_color("green", 0x00ff00);
    add_color("blue", 0x0000ff);

    char input[1024];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        char *color_name = strtok(input, " ");
        if (color_name == NULL) {
            fprintf(stderr, "Error: Invalid input.\n");
            continue;
        }

        int color_value = get_color_value(color_name);
        printf("#%06x\n", color_value);
    }

    return 0;
}