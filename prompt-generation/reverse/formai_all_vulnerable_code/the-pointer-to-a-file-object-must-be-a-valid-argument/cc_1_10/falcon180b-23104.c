//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

typedef struct {
    char **data;
    int row;
    int col;
} CSV;

CSV *csv_create(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = malloc(MAX_ROW * sizeof(char*));
    csv->row = 0;
    csv->col = 0;

    char line[MAX_ROW];
    while (fgets(line, MAX_ROW, fp)!= NULL) {
        char *token = strtok(line, ",");
        int i;
        for (i = 0; i < MAX_COL; i++) {
            csv->data[csv->row][i] = token;
            token = strtok(NULL, ",");
            if (token == NULL) break;
        }
        csv->row++;
    }

    return csv;
}

void csv_destroy(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->row; i++) {
        for (j = 0; j < csv->col; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_get_row_col(CSV *csv) {
    return csv->row * csv->col;
}

char **csv_get_data(CSV *csv) {
    return csv->data;
}

int main() {
    FILE *fp;
    fp = fopen("data.csv", "r");

    CSV *csv;
    csv = csv_create(fp);

    int row_col = csv_get_row_col(csv);
    char **data = csv_get_data(csv);

    int i, j;
    for (i = 0; i < csv->row; i++) {
        for (j = 0; j < csv->col; j++) {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }

    csv_destroy(csv);
    fclose(fp);

    return 0;
}