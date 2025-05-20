//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELD_LEN 128
#define MAX_FIELDS 10

typedef struct {
    char *fields[MAX_FIELDS];
    int num_fields;
} csv_line;

csv_line *read_csv(FILE *file) {
    char line[MAX_LINE_LEN];
    csv_line *csv = NULL;

    if (fgets(line, MAX_LINE_LEN, file)) {
        int i, j;
        csv = (csv_line*)malloc(sizeof(csv_line));
        csv->num_fields = 0;

        char *current_field = (char*)malloc(MAX_FIELD_LEN);
        j = 0;

        for (i = 0; line[i] && line[i] != '\n'; i++) {
            if (line[i] == ',') {
                current_field[j] = '\0';
                csv->fields[csv->num_fields++] = current_field;
                current_field = (char*)malloc(MAX_FIELD_LEN);
                j = 0;
            } else {
                current_field[j++] = line[i];
            }
        }

        current_field[j] = '\0';
        csv->fields[csv->num_fields++] = current_field;
    }

    return csv;
}

int main(int argc, char *argv[]) {
    FILE *file;

    if (argc < 2) {
        printf("Usage: csv_reader <file>\n");
        exit(1);
    }

    if ((file = fopen(argv[1], "r")) == NULL) {
        printf("Could not open file: %s\n", argv[1]);
        exit(1);
    }

    csv_line *csv;

    while ((csv = read_csv(file)) != NULL) {
        int i;

        for (i = 0; i < csv->num_fields; i++) {
            printf("%s\t", csv->fields[i]);
        }

        printf("\n");

        for (i = 0; i < csv->num_fields; i++) {
            free(csv->fields[i]);
        }

        free(csv);
    }

    fclose(file);
    return 0;
}