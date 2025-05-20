//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

char* get_csv_value(char* line, int col) {
    char* token = strtok(line, ",");
    int current_col = 0;
    while (token != NULL) {
        if (current_col == col) {
            token[strcspn(token, "\n")] = 0;
            return token;
        }
        token = strtok(NULL, ",");
        current_col++;
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./csv_reader <filename>\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Could not open file %s\n", argv[1]);
        return 1;
    }

    char* rows[MAX_ROWS];
    int row_count = 0;
    while (!feof(file)) {
        char* row = malloc(MAX_COLS * sizeof(char));
        char* result = fgets(row, MAX_COLS, file);
        if (result == NULL) {
            break;
        }
        rows[row_count++] = row;
    }

    int col_count = 0;
    char* header_row = rows[0];
    char* header_token = strtok(header_row, ",");
    while (header_token != NULL) {
        col_count++;
        header_token = strtok(NULL, ",");
    }

    char* columns[MAX_COLS][MAX_ROWS];
    int row, col;
    for (row = 0; row < row_count; row++) {
        char* current_row = rows[row];
        for (col = 0; col < col_count; col++) {
            char* current_value = get_csv_value(current_row, col);
            columns[col][row] = current_value;
        }
    }

    // Print the values in the CSV file
    for (row = 0; row < row_count; row++) {
        for (col = 0; col < col_count; col++) {
            printf("%s\t", columns[col][row]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (row = 0; row < row_count; row++) {
        free(rows[row]);
    }

    fclose(file);
    return 0;
}