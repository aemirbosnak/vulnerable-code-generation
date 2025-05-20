//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 20

char **data;
int rows = 0, cols = 0;

void read_csv(FILE *fp) {
    char line[1024], *token;
    int i = 0, j = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (i == rows) {
            data = realloc(data, sizeof(char *) * (rows + 1));
            data[rows] = malloc(sizeof(char *) * (cols + 1));
            memset(data[rows], 0, sizeof(char *) * (cols + 1));
            rows++;
            cols = 0;
        }

        token = strtok(line, ",");
        while (token != NULL) {
            if (j == cols) {
                data[i] = realloc(data[i], sizeof(char *) * (cols + 1));
                data[i][cols] = malloc(strlen(token) + 1);
                strcpy(data[i][cols], token);
                cols++;
            }

            token = strtok(NULL, ",");
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    if (argc != 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    read_csv(fp);
    fclose(fp);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s%c", data[i][j], j == cols - 1 ? '\n' : ',');
        }
    }

    for (int i = 0; i < rows; i++) {
        free(data[i]);
    }
    free(data);

    return EXIT_SUCCESS;
}