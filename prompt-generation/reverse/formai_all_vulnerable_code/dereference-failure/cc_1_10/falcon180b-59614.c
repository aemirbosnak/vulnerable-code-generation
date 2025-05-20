//Falcon-180B DATASET v1.0 Category: Data mining ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_WORDS 100

struct data_set {
    int rows;
    int cols;
    char **words;
};

struct data_set *load_data(char *filename) {
    FILE *fp = fopen(filename, "r");
    struct data_set *ds = (struct data_set *)malloc(sizeof(struct data_set));

    if (fp == NULL) {
        printf("Error loading data set.\n");
        exit(1);
    }

    fscanf(fp, "%d %d", &ds->rows, &ds->cols);
    ds->words = (char **)malloc(sizeof(char *) * ds->rows);

    for (int i = 0; i < ds->rows; i++) {
        ds->words[i] = (char *)malloc(sizeof(char) * (MAX_WORDS + 1));
        fscanf(fp, "%s", ds->words[i]);
    }

    fclose(fp);
    return ds;
}

void print_data(struct data_set *ds) {
    printf("Data set:\n");
    printf("Rows: %d\n", ds->rows);
    printf("Columns: %d\n", ds->cols);
    printf("Words:\n");

    for (int i = 0; i < ds->rows; i++) {
        printf("%s\n", ds->words[i]);
    }
}

void free_data(struct data_set *ds) {
    for (int i = 0; i < ds->rows; i++) {
        free(ds->words[i]);
    }
    free(ds->words);
    free(ds);
}

int main() {
    struct data_set *data = load_data("data.txt");
    print_data(data);
    free_data(data);

    return 0;
}