//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ROWS 100
#define MAX_COLS 200
#define MAX_DATA 1000

typedef struct {
    char *data;
    int rows;
    int cols;
} Table;

Table *createTable(int rows, int cols) {
    Table *table = (Table *)malloc(sizeof(Table));
    table->data = (char *)malloc(sizeof(char) * rows * cols);
    table->rows = rows;
    table->cols = cols;
    return table;
}

void destroyTable(Table *table) {
    free(table->data);
    free(table);
}

void printTable(Table *table) {
    int i, j;
    for(i=0; i<table->rows; i++) {
        for(j=0; j<table->cols; j++) {
            printf("%c", table->data[i*table->cols+j]);
        }
        printf("\n");
    }
}

int main() {
    Table *table = createTable(3, 3);
    table->data[0] = 'A';
    table->data[1] = 'B';
    table->data[2] = 'C';
    table->data[3] = 'D';
    table->data[4] = 'E';
    table->data[5] = 'F';
    table->data[6] = 'G';
    table->data[7] = 'H';
    table->data[8] = 'I';
    printTable(table);
    destroyTable(table);
    return 0;
}