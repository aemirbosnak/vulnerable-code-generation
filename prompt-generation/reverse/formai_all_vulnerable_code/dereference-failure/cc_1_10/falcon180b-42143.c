//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 100
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char *name;
    char code[MAX_COLOR_CODE_LENGTH + 1];
} Color;

Color colors[MAX_COLOR_NAMES];
int num_colors;

void add_color(char *name, char *code) {
    if (num_colors >= MAX_COLOR_NAMES) {
        printf("Error: Too many colors defined.\n");
        exit(1);
    }

    strcpy(colors[num_colors].name, name);
    strcpy(colors[num_colors].code, code);

    num_colors++;
}

int main() {
    add_color("red", "\033[31m");
    add_color("green", "\033[32m");
    add_color("yellow", "\033[33m");
    add_color("blue", "\033[34m");
    add_color("magenta", "\033[35m");
    add_color("cyan", "\033[36m");
    add_color("white", "\033[37m");

    char input[100];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        int i;
        for (i = 0; i < num_colors; i++) {
            if (strstr(input, colors[i].code)!= NULL) {
                printf("\033[0m");
                printf("%s", colors[i].name);
                printf("\033[0m ");
            }
        }

        printf("%s", input);
    }

    return 0;
}