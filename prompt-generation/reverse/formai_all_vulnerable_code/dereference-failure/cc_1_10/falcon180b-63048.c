//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100
#define DELIMITER ','

// Function to split a line into columns
void split_line(char *line, char delimiter, char **columns, int num_columns) {
    int i = 0;
    char *token = strtok(line, delimiter);
    while (token!= NULL && i < num_columns) {
        columns[i] = token;
        i++;
        token = strtok(NULL, delimiter);
    }
}

// Function to read a CSV file and print its contents
void read_csv_file(FILE *fp, int num_columns) {
    char line[MAX_LINE_LENGTH];
    char *columns[MAX_COLUMNS];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        split_line(line, DELIMITER, columns, num_columns);
        for (int i = 0; i < num_columns; i++) {
            printf("%s ", columns[i]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <num_columns>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", argv[1]);
        return 1;
    }

    int num_columns = atoi(argv[2]);
    if (num_columns <= 0 || num_columns > MAX_COLUMNS) {
        printf("Error: Invalid number of columns.\n");
        fclose(fp);
        return 1;
    }

    read_csv_file(fp, num_columns);

    fclose(fp);
    return 0;
}