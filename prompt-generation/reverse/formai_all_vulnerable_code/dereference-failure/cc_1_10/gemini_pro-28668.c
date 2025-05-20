//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

CSVRow *csv_read_row(FILE *fp) {
    char line[1024];
    CSVRow *row = malloc(sizeof(CSVRow));

    if (!fgets(line, sizeof(line), fp)) {
        return NULL;
    }

    int num_fields = 0;
    char *field_start = line;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == ',') {
            num_fields++;
            field_start = line + i + 1;
        }
    }
    num_fields++;

    row->fields = malloc(sizeof(char *) * num_fields);
    row->num_fields = num_fields;

    char *field = field_start;
    for (int i = 0; i < num_fields; i++) {
        char *next_field = strchr(field, ',');
        if (next_field) {
            row->fields[i] = strndup(field, next_field - field);
            field = next_field + 1;
        } else {
            row->fields[i] = strdup(field);
        }
    }

    return row;
}

void csv_free_row(CSVRow *row) {
    for (int i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (!fp) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    CSVRow *row;
    while ((row = csv_read_row(fp))) {
        for (int i = 0; i < row->num_fields; i++) {
            printf("%s\t", row->fields[i]);
        }
        printf("\n");
        csv_free_row(row);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}