//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variable to store the database
int database[100][10];

// Function to add a new employee to the database
void addEmployee(int id, char* name, char* job, int salary, int department) {
    if (id < 0 || id > 99) {
        printf("Invalid employee ID.\n");
        return;
    }
    
    if (strlen(name) == 0) {
        printf("Invalid employee name.\n");
        return;
    }
    
    if (strlen(job) == 0) {
        printf("Invalid employee job title.\n");
        return;
    }
    
    if (salary < 0) {
        printf("Invalid employee salary.\n");
        return;
    }
    
    if (department < 0 || department > 9) {
        printf("Invalid employee department.\n");
        return;
    }
    
    database[id][0] = id;
    strcpy(database[id][1], name);
    strcpy(database[id][2], job);
    database[id][3] = salary;
    database[id][4] = department;
}

// Function to search for an employee by ID
void searchEmployee(int id) {
    if (id < 0 || id > 99) {
        printf("Invalid employee ID.\n");
        return;
    }
    
    if (database[id][0] == -1) {
        printf("Employee not found.\n");
        return;
    }
    
    printf("Employee ID: %d\n", database[id][0]);
    printf("Name: %s\n", database[id][1]);
    printf("Job Title: %s\n", database[id][2]);
    printf("Salary: %d\n", database[id][3]);
    printf("Department: %d\n", database[id][4]);
}

// Function to update an employee's information
void updateEmployee(int id, char* name, char* job, int salary, int department) {
    if (id < 0 || id > 99) {
        printf("Invalid employee ID.\n");
        return;
    }
    
    if (strlen(name) == 0) {
        printf("Invalid employee name.\n");
        return;
    }
    
    if (strlen(job) == 0) {
        printf("Invalid employee job title.\n");
        return;
    }
    
    if (salary < 0) {
        printf("Invalid employee salary.\n");
        return;
    }
    
    if (department < 0 || department > 9) {
        printf("Invalid employee department.\n");
        return;
    }
    
    strcpy(database[id][1], name);
    strcpy(database[id][2], job);
    database[id][3] = salary;
    database[id][4] = department;
}

// Function to delete an employee from the database
void deleteEmployee(int id) {
    if (id < 0 || id > 99) {
        printf("Invalid employee ID.\n");
        return;
    }
    
    if (database[id][0] == -1) {
        printf("Employee not found.\n");
        return;
    }
    
    for (int i = id; i < 100; i++) {
        for (int j = 0; j < 10; j++) {
            database[i][j] = database[i+1][j];
        }
    }
    
    database[99][0] = -1;
}

int main() {
    // Add employees to the database
    addEmployee(1, "John Doe", "Software Engineer", 50000, 1);
    addEmployee(2, "Jane Smith", "Data Analyst", 55000, 2);
    addEmployee(3, "Michael Johnson", "HR Manager", 60000, 3);
    
    // Search for an employee
    searchEmployee(1);
    searchEmployee(2);
    searchEmployee(3);
    
    // Update an employee's information
    updateEmployee(1, "John Doe", "Senior Software Engineer", 60000, 1);
    
    // Delete an employee
    deleteEmployee(2);
    
    return 0;
}