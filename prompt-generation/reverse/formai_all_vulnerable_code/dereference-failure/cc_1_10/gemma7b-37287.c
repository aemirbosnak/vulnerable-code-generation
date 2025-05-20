//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define CSV_BUFFER_SIZE 1024

typedef struct CSV_RECORD {
    char **fields;
    int num_fields;
} CSV_RECORD;

CSV_RECORD *read_csv_file(char *filename) {
    CSV_RECORD *record = malloc(sizeof(CSV_RECORD));
    record->fields = NULL;
    record->num_fields = 0;

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    char buffer[CSV_BUFFER_SIZE];
    int line_num = 0;
    while (fgets(buffer, CSV_BUFFER_SIZE, file) != NULL) {
        line_num++;
        char **fields = malloc(sizeof(char *) * 10);
        int num_fields = 0;

        char *field = strtok(buffer, ",");
        while (field) {
            fields[num_fields++] = strdup(field);
            field = strtok(NULL, ",");
        }

        record->fields = fields;
        record->num_fields = num_fields;
    }

    fclose(file);
    return record;
}

int main() {
    CSV_RECORD *record = read_csv_file("data.csv");

    if (record) {
        for (int i = 0; i < record->num_fields; i++) {
            printf("%s,", record->fields[i]);
        }
        printf("\n");

        free(record->fields);
        free(record);
    }

    return 0;
}