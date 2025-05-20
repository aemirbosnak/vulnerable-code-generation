//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLORS 256

typedef struct {
    char name[20];
    int value;
} Color;

Color colors[MAX_COLORS];
int num_colors = 0;

void init_colors() {
    colors[num_colors++] = (Color) {"black", 0};
    colors[num_colors++] = (Color) {"white", 7};
    colors[num_colors++] = (Color) {"red", 1};
    colors[num_colors++] = (Color) {"green", 2};
    colors[num_colors++] = (Color) {"blue", 4};
    colors[num_colors++] = (Color) {"yellow", 6};
    colors[num_colors++] = (Color) {"magenta", 5};
    colors[num_colors++] = (Color) {"cyan", 3};
    colors[num_colors++] = (Color) {"gray", 8};
}

int get_color_value(char *name) {
    int i;
    for (i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, name) == 0) {
            return colors[i].value;
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    init_colors();

    if (argc < 2) {
        printf("Usage: %s <color_name> <code>\n", argv[0]);
        return 1;
    }

    int color_value = get_color_value(argv[1]);
    if (color_value == -1) {
        printf("Invalid color name.\n");
        return 1;
    }

    printf("%s = %d\n", argv[1], color_value);

    return 0;
}