//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_COLUMNS 100

typedef struct {
    char **data;
    int num_columns;
} CSVRow;

typedef struct {
    CSVRow *rows;
    int num_rows;
} CSVData;

CSVData* create_csv_data(int num_rows, int num_columns) {
    CSVData *csv_data = (CSVData*)malloc(sizeof(CSVData));
    csv_data->num_rows = num_rows;
    csv_data->rows = (CSVRow*)malloc(num_rows * sizeof(CSVRow));
    for (int i = 0; i < num_rows; i++) {
        csv_data->rows[i].num_columns = num_columns;
        csv_data->rows[i].data = (char**)malloc(num_columns * sizeof(char*));
        for (int j = 0; j < num_columns; j++) {
            csv_data->rows[i].data[j] = NULL;
        }
    }
    return csv_data;
}

void free_csv_data(CSVData *csv_data) {
    for (int i = 0; i < csv_data->num_rows; i++) {
        for (int j = 0; j < csv_data->rows[i].num_columns; j++) {
            free(csv_data->rows[i].data[j]);
        }
        free(csv_data->rows[i].data);
    }
    free(csv_data->rows);
    free(csv_data);
}

int split_csv_line(char *line, CSVRow *csv_row) {
    int column = 0;
    char *token = strtok(line, ",");
    while (token != NULL && column < csv_row->num_columns) {
        csv_row->data[column] = malloc(strlen(token) + 1);
        strcpy(csv_row->data[column], token);
        column++;
        token = strtok(NULL, ",");
    }
    return column; // return the number of columns filled
}

CSVData* read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    CSVData *csv_data = create_csv_data(0, MAX_NUM_COLUMNS);
    char line[MAX_LINE_LENGTH];
    int row_count = 0;

    while (fgets(line, sizeof(line), file)) {
        if (row_count >= csv_data->num_rows) {
            csv_data->num_rows += 10; // increase size in a scalable way
            csv_data->rows = realloc(csv_data->rows, csv_data->num_rows * sizeof(CSVRow));
        }
        
        int num_columns = split_csv_line(line, &csv_data->rows[row_count]);
        if (num_columns > 0) {
            csv_data->rows[row_count].num_columns = num_columns;
            row_count++;
        }
    }
    fclose(file);
    csv_data->num_rows = row_count; // update the actual row count

    return csv_data;
}

void print_csv_data(CSVData *csv_data) {
    for (int i = 0; i < csv_data->num_rows; i++) {
        for (int j = 0; j < csv_data->rows[i].num_columns; j++) {
            printf("%s", csv_data->rows[i].data[j]);
            if (j < csv_data->rows[i].num_columns - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    CSVData *csv_data = read_csv(argv[1]);
    if (csv_data == NULL) {
        return 1; // error reading CSV
    }

    print_csv_data(csv_data);
    free_csv_data(csv_data);

    return 0;
}