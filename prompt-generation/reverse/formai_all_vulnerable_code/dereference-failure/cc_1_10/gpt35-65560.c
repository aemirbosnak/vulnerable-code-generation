//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 10

typedef struct csv_row {
    char field[MAX_NUM_FIELDS][MAX_LINE_LENGTH];
    int num_fields;
} csv_row;

csv_row* read_csv_file(char* filename) {
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        return NULL;
    }

    csv_row* rows = (csv_row*) malloc(sizeof(csv_row) * MAX_LINE_LENGTH);
    int i = 0;

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, fp) != NULL) {
        char* token = strtok(buffer, ",");
        int j = 0;

        while (token != NULL && j < MAX_NUM_FIELDS) {
            strcpy(rows[i].field[j], token);
            token = strtok(NULL, ",");
            j++;
        }

        rows[i].num_fields = j;
        i++;
    }

    fclose(fp);
    return rows;
}

int main() {
    csv_row* rows = read_csv_file("example.csv");

    for (int i = 0; i < MAX_LINE_LENGTH && rows[i].num_fields != 0; i++) {
        for (int j = 0; j < rows[i].num_fields; j++) {
            printf("%s,", rows[i].field[j]);
        }
        printf("\n");
    }

    free(rows);
    return 0;
}