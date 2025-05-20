//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLORS 256
#define MAX_COLOR_NAME_LENGTH 32

typedef struct {
    char name[MAX_COLOR_NAME_LENGTH];
    int red;
    int green;
    int blue;
} Color;

int main() {
    Color colors[MAX_COLORS];
    int numColors = 0;

    FILE *inputFile = fopen("colors.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    char line[MAX_COLOR_NAME_LENGTH];
    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        if (numColors == MAX_COLORS) {
            printf("Error: Maximum number of colors reached.\n");
            fclose(inputFile);
            return 1;
        }

        char *token = strtok(line, ",");
        strcpy(colors[numColors].name, token);

        token = strtok(NULL, ",");
        colors[numColors].red = atoi(token);

        token = strtok(NULL, ",");
        colors[numColors].green = atoi(token);

        token = strtok(NULL, ",");
        colors[numColors].blue = atoi(token);

        numColors++;
    }

    fclose(inputFile);

    printf("Enter a color name or press Enter to quit: ");
    char input[MAX_COLOR_NAME_LENGTH];
    fgets(input, sizeof(input), stdin);

    char *colorName = strtok(input, "\n");
    while (colorName!= NULL) {
        for (int i = 0; i < numColors; i++) {
            if (strcmp(colors[i].name, colorName) == 0) {
                printf("Color code for %s: %d,%d,%d\n", colors[i].name, colors[i].red, colors[i].green, colors[i].blue);
                break;
            }
        }
        printf("Enter a color name or press Enter to quit: ");
        fgets(input, sizeof(input), stdin);
        colorName = strtok(input, "\n");
    }

    return 0;
}