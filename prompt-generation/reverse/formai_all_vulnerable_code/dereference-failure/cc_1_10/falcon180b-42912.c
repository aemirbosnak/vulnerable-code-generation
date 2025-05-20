//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000

typedef struct {
    int row;
    int col;
    char data[MAX_COL];
} Cell;

typedef struct {
    int row;
    int col;
} Coord;

Cell *csvReader(char *filename) {
    FILE *fp;
    char line[MAX_ROW];
    char *ptr;
    Cell *table = (Cell *)malloc(sizeof(Cell));
    int row = 0;
    int col = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_ROW, fp)!= NULL) {
        ptr = strtok(line, ",");
        while (ptr!= NULL) {
            if (col >= MAX_COL) {
                printf("Error: Column limit exceeded\n");
                exit(1);
            }
            strcpy(table->data, ptr);
            table->row = row;
            table->col = col;
            col++;
            table++;
            ptr = strtok(NULL, ",");
        }
        row++;
        col = 0;
    }

    fclose(fp);
    return table;
}

void printTable(Cell *table, int row, int col) {
    int i, j;

    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%s ", table[i * col + j].data);
        }
        printf("\n");
    }
}

int main() {
    char filename[MAX_ROW];
    Cell *table;

    printf("Enter CSV file name: ");
    scanf("%s", filename);

    table = csvReader(filename);
    printTable(table, table[0].row, table[0].col);

    free(table);
    return 0;
}