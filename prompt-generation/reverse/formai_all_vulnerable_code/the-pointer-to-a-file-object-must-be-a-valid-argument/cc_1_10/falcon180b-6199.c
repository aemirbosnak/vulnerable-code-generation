//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create(void) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    if (csv->data!= NULL) {
        for (int i = 0; i < csv->rows; i++) {
            free(csv->data[i]);
        }
        free(csv->data);
    }
    free(csv);
}

int csv_read(CSV *csv, FILE *fp) {
    char line[1024];
    char *token;
    char **row = NULL;
    int rows = 0;
    int cols = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        token = strtok(line, ",");
        if (token == NULL) {
            continue;
        }

        if (rows == 0) {
            cols = 1;
            csv->cols = cols;
        } else if (cols!= csv->cols) {
            printf("Error: number of columns is inconsistent.\n");
            csv_destroy(csv);
            return -1;
        }

        row = (char **)realloc(row, sizeof(char *) * (rows + 1));
        row[rows] = (char *)malloc(strlen(token) + 1);
        strcpy(row[rows], token);
        rows++;
    }

    if (rows > 0) {
        csv->rows = rows;
        csv->cols = cols;
        csv->data = row;
    } else {
        csv_destroy(csv);
        return -1;
    }

    return 0;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    CSV *csv = csv_create();

    if (csv_read(csv, fp)!= 0) {
        return -1;
    }

    csv_print(csv);

    csv_destroy(csv);
    fclose(fp);

    return 0;
}