//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 1000

struct Color {
    char name[20];
    int red, green, blue;
};

int main() {
    int numColors = 0;
    struct Color colors[MAX_COLOR_NAMES];

    FILE *fp;
    char line[100];
    char *token;
    char *colorName;

    // Read in color names and RGB values
    fp = fopen("colors.txt", "r");

    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, " ");
        if (token!= NULL) {
            colorName = strtok(NULL, " ");

            if (numColors == MAX_COLOR_NAMES) {
                printf("Error: Too many colors defined.\n");
                exit(1);
            }

            strcpy(colors[numColors].name, colorName);
            colors[numColors].red = atoi(token);
            colors[numColors].green = atoi(strtok(NULL, " "));
            colors[numColors].blue = atoi(strtok(NULL, " "));

            numColors++;
        }
    }

    fclose(fp);

    // Convert color names to RGB values
    char colorNameInput[20];
    int colorIndex;

    while (1) {
        printf("Enter a color name or type 'quit' to exit: ");
        scanf("%s", colorNameInput);

        if (strcmp(colorNameInput, "quit") == 0) {
            break;
        }

        colorIndex = -1;
        for (int i = 0; i < numColors; i++) {
            if (strcmp(colors[i].name, colorNameInput) == 0) {
                colorIndex = i;
                break;
            }
        }

        if (colorIndex == -1) {
            printf("Error: Color not found.\n");
        } else {
            printf("RGB values for %s: %d %d %d\n", colors[colorIndex].name, colors[colorIndex].red, colors[colorIndex].green, colors[colorIndex].blue);
        }
    }

    return 0;
}