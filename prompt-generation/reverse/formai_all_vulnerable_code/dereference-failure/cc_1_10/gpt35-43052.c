//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 100
#define MAX_LINE_LENGTH 1000

typedef struct {
    char *column_names[MAX_COLUMNS];
    int num_columns;
    char *data[MAX_COLUMNS][MAX_LINE_LENGTH];
    int num_rows;
} CsvData;

CsvData *csv_reader(char *filename) {
    FILE *fp;
    CsvData *csv_data;
    char buffer[MAX_LINE_LENGTH];
    char *token;
    char *line;

    csv_data = (CsvData *) malloc(sizeof(CsvData));
    csv_data->num_rows = 0;
    csv_data->num_columns = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file '%s' for reading.\n", filename);
        return NULL;
    }

    // Read the column names from the first line
    if (fgets(buffer, MAX_LINE_LENGTH, fp) != NULL) {
        line = strdup(buffer);
        token = strtok(line, ",");
        while (token != NULL) {
            csv_data->column_names[csv_data->num_columns++] = strdup(token);
            token = strtok(NULL, ",");
        }
    }

    // Read the data lines
    while (fgets(buffer, MAX_LINE_LENGTH, fp) != NULL) {
        line = strdup(buffer);
        csv_data->num_rows++;
        int i = 0;
        token = strtok(line, ",");
        while (token != NULL) {
            csv_data->data[i++][csv_data->num_rows - 1] = strdup(token);
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
    return csv_data;
}

void print_csv(CsvData *csv_data) {
    int i, j;
    for (i = 0; i < csv_data->num_rows; i++) {
        for (j = 0; j < csv_data->num_columns; j++) {
            printf("%s=%s ", csv_data->column_names[j], csv_data->data[j][i]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    CsvData *csv_data = csv_reader("example.csv");
    if (csv_data != NULL) {
        print_csv(csv_data);
    }
    return 0;
}