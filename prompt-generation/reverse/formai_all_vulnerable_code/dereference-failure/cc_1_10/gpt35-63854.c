//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 100
#define MAX_ROWS 100

int row = 0;
int col = 0;

char *csv_field[MAX_ROWS][MAX_COLS];
char csv_line[MAX_COLS * 20];

int read_csv(char *filename) {

    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return -1;
    }

    while(fgets(csv_line, MAX_COLS * 20, fp) != NULL && row < MAX_ROWS) {
        col = 0;
        char *token = strtok(csv_line, ",");
        while(token != NULL && col < MAX_COLS) {
            csv_field[row][col] = malloc(strlen(token) + 1);
            strcpy(csv_field[row][col], token);
            token = strtok(NULL, ",");
            col ++;
        }
        row ++;
    }

    fclose(fp);
    return 0;
}

void display_csv() {

    for(int i = 0; i < row; i ++) {
        for(int j = 0; j < col; j ++) {
            printf("%s ", csv_field[i][j]);
            free(csv_field[i][j]);
        }
        printf("\n");
    }
}

int main() {

    char filename[] = "example.csv";
    if(read_csv(filename) == 0) {
        display_csv();
    }

    return 0;
}