//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct csv_data {
    char **columns;
    int num_columns;
    char ***rows;
    int num_rows;
} CSV_DATA;

CSV_DATA read_csv(char *filename, char delimiter) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Failed to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    CSV_DATA data;
    char line[4096];
    int i = 0;
    while (fgets(line, 4096, fp)) {
        if (i == 0) {
            char *token = strtok(line, &delimiter);
            while (token) {
                data.columns = realloc(data.columns, (data.num_columns + 1) * sizeof(*data.columns));
                data.columns[data.num_columns++] = strdup(token);
                token = strtok(NULL, &delimiter);
            }
        } else {
            data.rows = realloc(data.rows, (data.num_rows + 1) * sizeof(*data.rows));
            data.rows[data.num_rows] = calloc(data.num_columns, sizeof(**data.rows));

            char *token = strtok(line, &delimiter);
            int j = 0;
            while (token) {
                data.rows[data.num_rows][j++] = strdup(token);
                token = strtok(NULL, &delimiter);
            }

            data.num_rows++;
        }
        i++;
    }

    fclose(fp);
    return data;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    CSV_DATA data = read_csv(argv[1], ',');
    printf("CSV contains %d columns and %d rows\n", data.num_columns, data.num_rows);

    for (int i = 0; i < data.num_columns; i++) {
        printf("%s\t", data.columns[i]);
    }
    printf("\n");

    for (int i = 0; i < data.num_rows; i++) {
        for (int j = 0; j < data.num_columns; j++) {
            printf("%s\t", data.rows[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < data.num_columns; i++) {
        free(data.columns[i]);
    }
    free(data.columns);

    for (int i = 0; i < data.num_rows; i++) {
        for (int j = 0; j < data.num_columns; j++) {
            free(data.rows[i][j]);
        }
        free(data.rows[i]);
    }
    free(data.rows);

    return 0;
}