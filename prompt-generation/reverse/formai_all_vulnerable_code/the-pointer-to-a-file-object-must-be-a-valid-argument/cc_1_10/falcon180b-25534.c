//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int num_fields;
} csv_record;

csv_record *csv_open(FILE *fp) {
    csv_record *record = malloc(sizeof(csv_record));
    record->fields = malloc(MAX_FIELDS * sizeof(char *));
    record->num_fields = 0;
    return record;
}

int csv_read(csv_record *record, FILE *fp) {
    char line[MAX_LINE_LENGTH];
    char *token;
    int num_fields = 0;

    if (fgets(line, MAX_LINE_LENGTH, fp) == NULL) {
        return 0;
    }

    token = strtok(line, ",");
    while (token!= NULL) {
        record->fields[num_fields] = strdup(token);
        num_fields++;
        token = strtok(NULL, ",");
    }
    record->num_fields = num_fields;

    return num_fields;
}

void csv_close(csv_record *record) {
    for (int i = 0; i < record->num_fields; i++) {
        free(record->fields[i]);
    }
    free(record->fields);
    free(record);
}

void csv_print(csv_record *record) {
    for (int i = 0; i < record->num_fields; i++) {
        printf("%s ", record->fields[i]);
    }
    printf("\n");
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    csv_record *record = csv_open(fp);

    while (csv_read(record, fp) > 0) {
        csv_print(record);
    }

    csv_close(record);
    fclose(fp);

    return 0;
}