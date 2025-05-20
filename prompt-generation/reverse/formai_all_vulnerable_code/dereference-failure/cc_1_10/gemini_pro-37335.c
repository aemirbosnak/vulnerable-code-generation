//GEMINI-pro DATASET v1.0 Category: Data mining ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_RECORDS 10000
#define MAX_ATTRIBUTES 100
#define MAX_ATTRIBUTE_LENGTH 100

typedef struct {
    char *name;
    char *value;
} Attribute;

typedef struct {
    Attribute attributes[MAX_ATTRIBUTES];
    int num_attributes;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int num_records;
} Dataset;

Dataset *load_dataset(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    Dataset *dataset = malloc(sizeof(Dataset));
    if (dataset == NULL) {
        fprintf(stderr, "Error allocating memory for dataset\n");
        fclose(fp);
        return NULL;
    }

    dataset->num_records = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        Record *record = &dataset->records[dataset->num_records++];
        record->num_attributes = 0;

        char *token = strtok(line, ",");
        while (token != NULL) {
            Attribute *attribute = &record->attributes[record->num_attributes++];
            attribute->name = strdup(token);
            attribute->value = strdup(strtok(NULL, ","));
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);

    return dataset;
}

void free_dataset(Dataset *dataset) {
    for (int i = 0; i < dataset->num_records; i++) {
        Record *record = &dataset->records[i];
        for (int j = 0; j < record->num_attributes; j++) {
            Attribute *attribute = &record->attributes[j];
            free(attribute->name);
            free(attribute->value);
        }
    }

    free(dataset);
}

void print_dataset(Dataset *dataset) {
    for (int i = 0; i < dataset->num_records; i++) {
        Record *record = &dataset->records[i];
        for (int j = 0; j < record->num_attributes; j++) {
            Attribute *attribute = &record->attributes[j];
            printf("%s: %s\n", attribute->name, attribute->value);
        }
        printf("\n");
    }
}

int main() {
    Dataset *dataset = load_dataset("data.csv");
    if (dataset == NULL) {
        return 1;
    }

    print_dataset(dataset);

    free_dataset(dataset);

    return 0;
}