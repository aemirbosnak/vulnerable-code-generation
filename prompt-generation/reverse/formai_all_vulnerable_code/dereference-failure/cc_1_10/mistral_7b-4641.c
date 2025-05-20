//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_LINE_LENGTH 1024

// Function to split a line by delimiter
char** split_line(char* line, int* column_count) {
    char** tokens = (char**)malloc(MAX_COLUMNS * sizeof(char*));
    char* token = strtok(line, ",");
    int columns = 0;

    while (token != NULL) {
        tokens[columns] = token;
        columns++;

        if (columns >= MAX_COLUMNS) {
            fprintf(stderr, "Error: Too many columns in a line.\n");
            free(tokens);
            return NULL;
        }

        token = strtok(NULL, ",");
    }

    *column_count = columns;
    tokens[columns] = NULL;
    return tokens;
}

int main(int argc, char* argv[]) {
    FILE* file;
    char line[MAX_LINE_LENGTH];
    int columns;
    char** header;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file.");
        return 1;
    }

    header = split_line(fgets(line, MAX_LINE_LENGTH, file), &columns);
    if (header == NULL) {
        fclose(file);
        return 1;
    }

    printf("CSV Header:\n");
    for (int i = 0; i < columns; i++) {
        printf("%s\n", header[i]);
    }

    free(header);
    fclose(file);

    return 0;
}