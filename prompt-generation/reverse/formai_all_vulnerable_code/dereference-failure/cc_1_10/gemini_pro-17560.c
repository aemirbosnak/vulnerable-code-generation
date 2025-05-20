//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 10000
#define MAX_FIELDS 100
#define MAX_FIELD_LENGTH 100

typedef struct {
    char *fields[MAX_FIELDS];
    int num_fields;
} record_t;

typedef struct {
    record_t records[MAX_RECORDS];
    int num_records;
} dataset_t;

dataset_t *load_dataset(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    dataset_t *dataset = malloc(sizeof(dataset_t));
    if (dataset == NULL) {
        fprintf(stderr, "Error allocating memory for dataset\n");
        fclose(fp);
        return NULL;
    }

    char line[MAX_FIELD_LENGTH];
    int i, j;
    while (fgets(line, MAX_FIELD_LENGTH, fp) != NULL) {
        record_t *record = &dataset->records[dataset->num_records++];
        record->num_fields = 0;

        char *field = strtok(line, ",");
        while (field != NULL) {
            if (record->num_fields < MAX_FIELDS) {
                record->fields[record->num_fields++] = strdup(field);
            } else {
                fprintf(stderr, "Error: too many fields in record %d\n", dataset->num_records);
                free(dataset);
                fclose(fp);
                return NULL;
            }

            field = strtok(NULL, ",");
        }
    }

    fclose(fp);

    return dataset;
}

void free_dataset(dataset_t *dataset) {
    int i, j;
    for (i = 0; i < dataset->num_records; i++) {
        for (j = 0; j < dataset->records[i].num_fields; j++) {
            free(dataset->records[i].fields[j]);
        }
    }

    free(dataset);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    dataset_t *dataset = load_dataset(argv[1]);
    if (dataset == NULL) {
        return 1;
    }

    // Do something with the dataset

    free_dataset(dataset);

    return 0;
}