//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_NAMES 256
#define MAX_COLOR_VALUE 32
#define MAX_COLOR_CODE 7

typedef struct {
    char *name;
    char value[MAX_COLOR_VALUE];
    char code[MAX_COLOR_CODE];
} Color;

Color colors[MAX_COLOR_NAMES];
int num_colors = 0;

void add_color(char *name, char *value, char *code) {
    if (num_colors >= MAX_COLOR_NAMES) {
        printf("Error: Too many colors defined.\n");
        exit(1);
    }
    strcpy(colors[num_colors].name, name);
    strcpy(colors[num_colors].value, value);
    strcpy(colors[num_colors].code, code);
    num_colors++;
}

char *get_color_value(char *name) {
    int i;
    for (i = 0; i < num_colors; i++) {
        if (strcmp(colors[i].name, name) == 0) {
            return colors[i].value;
        }
    }
    return NULL;
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
    add_color("red", "#FF0000", "FF0000");
    add_color("green", "#00FF00", "00FF00");
    add_color("blue", "#0000FF", "0000FF");
    add_color("yellow", "#FFFF00", "FFFF00");
    add_color("cyan", "#00FFFF", "00FFFF");
    add_color("magenta", "#FF00FF", "FF00FF");
    add_color("white", "#FFFFFF", "FFFFFF");
    add_color("black", "#000000", "000000");

    char input[MAX_COLOR_VALUE];
    while (1) {
        printf("Enter a color name or value: ");
        scanf("%s", input);
        char *value = get_color_value(input);
        if (value!= NULL) {
            printf("Value: %s\n", value);
        } else {
            char *code = get_color_code(input);
            if (code!= NULL) {
                printf("Code: %s\n", code);
            } else {
                printf("Error: Invalid color.\n");
            }
        }
    }

    return 0;
}