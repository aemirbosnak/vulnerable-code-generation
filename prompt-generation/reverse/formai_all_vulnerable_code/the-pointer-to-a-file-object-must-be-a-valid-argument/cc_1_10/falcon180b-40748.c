//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 1000
#define MAX_ROWS 100000

typedef struct {
    char **data;
    int num_columns;
    int num_rows;
} CSVData;

CSVData *read_csv(FILE *file) {
    CSVData *data = malloc(sizeof(CSVData));
    data->num_columns = 0;
    data->num_rows = 0;
    data->data = malloc(MAX_COLUMNS * sizeof(char*));

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, ",");
        int i = 0;
        while (token!= NULL) {
            data->data[i] = strdup(token);
            i++;
            token = strtok(NULL, ",");
        }
        data->num_columns = i;
        data->num_rows++;
    }

    data->data = realloc(data->data, data->num_columns * data->num_rows * sizeof(char*));

    return data;
}

void print_csv(CSVData *data) {
    for (int i = 0; i < data->num_columns; i++) {
        printf("%s\t", data->data[i]);
    }
    printf("\n");
}

int main() {
    FILE *file = fopen("example.csv", "r");
    CSVData *data = read_csv(file);
    fclose(file);

    for (int i = 0; i < data->num_columns; i++) {
        printf("%s\t", data->data[i]);
    }
    printf("\n");

    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_columns; j++) {
            printf("%s\t", data->data[i * data->num_columns + j]);
        }
        printf("\n");
    }

    return 0;
}