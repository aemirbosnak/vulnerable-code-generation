//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_NAME_LENGTH 10

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    int red;
    int green;
    int blue;
} Color;

Color* createColor(char* name, int red, int green, int blue) {
    Color* color = (Color*) malloc(sizeof(Color));
    strncpy(color->name, name, MAX_COLOR_NAME_LENGTH);
    color->red = red;
    color->green = green;
    color->blue = blue;
    return color;
}

void printColor(Color* color) {
    printf("%s: %d, %d, %d\n", color->name, color->red, color->green, color->blue);
}

int main() {
    Color* colors[] = {
        createColor("red", 255, 0, 0),
        createColor("green", 0, 255, 0),
        createColor("blue", 0, 0, 255),
        createColor("yellow", 255, 255, 0),
        createColor("cyan", 0, 255, 255),
        createColor("magenta", 255, 0, 255),
        createColor("white", 255, 255, 255),
        createColor("black", 0, 0, 0)
    };

    int numColors = sizeof(colors) / sizeof(Color*);

    printf("Enter a color name to convert:\n");
    scanf("%s", colors[0]->name);

    for (int i = 1; i < numColors; i++) {
        if (strcmp(colors[i]->name, colors[0]->name) == 0) {
            printf("Color found!\n");
            printColor(colors[i]);
            return 0;
        }
    }

    printf("Color not found.\n");
    return 1;
}