//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

char* get_field(char* line, int num) {
    char* tok;
    for (tok = strtok(line, ","); tok && *tok; tok = strtok(NULL, ",\n")) {
        if (!--num) {
            return tok;
        }
    }
    return NULL;
}

int main() {
    int row_count = 0;
    int col_count = 0;
    char buffer[1024];
    char** data = (char**) calloc(MAX_ROWS * MAX_COLS, sizeof(char*));

    FILE* fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Cannot open file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, 1024, fp)) {
        char* tmp = strdup(buffer);
        col_count = 0;
        char* token = strtok(buffer, ",");
        while (token) {
            data[row_count * MAX_COLS + col_count++] = strdup(token);
            token = strtok(NULL, ",");
        }
        row_count++;
        free(tmp);
    }

    fclose(fp);

    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < col_count; j++) {
            printf("%s ", data[i * MAX_COLS + j]);
        }
        printf("\n");
    }

    for (int i = 0; i < row_count * MAX_COLS; i++) {
        if (data[i]) {
            free(data[i]);
        }
    }
    free(data);

    return 0;
}