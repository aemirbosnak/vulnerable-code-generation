//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int field_count;
} CsvRow;

typedef struct {
    CsvRow *rows;
    int row_count;
} CsvData;

CsvData* read_csv(const char *filename);
void free_csv_data(CsvData *data);
void print_csv_data(const CsvData *data);
char** split_line(const char *line, int *field_count);
void trim_whitespace(char *str);

int main() {
    const char *filename = "data.csv";  // Replace with your CSV file path
    CsvData *csv_data = read_csv(filename);

    if (csv_data != NULL) {
        print_csv_data(csv_data);
        free_csv_data(csv_data);
    }

    return 0;
}

CsvData* read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    CsvData *data = malloc(sizeof(CsvData));
    data->rows = NULL;
    data->row_count = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        int field_count;
        char **fields = split_line(line, &field_count);

        if (field_count > 0) {
            data->rows = realloc(data->rows, sizeof(CsvRow) * (data->row_count + 1));
            data->rows[data->row_count].fields = fields;
            data->rows[data->row_count].field_count = field_count;
            data->row_count++;
        }
    }

    fclose(file);
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

char** split_line(const char *line, int *field_count) {
    char *line_copy = strdup(line);
    trim_whitespace(line_copy);
    
    char **fields = malloc(sizeof(char*) * MAX_FIELDS);
    *field_count = 0;

    char *token = strtok(line_copy, ",");
    while (token != NULL) {
        fields[*field_count] = strdup(token);
        (*field_count)++;
        token = strtok(NULL, ",");
    }

    free(line_copy);
    return fields;
}

void trim_whitespace(char *str) {
    // Trim leading whitespace
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing whitespace
    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
}