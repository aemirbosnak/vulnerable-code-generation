//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_NAMES 100
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char *name;
    char code[MAX_COLOR_CODE_LENGTH];
} Color;

Color colors[MAX_COLOR_NAMES];
int num_colors;

void add_color(char *name, char *code) {
    if (num_colors >= MAX_COLOR_NAMES) {
        printf("Error: Too many colors defined.\n");
        return;
    }

    strcpy(colors[num_colors].name, name);
    strcpy(colors[num_colors].code, code);

    num_colors++;
}

int main() {
    int i;
    char input[100];

    printf("Enter color names and codes, one per line.\n");
    printf("Format: name code\n");
    printf("Example: red #FF0000\n");

    while (fgets(input, 100, stdin)!= NULL) {
        input[strcspn(input, "\n")] = '\0'; // Remove newline character

        char *name = strtok(input, " ");
        char *code = strtok(NULL, " ");

        if (name == NULL || code == NULL) {
            printf("Error: Invalid input format.\n");
            continue;
        }

        add_color(name, code);
    }

    printf("\n");
    printf("Color Code Converter\n");
    printf("=====================\n");

    for (i = 0; i < num_colors; i++) {
        printf("%s -> %s\n", colors[i].name, colors[i].code);
    }

    return 0;
}