//FormAI DATASET v1.0 Category: Data mining ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 256
#define MAX_FIELD_SIZE 32
#define MAX_DATA_ROWS 1000
#define MAX_DATA_COLS 100

typedef struct {
    char fields[MAX_DATA_COLS][MAX_FIELD_SIZE];
} DataRow;

DataRow* read_csv_data(const char* csv_file, int* num_rows) {
    DataRow* data = NULL;
    FILE* fp = fopen(csv_file, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file '%s'\n", csv_file);
        return NULL;
    }

    char line[MAX_LINE_SIZE];
    int row = 0;
    while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        char* tok = strtok(line, ",");
        int col = 0;
        while (tok != NULL) {
            if (data == NULL) data = (DataRow*) malloc(sizeof(DataRow) * MAX_DATA_ROWS);
            strcpy(data[row].fields[col], tok);
            tok = strtok(NULL, ",");
            col++;
        }
        row++;
    }

    fclose(fp);
    *num_rows = row;
    return data;
}

void print_data_set(DataRow* data_set, int num_rows, int num_cols) {
    printf("Printing data set:\n");
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%s  ", data_set[i].fields[j]);
        }
        printf("\n");
    }
}

int main() {
    int num_rows = 0;
    DataRow* data_set = read_csv_data("data.csv", &num_rows);
    if (data_set != NULL) {
        print_data_set(data_set, num_rows, 3); // Assume 3 columns in the data set
        // TODO: Perform data mining tasks on the data set
        free(data_set);
    }
    return 0;
}