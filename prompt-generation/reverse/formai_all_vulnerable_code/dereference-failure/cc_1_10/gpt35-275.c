//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_FIELD_LEN 50

typedef struct {
    char fields[MAX_ROWS][MAX_COLS][MAX_FIELD_LEN];
    int rows;
    int cols;
} csv_data_t;

void print_csv_data(csv_data_t *data) {
    for (int i = 0; i < data->rows; i++) {
        for (int j = 0; j < data->cols; j++) {
            printf("%s", data->fields[i][j]);
            if (j < data->cols - 1) {
                printf(",");
            }
        }
        printf("\n");
    }
}

csv_data_t *read_csv_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        return NULL;
    }

    csv_data_t *data = malloc(sizeof(csv_data_t));
    data->rows = 0;
    data->cols = 0;

    char line[MAX_COLS * MAX_FIELD_LEN];
    while (fgets(line, sizeof(line), fp)) {
        char *field;
        field = strtok(line, ",");
        int i = 0;

        while (field) {
            strcpy(data->fields[data->rows][i], field);
            i++;
            field = strtok(NULL, ",");
        }

        data->rows++;
        if (i > data->cols) {
            data->cols = i;
        }
    }

    fclose(fp);
    return data;
}

int main(int argc, char **argv) {
    csv_data_t *data = read_csv_file(argv[1]);
    if (data) {
        printf("CSV file contains %d rows and %d columns:\n", data->rows, data->cols);
        print_csv_data(data);
    } else {
        printf("Failed to read CSV file\n");
    }

    free(data);
    return 0;
}