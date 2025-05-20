//LLAMA2-13B DATASET v1.0 Category: Database simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_RECORDS 1000
#define MAX_FIELDS 5

// Structure to represent a record
typedef struct {
    char name[20];
    int age;
    float salary;
} record_t;

// Function to read records from a file
record_t* read_records(const char* filename) {
    record_t* records = calloc(MAX_RECORDS, sizeof(record_t));
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: unable to open file %s\n", filename);
        return NULL;
    }
    int i = 0;
    while (fscanf(file, "%19s %d %f", records[i].name, &records[i].age, &records[i].salary) == 3) {
        i++;
    }
    fclose(file);
    return records;
}

// Function to write records to a file
void write_records(const char* filename, record_t* records, int count) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Error: unable to open file %s\n", filename);
        return;
    }
    int i = 0;
    for (; i < count; i++) {
        fprintf(file, "%s %d %f\n", records[i].name, records[i].age, records[i].salary);
    }
    fclose(file);
}

int main() {
    record_t* records = read_records("example.dat");
    if (!records) {
        printf("Error: unable to read records from file\n");
        return 1;
    }
    int count = sizeof(records) / sizeof(record_t);
    printf("Records read from file: \n");
    for (int i = 0; i < count; i++) {
        printf("%d: %s, %d, %f\n", i, records[i].name, records[i].age, records[i].salary);
    }
    write_records("output.dat", records, count);
    free(records);
    return 0;
}