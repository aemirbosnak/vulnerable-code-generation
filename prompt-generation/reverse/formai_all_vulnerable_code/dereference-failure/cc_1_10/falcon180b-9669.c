//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE_LENGTH 7
#define MAX_COLOR_NAMES 256

typedef struct {
    char *name;
    char code[MAX_CODE_LENGTH];
} color_t;

color_t colors[MAX_COLOR_NAMES];
int num_colors = 0;

void add_color(char *name, char *code) {
    if (num_colors >= MAX_COLOR_NAMES) {
        printf("Error: Too many colors defined.\n");
        exit(1);
    }

    strncpy(colors[num_colors].name, name, 256);
    strncpy(colors[num_colors].code, code, MAX_CODE_LENGTH);

    num_colors++;
}

char *get_color_code(char *name) {
    int i;

    for (i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, name) == 0) {
            return colors[i].code;
        }
    }

    return NULL;
}

int main() {
    add_color("red", "#FF0000");
    add_color("green", "#00FF00");
    add_color("blue", "#0000FF");

    char *code = get_color_code("red");

    if (code!= NULL) {
        printf("The color code for %s is %s.\n", "red", code);
    } else {
        printf("Error: Color not found.\n");
    }

    return 0;
}