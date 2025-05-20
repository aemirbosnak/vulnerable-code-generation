//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_COUNT 50

typedef struct {
    char **fields;
    int count;
} row_t;

row_t *parse_row(char *line, char delimiter) {
    // Allocate memory for row_t struct
    row_t *row = malloc(sizeof(row_t));
    row->fields = malloc(sizeof(char*) * MAX_FIELD_COUNT);
    row->count = 0;

    // Split line by delimiter
    char *field = strtok(line, &delimiter);
    while (field != NULL && row->count < MAX_FIELD_COUNT) {
        row->fields[row->count++] = strdup(field);
        field = strtok(NULL, &delimiter);
    }

    return row;
}

void free_row(row_t *row) {
    // Free memory of fields array
    for (int i = 0; i < row->count; i++) {
        free(row->fields[i]);
    }
    free(row->fields);

    // Free memory of row_t struct
    free(row);
}

int main() {
    printf("Welcome to our cheerful CSV Reader example!\n");

    // Open CSV file for reading
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Read and parse lines
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        row_t *row = parse_row(line, ',');
        printf("Row with %d fields:\n", row->count);
        for (int i = 0; i < row->count; i++) {
            printf("Field %d: %s\n", i+1, row->fields[i]);
        }
        free_row(row);
    }

    // Close file
    fclose(fp);

    printf("Thanks for using our CSV Reader example! Have a great day!\n");
    return 0;
}