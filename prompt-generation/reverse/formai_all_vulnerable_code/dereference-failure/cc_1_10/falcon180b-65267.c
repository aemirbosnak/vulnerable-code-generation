//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1000
#define MAX_COLOR_NAMES 20
#define MAX_COLOR_VALUES 20

typedef struct {
    char name[20];
    int value;
} Color;

int main() {
    Color colors[MAX_COLOR_NAMES];
    int numColors = 0;
    char line[MAX_LINE_SIZE];
    FILE *file;
    char *filename;
    int i;

    /* Get the name of the input file from the user */
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    /* Open the input file */
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    /* Read in the color names and values from the input file */
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        if (numColors >= MAX_COLOR_NAMES) {
            printf("Error: Too many color names in file %s\n", filename);
            exit(1);
        }

        /* Get the color name from the line */
        char *name = strtok(line, " ");

        /* Get the color value from the line */
        char *valueStr = strtok(NULL, " ");
        int value = atoi(valueStr);

        /* Add the color to the array */
        strcpy(colors[numColors].name, name);
        colors[numColors].value = value;
        numColors++;
    }

    /* Close the input file */
    fclose(file);

    /* Get the name of the output file from the user */
    printf("Enter the name of the output file: ");
    scanf("%s", filename);

    /* Open the output file */
    file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    /* Write the color names and values to the output file */
    for (i = 0; i < numColors; i++) {
        fprintf(file, "%s %d\n", colors[i].name, colors[i].value);
    }

    /* Close the output file */
    fclose(file);

    return 0;
}