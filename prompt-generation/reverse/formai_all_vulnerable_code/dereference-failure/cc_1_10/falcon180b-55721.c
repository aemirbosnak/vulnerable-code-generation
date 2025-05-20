//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
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

CSV *csv_create() {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(MAX_ROW * sizeof(char *));
    csv->row = 0;
    csv->col = 0;
    for (int i = 0; i < MAX_ROW; i++) {
        csv->data[i] = (char *)malloc(MAX_COL * sizeof(char));
    }
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_read(CSV *csv, FILE *fp) {
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            csv->row++;
            csv->col = 0;
        } else if (ch == ',') {
            csv->col++;
        } else {
            if (csv->row >= MAX_ROW || csv->col >= MAX_COL) {
                printf("Error: CSV row or column limit exceeded.\n");
                exit(1);
            }
            csv->data[csv->row][csv->col] = ch;
            csv->col++;
        }
    }
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        for (int j = 0; j < csv->col; j++) {
            printf("%c", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    CSV *csv = csv_create();
    csv_read(csv, fp);
    fclose(fp);

    csv_print(csv);

    csv_destroy(csv);

    return 0;
}