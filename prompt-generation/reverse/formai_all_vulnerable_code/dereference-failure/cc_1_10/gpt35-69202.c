//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_FIELDS 256

typedef struct record {
    char **fields;
    int num_fields;
} Record;

int read_csv(FILE *fp, Record **records, int *num_records) {
    char line[MAX_LINE_LENGTH];
    char *token, *saveptr;
    int record_index = 0;
    int i;

    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // allocate memory for new record
        *records = (Record *) realloc(*records, (record_index + 1) * sizeof(Record));
        (*records)[record_index].fields = (char **) malloc(MAX_FIELDS * sizeof(char *));
        (*records)[record_index].num_fields = 0;

        // parse CSV line
        token = strtok_r(line, ",", &saveptr);
        i = 0;
        while (token != NULL && i < MAX_FIELDS) {
            (*records)[record_index].fields[i] = (char *) malloc(MAX_FIELD_LENGTH * sizeof(char));
            strncpy((*records)[record_index].fields[i], token, MAX_FIELD_LENGTH - 1);
            (*records)[record_index].fields[i][MAX_FIELD_LENGTH - 1] = '\0';
            (*records)[record_index].num_fields++;
            i++;

            token = strtok_r(NULL, ",", &saveptr);
        }

        // increment record index
        record_index++;
    }

    *num_records = record_index;
    return 0;
}

int main(int argc, char *argv[]) {
    FILE *fp = fopen("example.csv", "r");
    Record *records = NULL;
    int num_records = 0;
    int i, j;

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        return 1;
    }

    read_csv(fp, &records, &num_records);

    for (i = 0; i < num_records; i++) {
        for (j = 0; j < records[i].num_fields; j++) {
            printf("%s ", records[i].fields[j]);
        }
        printf("\n");
    }

    // free memory
    for (i = 0; i < num_records; i++) {
        for (j = 0; j < records[i].num_fields; j++) {
            free(records[i].fields[j]);
        }
        free(records[i].fields);
    }
    free(records);

    // close file
    fclose(fp);

    return 0;
}