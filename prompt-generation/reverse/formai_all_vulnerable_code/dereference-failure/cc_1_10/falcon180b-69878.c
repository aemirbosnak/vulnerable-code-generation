//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROW 1000
#define MAX_COL 1000
#define MAX_LINE 10000

typedef struct {
    char **data;
    int row;
    int col;
} csv_t;

csv_t *csv_create(void) {
    csv_t *csv = malloc(sizeof(csv_t));
    csv->row = 0;
    csv->col = 0;
    csv->data = malloc(MAX_ROW * sizeof(char*));
    for (int i = 0; i < MAX_ROW; i++) {
        csv->data[i] = malloc(MAX_COL * sizeof(char));
        memset(csv->data[i], 0, MAX_COL);
    }
    return csv;
}

void csv_destroy(csv_t *csv) {
    for (int i = 0; i < csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_read(csv_t *csv, FILE *fp) {
    char line[MAX_LINE];
    char *token;
    while (fgets(line, MAX_LINE, fp)!= NULL) {
        csv->row++;
        token = strtok(line, ",");
        while (token!= NULL) {
            csv->col++;
            if (csv->col >= MAX_COL) {
                printf("Error: Column exceeds maximum limit.\n");
                exit(1);
            }
            strcpy(csv->data[csv->row-1] + csv->col*sizeof(char)-1, token);
            csv->col++;
            token = strtok(NULL, ",");
        }
        if (csv->col == 0) {
            csv->col++;
        }
    }
}

void csv_print(csv_t *csv) {
    for (int i = 0; i < csv->row; i++) {
        for (int j = 0; j < csv->col; j++) {
            printf("%s ", csv->data[i] + j*sizeof(char));
        }
        printf("\n");
    }
}

int main() {
    csv_t *csv = csv_create();
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    csv_read(csv, fp);
    fclose(fp);
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}