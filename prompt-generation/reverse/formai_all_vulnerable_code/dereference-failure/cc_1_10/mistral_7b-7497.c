//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ROWS 1000
#define MAX_COLS 10

typedef struct {
    char name[MAX_COLS];
    double value;
} CSV_DATA;

void parse_line(char *line, CSV_DATA *data) {
    char *token;
    int col = 0;

    token = strtok(line, ",");
    strcpy(data->name, token);

    while ((token = strtok(NULL, ",")) != NULL) {
        data->value = atof(token);
        col++;

        if (col >= MAX_COLS) {
            fprintf(stderr, "Too many columns in line: %s\n", line);
            exit(1);
        }
    }
}

int main() {
    FILE *file;
    CSV_DATA data[MAX_ROWS];
    char line[1024];
    int row = 0;

    file = fopen("data.csv", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        CSV_DATA *d = &data[row];
        parse_line(line, d);
        row++;

        if (row >= MAX_ROWS) {
            fprintf(stderr, "Too many rows in file\n");
            exit(1);
        }
    }

    fclose(file);

    // Perform mathematical operations on the data here

    return 0;
}