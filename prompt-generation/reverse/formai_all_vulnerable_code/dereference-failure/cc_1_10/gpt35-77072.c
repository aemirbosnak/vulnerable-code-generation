//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 256
#define MAX_BUFFER_SIZE 1024

typedef struct csv_reader {
    char *buffer;                   /* current buffer line */
    char *fields[MAX_COLS];         /* fields for current line */
    int num_cols;                   /* number of columns in the current line */
} csv_reader_t;

void csv_reader_init(csv_reader_t *csv, FILE *fp) {
    csv->buffer = (char*) malloc(sizeof(char) * MAX_BUFFER_SIZE);
    if(csv->buffer == NULL) {
        perror("Error allocating memory for buffer");
        exit(EXIT_FAILURE);
    }
    if(fgets(csv->buffer, MAX_BUFFER_SIZE, fp) == NULL) {
        perror("Error reading the first line of the CSV");
        exit(EXIT_FAILURE);
    }
    csv->num_cols = 0;
    char *token = strtok(csv->buffer, ",");
    while(token) {
        if(csv->num_cols == MAX_COLS) {
            perror("Too many columns!");
            exit(EXIT_FAILURE);
        }
        csv->fields[csv->num_cols++] = token;
        token = strtok(NULL, ",");
    }
}

char *csv_reader_get_field(csv_reader_t *csv, int col_idx) {
    if(col_idx >= csv->num_cols) {
        return NULL;
    }
    return csv->fields[col_idx];    
}

int main(int argc, char **argv) {
    if(argc < 2) {
        printf("Usage: %s [csv file name]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    csv_reader_t csv;
    csv_reader_init(&csv, fp);

    printf("Column 0 : %s\n", csv_reader_get_field(&csv, 0));
    printf("Column 3 : %s\n", csv_reader_get_field(&csv, 3));
    printf("Column 5 : %s\n", csv_reader_get_field(&csv, 5));

    fclose(fp);
    free(csv.buffer);
    return EXIT_SUCCESS;
}