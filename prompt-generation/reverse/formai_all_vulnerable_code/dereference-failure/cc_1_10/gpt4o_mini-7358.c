//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

// Function to read a line from the file
char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        free(line);
        return NULL;
    }
    return line;
}

// Function to split the line into columns
char **split_line(char *line, int *num_columns) {
    char **columns = malloc(MAX_COLUMNS * sizeof(char *));
    char *token;
    int count = 0;

    token = strtok(line, ",");
    while (token != NULL && count < MAX_COLUMNS) {
        columns[count] = malloc(strlen(token) + 1);
        strcpy(columns[count], token);
        count++;
        token = strtok(NULL, ",");
    }
    *num_columns = count;
    return columns;
}

// Function to free allocated memory for columns
void free_columns(char **columns, int num_columns) {
    for (int i = 0; i < num_columns; i++) {
        free(columns[i]);
    }
    free(columns);
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = read_line(file)) != NULL) {
        int num_columns;
        char **columns = split_line(line, &num_columns);
        
        printf("Read line: %s", line);
        printf("Number of columns: %d\n", num_columns);
        
        for (int i = 0; i < num_columns; i++) {
            printf("Column %d: %s\n", i + 1, columns[i]);
        }
        
        // Free memory for columns
        free_columns(columns, num_columns);
        free(line);
    }

    fclose(file);
    return 0;
}