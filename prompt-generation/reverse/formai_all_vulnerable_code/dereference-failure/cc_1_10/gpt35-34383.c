//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024 // defining buffer size for reading file

typedef struct {
    char *name;
    int age;
    float salary;
} Employee;

void parse_csv_file(char *filename, Employee **employees, int *size) {
    // open input file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // read file line by line
    char buffer[BUFFER_SIZE];
    char *token;
    int lineNumber = 0, fieldNumber = 0;
    while (fgets(buffer, BUFFER_SIZE, fp)) {
        // remove newline character at the end of line
        int len = strlen(buffer);
        if (len && buffer[len - 1] == '\n') {
            buffer[--len] = '\0';
        }

        if (lineNumber == 0) {
            // this is header line, so skip it
            lineNumber++;
            continue;
        }

        if (fieldNumber == 0) {
            // first field is name
            employees[*size]->name = strdup(strtok(buffer, ","));
        }
        else if (fieldNumber == 1) {
            // second field is age
            employees[*size]->age = atoi(strtok(NULL, ","));
        }
        else {
            // third field is salary
            employees[*size]->salary = atof(strtok(NULL, ","));
        }

        fieldNumber++;
        if (fieldNumber == 3) {
            // we have read one record,
            // allocate memory for next record
            (*size)++;
            employees[*size] = malloc(sizeof(Employee));
            fieldNumber = 0;
        }

        lineNumber++;
    }

    // close file pointer
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // allocate memory for employees
    int size = 0;
    Employee **employees = malloc(sizeof(Employee *));
    employees[size] = malloc(sizeof(Employee));

    // parse csv file
    parse_csv_file(argv[1], employees, &size);

    // print employee details
    printf("Name\tAge\tSalary\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%d\t%f\n", employees[i]->name, employees[i]->age, employees[i]->salary);
    }

    // free employee memory
    for (int i = 0; i < size; i++) {
        free(employees[i]->name);
        free(employees[i]);
    }
    free(employees);

    return 0;
}