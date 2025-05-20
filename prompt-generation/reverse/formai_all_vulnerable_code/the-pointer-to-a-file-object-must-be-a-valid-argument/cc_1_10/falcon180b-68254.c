//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 1000

typedef struct {
    char **data;
    int num_columns;
} CSVData;

CSVData *CSVReader(FILE *file) {
    CSVData *csv_data = malloc(sizeof(CSVData));
    csv_data->num_columns = 0;
    csv_data->data = NULL;

    char line[MAX_LINE_SIZE];
    char *token = NULL;
    int num_columns = 0;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            num_columns++;
            token = strtok(NULL, ",");
        }
        if (num_columns > csv_data->num_columns) {
            csv_data->num_columns = num_columns;
            csv_data->data = realloc(csv_data->data, csv_data->num_columns * sizeof(char *));
        }
    }

    rewind(file);
    csv_data->data = malloc(csv_data->num_columns * sizeof(char *));
    int i = 0;
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            csv_data->data[i] = strdup(token);
            token = strtok(NULL, ",");
            i++;
        }
    }

    return csv_data;
}

void CSVDestructor(CSVData *csv_data) {
    for (int i = 0; i < csv_data->num_columns; i++) {
        free(csv_data->data[i]);
    }
    free(csv_data->data);
    free(csv_data);
}

void CSVPrint(CSVData *csv_data) {
    for (int i = 0; i < csv_data->num_columns; i++) {
        printf("%s\t", csv_data->data[i]);
    }
    printf("\n");
}

int main() {
    FILE *file = fopen("example.csv", "r");
    CSVData *csv_data = CSVReader(file);
    CSVPrint(csv_data);
    CSVDestructor(csv_data);
    fclose(file);
    return 0;
}