//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read CSV file and return an array of strings
char** readCSV(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char** rows = (char**)malloc(sizeof(char*) * 100);
    char* line = NULL;
    size_t len = 0;
    size_t i = 0;
    while (getline(&line, &len, file)!= -1) {
        rows[i] = strdup(line);
        i++;
    }

    fclose(file);

    return rows;
}

// Function to print the CSV file data
void printCSV(char** rows, int num_rows) {
    for (int i = 0; i < num_rows; i++) {
        printf("%s\n", rows[i]);
    }
}

int main() {
    char** rows = readCSV("data.csv");
    int num_rows = 0;
    while (rows[num_rows]!= NULL) {
        num_rows++;
    }
    printf("Number of rows: %d\n", num_rows);

    printCSV(rows, num_rows);

    for (int i = 0; i < num_rows; i++) {
        free(rows[i]);
    }
    free(rows);

    return 0;
}