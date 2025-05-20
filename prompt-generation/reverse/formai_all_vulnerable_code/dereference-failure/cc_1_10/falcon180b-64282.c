//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 100
#define MAX_FIELD_SIZE 100

typedef struct {
    char *field[MAX_FIELDS];
    int num_fields;
} csv_record;

csv_record *csv_read(FILE *fp) {
    csv_record *record = malloc(sizeof(csv_record));
    record->num_fields = 0;

    char line[MAX_FIELD_SIZE];
    while (fgets(line, MAX_FIELD_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            if (record->num_fields >= MAX_FIELDS) {
                fprintf(stderr, "Error: Too many fields.\n");
                exit(1);
            }
            record->field[record->num_fields++] = strdup(token);
            token = strtok(NULL, ",");
        }
    }

    if (record->num_fields == 0) {
        free(record);
        return NULL;
    }

    return record;
}

void csv_print(csv_record *record) {
    for (int i = 0; i < record->num_fields; i++) {
        printf("%s ", record->field[i]);
    }
    printf("\n");
}

void csv_free(csv_record *record) {
    for (int i = 0; i < record->num_fields; i++) {
        free(record->field[i]);
    }
    free(record);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        exit(1);
    }

    csv_record *record;
    while ((record = csv_read(fp))!= NULL) {
        csv_print(record);
        csv_free(record);
    }

    fclose(fp);
    return 0;
}