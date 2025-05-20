//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 10

typedef struct {
    char *fields[MAX_NUM_FIELDS];
    int num_fields;
} CSVRecord;

CSVRecord *parse_csv_line(char *line) {
    CSVRecord *record = malloc(sizeof(CSVRecord));
    record->num_fields = 0;

    char *field = strtok(line, ",");
    while (field != NULL) {
        record->fields[record->num_fields] = strdup(field);
        record->num_fields++;

        field = strtok(NULL, ",");
    }

    return record;
}

void free_csv_record(CSVRecord *record) {
    for (int i = 0; i < record->num_fields; i++) {
        free(record->fields[i]);
    }

    free(record);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        CSVRecord *record = parse_csv_line(line);

        for (int i = 0; i < record->num_fields; i++) {
            printf("%s", record->fields[i]);

            if (i < record->num_fields - 1) {
                printf(", ");
            }
        }

        printf("\n");

        free_csv_record(record);
    }

    fclose(fp);

    return 0;
}