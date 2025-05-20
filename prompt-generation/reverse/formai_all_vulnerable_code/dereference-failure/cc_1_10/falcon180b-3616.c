//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
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

CSV* create_csv(void) {
    CSV *csv = (CSV*)malloc(sizeof(CSV));
    csv->data = (char**)malloc(MAX_ROW * sizeof(char*));
    csv->row = 0;
    csv->col = 0;
    for (int i = 0; i < MAX_ROW; i++) {
        csv->data[i] = (char*)malloc(MAX_COL * sizeof(char));
    }
    return csv;
}

void destroy_csv(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_append(CSV *csv, char *value) {
    if (csv->col >= MAX_COL) {
        fprintf(stderr, "Error: Column limit reached.\n");
        exit(1);
    }
    strcat(csv->data[csv->row], value);
    csv->col++;
}

void csv_new_row(CSV *csv) {
    if (csv->row >= MAX_ROW) {
        fprintf(stderr, "Error: Row limit reached.\n");
        exit(1);
    }
    csv->row++;
    csv->col = 0;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        printf("%s\n", csv->data[i]);
    }
}

int main(int argc, char *argv[]) {
    CSV *csv = create_csv();
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: File not found.\n");
        exit(1);
    }
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        if (ch == ',') {
            csv_new_row(csv);
        } else if (ch == '\n') {
            csv_new_row(csv);
        } else {
            csv_append(csv, &ch);
        }
    }
    fclose(fp);
    csv_print(csv);
    destroy_csv(csv);
    return 0;
}