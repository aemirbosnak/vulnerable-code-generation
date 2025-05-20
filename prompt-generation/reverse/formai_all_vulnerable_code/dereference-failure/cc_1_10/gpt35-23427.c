//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_FIELD_COUNT 32

typedef struct {
    char *headers[MAX_FIELD_COUNT];
    int field_count;
    char *fields[MAX_FIELD_COUNT];
} csv_row;

typedef struct {
    csv_row *rows;
    int row_count;
    int header_row_index;
} csv_file;

/*
 * Reads a CSV file into a csv_file struct.
 * Returns a pointer to the csv_file on success or NULL on failure.
 */
csv_file *read_csv(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    csv_file *csv = malloc(sizeof(csv_file));
    csv->rows = NULL;
    csv->row_count = 0;
    csv->header_row_index = -1;

    char line[MAX_LINE_LENGTH];
    int line_count = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        // Strip newline from end of line
        line[strcspn(line, "\r\n")] = 0;

        // Split line into fields
        char *token = strtok(line, ",");
        csv_row *row = malloc(sizeof(csv_row));
        row->field_count = 0;
        while (token != NULL) {
            if (line_count == 0) {
                // Header row
                row->headers[row->field_count] = token;
            } else {
                // Data row
                row->fields[row->field_count] = token;
            }
            row->field_count++;
            token = strtok(NULL, ",");
        }

        if (line_count == 0) {
            // Save header row index for later use
            csv->header_row_index = csv->row_count;
        }

        if (line_count == 0 || row->field_count == csv->rows[csv->header_row_index].field_count) {
            // Add row to csv_file
            csv->rows = realloc(csv->rows, (csv->row_count + 1) * sizeof(csv_row));
            csv->rows[csv->row_count] = *row;
            csv->row_count++;
        } else {
            // Error: field count mismatch
            printf("Error: Field count mismatch on line %d\n", line_count);
        }

        line_count++;
    }

    fclose(fp);
    return csv;
}

int main() {
    csv_file *csv = read_csv("data.csv");
    if (csv == NULL) {
        return 1;
    }

    // Print headers
    for (int i = 0; i < csv->rows[csv->header_row_index].field_count; i++) {
        printf("%s", csv->rows[csv->header_row_index].headers[i]);
        if (i < csv->rows[csv->header_row_index].field_count - 1) {
            printf(",");
        }
    }
    printf("\n");

    // Print data rows
    for (int i = 1; i < csv->row_count; i++) {
        for (int j = 0; j < csv->rows[i].field_count; j++) {
            printf("%s", csv->rows[i].fields[j]);
            if (j < csv->rows[i].field_count - 1) {
                printf(",");
            }
        }
        printf("\n");
    }

    return 0;
}