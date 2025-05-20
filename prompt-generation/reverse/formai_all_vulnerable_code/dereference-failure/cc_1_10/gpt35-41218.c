//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_LINES 1000
#define MAX_FIELDS 20

struct csv_row {
    char* fields[MAX_FIELDS];
    int num_fields;
};

void split_line(char* line, struct csv_row* row) {
    char* field;
    int i = 0;

    while ((field = strsep(&line, ",")) != NULL && i < MAX_FIELDS) {
        row->fields[i++] = field;
    }

    row->num_fields = i;
}

void read_csv_file(char* filename, struct csv_row** rows, int* num_rows) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    *rows = (struct csv_row*) malloc(sizeof(struct csv_row) * MAX_LINES);
    *num_rows = 0;

    while ((read = getline(&line, &len, fp)) != -1 && *num_rows < MAX_LINES) {
        struct csv_row row;
        split_line(line, &row);
        (*rows)[(*num_rows)++] = row;
    }

    if (line) {
        free(line);
    }

    fclose(fp);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: ./csv_reader <filename>\n");
        return EXIT_FAILURE;
    }

    struct csv_row* rows;
    int num_rows;

    read_csv_file(argv[1], &rows, &num_rows);

    printf("%d rows found in %s\n", num_rows, argv[1]);

    for (int i = 0; i < num_rows; i++) {
        struct csv_row row = rows[i];

        for (int j = 0; j < row.num_fields; j++) {
            printf("%s\t", row.fields[j]);
        }

        printf("\n");
    }

    free(rows);

    return EXIT_SUCCESS;
}