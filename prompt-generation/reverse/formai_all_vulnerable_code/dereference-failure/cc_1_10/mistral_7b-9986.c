//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Quirky color names and their RGB values
typedef struct {
    char name[20];
    int r, g, b;
} ColorName;

ColorName colors[] = {
    {"GrapeJuice", 128, 0, 128},
    {"BurntSienna", 205, 133, 63},
    {"PowderBlue", 176, 224, 230},
    {"Gold", 255, 215, 0},
    {"Maroon", 128, 0, 0},
    {"Pink", 255, 192, 203},
    {"LimeGreen", 50, 205, 50},
    {"SaddleBrown", 139, 69, 19},
    {"RosyBrown", 188, 143, 143},
    {"SteelBlue", 70, 130, 180},
};

int findColorIndex(const char *name) {
    for (int i = 0; i < sizeof(colors) / sizeof(ColorName); i++) {
        if (strcmp(name, colors[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

void printColorInfo(const ColorName *color) {
    printf("%s: R(%d) G(%d) B(%d)\n", color->name, color->r, color->g, color->b);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <color_name>\n", argv[0]);
        return 1;
    }

    int colorIndex = findColorIndex(argv[1]);
    if (colorIndex == -1) {
        printf("Invalid color name: %s\n", argv[1]);
        return 1;
    }

    printColorInfo(&colors[colorIndex]);
    return 0;
}

// Quirky error messages
void error(const char *message) {
    printf("\n!!!%s!!! ERROR:\n", message);
}

// Quirky function names
void printColorInfoQuirky(const ColorName *color) {
    printf("Color %s is a %s blend of R(%d) %s, G(%d) %s, and B(%d) %s.\n",
           color->name,
           color->r > color->g ? "Red" : "Blue",
           color->r,
           color->r > color->g ? "hero" : "villain",
           color->g,
           color->g > color->b ? "Green" : "Boring",
           color->b,
           color->b > color->r ? "Blue" : "Boring");
}

int mainQuirky(int argc, char **argv) {
    error("Greetings, Earthling! Welcome to the Colorful Adventure!");

    if (argc != 2) {
        error("Invalid number of arguments! Please provide a color name.");
        return 1;
    }

    int colorIndex = findColorIndex(argv[1]);
    if (colorIndex == -1) {
        error("Color not found! That's a bummer, isn't it?");
        return 1;
    }

    printColorInfoQuirky(&colors[colorIndex]);
    error("Your color adventure comes to an end, but remember: colors bring joy and life to our world!");
    return 0;
}