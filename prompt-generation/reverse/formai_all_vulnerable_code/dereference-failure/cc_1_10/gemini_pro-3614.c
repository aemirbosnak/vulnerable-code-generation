//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char **fields;
    size_t num_fields;
} csv_record;

csv_record *csv_read_line(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    if ((nread = getline(&line, &len, fp)) == -1) {
        return NULL;
    }

    csv_record *record = malloc(sizeof(csv_record));
    record->num_fields = 0;
    record->fields = NULL;

    char *field = strtok(line, ",");
    while (field) {
        record->fields = realloc(record->fields, (record->num_fields + 1) * sizeof(char *));
        record->fields[record->num_fields++] = strdup(field);
        field = strtok(NULL, ",");
    }

    free(line);
    return record;
}

void csv_free_record(csv_record *record) {
    for (size_t i = 0; i < record->num_fields; i++) {
        free(record->fields[i]);
    }
    free(record->fields);
    free(record);
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    csv_record *record;
    while ((record = csv_read_line(fp)) != NULL) {
        for (size_t i = 0; i < record->num_fields; i++) {
            printf("%s ", record->fields[i]);
        }
        printf("\n");
        csv_free_record(record);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}