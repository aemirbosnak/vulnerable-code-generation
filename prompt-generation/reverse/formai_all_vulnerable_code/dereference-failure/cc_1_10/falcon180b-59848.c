//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

CSVRow *read_csv_file(FILE *file) {
    CSVRow *row = NULL;
    char *line = NULL;
    size_t len = 0;
    int num_fields = 0;

    while ((getline(&line, &len, file))!= -1) {
        if (line[0] == '#' || line[0] == '\n') {
            continue;
        }

        char *token = strtok(line, ",");
        while (token!= NULL) {
            num_fields++;
            token = strtok(NULL, ",");
        }

        if (num_fields > 0) {
            row = (CSVRow *) malloc(sizeof(CSVRow));
            row->num_fields = num_fields;
            row->fields = (char **) malloc(sizeof(char *) * num_fields);

            token = strtok(line, ",");
            int i = 0;
            while (token!= NULL) {
                row->fields[i] = strdup(token);
                token = strtok(NULL, ",");
                i++;
            }
        }
    }

    return row;
}

void print_csv_row(CSVRow *row) {
    int i;
    for (i = 0; i < row->num_fields; i++) {
        printf("%s ", row->fields[i]);
    }
    printf("\n");
}

void free_csv_row(CSVRow *row) {
    int i;
    for (i = 0; i < row->num_fields; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    CSVRow *row = read_csv_file(file);

    if (row!= NULL) {
        print_csv_row(row);
    }

    fclose(file);
    free_csv_row(row);

    return 0;
}