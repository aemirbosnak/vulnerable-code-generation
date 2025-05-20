//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 1000

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSVData;

CSVData *read_csv_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    CSVData *data = (CSVData *) malloc(sizeof(CSVData));
    data->num_rows = 0;
    data->num_columns = 0;

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, ",");
        int num_tokens = 0;

        while (token!= NULL) {
            num_tokens++;
            if (data->num_columns == 0) {
                data->num_columns = num_tokens;
            } else if (num_tokens!= data->num_columns) {
                printf("Error: Inconsistent number of columns in line %d\n", data->num_rows + 1);
                exit(1);
            }

            if (data->num_rows == 0) {
                data->data = (char **) malloc(data->num_columns * sizeof(char *));
            } else {
                data->data = (char **) realloc(data->data, (data->num_rows + 1) * data->num_columns * sizeof(char *));
            }

            data->data[data->num_rows][num_tokens - 1] = strdup(token);

            token = strtok(NULL, ",");
        }

        data->num_rows++;
    }

    fclose(file);
    return data;
}

void print_csv_data(CSVData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_columns; j++) {
            printf("%s ", data->data[i][j]);
        }
        printf("\n");
    }
}

void free_csv_data(CSVData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_columns; j++) {
            free(data->data[i][j]);
        }
        free(data->data[i]);
    }
    free(data->data);
    free(data);
}

int main() {
    CSVData *data = read_csv_file("example.csv");
    print_csv_data(data);
    free_csv_data(data);

    return 0;
}