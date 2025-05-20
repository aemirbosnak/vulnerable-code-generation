//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 10

typedef struct {
    char *fields[MAX_NUM_FIELDS];
    int num_fields;
} CSVRow;

CSVRow *read_csv_row(FILE *f) {
    char line[MAX_LINE_LENGTH];
    if (fgets(line, MAX_LINE_LENGTH, f) == NULL) {
        return NULL;
    }

    CSVRow *row = malloc(sizeof(CSVRow));
    row->num_fields = 0;

    char *field = strtok(line, ",");
    while (field) {
        row->fields[row->num_fields++] = strdup(field);
        field = strtok(NULL, ",");
    }

    return row;
}

void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        return 1;
    }

    CSVRow *row;
    while ((row = read_csv_row(f)) != NULL) {
        for (int i = 0; i < row->num_fields; i++) {
            printf("%s", row->fields[i]);
            if (i < row->num_fields - 1) {
                printf(",");
            }
        }
        printf("\n");
        free_csv_row(row);
    }

    fclose(f);

    return 0;
}