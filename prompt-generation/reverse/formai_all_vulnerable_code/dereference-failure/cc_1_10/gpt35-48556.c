//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 100
#define MAX_LINE_LEN 100

char* csv_rows[MAX_ROWS][MAX_COLS];
char csv_line[MAX_LINE_LEN];

void panic(char* message)
{
    printf("Error: %s\n", message);
    exit(1);
}

void read_csv_file(char* filename)
{
    FILE* file = fopen(filename, "r");

    if (!file) panic("Failed to open file");

    int row = 0;

    while (fgets(csv_line, MAX_LINE_LEN, file) && row < MAX_ROWS) {
        int col = 0;
        char* token = strtok(csv_line, ",");
        while (token != NULL && col < MAX_COLS) {
            csv_rows[row][col] = malloc(strlen(token) + 1);
            if (!csv_rows[row][col]) panic("Failed to allocate memory");
            strncpy(csv_rows[row][col], token, strlen(token));
            csv_rows[row][col][strlen(token)] = '\0';
            token = strtok(NULL, ",");
            col++;
        }
        row++;
    }

    fclose(file);
}

void print_csv_file()
{
    int row, col;

    printf("=== Start of CSV file ===\n");

    for (row = 0; row < MAX_ROWS; row++) {
        if (csv_rows[row][0] == NULL) break;
        for (col = 0; col < MAX_COLS; col++) {
            if (csv_rows[row][col] == NULL) break;
            printf("%s ", csv_rows[row][col]);
        }
        printf("\n");
    }

    printf("=== End of CSV file ===\n");
}

int main(int argc, char* argv[])
{
    if (argc != 2) panic("Expected one argument");

    read_csv_file(argv[1]);

    print_csv_file();

    return 0;
}