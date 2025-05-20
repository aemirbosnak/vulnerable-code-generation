//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store data
typedef struct Employee {
    char name[50];
    int age;
    struct Employee* next;
} Employee;

// Define a hashing function to hash a key
int hash(char* key) {
    int hash_value = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash_value = hash_value * 33 + key[i];
    }
    return hash_value;
}

// Define an indexing system
struct IndexSystem {
    Employee** buckets;
    int size;
    int num_buckets;
};

// Create an indexing system
struct IndexSystem* create_indexing_system(int num_buckets) {
    struct IndexSystem* system = (struct IndexSystem*)malloc(sizeof(struct IndexSystem));
    system->buckets = (Employee**)malloc(num_buckets * sizeof(Employee*));
    system->size = 0;
    system->num_buckets = num_buckets;
    return system;
}

// Insert an employee into the indexing system
void insert_employee(struct IndexSystem* system, Employee* employee) {
    int bucket_index = hash(employee->name) % system->num_buckets;
    Employee* new_employee = (Employee*)malloc(sizeof(Employee));
    new_employee->next = system->buckets[bucket_index];
    system->buckets[bucket_index] = new_employee;
    system->size++;
}

// Search for an employee in the indexing system
Employee* search_employee(struct IndexSystem* system, char* name) {
    int bucket_index = hash(name) % system->num_buckets;
    Employee* current_employee = system->buckets[bucket_index];
    while (current_employee) {
        if (strcmp(current_employee->name, name) == 0) {
            return current_employee;
        }
        current_employee = current_employee->next;
    }
    return NULL;
}

int main() {
    // Create an indexing system with 10 buckets
    struct IndexSystem* system = create_indexing_system(10);

    // Insert some employees
    Employee* employee1 = (Employee*)malloc(sizeof(Employee));
    strcpy(employee1->name, "John Doe");
    employee1->age = 25;
    insert_employee(system, employee1);

    Employee* employee2 = (Employee*)malloc(sizeof(Employee));
    strcpy(employee2->name, "Jane Doe");
    employee2->age = 30;
    insert_employee(system, employee2);

    // Search for an employee
    Employee* found_employee = search_employee(system, "Jane Doe");

    // Print the found employee
    if (found_employee) {
        printf("Name: %s, Age: %d\n", found_employee->name, found_employee->age);
    } else {
        printf("Employee not found\n");
    }

    return 0;
}