//FormAI DATASET v1.0 Category: Database Indexing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LEN 25
#define MAX_DEPT_LEN 10

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char department[MAX_DEPT_LEN];
    float salary;
} Employee;

typedef struct {
    int id;
    int rec_index;
} IndexEntry;

typedef struct {
    IndexEntry index[MAX_RECORDS];
    int num_entries;
} Index;

Employee employee_db[MAX_RECORDS];
Index employee_index;

void init_index() {
    employee_index.num_entries = 0;
    for (int i = 0; i < MAX_RECORDS; i++) {
        employee_index.index[i].id = -1;
        employee_index.index[i].rec_index = -1;
    }
}

void add_index_entry(int id, int rec_index) {
    employee_index.index[employee_index.num_entries].id = id;
    employee_index.index[employee_index.num_entries].rec_index = rec_index;
    employee_index.num_entries++;
}

void add_employee_record(int id, char* name, char* dept, float salary) {
    employee_db[id].id = id;
    strcpy(employee_db[id].name, name);
    strcpy(employee_db[id].department, dept);
    employee_db[id].salary = salary;
    add_index_entry(id, id);
}

void load_records_from_file(char* filename) {
    FILE* fp;
    char line[100];
    char* tmp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    while (fgets(line, 100, fp) != NULL && employee_index.num_entries < MAX_RECORDS) {
        Employee emp;
        tmp = strtok(line, ",");
        emp.id = atoi(tmp);
        tmp = strtok(NULL, ",");
        strcpy(emp.name, tmp);
        tmp = strtok(NULL, ",");
        strcpy(emp.department, tmp);
        tmp = strtok(NULL, ",");
        emp.salary = atof(tmp);
        add_employee_record(emp.id, emp.name, emp.department, emp.salary);
    }
    fclose(fp);
}

void print_employee_record(Employee emp) {
    printf("%d, %s, %s, %.2f\n", emp.id, emp.name, emp.department, emp.salary);
}

void print_records_for_department(char* dept) {
    int i;
    for (i = 0; i < employee_index.num_entries; i++) {
        Employee emp = employee_db[employee_index.index[i].rec_index];
        if (strcmp(emp.department, dept) == 0) {
            print_employee_record(emp);
        }
    }
}

void print_records_for_salary_range(float min_salary, float max_salary) {
    int i;
    for (i = 0; i < employee_index.num_entries; i++) {
        Employee emp = employee_db[employee_index.index[i].rec_index];
        if (emp.salary >= min_salary && emp.salary <= max_salary) {
            print_employee_record(emp);
        }
    }
}

int main() {
    char filename[] = "employee_data.txt";
    load_records_from_file(filename);
    printf("Loaded %d employee records from file %s\n", employee_index.num_entries, filename);
    printf("---All Employees---\n");
    for (int i = 0; i < employee_index.num_entries; i++) {
        Employee emp = employee_db[employee_index.index[i].rec_index];
        print_employee_record(emp);
    }
    printf("---Employees in Engineering Department---\n");
    print_records_for_department("Engineering");
    printf("---Employees with salaries between 50000 and 80000---\n");
    print_records_for_salary_range(50000.0, 80000.0);
    return 0;
}