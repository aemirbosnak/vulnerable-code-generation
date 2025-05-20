//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

// Function to split a string based on delimiter
char **split(char *str, char delimiter) {
    int count = 0;
    char **tokens = NULL;
    char *token = strtok(str, delimiter);

    while (token!= NULL) {
        count++;
        tokens = realloc(tokens, sizeof(char *) * count);
        tokens[count - 1] = token;
        token = strtok(NULL, delimiter);
    }

    tokens[count - 1] = NULL;
    return tokens;
}

// Function to read CSV file and store data in 2D array
void read_csv(char *filename, char ***data, int *rows, int *cols) {
    FILE *fp = fopen(filename, "r");
    char line[MAX_CELL_SIZE];
    int row = 0;
    int col = 0;

    // Read first line to determine number of columns
    fgets(line, MAX_CELL_SIZE, fp);
    *cols = split(line, ',')[0];

    // Allocate memory for 2D array
    *data = malloc(*rows * sizeof(char *));
    for (row = 0; row < *rows; row++) {
        (*data)[row] = malloc(*cols * sizeof(char *));
    }

    // Read remaining lines and store data in 2D array
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char **tokens = split(line, ',');

        for (col = 0; col < *cols; col++) {
            strcpy((*data)[row][col], tokens[col]);
        }

        row++;
    }

    fclose(fp);
}

// Function to print 2D array
void print_data(int rows, int cols, char **data) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            printf("%s\t", data[row][col]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    char **data;
    int rows, cols;

    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    read_csv(argv[1], &data, &rows, &cols);
    print_data(rows, cols, data);

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            free(data[row][col]);
        }
        free(data[row]);
    }
    free(data);

    return 0;
}