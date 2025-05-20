//Falcon-180B DATASET v1.0 Category: Error handling ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main() {
    char input_file_name[MAX_LINE_LENGTH];
    char output_file_name[MAX_LINE_LENGTH];
    FILE *input_file, *output_file;
    char line[MAX_LINE_LENGTH];
    char *error_message = NULL;

    printf("Enter input file name: ");
    fgets(input_file_name, MAX_LINE_LENGTH, stdin);
    input_file_name[strcspn(input_file_name, "\n")] = '\0';

    printf("Enter output file name: ");
    fgets(output_file_name, MAX_LINE_LENGTH, stdin);
    output_file_name[strcspn(output_file_name, "\n")] = '\0';

    // Open input file for reading
    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        error_message = "Error opening input file for reading";
        goto error;
    }

    // Create output file for writing
    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        error_message = "Error creating output file for writing";
        goto error;
    }

    // Read input file line by line and write to output file
    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        fprintf(output_file, "%s", line);
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    printf("File conversion completed successfully!\n");
    return 0;

error:
    if (error_message!= NULL) {
        printf("Error: %s\n", error_message);
    }
    return 1;
}