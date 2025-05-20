//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_COLS 50

char* fields[MAX_ENTRIES][MAX_COLS];
int num_rows = 0;
int num_cols = 0;

void parse_csv(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char line[1000];
    while (fgets(line, 1000, fp)) {
        char* token = strtok(line, ",");
        int col = 0;

        while (token != NULL) {
            fields[num_rows][col] = (char*) malloc(sizeof(char) * strlen(token));
            strcpy(fields[num_rows][col], token);
            token = strtok(NULL, ",");
            col++;
        }

        if (col > num_cols) {
            num_cols = col;
        }

        num_rows++;
    }

    fclose(fp);
}

int main() {
    char filename[] = "example.csv";

    parse_csv(filename);

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%s ", fields[i][j]);
        }
        printf("\n");
    }

    return 0;
}