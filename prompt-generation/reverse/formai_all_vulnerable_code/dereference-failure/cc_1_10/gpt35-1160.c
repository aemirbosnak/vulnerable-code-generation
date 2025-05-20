//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define MAX_FIELD 128

/* Struct to store the CSV data */
typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

/* Function to split a line into CSV fields */
CSVRow* parse_csv_line(char *line) {
    CSVRow *row = malloc(sizeof(CSVRow));
    row->fields = malloc(MAX_FIELD * sizeof(char*));
    row->num_fields = 0;

    char *token, *end;
    for (token = strtok_r(line, ",", &end); token; token = strtok_r(NULL, ",", &end)) {
        if (row->num_fields >= MAX_FIELD) {
            fprintf(stderr, "Error: too many fields in line\n");
            return NULL;
        }
        int len = strlen(token);
        row->fields[row->num_fields] = malloc((len+1) * sizeof(char));
        strncpy(row->fields[row->num_fields], token, len);
        row->fields[row->num_fields][len] = '\0';
        row->num_fields++;
    }
    return row;
}

/* Function to free memory allocated for a CSV row */
void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

/* Function to read a CSV file */
int read_csv_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: cannot open file\n");
        return 1;
    }

    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, file)) {
        CSVRow *row = parse_csv_line(line);
        if (!row) {
            return 1;
        }
        for (int i = 0; i < row->num_fields; i++) {
            printf("%s ", row->fields[i]);
        }
        printf("\n");
        free_csv_row(row);
    }

    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: csvreader <filename>\n");
        return 1;
    }

    if (read_csv_file(argv[1])) {
        fprintf(stderr, "Error: reading CSV file\n");
        return 1;
    }

    return 0;
}