//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

int main(int argc, char **argv) {

    char *filename;
    if (argc == 2) {
        filename = argv[1];
    } else {
        printf("Usage: csvreader <filename>\n");
        return 1;
    }

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Cannot read file %s\n", filename);
        return 1;
    }

    char line[MAX_LINE_SIZE];
    char *token;
    int row = 0;
    while (fgets(line, MAX_LINE_SIZE, file)) {
        char *row_array[10];
        int col = 0;

        token = strtok(line, ",");
        while (token != NULL && col < 10) {
            row_array[col] = (char *)malloc(sizeof(char) * strlen(token));
            strcpy(row_array[col], token);
            token = strtok(NULL, ",");

            col++;
        }

        printf("Row %d: ", row);
        for (int i = 0; i < col; i++) {
            printf("%s ", row_array[i]);
        }
        printf("\n");

        for (int i = 0; i < col; i++) {
            free(row_array[i]);
        }

        row++;
    }

    fclose(file);

    return 0;
}