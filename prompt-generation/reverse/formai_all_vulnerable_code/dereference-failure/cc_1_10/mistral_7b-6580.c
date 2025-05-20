//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_LENGTH 5

typedef struct {
    char name[MAX_COLOR_LENGTH];
    int r;
    int g;
    int b;
} Color;

Color colors[] = {
    {"Red", 255, 0, 0},
    {"Green", 0, 255, 0},
    {"Blue", 0, 0, 255},
    {"Cyan", 0, 255, 255},
    {"Magenta", 255, 0, 255},
    {"Yellow", 255, 255, 0},
    {"Black", 0, 0, 0},
    {"White", 255, 255, 255}
};

int getColorIndex(char* colorName) {
    int i;
    for (i = 0; i < sizeof(colors) / sizeof(colors[0]); i++) {
        if (strcmp(colorName, colors[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

void printColor(Color color) {
    printf("\033[38;5;%sm%s\033[0m", color.r, colors[color.r > 0 ? color.r - 1 : 0].name);
    printf("%s", colors[color.g > 0 ? color.g - 1 : 0].name);
    printf("%s", colors[color.b > 0 ? color.b - 1 : 0].name);
}

int main(int argc, char* argv[]) {
    int i, len;
    if (argc < 2) {
        printf("Usage: %s <color>\n", argv[0]);
        return 1;
    }

    int colorIndex = getColorIndex(argv[1]);
    if (colorIndex == -1) {
        printf("Invalid color: %s\n", argv[1]);
        return 1;
    }

    printColor(colors[colorIndex]);
    printf("\n");

    return 0;
}