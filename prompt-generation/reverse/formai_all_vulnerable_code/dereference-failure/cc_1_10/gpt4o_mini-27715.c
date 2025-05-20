//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 64

void trim_whitespace(char *str) {
    while (*str == ' ') str++;
    char *end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\n')) end--;
    *(end + 1) = '\0';
}

int read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s for reading.\n", filename);
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    char *columns[MAX_COLUMNS];
    int column_count;

    // Read the header line
    if (fgets(line, sizeof(line), file)) {
        trim_whitespace(line);
        printf("Header: %s\n", line);
    } else {
        fprintf(stderr, "Error reading header line.\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Read each subsequent line
    while (fgets(line, sizeof(line), file)) {
        trim_whitespace(line);
        column_count = 0;

        // Split the line into tokens
        char *token = strtok(line, ",");
        while (token && column_count < MAX_COLUMNS) {
            columns[column_count] = malloc(strlen(token) + 1);
            if (!columns[column_count]) {
                fprintf(stderr, "Memory allocation failed.\n");
                fclose(file);
                return EXIT_FAILURE;
            }
            strcpy(columns[column_count], token);
            trim_whitespace(columns[column_count]);  // Trim whitespace
            column_count++;
            token = strtok(NULL, ",");
        }

        // Print the columns
        printf("Row: ");
        for (int i = 0; i < column_count; i++) {
            printf("[%s]", columns[i]);
            free(columns[i]);  // Free the allocated strings
        }
        printf("\n");
    }

    fclose(file);
    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    return read_csv(argv[1]);
}