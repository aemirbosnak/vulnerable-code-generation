//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_COUNT 10

typedef struct {
    char *fields[MAX_FIELD_COUNT];
    int field_count;
} csv_record;

csv_record *csv_record_new() {
    csv_record *record = malloc(sizeof(csv_record));
    record->field_count = 0;
    return record;
}

void csv_record_free(csv_record *record) {
    for (int i = 0; i < record->field_count; i++) {
        free(record->fields[i]);
    }
    free(record);
}

int csv_record_add_field(csv_record *record, char *field) {
    if (record->field_count >= MAX_FIELD_COUNT) {
        return -1;
    }
    record->fields[record->field_count] = strdup(field);
    record->field_count++;
    return 0;
}

csv_record *csv_record_from_line(char *line) {
    csv_record *record = csv_record_new();
    char *field = strtok(line, ",");
    while (field != NULL) {
        csv_record_add_field(record, field);
        field = strtok(NULL, ",");
    }
    return record;
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        csv_record *record = csv_record_from_line(line);
        for (int i = 0; i < record->field_count; i++) {
            printf("%s ", record->fields[i]);
        }
        printf("\n");
        csv_record_free(record);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}