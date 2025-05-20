//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELDS 10

typedef struct {
    char* fields[MAX_FIELDS];
    int num_fields;
} CSV_Row;

CSV_Row* csv_read_row(FILE* fp) {
    char line[MAX_LINE_SIZE];
    char* field_start;
    CSV_Row* row = malloc(sizeof(CSV_Row));
    if (row == NULL) {
        return NULL;
    }
    row->num_fields = 0;

    if (fgets(line, MAX_LINE_SIZE, fp) == NULL) {
        free(row);
        return NULL;
    }

    field_start = line;
    while (*field_start != '\0') {
        if (row->num_fields >= MAX_FIELDS) {
            // Handle error: Too many fields
            free(row);
            return NULL;
        }

        // Skip leading whitespace
        while (isspace(*field_start)) {
            field_start++;
        }

        // Find the end of the field
        char* field_end = field_start;
        while (*field_end != '\0' && !isspace(*field_end) && *field_end != ',') {
            field_end++;
        }

        // Copy the field into the row
        int field_length = field_end - field_start;
        row->fields[row->num_fields] = malloc(field_length + 1);
        if (row->fields[row->num_fields] == NULL) {
            // Handle error: Out of memory
            free(row);
            return NULL;
        }
        memcpy(row->fields[row->num_fields], field_start, field_length);
        row->fields[row->num_fields][field_length] = '\0';
        row->num_fields++;

        // Skip trailing whitespace and the comma
        while (isspace(*field_end)) {
            field_end++;
        }
        if (*field_end == ',') {
            field_end++;
        }

        field_start = field_end;
    }

    return row;
}

void csv_free_row(CSV_Row* row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row);
}

int main(int argc, char** argv) {
    FILE* fp;
    CSV_Row* row;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    while ((row = csv_read_row(fp)) != NULL) {
        // Process the row
        for (int i = 0; i < row->num_fields; i++) {
            printf("Field %d: %s\n", i + 1, row->fields[i]);
        }

        csv_free_row(row);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}