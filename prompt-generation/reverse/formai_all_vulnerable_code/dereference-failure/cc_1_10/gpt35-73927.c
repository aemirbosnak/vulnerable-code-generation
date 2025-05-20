//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

/**
 * Function to parse a CSV file and return a 2D array.
 * Inputs: filename, delimiter
 * Outputs: 2D array of strings
 */
char*** parse_csv(const char* filename, const char* delimiter) {
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    int row = 0, col = 0;
    char*** table = malloc(MAX_ROWS * sizeof(char**));

    char buf[1024];

    while (fgets(buf, 1024, fp)) {
        col = 0;

        // Replace newlines with null characters
        buf[strcspn(buf, "\n")] = '\0';

        // Allocate memory for each row in the 2D array
        table[row] = malloc(MAX_COLS * sizeof(char*));

        char* token = strtok(buf, delimiter);

        while (token != NULL && col < MAX_COLS) {
            // Allocate memory for each column in the current row
            table[row][col] = malloc((strlen(token) + 1) * sizeof(char));

            // Copy the token into the current cell of the 2D array
            strcpy(table[row][col], token);

            // Increment column number and get next token
            col++;
            token = strtok(NULL, delimiter);
        }

        // Increment row number
        row++;
    }

    fclose(fp);

    return table;
}

int main() {
    char*** table = parse_csv("data.csv", ",");

    for (int i = 0; i < MAX_ROWS; i++) {
        if (table[i] == NULL) break;

        for (int j = 0; j < MAX_COLS; j++) {
            if (table[i][j] == NULL) break;

            printf("%s ", table[i][j]);
            free(table[i][j]);
        }

        printf("\n");
        free(table[i]);
    }

    free(table);

    return 0;
}