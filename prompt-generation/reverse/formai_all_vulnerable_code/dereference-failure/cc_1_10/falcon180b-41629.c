//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

struct csv_record {
    char *data;
    struct csv_record *next;
};

typedef struct csv_record CSVRecord;

CSVRecord *csv_record_create(char *data) {
    CSVRecord *record = (CSVRecord *)malloc(sizeof(CSVRecord));
    record->data = strdup(data);
    record->next = NULL;
    return record;
}

void csv_record_free(CSVRecord *record) {
    free(record->data);
    free(record);
}

CSVRecord *csv_record_parse(char *line) {
    CSVRecord *record = NULL;
    char *data = strtok(line, ",");
    while (data!= NULL) {
        CSVRecord *new_record = csv_record_create(data);
        if (record == NULL) {
            record = new_record;
        } else {
            CSVRecord *last_record = record;
            while (last_record->next!= NULL) {
                last_record = last_record->next;
            }
            last_record->next = new_record;
        }
        data = strtok(NULL, ",");
    }
    return record;
}

void csv_record_print(CSVRecord *record) {
    while (record!= NULL) {
        printf("%s -> ", record->data);
        record = record->next;
    }
    printf("NULL\n");
}

int main() {
    FILE *file = fopen("example.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LINE_SIZE];
    CSVRecord *record = NULL;
    while (fgets(line, MAX_LINE_SIZE, file)!= NULL) {
        record = csv_record_parse(line);
        csv_record_print(record);
    }

    csv_record_free(record);
    fclose(file);

    return 0;
}