//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// Function to read a CSV file and store content in a dynamically allocated array of strings
char **read_csv(const char *filename, int *num_rows, int *num_fields) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    char **data = NULL;
    *num_rows = 0;
    *num_fields = 0;

    while (fgets(line, sizeof(line), file)) {
        // Strip newline character from the end of the line
        line[strcspn(line, "\n")] = '\0';
        
        // Allocate memory for a new row
        data = realloc(data, (*num_rows + 1) * sizeof(char *));
        data[*num_rows] = malloc(MAX_FIELDS * MAX_LINE_LENGTH);
        
        // Tokenize the line and store each field
        char *field = strtok(line, ",");
        int field_count = 0;

        while (field) {
            // Store the field in the current row
            strcpy(data[*num_rows] + field_count * MAX_LINE_LENGTH, field);
            field_count++;
            field = strtok(NULL, ",");
        }

        *num_fields = field_count; // Set the number of fields
        (*num_rows)++; // Increment row count
    }

    fclose(file);
    return data;
}

// Function to print the CSV content stored in the 2D array
void print_csv(char **data, int num_rows, int num_fields) {
    printf("CSV Data:\n");

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_fields; j++) {
            printf("%s", data[i] + j * MAX_LINE_LENGTH);
            if (j < num_fields - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

// Free allocated memory for the CSV data
void free_csv(char **data, int num_rows) {
    for (int i = 0; i < num_rows; i++) {
        free(data[i]);
    }
    free(data);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int num_rows = 0;
    int num_fields = 0;
    char **data = read_csv(argv[1], &num_rows, &num_fields);

    if (!data) {
        return EXIT_FAILURE;
    }

    print_csv(data, num_rows, num_fields);
    free_csv(data, num_rows);

    return EXIT_SUCCESS;
}