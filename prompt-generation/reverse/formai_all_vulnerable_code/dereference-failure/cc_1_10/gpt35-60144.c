//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 256
#define DELIMITER ','

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

typedef struct {
    CSVRow *rows;
    int num_rows;
} CSVFile;

CSVFile *read_csv_file(FILE *fp) {
    CSVFile *csv = malloc(sizeof(CSVFile));
    csv->rows = malloc(sizeof(CSVRow) * MAX_LINE_LENGTH);
    csv->num_rows = 0;

    char line[MAX_LINE_LENGTH];

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char *field = strtok(line, ",");
        int field_count = 0;
        CSVRow row = { malloc(sizeof(char *) * MAX_FIELDS), 0 };

        while (field != NULL) {
            row.fields[row.num_fields++] = strdup(field);
            field = strtok(NULL, ",");
            field_count++;
        }

        csv->rows[csv->num_rows++] = row;

        if (field_count > MAX_FIELDS) {
            fprintf(stderr, "Error: too many fields on line.\n");
            exit(1);
        }
    }

    return csv;
}

void print_csv_file(CSVFile *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->rows[i].num_fields; j++) {
            printf("%s", csv->rows[i].fields[j]);
            if (j != csv->rows[i].num_fields - 1) {
                printf(",");
            }
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("example.csv", "r");

    if (!fp) {
        fprintf(stderr, "Failed to open input file.\n");
        exit(1);
    }

    CSVFile *csv = read_csv_file(fp);
    print_csv_file(csv);

    fclose(fp);

    return 0;
}