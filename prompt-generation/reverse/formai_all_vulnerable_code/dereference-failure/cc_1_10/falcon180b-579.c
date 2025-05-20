//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
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

CSV* csv_create() {
    CSV *csv = (CSV*)malloc(sizeof(CSV));
    csv->row = 0;
    csv->col = 0;
    csv->data = (char**)malloc(sizeof(char*));
    csv->data[0] = NULL;
    return csv;
}

void csv_destroy(CSV *csv) {
    int i;
    for (i = 0; i <= csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_read_file(CSV *csv, FILE *fp) {
    char ch;
    int in_quote = 0;
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '"') {
            in_quote =!in_quote;
        } else if (ch == ',' &&!in_quote) {
            csv->data[csv->row] = (char*)realloc(csv->data[csv->row], strlen(csv->data[csv->row]) + 2);
            strcat(csv->data[csv->row], ",");
            csv->col++;
        } else if (ch == '\n' &&!in_quote) {
            csv->row++;
            csv->data = (char**)realloc(csv->data, sizeof(char*) * (csv->row + 1));
            csv->data[csv->row] = NULL;
            csv->col = 0;
        } else {
            csv->data[csv->row] = (char*)realloc(csv->data[csv->row], strlen(csv->data[csv->row]) + 2);
            strncat(csv->data[csv->row], &ch, 1);
            csv->col++;
        }
    }
}

void csv_print(CSV *csv) {
    int i, j;
    for (i = 0; i <= csv->row; i++) {
        for (j = 0; j < csv->col; j++) {
            printf("%c", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    CSV *csv;

    fp = fopen("example.csv", "r");
    csv = csv_create();
    csv_read_file(csv, fp);
    fclose(fp);

    csv_print(csv);

    csv_destroy(csv);

    return 0;
}