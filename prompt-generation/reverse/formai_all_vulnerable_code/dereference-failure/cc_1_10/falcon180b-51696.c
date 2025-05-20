//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAMES 1000
#define MAX_COLOR_CODE_LENGTH 7

typedef struct {
    char name[MAX_COLOR_NAMES];
    char code[MAX_COLOR_CODE_LENGTH];
} Color;

int main() {
    FILE *fp;
    char line[1000];
    char *token;
    Color colors[MAX_COLOR_NAMES];
    int numColors = 0;
    char input[MAX_COLOR_CODE_LENGTH];

    // Open the color code file
    fp = fopen("colors.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open colors.txt file.\n");
        return 1;
    }

    // Read in the color codes
    while (fgets(line, sizeof(line), fp)!= NULL) {
        // Split the line into the color name and code
        token = strtok(line, ",");
        strcpy(colors[numColors].name, token);
        token = strtok(NULL, ",");
        strcpy(colors[numColors].code, token);
        numColors++;
    }

    // Close the color code file
    fclose(fp);

    // Get user input
    printf("Enter a color code (e.g. #FF0000): ");
    scanf("%s", input);

    // Convert the input color code to a color name
    int i;
    for (i = 0; i < numColors; i++) {
        if (strcmp(input, colors[i].code) == 0) {
            printf("Color name: %s\n", colors[i].name);
            break;
        }
    }

    // Close the program
    return 0;
}