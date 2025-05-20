//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 1000
#define DELIMITER ','

typedef struct {
    char **data;
    int num_columns;
} CSVData;

CSVData *read_csv_file(FILE *file) {
    CSVData *data = malloc(sizeof(CSVData));
    data->num_columns = 0;
    data->data = malloc(MAX_COLUMNS * sizeof(char*));

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        char *token = strtok(line, DELIMITER);
        while (token!= NULL) {
            data->num_columns++;
            data->data = realloc(data->data, data->num_columns * sizeof(char*));
            data->data[data->num_columns - 1] = malloc((strlen(token) + 1) * sizeof(char));
            strcpy(data->data[data->num_columns - 1], token);
            token = strtok(NULL, DELIMITER);
        }
    }

    return data;
}

void print_csv_data(CSVData *data) {
    for (int i = 0; i < data->num_columns; i++) {
        printf("%s\t", data->data[i]);
    }
    printf("\n");
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    CSVData *data = read_csv_file(file);
    print_csv_data(data);

    for (int i = 0; i < data->num_columns; i++) {
        free(data->data[i]);
    }
    free(data->data);
    free(data);

    fclose(file);
    return 0;
}