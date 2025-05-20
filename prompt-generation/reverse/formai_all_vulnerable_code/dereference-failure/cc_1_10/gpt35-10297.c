//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024      // Maximum size of each line in csv file
#define MAX_NUM_FIELDS 100     // Maximum number of fields in each line

typedef struct record {
    char **fields;             // Array of strings holding field values
    int num_fields;            // Number of fields in the record
} Record;

typedef struct csv {
    Record *records;           // Array of records
    int num_records;           // Number of records in the csv file
    int num_fields;            // Number of fields in each record
} CSV;

CSV* read_csv_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: unable to open file %s\n", filename);
        return NULL;
    }

    char line[MAX_LINE_SIZE];
    CSV *csv_file = (CSV*)malloc(sizeof(CSV));
    csv_file->records = NULL;
    csv_file->num_records = -1;
    csv_file->num_fields = -1; // Initialize to negative values for error checking

    int line_num = 0;
    while (fgets(line, MAX_LINE_SIZE, fp) != NULL) {
        if (line_num == 0) {
            // First line -- read number of fields and initialize structure accordingly
            char *token = strtok(line, ",");
            csv_file->num_fields = 0;
            while (token != NULL) {
                csv_file->num_fields++;
                token = strtok(NULL, ",");
            }
            if (csv_file->num_fields == 0) {
                printf("Error: empty csv file\n");
                free(csv_file);
                return NULL;
            }
            csv_file->records = (Record*)malloc(sizeof(Record));
            csv_file->num_records = 0;
        } else {
            // Subsequent lines -- read fields and add record to structure
            if (csv_file->num_fields == -1) {
                printf("Error: csv file has inconsistent number of fields\n");
                free(csv_file->records);
                free(csv_file);
                return NULL;
            }
            if (csv_file->num_fields > MAX_NUM_FIELDS) {
                printf("Error: csv file has too many fields\n");
                free(csv_file->records);
                free(csv_file);
                return NULL;
            }
            char *fields[MAX_NUM_FIELDS];
            int num_fields = 0;
            char *token = strtok(line, ",");
            while (token != NULL) {
                fields[num_fields] = strdup(token);
                num_fields++;
                token = strtok(NULL, ",");
            }
            if (num_fields != csv_file->num_fields) {
                printf("Error: csv file has inconsistent number of fields in line %d\n", line_num);
                free(csv_file->records);
                free(csv_file);
                return NULL;
            }
            csv_file->records = (Record*)realloc(csv_file->records, (csv_file->num_records + 1) * sizeof(Record));
            csv_file->records[csv_file->num_records].fields = (char**)malloc(num_fields * sizeof(char*));
            csv_file->records[csv_file->num_records].num_fields = num_fields;
            for (int i = 0; i < num_fields; i++) {
                csv_file->records[csv_file->num_records].fields[i] = fields[i];
            }
            csv_file->num_records++;
        }
        line_num++;
    }

    fclose(fp);

    return csv_file;
}

void free_csv(CSV *csv_file) {
    if (csv_file == NULL) {
        return;
    }
    for (int i = 0; i < csv_file->num_records; i++) {
        for (int j = 0; j < csv_file->records[i].num_fields; j++) {
            free(csv_file->records[i].fields[j]);
        }
        free(csv_file->records[i].fields);
    }
    free(csv_file->records);
    free(csv_file);
}

int main() {
    CSV *csv_file = read_csv_file("example.csv");
    if (csv_file == NULL) {
        printf("Error reading csv file\n");
        return 1;
    }
    printf("Number of records: %d\n", csv_file->num_records);
    printf("Number of fields: %d\n", csv_file->num_fields);
    printf("Records:\n");
    for (int i = 0; i < csv_file->num_records; i++) {
        for (int j = 0; j < csv_file->records[i].num_fields; j++) {
            printf("%s", csv_file->records[i].fields[j]);
            if (j < csv_file->records[i].num_fields - 1) {
                printf(",");
            }
        }
        printf("\n");
    }
    free_csv(csv_file);
    return 0;
}