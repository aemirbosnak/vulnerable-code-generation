//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

typedef struct {
    int row;
    int col;
    char **data;
} CSV;

CSV *csv_create(void) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->row = 0;
    csv->col = 0;
    csv->data = (char **)malloc(MAX_ROW * sizeof(char *));
    for (int i = 0; i < MAX_ROW; i++) {
        csv->data[i] = (char *)malloc(MAX_COL * sizeof(char));
        memset(csv->data[i], 0, MAX_COL);
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
        if (csv->col >= MAX_COL) {
            printf("Error: Column overflow.\n");
            exit(1);
        }
        if (csv->row >= MAX_ROW) {
            printf("Error: Row overflow.\n");
            exit(1);
        }
        if (ch == ',') {
            csv->data[csv->row][csv->col] = 0;
            csv->col++;
        } else if (ch == '\n') {
            csv->data[csv->row][csv->col] = 0;
            csv->col = 0;
            csv->row++;
        } else {
            csv->data[csv->row][csv->col++] = ch;
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
    fp = fopen("data.csv", "r");
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