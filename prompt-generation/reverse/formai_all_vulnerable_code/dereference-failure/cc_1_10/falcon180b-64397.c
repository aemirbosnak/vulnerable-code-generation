//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 100
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char *name;
    char code[MAX_COLOR_CODE_LENGTH];
} Color;

Color colors[MAX_COLOR_NAMES];
int numColors;

void addColor(char *name, char *code) {
    if (numColors >= MAX_COLOR_NAMES) {
        printf("Error: Too many colors defined.\n");
        exit(1);
    }
    strcpy(colors[numColors].name, name);
    strcpy(colors[numColors].code, code);
    numColors++;
}

int main() {
    addColor("red", "#FF0000");
    addColor("green", "#00FF00");
    addColor("blue", "#0000FF");
    addColor("yellow", "#FFFF00");
    addColor("purple", "#FF00FF");
    addColor("cyan", "#00FFFF");
    addColor("white", "#FFFFFF");
    addColor("black", "#000000");

    char input[MAX_COLOR_CODE_LENGTH];
    printf("Enter a color code: ");
    scanf("%s", input);

    int i;
    for (i = 0; i < numColors; i++) {
        if (strcmp(input, colors[i].code) == 0) {
            printf("Color name: %s\n", colors[i].name);
            return 0;
        }
    }

    printf("Invalid color code.\n");
    return 1;
}