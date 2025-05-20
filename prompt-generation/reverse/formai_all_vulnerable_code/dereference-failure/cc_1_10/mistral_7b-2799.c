//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 5
#define MAX_COLS 5
#define BUFFER_SIZE 1024

typedef struct {
    char *name;
    float value;
} DataPoint;

DataPoint **data;

void parse_line(char *line) {
    DataPoint *dp;
    char *token;
    int i = 0;

    dp = (DataPoint *)calloc(MAX_COLS, sizeof(DataPoint));
    token = strtok(line, ",");

    while (token != NULL) {
        dp[i].name = strdup(token);
        dp[i].value = strtof(token, NULL);
        i++;

        if (i >= MAX_COLS) {
            fprintf(stderr, "Too many columns in a row\n");
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, ",");
    }

    data[i] = dp;
    i++;
}

void read_csv(char *filename) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char *line;
    int rows = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Couldn't open file");
        exit(EXIT_FAILURE);
    }

    data = (DataPoint **)calloc(MAX_ROWS, sizeof(DataPoint *));

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        line = strdup(buffer);
        parse_line(line);
        rows++;

        if (rows >= MAX_ROWS) {
            fprintf(stderr, "Too many rows in the file\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    read_csv(argv[1]);

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            printf("%s: %.2f\n", data[i][j].name, data[i][j].value);
        }
        printf("\n");
    }

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            free(data[i][j].name);
        }
        free(data[i]);
    }
    free(data);

    return EXIT_SUCCESS;
}