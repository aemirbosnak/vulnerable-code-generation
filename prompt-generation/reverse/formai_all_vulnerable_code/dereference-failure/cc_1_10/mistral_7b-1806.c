//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define COLOR_SIZE 3

typedef struct {
    char name[20];
    int r;
    int g;
    int b;
} Color;

Color colors[] = {
    {"Red", 255, 0, 0},
    {"Green", 0, 255, 0},
    {"Blue", 0, 0, 255},
    {"Yellow", 255, 255, 0},
    {"Pink", 255, 192, 203},
    {"Black", 0, 0, 0},
    {"White", 255, 255, 255}
};

int findColorIndex(char* colorName) {
    for (int i = 0; i < sizeof(colors) / sizeof(colors[0]); i++) {
        if (strcmp(colorName, colors[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <color_name> <rgb_value>\n", argv[0]);
        return 1;
    }

    int colorIndex = findColorIndex(argv[1]);

    if (colorIndex == -1) {
        printf("Error: Unknown color name.\n");
        return 1;
    }

    sscanf(argv[2], "%d %d %d", &colors[colorIndex].r, &colors[colorIndex].g, &colors[colorIndex].b);

    printf("Successfully updated color: %s\n", argv[1]);
    printf("New RGB values: R=%d, G=%d, B=%d\n", colors[colorIndex].r, colors[colorIndex].g, colors[colorIndex].b);

    return 0;
}