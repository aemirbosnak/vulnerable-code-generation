//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROW 1000
#define MAX_COL 1000

struct CSV {
    char delimiter;
    int row;
    int col;
    char **data;
};

struct CSV *csv_open(FILE *fp, char delimiter) {
    struct CSV *csv = (struct CSV *)malloc(sizeof(struct CSV));
    csv->delimiter = delimiter;
    csv->row = 0;
    csv->col = 0;
    csv->data = (char **)malloc(MAX_ROW * sizeof(char *));
    for (int i = 0; i < MAX_ROW; i++) {
        csv->data[i] = (char *)malloc(MAX_COL * sizeof(char));
        memset(csv->data[i], '\0', MAX_COL);
    }
    return csv;
}

void csv_close(struct CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_read(struct CSV *csv, FILE *fp) {
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            csv->row++;
            csv->col = 0;
        } else if (ch == csv->delimiter) {
            csv->data[csv->row][csv->col] = '\0';
            csv->col++;
        } else {
            csv->data[csv->row][csv->col++] = ch;
        }
    }
    return 1;
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    struct CSV *csv = csv_open(fp, ',');

    int row = 0;
    while (csv_read(csv, fp)) {
        for (int i = 0; i < csv->row; i++) {
            printf("Row %d: %s\n", i + 1, csv->data[i]);
        }
        row++;
    }

    csv_close(csv);
    fclose(fp);
    return 0;
}