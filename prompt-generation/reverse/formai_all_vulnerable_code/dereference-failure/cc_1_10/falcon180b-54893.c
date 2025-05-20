//Falcon-180B DATASET v1.0 Category: Data mining ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void readCSV(char* filename, Employee* employees) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        exit(1);
    }

    char line[1000];
    int row = 0;
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char* token = strtok(line, ",");
        if (token == NULL)
            continue;

        strcpy(employees[row].name, token);
        token = strtok(NULL, ",");
        employees[row].id = atoi(token);
        token = strtok(NULL, ",");
        employees[row].salary = atof(token);

        row++;
        if (row >= MAX_ROWS) {
            printf("Maximum number of rows exceeded\n");
            exit(1);
        }
    }

    fclose(fp);
}

void calculateStatistics(Employee* employees, int numEmployees) {
    float totalSalary = 0.0;
    for (int i = 0; i < numEmployees; i++) {
        totalSalary += employees[i].salary;
    }

    float avgSalary = totalSalary / numEmployees;
    printf("Average salary: %.2f\n", avgSalary);

    int maxId = 0;
    for (int i = 0; i < numEmployees; i++) {
        if (employees[i].id > maxId) {
            maxId = employees[i].id;
        }
    }

    printf("Maximum ID: %d\n", maxId);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    Employee employees[MAX_ROWS];
    readCSV(argv[1], employees);

    int numEmployees = 0;
    for (int i = 0; i < MAX_ROWS; i++) {
        if (employees[i].id == 0)
            break;
        numEmployees++;
    }

    calculateStatistics(employees, numEmployees);

    return 0;
}