//MISTRAL-7B DATASET v1.0 Category: Building a CSV Reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLUMNS 100
#define MAX_STRING 255

typedef struct {
    char name[MAX_STRING];
    int age;
    float salary;
} Employee;

void read_csv(FILE *file, Employee employees[], int *num_employees) {
    char line[MAX_STRING];
    char *token;
    int row = 0;

    while (fgets(line, MAX_STRING, file) != NULL) {
        token = strtok(line, ",");
        strcpy(employees[row].name, token);

        token = strtok(NULL, ",");
        employees[row].age = atoi(token);

        token = strtok(NULL, ",");
        employees[row].salary = atof(token);

        if (row < *num_employees - 1) {
            getchar(); // consume newline character
        }
        row++;

        if (row >= MAX_COLUMNS) {
            fprintf(stderr, "Error: Too many columns in CSV file\n");
            exit(1);
        }

        *num_employees = row + 1;
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    Employee employees[MAX_COLUMNS];
    int num_employees = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    read_csv(file, employees, &num_employees);

    printf("Name\tAge\tSalary\n");
    for (int i = 0; i < num_employees; i++) {
        printf("%s\t%d\t%.2f\n", employees[i].name, employees[i].age, employees[i].salary);
    }

    fclose(file);
    return 0;
}