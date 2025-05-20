//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define DELIMITER ','

// Function to split a string by a delimiter
char **split(char *str, char delimiter) {
    int count = 0;
    char **result = NULL;
    char *token = strtok(str, delimiter);

    while (token!= NULL) {
        count++;
        result = realloc(result, sizeof(char *) * count);
        result[count - 1] = strdup(token);
        token = strtok(NULL, delimiter);
    }

    result[count - 1] = NULL;
    return result;
}

// Function to read a CSV file and return a 2D array of strings
char **read_csv(FILE *file) {
    char **rows = NULL;
    char line[1024];

    while (fgets(line, sizeof(line), file)!= NULL) {
        char **tokens = split(line, DELIMITER);
        rows = realloc(rows, sizeof(char *) * (MAX_ROWS + 1));
        rows[MAX_ROWS] = NULL;
        int i = 0;
        while (tokens[i]!= NULL) {
            rows[i] = tokens[i];
            i++;
        }
        free(tokens);
        i = 0;
    }

    return rows;
}

// Function to print a 2D array of strings
void print_array(char **array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", array[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    FILE *file = fopen("example.csv", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char **data = read_csv(file);

    print_array(data, MAX_ROWS, MAX_COLS);

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            free(data[i][j]);
        }
        free(data[i]);
    }
    free(data);

    fclose(file);

    return 0;
}