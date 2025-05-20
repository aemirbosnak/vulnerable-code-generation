//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 100
#define MAX_COLOR_CODES 100

typedef struct {
    char *name;
    char *code;
} Color;

Color colors[MAX_COLOR_NAMES];
int numColors = 0;

void addColor(char *name, char *code) {
    if (numColors >= MAX_COLOR_NAMES) {
        printf("Error: Maximum number of colors reached.\n");
        return;
    }
    colors[numColors].name = strdup(name);
    colors[numColors].code = strdup(code);
    numColors++;
}

int getColorIndex(char *name) {
    for (int i = 0; i < numColors; i++) {
        if (strcmp(colors[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    addColor("red", "#FF0000");
    addColor("green", "#00FF00");
    addColor("blue", "#0000FF");

    char input[100];
    while (1) {
        printf("Enter a color name or code: ");
        scanf("%s", input);

        int colorIndex = getColorIndex(input);
        if (colorIndex >= 0) {
            printf("Color code for %s: %s\n", colors[colorIndex].name, colors[colorIndex].code);
        } else {
            printf("Color not found.\n");
        }
    }

    return 0;
}