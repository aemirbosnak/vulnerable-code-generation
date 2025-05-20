//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

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
    {"cyan", 7},
    {"gray", 8},
    {"darkgray", 9},
    {"lightgray", 10},
    {"orange", 11},
    {"pink", 12},
    {"brown", 13},
    {"lightblue", 14},
    {"lightgreen", 15},
    {NULL, -1}
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    char *color_name = argv[1];
    Color *color = NULL;

    for (Color *c = colors; c->name!= NULL; c++) {
        if (strcmp(c->name, color_name) == 0) {
            color = c;
            break;
        }
    }

    if (color == NULL) {
        printf("Invalid color name.\n");
        return 1;
    }

    printf("RGB value: %d\n", color->value);
    printf("Hex value: #%06X\n", color->value);

    return 0;
}