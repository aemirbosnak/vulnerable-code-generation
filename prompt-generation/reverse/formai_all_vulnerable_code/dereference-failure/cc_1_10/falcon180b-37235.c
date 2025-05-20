//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 100
#define MAX_ROWS 1000

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CsvData;

CsvData *csv_read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    CsvData *data = (CsvData *)malloc(sizeof(CsvData));
    data->num_rows = 0;
    data->num_columns = 0;
    data->data = (char **)malloc(MAX_ROWS * sizeof(char *));

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, ",");
        int num_tokens = 0;

        while (token!= NULL) {
            num_tokens++;
            if (data->num_columns <= 0 || data->num_rows >= MAX_ROWS) {
                printf("Error: CSV file is too large\n");
                exit(1);
            }

            data->data[data->num_rows] = (char *)malloc(strlen(token) + 1);
            strcpy(data->data[data->num_rows], token);

            data->num_rows++;
            data->num_columns = num_tokens;

            token = strtok(NULL, ",");
        }
    }

    fclose(file);
    return data;
}

void csv_print_data(CsvData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_columns; j++) {
            printf("%s ", data->data[i]);
        }
        printf("\n");
    }
}

void csv_free_data(CsvData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        free(data->data[i]);
    }
    free(data->data);
    free(data);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    CsvData *data = csv_read_file(argv[1]);
    csv_print_data(data);
    csv_free_data(data);

    return 0;
}