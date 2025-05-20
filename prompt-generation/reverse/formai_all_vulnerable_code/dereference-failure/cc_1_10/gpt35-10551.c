//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_CHARS_PER_LINE 200

int get_csv_field(char *line, char *field, int field_num) {
    int i, j, k;
    int delim_found = 0;
    int len = strlen(line);

    for (i = 0, j = 0, k = 1; i < len && k <= field_num; i++) {
        if (line[i] != ',' && line[i] != '\n') {
            if (k == field_num && !delim_found) {
                field[j++] = line[i];
            }
        } else {
            k++;
            delim_found = 1;
        }
    }

    field[j] = '\0';

    if (k < field_num) {
        return -1;
    }

    return 0;
}

int main(int argc, char **argv) {
    FILE *fp;
    char line[MAX_CHARS_PER_LINE];
    char field[MAX_CHARS_PER_LINE];
    char *filename;
    int num_fields, i;

    if (argc != 3) {
        printf("Usage: csv_reader <filename> <num_fields>\n");
        return 1;
    }

    filename = argv[1];
    num_fields = atoi(argv[2]);

    if (num_fields > MAX_COLS) {
        printf("Too many fields requested (max %d)\n", MAX_COLS);
        return 1;
    }

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    while (fgets(line, MAX_CHARS_PER_LINE, fp) != NULL) {
        for (i = 1; i <= num_fields; i++) {
            if (get_csv_field(line, field, i) == -1) {
                printf("Error: not enough fields on line\n");
                break;
            }
            printf("Field %d: %s\n", i, field);
        }
    }

    fclose(fp);

    return 0;
}