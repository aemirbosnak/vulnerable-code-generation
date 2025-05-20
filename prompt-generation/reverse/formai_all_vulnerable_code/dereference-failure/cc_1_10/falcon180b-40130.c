//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_COLUMNS 100

// Function to split a line of text into columns based on a delimiter
int split_line(char *line, char delimiter, char **columns, int max_columns) {
    int num_columns = 0;
    char *token = strtok(line, delimiter);

    while (token!= NULL && num_columns < max_columns) {
        columns[num_columns] = token;
        num_columns++;
        token = strtok(NULL, delimiter);
    }

    return num_columns;
}

// Function to read a CSV file and print its contents
void read_csv_file(FILE *file, char delimiter) {
    char line[MAX_LINE_SIZE];
    char **columns = NULL;
    int num_columns;

    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        num_columns = split_line(line, delimiter, columns, MAX_COLUMNS);

        if (num_columns > 0) {
            for (int i = 0; i < num_columns; i++) {
                printf("%s ", columns[i]);
            }
            printf("\n");
        }

        free(columns);
        columns = NULL;
    }
}

// Main function to open a CSV file and read its contents
int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <delimiter>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file '%s'.\n", argv[1]);
        return 1;
    }

    char delimiter = argv[2][0];

    read_csv_file(file, delimiter);

    fclose(file);
    return 0;
}