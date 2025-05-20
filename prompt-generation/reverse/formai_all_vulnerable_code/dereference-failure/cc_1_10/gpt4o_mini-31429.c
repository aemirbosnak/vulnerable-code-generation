//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    size_t field_count;
} CsvRow;

typedef struct {
    CsvRow *rows;
    size_t row_count;
} CsvData;

void free_csv_data(CsvData *data) {
    if (data) {
        for (size_t i = 0; i < data->row_count; i++) {
            for (size_t j = 0; j < data->rows[i].field_count; j++) {
                free(data->rows[i].fields[j]);
            }
            free(data->rows[i].fields);
        }
        free(data->rows);
        free(data);
    }
}

size_t count_fields(const char *line) {
    size_t count = 0;
    const char *ptr = line;

    while (*ptr) {
        if (*ptr == ',' || *(ptr + 1) == '\0') {
            count++;
        }
        ptr++;
    }
    return count;
}

char **split_line(const char *line, size_t *field_count) {
    *field_count = count_fields(line);
    char **fields = malloc((*field_count) * sizeof(char*));
    if (!fields) {
        perror("Failed to allocate memory for fields");
        exit(EXIT_FAILURE);
    }

    size_t index = 0;
    const char *start = line;
    const char *end = line;

    while (*end) {
        if (*end == ',' || *(end + 1) == '\0') {
            size_t length = (size_t)(end - start) + (*(end + 1) == '\0' ? 1 : 0);
            fields[index] = malloc(length + 1);
            if (!fields[index]) {
                perror("Failed to allocate memory for field");
                exit(EXIT_FAILURE);
            }
            strncpy(fields[index], start, length);
            fields[index][length] = '\0';
            index++;
            start = end + 1;
        }
        end++;
    }
    return fields;
}

CsvData *read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    CsvData *data = malloc(sizeof(CsvData));
    if (!data) {
        perror("Failed to allocate memory for CsvData");
        fclose(file);
        return NULL;
    }

    data->rows = NULL;
    data->row_count = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        CsvRow row;
        row.fields = split_line(line, &row.field_count);
        data->row_count++;
        data->rows = realloc(data->rows, data->row_count * sizeof(CsvRow));
        if (!data->rows) {
            perror("Failed to allocate memory for rows");
            free(row.fields);
            free_csv_data(data);
            fclose(file);
            return NULL;
        }
        data->rows[data->row_count - 1] = row;
    }

    fclose(file);
    return data;
}

void print_csv_data(const CsvData *data) {
    for (size_t i = 0; i < data->row_count; i++) {
        for (size_t j = 0; j < data->rows[i].field_count; j++) {
            printf("%s", data->rows[i].fields[j]);
            if (j < data->rows[i].field_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    CsvData *data = read_csv(argv[1]);
    if (data) {
        print_csv_data(data);
        free_csv_data(data);
    }

    return EXIT_SUCCESS;
}