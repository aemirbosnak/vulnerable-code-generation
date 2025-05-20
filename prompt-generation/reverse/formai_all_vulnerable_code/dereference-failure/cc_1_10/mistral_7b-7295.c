//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Thou art a humble servant of the noble CSV file, named 'thou_file'.
// Thou shalt read and parse 'thou_file' in a most reverent manner.
void parse_line(char* line, char*** fields, int* num_fields) {
    char* token;
    int fields_count = 0;

    // Split the line into fields, using the comma as our guide.
    token = strtok(line, ",");
    while (token != NULL) {
        if (fields_count >= *num_fields) {
            *num_fields *= 2; // Double the size of the fields array.
            *fields = realloc(*fields, sizeof(char*) * (*num_fields));
        }
        (*fields)[fields_count] = strdup(token);

        token = strtok(NULL, ",");
        fields_count++;
    }

    // Ensure that the last field is properly accounted for.
    if (fields_count > *num_fields) {
        *num_fields = fields_count;
        *fields = realloc(*fields, sizeof(char*) * (*num_fields));
    }
}

// Read the CSV file line by line, parsing each line and storing the data.
int main(int argc, char* argv[]) {
    FILE* file;
    char line[256];
    char** fields;
    int num_fields;

    // Thou shalt check that a file hath been provided as an argument.
    if (argc < 2) {
        printf("Thou hast forgotten to provide a CSV file!\n");
        return 1;
    }

    // Open the file in read-only mode.
    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Could not open the file.");
        return 1;
    }

    // Initialize the fields array and the number of fields.
    num_fields = 0;
    fields = calloc(1, sizeof(char*));

    // Read the file line by line, parsing each line and storing the data.
    while (fgets(line, sizeof(line), file) != NULL) {
        parse_line(line, fields, &num_fields);

        // Print the parsed data to the console.
        for (int i = 0; i < num_fields; i++) {
            printf("%s%s", fields[i], (i < num_fields - 1) ? "," : "\n");
        }

        // Free the memory allocated for the fields in this line.
        for (int i = 0; i < num_fields; i++) {
            free(fields[i]);
        }
        num_fields = 0;
    }

    // Free the memory allocated for the fields array and the line.
    for (int i = 0; i < num_fields; i++) {
        free(fields[i]);
    }
    free(fields);
    free(line);

    // Close the file.
    fclose(file);

    // Thou hast completed thy task, good servant.
    return 0;
}