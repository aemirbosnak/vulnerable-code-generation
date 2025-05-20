//Falcon-180B DATASET v1.0 Category: File handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int main() {
    FILE* input_file = NULL;
    FILE* output_file = NULL;
    char input_filename[MAX_LINE_LENGTH];
    char output_filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char delimiter;

    // Ask user for input file name
    printf("Enter input file name: ");
    fgets(input_filename, MAX_LINE_LENGTH, stdin);
    input_filename[strcspn(input_filename, "\n")] = '\0';

    // Ask user for output file name
    printf("Enter output file name: ");
    fgets(output_filename, MAX_LINE_LENGTH, stdin);
    output_filename[strcspn(output_filename, "\n")] = '\0';

    // Ask user for delimiter
    printf("Enter delimiter: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    delimiter = line[0];

    // Open input file
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Open output file
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    // Read input file line by line
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        // Split line into fields based on delimiter
        char* field = strtok(line, delimiter);
        while (field!= NULL) {
            // Write field to output file
            fprintf(output_file, "%s\n", field);
            field = strtok(NULL, delimiter);
        }
    }

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("Done.\n");
    return 0;
}