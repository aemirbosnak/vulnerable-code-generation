//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int length;
} CSVRecord;

typedef struct {
    CSVRecord *records;
    int num_records;
} CSVFile;

CSVFile *csv_read(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    CSVFile *csv = malloc(sizeof(CSVFile));
    if (csv == NULL) {
        fclose(fp);
        return NULL;
    }

    csv->records = NULL;
    csv->num_records = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        CSVRecord record;
        record.data = strdup(line);
        record.length = strlen(line);

        csv->records = realloc(csv->records, sizeof(CSVRecord) * (csv->num_records + 1));
        csv->records[csv->num_records] = record;
        csv->num_records++;
    }

    fclose(fp);
    return csv;
}

void csv_free(CSVFile *csv) {
    for (int i = 0; i < csv->num_records; i++) {
        free(csv->records[i].data);
    }
    free(csv->records);
    free(csv);
}

int main() {
    CSVFile *csv = csv_read("data.csv");
    if (csv == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    for (int i = 0; i < csv->num_records; i++) {
        printf("%s", csv->records[i].data);
    }

    csv_free(csv);
    return 0;
}