//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LINES 10000
#define MAX_COLS 100
#define MAX_STR_LEN 100

typedef struct {
    int num_lines;
    int num_cols;
    char **data;
} dataset_t;

dataset_t *load_dataset(char *filename) {
    FILE *fp;
    char line[MAX_STR_LEN];
    dataset_t *dataset = malloc(sizeof(dataset_t));
    dataset->num_lines = 0;
    dataset->num_cols = 0;
    dataset->data = NULL;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, MAX_STR_LEN, fp) != NULL) {
        dataset->num_lines++;
        if (dataset->num_lines == 1) {
            char *token;
            token = strtok(line, ",");
            while (token != NULL) {
                dataset->num_cols++;
                token = strtok(NULL, ",");
            }
            dataset->data = malloc(sizeof(char *) * dataset->num_lines);
            for (int i = 0; i < dataset->num_lines; i++) {
                dataset->data[i] = malloc(sizeof(char) * MAX_STR_LEN);
            }
        }
        strcpy(dataset->data[dataset->num_lines - 1], line);
    }

    fclose(fp);

    return dataset;
}

void free_dataset(dataset_t *dataset) {
    for (int i = 0; i < dataset->num_lines; i++) {
        free(dataset->data[i]);
    }
    free(dataset->data);
    free(dataset);
}

void print_dataset(dataset_t *dataset) {
    for (int i = 0; i < dataset->num_lines; i++) {
        for (int j = 0; j < dataset->num_cols; j++) {
            printf("%s\t", dataset->data[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    dataset_t *dataset = load_dataset(argv[1]);

    print_dataset(dataset);

    free_dataset(dataset);

    return EXIT_SUCCESS;
}