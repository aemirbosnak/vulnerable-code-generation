//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
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
    csv->data = (char**)malloc(sizeof(char*) * MAX_ROW);
    csv->row = 0;
    csv->col = 0;
    for (int i = 0; i < MAX_ROW; i++) {
        csv->data[i] = (char*)malloc(sizeof(char) * MAX_COL);
        memset(csv->data[i], '\0', MAX_COL);
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

void csv_read_file(CSV *csv, FILE *fp) {
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            csv->row++;
            csv->col = 0;
        } else if (ch == ',') {
            csv->col++;
        } else {
            int row = csv->row;
            int col = csv->col;
            csv->data[row][col] = ch;
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
    CSV *csv;
    char filename[100];

    printf("Enter the CSV file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found!\n");
        return 1;
    }

    csv = csv_create();
    csv_read_file(csv, fp);
    fclose(fp);

    printf("CSV file content:\n");
    csv_print(csv);

    csv_destroy(csv);

    return 0;
}