//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create(void) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    csv->rows = 0;
    csv->cols = 0;
    
    for (int i = 0; i < MAX_ROWS; i++) {
        csv->data[i] = (char *)malloc(MAX_COLS * sizeof(char));
    }
    
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_read(CSV *csv, FILE *fp) {
    char ch;
    int row = 0;
    int col = 0;
    
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == ',') {
            csv->data[row][col] = '\0';
            col++;
        } else if (ch == '\n') {
            csv->data[row][col] = '\0';
            row++;
            col = 0;
        } else {
            csv->data[row][col++] = ch;
        }
    }
    
    csv->data[row][col] = '\0';
    csv->rows++;
    csv->cols = col;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *fp_in = fopen(argv[1], "r");
    FILE *fp_out = fopen(argv[2], "w");

    if (fp_in == NULL || fp_out == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    CSV *csv = csv_create();
    csv_read(csv, fp_in);
    csv_print(csv);

    csv_destroy(csv);

    return 0;
}