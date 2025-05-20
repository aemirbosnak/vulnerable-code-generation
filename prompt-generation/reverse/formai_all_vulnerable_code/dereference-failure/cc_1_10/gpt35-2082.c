//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to hold CSV data
typedef struct {
    char name[50];
    int age;
    float salary;
} CsvRecord;

// function for parsing CSV record
CsvRecord parseCsvRecord(char line[]) {
    CsvRecord record;
    char *token;
    token = strtok(line, ", ");
    strcpy(record.name, token);
    token = strtok(NULL, ", ");
    record.age = atoi(token);
    token = strtok(NULL, ", ");
    record.salary = atof(token);
    return record;
}

int main() {
    FILE *file;
    char line[100];
    CsvRecord record;

    // open CSV file for reading
    file = fopen("employees.csv", "r");
    if (file == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    // read CSV file line by line
    printf("CSV file contents:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        // parse CSV record
        record = parseCsvRecord(line);

        // print CSV record
        printf("Name: %s\n", record.name);
        printf("Age: %d\n", record.age);
        printf("Salary: %.2f\n\n", record.salary);
    }

    // close CSV file
    fclose(file);

    return 0;
}