//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_DATA {
    char **data;
    int rows;
    int cols;
} CSV_DATA;

CSV_DATA *csv_reader(char *filename) {
    CSV_DATA *csv_data = malloc(sizeof(CSV_DATA));
    csv_data->data = NULL;
    csv_data->rows = 0;
    csv_data->cols = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    // Read the number of rows and columns
    char line[1024];
    int i = 0;
    while (fgets(line, 1024, fp) != NULL) {
        csv_data->rows++;
        i++;
    }

    csv_data->cols = i;

    // Allocate memory for the data
    csv_data->data = malloc(sizeof(char *) * csv_data->rows);
    for (i = 0; i < csv_data->rows; i++) {
        csv_data->data[i] = malloc(sizeof(char) * csv_data->cols);
    }

    // Read the data from the file
    rewind(fp);
    i = 0;
    while (fgets(line, 1024, fp) != NULL) {
        char *p = line;
        for (int j = 0; j < csv_data->cols; j++) {
            csv_data->data[i][j] = strdup(p);
            p += strlen(p) + 1;
        }
        i++;
    }

    fclose(fp);

    return csv_data;
}

int main() {
    char *filename = "test.csv";
    CSV_DATA *csv_data = csv_reader(filename);

    if (csv_data) {
        // Print the data
        for (int i = 0; i < csv_data->rows; i++) {
            for (int j = 0; j < csv_data->cols; j++) {
                printf("%s ", csv_data->data[i][j]);
            }
            printf("\n");
        }

        // Free the memory
        for (int i = 0; i < csv_data->rows; i++) {
            free(csv_data->data[i]);
        }
        free(csv_data->data);
        free(csv_data);
    }

    return 0;
}