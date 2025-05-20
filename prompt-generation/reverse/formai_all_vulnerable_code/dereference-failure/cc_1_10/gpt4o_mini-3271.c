//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <csv_file_path> [delimiter]\n", prog_name);
    fprintf(stderr, "Default delimiter is ',' if not provided.\n");
}

void parse_csv(const char *filename, const char delimiter) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *fields[MAX_FIELDS];
        int field_count = 0;

        char *token = strtok(line, &delimiter);
        while (token != NULL && field_count < MAX_FIELDS) {
            fields[field_count] = strdup(token);
            token = strtok(NULL, &delimiter);
            field_count++;
        }

        // Print the fields
        printf("Parsed line:\n");
        for (int i = 0; i < field_count; i++) {
            printf("Field %d: %s\n", i + 1, fields[i]);
            free(fields[i]); // free the allocated memory
        }
        printf("\n");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    char delimiter = ',';

    if (argc == 3) {
        delimiter = argv[2][0]; // Use the first character of the second argument as delimiter
    }

    printf("Reading CSV file: %s with delimiter: '%c'\n", filename, delimiter);
    parse_csv(filename, delimiter);

    return EXIT_SUCCESS;
}