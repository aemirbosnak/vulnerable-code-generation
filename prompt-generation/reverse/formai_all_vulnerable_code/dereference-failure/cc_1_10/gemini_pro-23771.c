//GEMINI-pro DATASET v1.0 Category: File handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Delimiter used in CSV file
#define DELIM ","

// Function to split a line into tokens
char **split_line(char *line, int *num_tokens) {
    char **tokens = malloc(sizeof(char *) * 100);
    int token_count = 0;
    char *token = strtok(line, DELIM);
    while (token != NULL) {
        tokens[token_count++] = token;
        token = strtok(NULL, DELIM);
    }
    *num_tokens = token_count;
    return tokens;
}

// Function to read a CSV file and store its contents in a 2D array
char ***read_csv(char *filename, int *num_rows, int *num_cols) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    char line[1024];
    int row_count = 0;
    int col_count = 0;
    int num_tokens = 0;

    // Read the first line to determine the number of columns
    fgets(line, sizeof(line), fp);
    char **tokens = split_line(line, &num_tokens);
    col_count = num_tokens;

    // Allocate memory for the 2D array
    char ***data = malloc(sizeof(char **) * 100);
    for (int i = 0; i < 100; i++) {
        data[i] = malloc(sizeof(char *) * col_count);
    }

    // Read the remaining lines and store their contents in the 2D array
    while (fgets(line, sizeof(line), fp) != NULL) {
        tokens = split_line(line, &num_tokens);
        for (int i = 0; i < num_tokens; i++) {
            data[row_count][i] = tokens[i];
        }
        row_count++;
    }

    fclose(fp);

    *num_rows = row_count;
    *num_cols = col_count;
    return data;
}

// Function to write a 2D array to a CSV file
void write_csv(char *filename, char ***data, int num_rows, int num_cols) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            fprintf(fp, "%s,", data[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

// Main function
int main() {
    // Read a CSV file
    int num_rows, num_cols;
    char ***data = read_csv("data.csv", &num_rows, &num_cols);

    // Print the contents of the 2D array
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%s ", data[i][j]);
        }
        printf("\n");
    }

    // Write the 2D array to a new CSV file
    write_csv("new_data.csv", data, num_rows, num_cols);

    // Free the memory allocated for the 2D array
    for (int i = 0; i < num_rows; i++) {
        free(data[i]);
    }
    free(data);

    return 0;
}