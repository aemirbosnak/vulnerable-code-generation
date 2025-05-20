//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FIELD_SIZE 256

typedef struct {
    char *field[MAX_FIELD_SIZE];
    int field_count;
} csv_row;

csv_row *csv_parse_line(char *line) {
    char *token = strtok(line, ",");
    csv_row *row = (csv_row *)malloc(sizeof(csv_row));
    row->field_count = 0;
    while (token!= NULL) {
        if (row->field_count >= MAX_FIELD_SIZE) {
            printf("Error: Too many fields in row.\n");
            exit(1);
        }
        row->field[row->field_count] = strdup(token);
        row->field_count++;
        token = strtok(NULL, ",");
    }
    return row;
}

void csv_print_row(csv_row *row) {
    for (int i = 0; i < row->field_count; i++) {
        printf("%s ", row->field[i]);
    }
    printf("\n");
}

void csv_free_row(csv_row *row) {
    for (int i = 0; i < row->field_count; i++) {
        free(row->field[i]);
    }
    free(row);
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    char line[MAX_LINE_SIZE];
    csv_row *row;
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        row = csv_parse_line(line);
        csv_print_row(row);
        csv_free_row(row);
    }
    fclose(file);
    return 0;
}