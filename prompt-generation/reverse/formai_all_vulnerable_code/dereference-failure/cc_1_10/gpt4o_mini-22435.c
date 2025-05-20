//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 1024
#define MAX_FIELDS 64

typedef struct {
    char **fields;
    int field_count;
} CsvRow;

typedef struct {
    CsvRow *rows;
    int row_count;
} CsvData;

CsvData *create_csv_data() {
    CsvData *data = malloc(sizeof(CsvData));
    data->rows = NULL;
    data->row_count = 0;
    return data;
}

void free_csv_data(CsvData *data) {
    for (int i = 0; i < data->row_count; i++) {
        for (int j = 0; j < data->rows[i].field_count; j++) {
            free(data->rows[i].fields[j]);
        }
        free(data->rows[i].fields);
    }
    free(data->rows);
    free(data);
}

char **split_line(const char *line, int *count) {
    char **fields = malloc(MAX_FIELDS * sizeof(char *));
    char *token, *line_copy, *delim = ",";
    int index = 0;

    line_copy = strdup(line);
    token = strtok(line_copy, delim);
    while (token != NULL && index < MAX_FIELDS) {
        fields[index++] = strdup(token);
        token = strtok(NULL, delim);
    }

    free(line_copy);
    *count = index;
    return fields;
}

CsvData *read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return NULL;
    }

    CsvData *data = create_csv_data();
    char line[LINE_SIZE];
    while (fgets(line, sizeof(line), file)) {
        int field_count;
        CsvRow row;
        row.fields = split_line(line, &field_count);
        row.field_count = field_count;

        data->rows = realloc(data->rows, (data->row_count + 1) * sizeof(CsvRow));
        data->rows[data->row_count++] = row;
    }

    fclose(file);
    return data;
}

void print_csv_data(const CsvData *data) {
    for (int i = 0; i < data->row_count; i++) {
        for (int j = 0; j < data->rows[i].field_count; j++) {
            printf("%s", data->rows[i].fields[j]);
            if (j < data->rows[i].field_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CsvData *csv_data = read_csv(argv[1]);
    if (!csv_data) {
        return EXIT_FAILURE;
    }

    print_csv_data(csv_data);
    free_csv_data(csv_data);

    return EXIT_SUCCESS;
}