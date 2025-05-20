//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int num_fields;
} CSVRow;

CSVRow *csv_read(FILE *fp) {
    char line[MAX_LINE_LENGTH];
    CSVRow *row = malloc(sizeof(CSVRow));
    row->num_fields = 0;
    row->fields = malloc(MAX_FIELDS * sizeof(char *));

    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        char *token = strtok(line, ",");
        while (token) {
            row->fields[row->num_fields] = token;
            row->num_fields++;
            token = strtok(NULL, ",");
        }
    }

    row->fields[row->num_fields] = NULL;
    return row;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s filename.csv\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Error opening file\n");
        return 1;
    }

    CSVRow *row = csv_read(fp);
    while (row) {
        for (int i = 0; i < row->num_fields; i++) {
            printf("%s ", row->fields[i]);
        }
        printf("\n");
        row = csv_read(fp);
    }

    fclose(fp);
    return 0;
}