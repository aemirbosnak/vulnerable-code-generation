//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct CSV_Record {
    char **data;
    int num_fields;
} CSV_Record;

CSV_Record *read_csv_file(char *filename) {
    FILE *fp;
    CSV_Record *record = malloc(sizeof(CSV_Record));
    record->data = NULL;
    record->num_fields = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char buffer[MAX_BUFFER_SIZE];
    int line_num = 0;
    while (fgets(buffer, MAX_BUFFER_SIZE, fp) != NULL) {
        line_num++;
        char **fields = NULL;
        int num_fields = 0;

        // Split the line into fields
        char *field = strtok(buffer, ",");
        while (field) {
            fields = realloc(fields, (num_fields + 1) * sizeof(char *));
            fields[num_fields++] = strdup(field);
            field = strtok(NULL, ",");
        }

        record->data = fields;
        record->num_fields = num_fields;
    }

    fclose(fp);
    return record;
}

int main() {
    CSV_Record *record = read_csv_file("example.csv");
    for (int i = 0; i < record->num_fields; i++) {
        printf("%s ", record->data[i]);
    }
    printf("\n");

    free(record->data);
    free(record);

    return 0;
}