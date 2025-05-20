//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_ROWS 200
#define MAX_FIELD_LEN 100

int read_csv(char* filename, char*** table)
{
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        perror("Failed to open file");
        return -1;
    }

    char line[MAX_COLS * MAX_FIELD_LEN];
    int row = 0;
    int col = 0;

    while (fgets(line, sizeof(line), fp)) {
        char* field = strtok(line, ",");
        col = 0;
        while (field) {
            if (col >= MAX_COLS) {
                fprintf(stderr, "Too many columns in row %d\n", row);
                return -1;
            }
            if (strlen(field) >= MAX_FIELD_LEN) {
                fprintf(stderr, "Field too long in row %d column %d\n", row, col);
                return -1;
            }
            strcpy(table[row][col], field);
            field = strtok(NULL, ",");
            col++;
        }
        row++;
    }

    fclose(fp);
    return row;
}

int main()
{
    char** table = (char**)malloc(sizeof(char*) * MAX_ROWS);
    for (int i = 0; i < MAX_ROWS; i++) {
        table[i] = (char*)malloc(sizeof(char) * MAX_COLS * MAX_FIELD_LEN);
    }

    int num_rows = read_csv("example.csv", &table);
    if (num_rows < 0) {
        fprintf(stderr, "Failed to read CSV\n");
        return -1;
    }

    // Print the table
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%s", table[i][j]);
            if (j < MAX_COLS - 1) printf(",");
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < MAX_ROWS; i++) {
        free(table[i]);
    }
    free(table);

    return 0;
}