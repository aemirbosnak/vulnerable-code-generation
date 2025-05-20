//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSV_Record {
    char **data;
    int num_fields;
} CSV_Record;

CSV_Record *csv_read(char *filename) {
    CSV_Record *record = malloc(sizeof(CSV_Record));

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char buffer[MAX_BUFFER_SIZE];
    fscanf(fp, "%[^\n]", buffer);

    char *line = strtok(buffer, ",");
    record->num_fields = 0;
    record->data = NULL;

    while (line) {
        record->data = realloc(record->data, (record->num_fields + 1) * sizeof(char *));
        record->data[record->num_fields++] = strdup(line);
        line = strtok(NULL, ",");
    }

    fclose(fp);
    return record;
}

int main() {
    CSV_Record *record = csv_read("data.csv");

    for (int i = 0; i < record->num_fields; i++) {
        printf("%s,", record->data[i]);
    }

    printf("\n");

    free(record->data);
    free(record);

    return 0;
}