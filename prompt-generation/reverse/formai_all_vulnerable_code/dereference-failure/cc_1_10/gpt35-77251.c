//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 128
#define MAX_FIELDS 10

struct csv_row {
    char fields[MAX_FIELDS][MAX_FIELD_LENGTH];
    int field_count;
};

void remove_newline(char *line) {
    char *pos = strchr(line, '\n');
    if (pos != NULL) {
        *pos = '\0';
    }
}

struct csv_row *parse_csv_row(char *line) {
    struct csv_row *row = malloc(sizeof(struct csv_row));
    row->field_count = 0;
    char *field = strtok(line, ",");
    while (field != NULL && row->field_count < MAX_FIELDS) {
        strncpy(row->fields[row->field_count], field, MAX_FIELD_LENGTH);
        row->field_count++;
        field = strtok(NULL, ",");
    }
    return row;
}

void print_csv_row(struct csv_row *row) {
    for (int i = 0; i < row->field_count; i++) {
        printf("%s,", row->fields[i]);
    }
    printf("\n");
}

void free_csv_row(struct csv_row *row) {
    free(row);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: could not open file\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, MAX_LINE_LENGTH, fp); // skip header

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        remove_newline(line);
        struct csv_row *row = parse_csv_row(line);
        print_csv_row(row);
        free_csv_row(row);
    }

    fclose(fp);
    return 0;
}