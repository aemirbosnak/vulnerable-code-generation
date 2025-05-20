//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_CODE_LENGTH 7
#define MAX_COLOR_NAME_LENGTH 20

typedef struct {
    char* colorCode;
    char* colorName;
} ColorCodeConverter;

ColorCodeConverter* createColorCodeConverter() {
    ColorCodeConverter* converter = (ColorCodeConverter*)malloc(sizeof(ColorCodeConverter));
    converter->colorCode = (char*)malloc(MAX_COLOR_CODE_LENGTH * sizeof(char));
    converter->colorName = (char*)malloc(MAX_COLOR_NAME_LENGTH * sizeof(char));
    return converter;
}

void destroyColorCodeConverter(ColorCodeConverter* converter) {
    free(converter->colorCode);
    free(converter->colorName);
    free(converter);
}

void setColorCode(ColorCodeConverter* converter, char* colorCode) {
    strncpy(converter->colorCode, colorCode, MAX_COLOR_CODE_LENGTH);
}

void setColorName(ColorCodeConverter* converter, char* colorName) {
    strncpy(converter->colorName, colorName, MAX_COLOR_NAME_LENGTH);
}

char* getColorName(ColorCodeConverter* converter) {
    return converter->colorName;
}

char* getColorCode(ColorCodeConverter* converter) {
    return converter->colorCode;
}

int main() {
    ColorCodeConverter* converter = createColorCodeConverter();
    char colorCode[MAX_COLOR_CODE_LENGTH];
    char colorName[MAX_COLOR_NAME_LENGTH];

    printf("Enter a color code (e.g. #FF0000): ");
    scanf("%s", colorCode);

    setColorCode(converter, colorCode);

    printf("Enter a color name: ");
    scanf("%s", colorName);

    setColorName(converter, colorName);

    printf("Color code: %s\n", getColorCode(converter));
    printf("Color name: %s\n", getColorName(converter));

    destroyColorCodeConverter(converter);

    return 0;
}