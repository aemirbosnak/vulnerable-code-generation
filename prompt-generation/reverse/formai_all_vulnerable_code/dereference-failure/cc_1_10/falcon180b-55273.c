//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *hexCode;
    int red;
    int green;
    int blue;
} ColorCode;

ColorCode *parseColorCodeLine(char *line);
void printColorCode(ColorCode *colorCode);
void freeColorCode(ColorCode *colorCode);

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    ColorCode *colorCode;

    file = fopen("color_codes.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        colorCode = parseColorCodeLine(line);
        printColorCode(colorCode);
        freeColorCode(colorCode);
    }

    fclose(file);

    return 0;
}

ColorCode *parseColorCodeLine(char *line) {
    char *hexCode;
    int red, green, blue;

    hexCode = strtok(line, " ");
    red = strtol(strtok(NULL, " "), NULL, 16);
    green = strtol(strtok(NULL, " "), NULL, 16);
    blue = strtol(strtok(NULL, " "), NULL, 16);

    ColorCode *colorCode = malloc(sizeof(ColorCode));
    colorCode->hexCode = strdup(hexCode);
    colorCode->red = red;
    colorCode->green = green;
    colorCode->blue = blue;

    return colorCode;
}

void printColorCode(ColorCode *colorCode) {
    printf("Hex code: %s\n", colorCode->hexCode);
    printf("RGB: %d, %d, %d\n", colorCode->red, colorCode->green, colorCode->blue);
}

void freeColorCode(ColorCode *colorCode) {
    free(colorCode->hexCode);
    free(colorCode);
}