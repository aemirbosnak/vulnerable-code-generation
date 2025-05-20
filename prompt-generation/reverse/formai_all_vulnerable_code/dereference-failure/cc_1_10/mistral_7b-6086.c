//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODES 100
#define COLOR_CODE_LENGTH 7

typedef struct {
    char name[20];
    char code[COLOR_CODE_LENGTH];
} ColorCode;

ColorCode colorCodes[MAX_COLOR_CODES];

int findColorIndex(char* name) {
    for (int i = 0; i < MAX_COLOR_CODES; i++) {
        if (strcmp(colorCodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void convertColorCode(char* code) {
    int r, g, b;

    if (sscanf(code, "#%x%x%x", &r, &g, &b) != 3) {
        printf("Invalid color code: %s\n", code);
        return;
    }

    printf("R: %d, G: %d, B: %d\n", r, g, b);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <color_code>\n", argv[0]);
        return 1;
    }

    // Initialize color codes
    strcpy(colorCodes[0].name, "AliceBlue");
    strcpy(colorCodes[0].code, "#F0F8FF");

    strcpy(colorCodes[1].name, "AntiqueWhite");
    strcpy(colorCodes[1].code, "#FAEBD7");

    // ... add more color codes here ...

    int index = findColorIndex(argv[1]);
    if (index == -1) {
        printf("Unknown color: %s\n", argv[1]);
        return 1;
    }

    printf("Color name: %s\n", colorCodes[index].name);
    convertColorCode(argv[1]);

    return 0;
}