//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 10000
#define MAX_COLUMNS 100

typedef struct {
    char *name;
    char *address;
    char *phone;
} Person;

typedef struct {
    int num_rows;
    int num_columns;
    char **row;
} CSV;

CSV *load_csv(const char *filename) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->num_rows = 0;
    csv->num_columns = 0;
    csv->row = NULL;
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Failed to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#') {
            continue;
        }
        char *words[MAX_COLUMNS];
        int word_count = 0;
        char *word = strtok(line, ",");
        while (word) {
            words[word_count] = word;
            word_count++;
            word = strtok(NULL, ",");
        }
        if (word_count > csv->num_columns) {
            csv->num_columns = word_count;
            csv->row = (char **)realloc(csv->row, sizeof(char *) * csv->num_columns);
            for (int i = 0; i < csv->num_columns; i++) {
                csv->row[i] = strdup(words[i]);
            }
        } else {
            fprintf(stderr, "Error: Column count mismatch for file %s\n", filename);
            exit(EXIT_FAILURE);
        }
        csv->num_rows++;
    }
    fclose(file);
    return csv;
}

void free_csv(CSV *csv) {
    if (csv!= NULL) {
        free(csv->row);
        free(csv);
    }
}

void print_csv(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        printf("%s\n", csv->row[i]);
    }
}

int main() {
    CSV *csv = load_csv("people.csv");
    print_csv(csv);
    free_csv(csv);
    return 0;
}