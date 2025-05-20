//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_COLOR_NAME_LENGTH 64
#define MAX_COLOR_CODE_LENGTH 8
#define MAX_COLOR_NAMES 100
#define MAX_COLOR_CODES 100


typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    char code[MAX_COLOR_CODE_LENGTH];
} Color;

Color colors[MAX_COLOR_NAMES];
int numColors;

void generateRandomColorName() {
    char name[MAX_COLOR_NAME_LENGTH];
    sprintf(name, "Color %d", rand() % 1000);
    strcpy(colors[numColors].name, name);
}

void generateRandomColorCode() {
    char code[MAX_COLOR_CODE_LENGTH];
    sprintf(code, "#%02X%02X%02X", rand() % 256, rand() % 256, rand() % 256);
    strcpy(colors[numColors].code, code);
}

void addColor() {
    generateRandomColorName();
    generateRandomColorCode();
    numColors++;
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Color Code Converter!\n");
    printf("How many colors do you want to convert? ");
    scanf("%d", &numColors);

    for (int i = 0; i < numColors; i++) {
        addColor();
    }

    printf("\n");
    printf("Color Name  |  Color Code\n");
    printf("-----------|-------------\n");

    for (int i = 0; i < numColors; i++) {
        printf("%-30s|  %s\n", colors[i].name, colors[i].code);
    }

    return 0;
}