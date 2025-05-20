//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *field_name;
    int field_value;
} Column;

typedef struct {
    Column* columns;
    int num_columns;
} CsvReader;

CsvReader *create_csv_reader(char *filename) {
    FILE *file;
    CsvReader *result = NULL;
    char line[1024];
    int i, num_columns;

    file = fopen(filename, "r");

    if (!file) {
        printf("Cannot open %s", filename);
        exit(1);
    }

    if (!fgets(line, 1024, file)) {
        printf("Cannot read header line of %s", filename);
        exit(1);
    }

    fclose(file);

    num_columns = 0;
    for (i = 0; i < strlen(line); i++) {
        if (line[i] == ',') {
            num_columns++;
        }
    }
    num_columns++;

    result = (CsvReader *) malloc(sizeof(CsvReader));
    result->columns = (Column *) malloc(num_columns * sizeof(Column));
    result->num_columns = num_columns;

    char *comma_ptr = strtok(line, ",");
    i = 0;
    while (comma_ptr != NULL) {
        result->columns[i].field_name = strdup(comma_ptr);
        comma_ptr = strtok(NULL, ",");
        i++;
    }

    return result;
}

int main() {
    CsvReader *reader = create_csv_reader("example.csv");

    printf("Number of columns: %d\n", reader->num_columns);

    for (int i = 0; i < reader->num_columns; i++) {
        printf("Column name: %s\n", reader->columns[i].field_name);
    }

    return 0;
}