//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Record {
    char *name;
    int age;
    float salary;
} Record;

void parse_csv_line(char *line, Record *record) {
    char *token = strtok(line, ",");
    record->name = malloc(strlen(token) + 1);
    strcpy(record->name, token);
    token = strtok(NULL, ",");
    record->age = atoi(token);
    token = strtok(NULL, ",");
    record->salary = atof(token);
}

void print_record(Record *record) {
    printf("%s, %d, %.2f\n", record->name, record->age, record->salary);
}

int main() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    Record record;

    fp = fopen("data.csv", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    // read header line and discard it
    read = getline(&line, &len, fp);

    // iterate over file lines and parse CSV data
    while ((read = getline(&line, &len, fp)) != -1) {
        parse_csv_line(line, &record);
        print_record(&record);
        free(record.name);
    }

    if (line)
        free(line);

    fclose(fp);
    exit(EXIT_SUCCESS);
}