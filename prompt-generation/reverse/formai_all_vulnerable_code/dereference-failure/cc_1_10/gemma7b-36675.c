//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char **data = NULL;
    int **ptr = NULL;
    char csv_file[] = "data.csv";
    FILE *fp;
    int row_num = 0, col_num = 0, i, j;

    fp = fopen(csv_file, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Allocate memory for the data and pointer arrays
    data = (char**)malloc(row_num * sizeof(char*));
    ptr = (int**)malloc(row_num * sizeof(int*));

    // Read the CSV file line by line
    char line[1024];
    while (fgets(line, 1024, fp) != NULL) {
        // Count the number of columns in the line
        col_num = 0;
        char *token = strtok(line, ",");
        while (token) {
            col_num++;
            token = strtok(NULL, ",");
        }

        // Allocate memory for the data and pointer arrays
        data = (char**)realloc(data, row_num * sizeof(char*));
        ptr = (int**)realloc(ptr, row_num * sizeof(int*));

        // Store the data in the arrays
        data[row_num] = strdup(line);
        ptr[row_num] = col_num;

        row_num++;
    }

    // Close the file
    fclose(fp);

    // Print the data
    for (i = 0; i < row_num; i++) {
        for (j = 0; j < ptr[i]; j++) {
            printf("%s,", data[i]);
        }
        printf("\n");
    }

    // Free the memory
    free(data);
    free(ptr);

    return 0;
}