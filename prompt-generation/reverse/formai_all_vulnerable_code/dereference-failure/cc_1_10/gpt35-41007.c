//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_LINE_LENGTH 1024

char *csv_rows[MAX_ROWS][MAX_COLS];
int csv_rows_length[MAX_ROWS];

void parse_csv(FILE *csv_file) {
    char line[MAX_LINE_LENGTH];
    int row_num = 0;
    while (fgets(line, MAX_LINE_LENGTH, csv_file)) {
        if (strlen(line) == MAX_LINE_LENGTH-1) {
            printf("Line %d is too long, skipping...\n", row_num);
            continue;
        }

        char *token = strtok(line, ",");
        int col_num = 0;
        while (token && col_num < MAX_COLS) {
            char *cell_value = malloc(strlen(token) + 1);
            strcpy(cell_value, token);
            csv_rows[row_num][col_num] = cell_value;
            csv_rows_length[row_num] = ++col_num;
            token = strtok(NULL, ",");
        }

        row_num++;
        if (row_num == MAX_ROWS) {
            printf("Reached maximum row limit %d, stopping...\n", MAX_ROWS);
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a CSV file as the first argument!\n");
        return 1;
    }

    FILE *csv_file = fopen(argv[1], "r");
    if (!csv_file) {
        printf("Unable to open CSV file!\n");
        return 1;
    }

    parse_csv(csv_file);

    for (int i = 0; i < MAX_ROWS; i++) {
        if (csv_rows_length[i] > 0) {
            for (int j = 0; j < csv_rows_length[i]; j++) {
                printf("%s,", csv_rows[i][j]);
            }
            printf("\n");
        }
    }

    fclose(csv_file);

    return 0;
}