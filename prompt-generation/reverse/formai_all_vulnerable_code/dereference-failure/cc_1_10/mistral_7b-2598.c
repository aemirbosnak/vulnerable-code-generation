//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT 1024
#define MAX_COLOR 64

typedef struct {
    char name[20];
    int r, g, b;
} Color;

Color colors[MAX_COLOR] = {
    {"black", 0, 0, 0},
    {"navy", 0, 0, 128},
    {"red", 255, 0, 0},
    {"green", 0, 255, 0},
    {"yellow", 255, 255, 0},
    {"blue", 0, 0, 255},
    {"purple", 128, 0, 128},
    {"pink", 255, 192, 203},
    {"teal", 0, 128, 128},
    {"gray", 128, 128, 128},
    {"silver", 192, 192, 192},
    {"maroon", 128, 0, 0},
    {"white", 255, 255, 255},
};

int main(int argc, char **argv) {
    char input[MAX_INPUT];
    Color *current;
    int i;

    if (argc < 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);

    for (i = 0; i < MAX_COLOR; i++) {
        current = &colors[i];
        if (strcasecmp(input, current->name) == 0) {
            printf("R: %d, G: %d, B: %d\n", current->r, current->g, current->b);
            return 0;
        }
    }

    printf("Invalid color name: %s\n", input);
    return 1;
}