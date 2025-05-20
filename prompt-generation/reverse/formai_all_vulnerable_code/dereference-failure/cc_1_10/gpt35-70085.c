//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024 /* Maximum size of a line in the file */

/* Function to split a line based on a delimiter and return an array of tokens */
char **split_line(char *line, const char *delimiter, int *num_tokens) {
    int i;
    char **tokens = NULL;
    char *token = strtok(line, delimiter);

    while (token != NULL) {
        tokens = realloc(tokens, sizeof(char*) * (*num_tokens + 1));
        tokens[*num_tokens] = token;
        (*num_tokens)++;
        token = strtok(NULL, delimiter);
    }

    /* Add NULL at the end for safety */
    tokens = realloc(tokens, sizeof(char*) * (*num_tokens + 1));
    tokens[*num_tokens] = NULL;

    return tokens;
}

/* Function to read a CSV file and return a 2D array of data */
char ***read_csv_file(const char *filename, int *num_rows, int *num_cols) {
    int i, j;
    char ***data = NULL;
    char line[MAX_LINE_SIZE];
    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    /* Read the first line to determine the number of columns */
    if (fgets(line, MAX_LINE_SIZE, fp) == NULL) {
        fprintf(stderr, "Error: could not read file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }
    char **first_row_tokens = split_line(line, ",", num_cols);

    /* Read the remaining rows */
    while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        char **tokens = split_line(line, ",", num_cols);

        /* Add row to data */
        data = realloc(data, sizeof(char**) * (*num_rows + 1));
        data[*num_rows] = malloc(sizeof(char*) * (*num_cols));
        for (j = 0; j < *num_cols; j++) {
            data[*num_rows][j] = tokens[j];
        }
        (*num_rows)++;

        free(tokens);
    }

    fclose(fp);

    return data;
}

int main() {
    int i, j;
    int num_rows = 0;
    int num_cols = 0;
    char ***data = read_csv_file("data.csv", &num_rows, &num_cols);

    /* Print the data */
    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            printf("%s%c", data[i][j], j == num_cols - 1 ? '\n' : ',');
        }
    }

    /* Free the memory */
    for (i = 0; i < num_rows; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}