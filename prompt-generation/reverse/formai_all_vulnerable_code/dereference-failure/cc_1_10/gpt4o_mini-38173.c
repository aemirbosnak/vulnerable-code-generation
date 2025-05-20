//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256

typedef struct {
    char **fields;
    size_t field_count;
} CSVRow;

CSVRow parse_csv_line(const char *line) {
    CSVRow row;
    row.field_count = 0;
    row.fields = (char **)malloc(sizeof(char *) * MAX_FIELD_LENGTH);
    if (!row.fields) {
        perror("Failed to allocate memory for fields");
        exit(EXIT_FAILURE);
    }

    const char *start = line;
    char field[MAX_FIELD_LENGTH];
    size_t field_index = 0;

    while (*start) {
        size_t length = 0;

        while (*start && *start != ',') {
            field[length++] = *start++;
        }

        field[length] = '\0';
        row.fields[row.field_count] = strdup(field);
        row.field_count++;

        if (*start) { // skip the comma
            start++;
        }
    }

    return row;
}

void free_csv_row(CSVRow *row) {
    for (size_t i = 0; i < row->field_count; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
}

void print_csv_row(CSVRow *row) {
    for (size_t i = 0; i < row->field_count; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("%s", row->fields[i]);
    }
    printf("\n");
}

void read_csv_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        CSVRow row = parse_csv_line(line);
        print_csv_row(&row);
        free_csv_row(&row);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csvfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_csv_file(argv[1]);

    return EXIT_SUCCESS;
}