//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW 1000
#define MAX_COL 1000
#define MAX_CHAR 100

typedef struct {
    int row;
    int col;
    char value[MAX_CHAR];
} Cell;

typedef struct {
    int row;
    int col;
    int num_cells;
    Cell cells[MAX_ROW][MAX_COL];
} Sheet;

Sheet* create_sheet() {
    Sheet* sheet = (Sheet*)malloc(sizeof(Sheet));
    sheet->row = 0;
    sheet->col = 0;
    sheet->num_cells = 0;
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COL; j++) {
            sheet->cells[i][j].row = -1;
            sheet->cells[i][j].col = -1;
            sheet->cells[i][j].value[0] = '\0';
        }
    }
    return sheet;
}

void destroy_sheet(Sheet* sheet) {
    free(sheet);
}

int read_csv_file(Sheet* sheet, FILE* fp) {
    char line[MAX_CHAR];
    while (fgets(line, MAX_CHAR, fp)!= NULL) {
        int row = 0;
        int col = 0;
        char* p = strtok(line, ",");
        while (p!= NULL) {
            Cell* cell = &sheet->cells[row][col];
            strncpy(cell->value, p, MAX_CHAR - 1);
            cell->value[MAX_CHAR - 1] = '\0';
            cell->row = row;
            cell->col = col;
            sheet->num_cells++;
            col++;
            p = strtok(NULL, ",");
        }
        row++;
    }
    return 0;
}

int write_csv_file(Sheet* sheet, FILE* fp) {
    for (int i = 0; i < sheet->row; i++) {
        for (int j = 0; j < sheet->col; j++) {
            Cell* cell = &sheet->cells[i][j];
            fprintf(fp, "%s,", cell->value);
        }
        fprintf(fp, "\n");
    }
    return 0;
}

int main() {
    Sheet* sheet = create_sheet();
    FILE* fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        destroy_sheet(sheet);
        return 1;
    }
    read_csv_file(sheet, fp);
    fclose(fp);

    fp = fopen("output.csv", "w");
    if (fp == NULL) {
        printf("Error: Cannot create file.\n");
        destroy_sheet(sheet);
        return 1;
    }
    write_csv_file(sheet, fp);
    fclose(fp);

    destroy_sheet(sheet);
    return 0;
}