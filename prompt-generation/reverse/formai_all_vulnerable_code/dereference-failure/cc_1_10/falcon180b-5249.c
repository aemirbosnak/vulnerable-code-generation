//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COLOR_NAMES 256

typedef struct {
    char *name;
    int value;
} ColorName;

ColorName colorNames[MAX_COLOR_NAMES];
int numColorNames = 0;

void addColorName(char *name, int value) {
    if (numColorNames >= MAX_COLOR_NAMES) {
        printf("Error: Too many color names defined.\n");
        return;
    }

    colorNames[numColorNames].name = strdup(name);
    colorNames[numColorNames].value = value;
    numColorNames++;
}

int main() {
    addColorName("red", 0xff0000);
    addColorName("green", 0x00ff00);
    addColorName("blue", 0x0000ff);
    addColorName("yellow", 0xffff00);
    addColorName("purple", 0x800080);

    int choice;
    printf("Enter your choice:\n1. Convert color name to RGB value\n2. Convert RGB value to color name\n");
    scanf("%d", &choice);

    if (choice == 1) {
        char colorName[50];
        printf("Enter color name: ");
        scanf("%s", colorName);

        ColorName *color = NULL;
        for (int i = 0; i < numColorNames; i++) {
            if (strcmp(colorNames[i].name, colorName) == 0) {
                color = &colorNames[i];
                break;
            }
        }

        if (color == NULL) {
            printf("Error: Color name not found.\n");
        } else {
            printf("RGB value: %06x\n", color->value);
        }
    } else if (choice == 2) {
        int rgbValue;
        printf("Enter RGB value (in hexadecimal): ");
        scanf("%06x", &rgbValue);

        ColorName *color = NULL;
        for (int i = 0; i < numColorNames; i++) {
            if (colorNames[i].value == rgbValue) {
                color = &colorNames[i];
                break;
            }
        }

        if (color == NULL) {
            printf("Error: Color name not found.\n");
        } else {
            printf("Color name: %s\n", color->name);
        }
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}