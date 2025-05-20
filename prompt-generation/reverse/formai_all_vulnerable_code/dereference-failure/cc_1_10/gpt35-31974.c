//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char **data;
    int num_cols;
} Row;

typedef struct {
    Row *rows;
    int num_rows;
    int num_cols;
} CSV;

void free_row(Row *row) {
    int i;
    for (i = 0; i < row->num_cols; i++) {
        free(row->data[i]);
    }
    free(row->data);
}

void free_csv(CSV *csv) {
    int i;
    for (i = 0; i < csv->num_rows; i++) {
        free_row(&csv->rows[i]);
    }
    free(csv->rows);
}

void split_line(char *line, char *delim, char ***tokens, int *num_tokens) {
    int i;
    char *token;
    char **tmp_tokens = NULL;
    
    token = strtok(line, delim);
    while (token != NULL) {
        tmp_tokens = (char**)realloc(tmp_tokens, (*num_tokens+1)*sizeof(char*));
        if (tmp_tokens == NULL) {
            fprintf(stderr, "Out of memory\n");
            exit(EXIT_FAILURE);
        }
        tmp_tokens[*num_tokens] = strdup(token);
        (*num_tokens)++;
        token = strtok(NULL, delim);
    }
    
    *tokens = tmp_tokens;
}

void load_csv(char *filename, CSV *csv) {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char **tokens;
    int num_tokens;
    int i, j;
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    
    /* count number of rows and columns */
    csv->num_rows = 0;
    csv->num_cols = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        split_line(line, ",", &tokens, &num_tokens);
        csv->num_rows++;
        if (csv->num_cols == 0) {
            csv->num_cols = num_tokens;
        }
        else if (csv->num_cols != num_tokens) {
            fprintf(stderr, "Error: inconsistent number of columns at row %d\n", csv->num_rows);
            exit(EXIT_FAILURE);
        }
        free(tokens);
    }
    
    /* allocate memory for rows */
    csv->rows = (Row*)malloc(csv->num_rows*sizeof(Row));
    if (csv->rows == NULL) {
        fprintf(stderr, "Out of memory\n");
        exit(EXIT_FAILURE);
    }
    
    rewind(fp);
    i = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        split_line(line, ",", &tokens, &num_tokens);
        csv->rows[i].data = tokens;
        csv->rows[i].num_cols = num_tokens;
        i++;
    }
    
    fclose(fp);
}

void print_csv(CSV *csv) {
    int i, j;
    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_cols; j++) {
            printf("%s", csv->rows[i].data[j]);
            if (j < csv->num_cols-1) {
                printf(",");
            }
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    CSV csv;
    load_csv(argv[1], &csv);
    print_csv(&csv);
    free_csv(&csv);
    
    return 0;
}