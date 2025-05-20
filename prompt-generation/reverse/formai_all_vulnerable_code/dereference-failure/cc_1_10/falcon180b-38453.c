//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

// Function to split a string by a delimiter
char **split(char *str, char delimiter) {
    int count = 0;
    char **result = NULL;
    char *token = strtok(str, delimiter);

    while (token!= NULL) {
        count++;
        result = realloc(result, sizeof(char *) * count);
        result[count - 1] = token;
        token = strtok(NULL, delimiter);
    }

    return result;
}

// Function to read a CSV file and return a 2D array of strings
char **read_csv(FILE *file) {
    char line[MAX_CELL_SIZE];
    char **result = NULL;
    int rows = 0;
    int cols = 0;

    while (fgets(line, MAX_CELL_SIZE, file)!= NULL) {
        rows++;
        cols = 0;
        char *cell = strtok(line, ",");

        while (cell!= NULL) {
            cols++;
            cell = strtok(NULL, ",");
        }

        if (result == NULL) {
            result = malloc(sizeof(char *) * rows);
        } else {
            result = realloc(result, sizeof(char *) * rows);
        }

        result[rows - 1] = malloc(sizeof(char) * (cols + 1));
        strcpy(result[rows - 1], line);
    }

    return result;
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
    fclose(file);

    print_array(data, 3, 3);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            free(data[i][j]);
        }
        free(data[i]);
    }
    free(data);

    return 0;
}