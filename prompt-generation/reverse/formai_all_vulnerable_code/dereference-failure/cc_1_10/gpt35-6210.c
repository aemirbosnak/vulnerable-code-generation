//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: peaceful
/*
* Program: CSV Reader Example
* Author: [Your Name]
* Date: [Date]
* Description: This program reads a Comma Separated Value (CSV) file and prints the data.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

void print_row(char **row, int cols) {
    for (int i = 0; i < cols; i++) {
        printf("%s\t", row[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char *filename;
    FILE *fp;
    char line[2048], *token;

    // Check if filename is passed in command line arguments
    if (argc < 2) {
        printf("Please provide a filename.\n");
        return 1;
    } else {
        filename = argv[1];
    }

    // Open file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    // Read the first line of CSV file (headers)
    if (fgets(line, sizeof(line), fp) != NULL) {
        // Remove new line character and split headers
        char **headers = malloc(sizeof(char *) * MAX_COLS);
        int cols = 0;
        token = strtok(line, ",");
        while (token != NULL) {
            token[strcspn(token, "\r\n")] = 0; // Remove new line character
            headers[cols] = token;
            cols++;
            token = strtok(NULL, ",");
        }

        // Print headers
        print_row(headers, cols);
        printf("----------------------------------------\n");

        // Read remaining rows
        char **rows = malloc(sizeof(char *) * MAX_ROWS);
        int row_count = 0;
        while (fgets(line, sizeof(line), fp) != NULL) {
            // Remove new line character and split row data
            char **row_data = malloc(sizeof(char *) * MAX_COLS);
            int col_count = 0;
            token = strtok(line, ",");
            while (token != NULL) {
                token[strcspn(token, "\r\n")] = 0; // Remove new line character
                row_data[col_count] = token;
                col_count++;
                token = strtok(NULL, ",");
            }
            rows[row_count] = row_data;
            row_count++;
        }

        // Print rows
        for (int i = 0; i < row_count; i++) {
            print_row(rows[i], cols);
        }

        // Free memory
        for (int i = 0; i < row_count; i++) {
            free(rows[i]);
        }
        free(rows);
        free(headers);
    }

    // Close file
    fclose(fp);

    return 0;
}