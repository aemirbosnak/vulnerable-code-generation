//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

typedef enum {
    RED,
    GREEN,
    BLUE
} Color;

typedef struct {
    char *name;
    Color color;
} ColorName;

ColorName colorNames[] = {
    {"Red", RED},
    {"Green", GREEN},
    {"Blue", BLUE}
};

int getColor(char *colorName) {
    int i;
    for (i = 0; i < sizeof(colorNames) / sizeof(ColorName); i++) {
        if (strcmp(colorNames[i].name, colorName) == 0) {
            return colorNames[i].color;
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    Color color = getColor(argv[1]);
    if (color == -1) {
        printf("Invalid color name.\n");
        return 1;
    }

    printf("Color code for %s:\n", argv[1]);
    printf("RGB: %d,%d,%d\n", (int)((color >> 16) & 0xFF), (int)((color >> 8) & 0xFF), (int)(color & 0xFF));
    printf("Hex: #%06X\n", color);

    return 0;
}