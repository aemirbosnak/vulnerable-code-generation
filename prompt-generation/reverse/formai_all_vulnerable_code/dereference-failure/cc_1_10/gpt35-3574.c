//FormAI DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define struct for database
typedef struct {
    char name[20];
    int age;
    float salary;
} Employee;

// Define struct for index
typedef struct {
    char name[20];
    int offset;
} Index;

void add_employee(FILE* database, FILE* index_file, Employee emp) {
    // Add employee to end of database file
    fseek(database, 0, SEEK_END);
    fwrite(&emp, sizeof(Employee), 1, database);

    // Add employee to index file
    Index idx;
    strcpy(idx.name, emp.name);
    idx.offset = ftell(database) - sizeof(Employee);
    fwrite(&idx, sizeof(Index), 1, index_file);
}

void search_employee(FILE* index_file, FILE* database, char name[20]) {
    Index idx;
    int found = 0;
    // Search for index entry with matching name
    while (!feof(index_file)) {
        fread(&idx, sizeof(Index), 1, index_file);
        if (strcmp(idx.name, name) == 0) {
            found = 1;
            break;
        }
    }
    if (found) {
        // Read employee from database using offset stored in index
        Employee emp;
        fseek(database, idx.offset, SEEK_SET);
        fread(&emp, sizeof(Employee), 1, database);

        // Print employee info
        printf("Employee found:\n");
        printf("Name: %s\n", emp.name);
        printf("Age: %d\n", emp.age);
        printf("Salary: %.2f\n", emp.salary);
    }
    else {
        printf("Employee not found.\n");
    }
}

int main() {
    FILE* database = fopen("database.dat", "wb");
    FILE* index_file = fopen("index.dat", "wb");
    if (database == NULL || index_file == NULL) {
        printf("Error opening files.");
        exit(1);
    }

    Employee e1 = {"John Smith", 35, 50000.00};
    Employee e2 = {"Sarah Johnson", 27, 45000.00};
    Employee e3 = {"David Thompson", 42, 75000.00};

    add_employee(database, index_file, e1);
    add_employee(database, index_file, e2);
    add_employee(database, index_file, e3);

    char search_name[20];
    printf("Enter name to search for: ");
    scanf("%s", search_name);
    search_employee(index_file, database, search_name);

    fclose(database);
    fclose(index_file);
    return 0;
}