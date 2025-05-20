//Falcon-180B DATASET v1.0 Category: Data mining ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_VALUES 10000

typedef struct {
    char **rows;
    int num_rows;
    int num_cols;
} DataSet;

void load_data(DataSet *data, char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[MAX_COLS];
    int i = 0;
    while (fgets(line, MAX_COLS, fp)!= NULL) {
        int j = 0;
        while (line[j]!= '\0' && line[j]!= '\n') {
            j++;
        }
        line[j] = '\0';
        if (i >= MAX_ROWS) {
            printf("Error: too many rows in data file.\n");
            exit(1);
        }
        data->rows[i] = (char *)malloc(strlen(line) + 1);
        strcpy(data->rows[i], line);
        i++;
    }
    data->num_rows = i;
    data->num_cols = strlen(data->rows[0]);
    fclose(fp);
}

void free_data(DataSet *data) {
    for (int i = 0; i < data->num_rows; i++) {
        free(data->rows[i]);
    }
    free(data->rows);
}

void print_data(DataSet *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
            printf("%c", data->rows[i][j]);
        }
        printf("\n");
    }
}

int main() {
    DataSet data;
    load_data(&data, "data.txt");
    print_data(&data);
    free_data(&data);
    return 0;
}