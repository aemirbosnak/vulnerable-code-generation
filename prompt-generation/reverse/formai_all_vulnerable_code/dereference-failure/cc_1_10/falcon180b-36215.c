//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

// Struct to hold CSV data
typedef struct {
    int num_cols;
    char **data;
} csv_data_t;

// Function to split a string by a delimiter
char **split(char *str, char delim) {
    int num_tokens = 0;
    char **tokens = NULL;
    char *token = strtok(str, delim);

    while (token!= NULL) {
        num_tokens++;
        tokens = realloc(tokens, sizeof(char *) * num_tokens);
        tokens[num_tokens - 1] = strdup(token);
        token = strtok(NULL, delim);
    }

    tokens[num_tokens] = NULL;
    return tokens;
}

// Function to read a CSV file
csv_data_t *read_csv_file(FILE *fp) {
    csv_data_t *data = NULL;
    char line[MAX_LINE_SIZE];
    char delim;

    // Read first line to determine delimiter
    fgets(line, MAX_LINE_SIZE, fp);
    delim = line[0];

    // Allocate memory for CSV data
    data = malloc(sizeof(csv_data_t));
    data->num_cols = 0;
    data->data = NULL;

    // Read remaining lines and split by delimiter
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char **tokens = split(line, delim);
        int num_cols = 0;

        // Count number of columns in row
        while (tokens[num_cols]!= NULL) {
            num_cols++;
        }

        // Reallocate memory for CSV data if necessary
        if (data->num_cols < num_cols) {
            data->num_cols = num_cols;
            data->data = realloc(data->data, sizeof(char *) * num_cols);
        }

        // Copy row data to CSV data
        for (int i = 0; i < num_cols; i++) {
            data->data[i] = strdup(tokens[i]);
        }

        // Free memory for tokens
        for (int i = 0; i < num_cols; i++) {
            free(tokens[i]);
        }
        free(tokens);
    }

    return data;
}

// Function to print CSV data
void print_csv_data(csv_data_t *data) {
    for (int i = 0; i < data->num_cols; i++) {
        printf("%s\t", data->data[i]);
    }
    printf("\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <CSV file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    csv_data_t *data = read_csv_file(fp);
    if (data == NULL) {
        printf("Error: Could not read CSV data.\n");
        return 1;
    }

    print_csv_data(data);

    // Free memory for CSV data
    for (int i = 0; i < data->num_cols; i++) {
        free(data->data[i]);
    }
    free(data->data);
    free(data);

    fclose(fp);
    return 0;
}