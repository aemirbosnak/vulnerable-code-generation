//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char delimiter;
    FILE *file;
    int num_columns;
    int *column_widths;
} CSVReader;

int main() {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->delimiter = ',';
    reader->file = fopen("data.csv", "r");
    reader->num_columns = 0;
    reader->column_widths = NULL;

    char line[MAX_LINE_LENGTH];
    int num_columns = 0;
    int row = 0;

    while (fgets(line, MAX_LINE_LENGTH, reader->file)) {
        int len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[--len] = '\0';
        }

        char *token = strtok(line, reader->delimiter);
        while (token!= NULL) {
            int column_width = strlen(token);
            if (column_width > reader->column_widths[num_columns]) {
                reader->column_widths[num_columns] = column_width;
            }
            num_columns++;
            token = strtok(NULL, reader->delimiter);
        }

        if (num_columns > reader->num_columns) {
            reader->num_columns = num_columns;
            reader->column_widths = realloc(
                reader->column_widths, reader->num_columns * sizeof(int));
        }

        row++;
        if (row == 10) {
            break;
        }
    }

    printf("Number of columns: %d\n", reader->num_columns);

    for (int i = 0; i < reader->num_columns; i++) {
        printf("Column %d width: %d\n", i + 1, reader->column_widths[i]);
    }

    fclose(reader->file);
    free(reader);

    return 0;
}