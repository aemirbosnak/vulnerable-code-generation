//FormAI DATASET v1.0 Category: Data recovery tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int isDataValid(char *data) {
    // checks if the data is valid or not, returns 1 if valid, else 0
    if (strlen(data) == 0)
        return 0;
    else
        return 1;
}

int main(int argc, char *argv[]) {
    // check if the correct number of arguments are passed
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    // open the input file in read mode
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    // open the output file in write mode
    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        printf("Error opening file: %s\n", argv[2]);
        return 1;
    }

    // allocate memory for buffer
    char buffer[BUFFER_SIZE];

    // read each line from the input file
    while (fgets(buffer, BUFFER_SIZE, inputFile)) {
        // check if the data is valid
        if (isDataValid(buffer)) {
            // write the data to the output file
            fprintf(outputFile, "%s", buffer);
        }
    }

    // close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("Data recovery successful!\n");

    return 0;
}