//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom error handling function
void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

// Custom CSV reader function
void read_csv(char *filename) {
    // Open file
    FILE *file = fopen(filename, "r");
    if (!file) error("Error opening file");

    // Read file line by line
    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        // Get number of fields
        int num_fields = 0;
        char *field = strtok(buffer, ",");
        while (field) {
            num_fields++;
            field = strtok(NULL, ",");
        }

        // Validate number of fields
        if (num_fields != 3) error("Invalid number of fields in line");

        // Parse fields
        char *name = strtok(buffer, ",");
        char *email = strtok(NULL, ",");
        char *age = strtok(NULL, ",");

        // Print fields
        printf("Name: %s\n", name);
        printf("Email: %s\n", email);
        printf("Age: %s\n", age);
        printf("\n");
    }

    // Close file
    fclose(file);
}

int main(int argc, char *argv[]) {
    // Check number of arguments
    if (argc != 2) error("Usage: csv_reader <filename>");

    // Read CSV file
    read_csv(argv[1]);

    return EXIT_SUCCESS;
}