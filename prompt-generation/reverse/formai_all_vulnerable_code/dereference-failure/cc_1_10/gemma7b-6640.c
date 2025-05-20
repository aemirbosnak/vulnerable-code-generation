//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 1024
#define MAX_COLS 256

typedef struct CSV_Record {
    char **data;
    int num_cols;
} CSV_Record;

CSV_Record **read_csv(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    CSV_Record **records = malloc(MAX_LINES * sizeof(CSV_Record));
    int num_records = 0;

    char line[MAX_LINES];
    while (fgets(line, MAX_LINES, fp) != NULL) {
        char **cols = malloc(MAX_COLS * sizeof(char *));
        int num_cols = 0;

        // Split the line into columns
        char *ptr = line;
        while (ptr) {
            char *col = strchr(ptr, ',');
            if (col) {
                *cols = strdup(ptr);
                num_cols++;
                ptr = col + 1;
            } else {
                *cols = strdup(ptr);
                num_cols++;
                ptr = NULL;
            }
        }

        CSV_Record *record = malloc(sizeof(CSV_Record));
        record->data = cols;
        record->num_cols = num_cols;

        records[num_records++] = record;
    }

    fclose(fp);
    return records;
}

int main() {
    CSV_Record **records = read_csv("data.csv");

    for (int i = 0; records[i] != NULL; i++) {
        for (int j = 0; records[i]->data[j] != NULL; j++) {
            printf("%s, ", records[i]->data[j]);
        }
        printf("\n");
    }

    return 0;
}