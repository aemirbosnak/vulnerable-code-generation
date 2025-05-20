//Falcon-180B DATASET v1.0 Category: Error handling ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *file;
    char line[MAX_LINE_SIZE];

    // Check if the correct number of arguments were provided
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <filename> <output>\n", argv[0]);
        return 1;
    }

    // Open the input file
    if ((file = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error opening file '%s': %s\n", argv[1], strerror(errno));
        return 1;
    }

    // Open the output file
    if ((file = fopen(argv[2], "w")) == NULL) {
        fprintf(stderr, "Error opening file '%s': %s\n", argv[2], strerror(errno));
        fclose(file);
        return 1;
    }

    // Read the input file line by line
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        // Reverse the characters in the line
        int i = 0, j = strlen(line) - 1;
        while (i < j) {
            char temp = line[i];
            line[i] = line[j];
            line[j] = temp;
            i++;
            j--;
        }
        // Write the reversed line to the output file
        if (fputs(line, file) == EOF) {
            fprintf(stderr, "Error writing to file '%s': %s\n", argv[2], strerror(errno));
            fclose(file);
            return 1;
        }
    }

    // Close the files
    fclose(file);
    fclose(file);

    return 0;
}