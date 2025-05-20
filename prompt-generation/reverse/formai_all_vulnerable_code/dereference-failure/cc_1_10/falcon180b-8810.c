//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
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

CSV *csv_open(char *filename) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(MAX_ROW * sizeof(char *));
    csv->row = 0;
    csv->col = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: can't open %s\n", filename);
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *ptr = strchr(line, '\n');
        if (ptr!= NULL) {
            *ptr = '\0';
        }
        csv->data[csv->row] = (char *)malloc((strlen(line) + 1) * sizeof(char));
        strcpy(csv->data[csv->row], line);
        csv->row++;
    }

    csv->col = strlen(csv->data[0]) / sizeof(char);

    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        for (int j = 0; j < csv->col; j++) {
            printf("%c", csv->data[i][j]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->row; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}