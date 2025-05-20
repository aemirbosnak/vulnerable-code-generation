//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLS 20

typedef struct CSV_ROW {
    char **data;
    int num_cols;
} CSV_ROW;

CSV_ROW **read_csv(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    CSV_ROW **rows = malloc(MAX_ROWS * sizeof(CSV_ROW));
    rows[0] = malloc(MAX_COLS * sizeof(char *));
    rows[0]->data = malloc(MAX_COLS * sizeof(char *));

    int num_rows = 0;
    char line[1024];
    while (fgets(line, 1024, fp) != NULL) {
        int num_cols = 0;
        char **data = rows[num_rows]->data;
        char *p = line;
        while (p = strchr(p, ',')) {
            data[num_cols++] = strdup(p + 1);
            p++;
        }
        data[num_cols] = NULL;
        rows[num_rows]->num_cols = num_cols;
        num_rows++;
    }

    fclose(fp);
    return rows;
}

int main() {
    CSV_ROW **rows = read_csv("data.csv");
    for (int i = 0; rows[i] != NULL; i++) {
        for (int j = 0; rows[i]->data[j] != NULL; j++) {
            printf("%s, ", rows[i]->data[j]);
        }
        printf("\n");
    }

    return 0;
}