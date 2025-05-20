//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* field1;
    char* field2;
    char* field3;
} CSV_Row;

int read_csv(FILE* fp, CSV_Row* rows, int* n_rows) {
    int n_cols = 3;
    int n_rows_read = 0;
    char buffer[128];

    while (fgets(buffer, sizeof(buffer), fp)) {
        char* fields[n_cols];

        for (int i = 0; i < n_cols; ++i) {
            fields[i] = strtok(buffer, ",");
            if (fields[i] == NULL) {
                fprintf(stderr, "Error reading field %d\n", i);
                exit(1);
            }
        }

        rows[n_rows_read].field1 = strdup(fields[0]);
        rows[n_rows_read].field2 = strdup(fields[1]);
        rows[n_rows_read].field3 = strdup(fields[2]);
        n_rows_read++;
    }

    *n_rows = n_rows_read;
    return n_rows_read;
}

int main() {
    FILE* fp = fopen("data.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }

    CSV_Row rows[10];
    int n_rows = 0;

    if (read_csv(fp, rows, &n_rows)!= n_rows) {
        fprintf(stderr, "Error reading file\n");
        exit(1);
    }

    for (int i = 0; i < n_rows; ++i) {
        printf("%s,%s,%s\n", rows[i].field1, rows[i].field2, rows[i].field3);
    }

    fclose(fp);

    return 0;
}