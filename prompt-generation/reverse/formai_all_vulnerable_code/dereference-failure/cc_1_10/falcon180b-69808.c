//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COLOR_NAMES 100

typedef struct {
    char *name;
    char hex[7];
} Color;

int main() {
    FILE *inputFile;
    char line[MAX_LINE_LENGTH];
    char *token;
    int numColors = 0;
    Color colors[MAX_COLOR_NAMES];

    inputFile = fopen("colors.txt", "r");

    if (inputFile == NULL) {
        printf("Error: unable to open input file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, inputFile)!= NULL) {
        token = strtok(line, ",");

        while (token!= NULL) {
            if (numColors >= MAX_COLOR_NAMES) {
                printf("Error: too many color names.\n");
                exit(1);
            }

            strcpy(colors[numColors].name, token);
            sprintf(colors[numColors].hex, "#%02X%02X%02X", rand() % 256, rand() % 256, rand() % 256);

            numColors++;
            token = strtok(NULL, ",");
        }
    }

    fclose(inputFile);

    printf("Enter a color name: ");
    scanf("%s", line);

    token = strtok(line, " ");
    while (token!= NULL) {
        for (int i = 0; i < numColors; i++) {
            if (strcmp(token, colors[i].name) == 0) {
                printf("%s: %s\n", token, colors[i].hex);
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    return 0;
}