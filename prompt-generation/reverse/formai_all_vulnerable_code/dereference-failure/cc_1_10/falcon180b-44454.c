//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *name;
    int value;
} Color;

Color colors[] = {
    {"black", 0},
    {"white", 1},
    {"red", 2},
    {"green", 3},
    {"blue", 4},
    {"yellow", 5},
    {"purple", 6},
    {"orange", 7},
    {"gray", 8},
    {"cyan", 9},
    {"pink", 10},
    {"brown", 11},
    {"lime", 12},
    {"navy", 13},
    {"aqua", 14},
    {"maroon", 15}
};

int main(int argc, char *argv[]) {
    char line[MAX_LINE_LENGTH];
    char *color_name;
    int color_value;

    printf("Enter a color name (or type 'exit' to quit):\n");
    fgets(line, MAX_LINE_LENGTH, stdin);

    while (strcmp(line, "exit")!= 0) {
        color_name = strtok(line, " ");
        color_value = -1;

        for (int i = 0; i < sizeof(colors) / sizeof(Color); i++) {
            if (strcmp(colors[i].name, color_name) == 0) {
                color_value = colors[i].value;
                break;
            }
        }

        if (color_value == -1) {
            printf("Invalid color name.\n");
        } else {
            printf("Color name: %s\n", color_name);
            printf("Color value: %d\n", color_value);
        }

        printf("Enter a color name (or type 'exit' to quit):\n");
        fgets(line, MAX_LINE_LENGTH, stdin);
    }

    return 0;
}