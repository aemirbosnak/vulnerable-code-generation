//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    char inputFile[100], outputFile[100];
    FILE *input, *output;
    int width, height, i, j, count = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", inputFile);

    printf("Enter the name of the output file: ");
    scanf("%s", outputFile);

    input = fopen(inputFile, "r");

    if (input == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }

    fscanf(input, "%d %d", &width, &height);
    fclose(input);

    output = fopen(outputFile, "w");

    if (output == NULL) {
        printf("Error: Output file could not be created.\n");
        exit(1);
    }

    printf("Enter the characters to use for ASCII art (up to %d): ", width);

    for (i = 0; i < width; i++) {
        scanf(" %c", &(input[i]));
    }

    input = fopen(inputFile, "r");

    if (input == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fscanf(input, "%c", &(inputFile[count]));
            fprintf(output, "%c", inputFile[count]);
            count++;
        }
        fprintf(output, "\n");
    }

    fclose(input);
    fclose(output);

    printf("ASCII art generated successfully!\n");

    return 0;
}