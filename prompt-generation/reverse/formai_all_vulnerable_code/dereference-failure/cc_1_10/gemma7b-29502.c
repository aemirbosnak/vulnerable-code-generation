//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024

typedef struct CSV_Record {
    char **fields;
    int num_fields;
} CSV_Record;

CSV_Record *read_csv(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    CSV_Record *record = malloc(sizeof(CSV_Record));
    record->fields = NULL;
    record->num_fields = 0;

    char line[MAX_LINES];
    while (fgets(line, MAX_LINES, fp) != NULL) {
        char **fields = malloc(sizeof(char *) * 10);
        int num_fields = 0;

        char *field = strtok(line, ",");
        while (field) {
            fields[num_fields++] = strdup(field);
            field = strtok(NULL, ",");
        }

        record->fields = fields;
        record->num_fields = num_fields;
    }

    fclose(fp);
    return record;
}

int main() {
    CSV_Record *record = read_csv("data.csv");

    for (int i = 0; i < record->num_fields; i++) {
        printf("%s ", record->fields[i]);
    }

    printf("\n");

    free(record->fields);
    free(record);

    return 0;
}