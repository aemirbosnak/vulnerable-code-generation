//FormAI DATASET v1.0 Category: Database simulation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define DATABASE_SIZE 100

// Database Structure Containing Emp Objects
struct db {
    int id;
    char name[20];
    int age;
};

struct db *database[DATABASE_SIZE];
int num_employees = 0;

pthread_mutex_t lock;

void* add_employee(void* args) {
    pthread_mutex_lock(&lock);
    struct db* employee = (struct db*) args;
    database[num_employees] = employee;
    num_employees++;
    printf("Employee added successfully\n");
    pthread_mutex_unlock(&lock);
    return NULL;
}

void print_all_employees() {
    pthread_mutex_lock(&lock);
    if(num_employees == 0) {
        printf("No employees in the database\n");
    } else {
        for(int i = 0; i < num_employees; i++) {
            printf("Employee %d: ID: %d, Name : %s, Age: %d\n", i, database[i]->id, database[i]->name, database[i]->age);
        }
    }
    pthread_mutex_unlock(&lock);
}

void* remove_employee(void* args) {
    pthread_mutex_lock(&lock);
    int index_to_delete = *(int*)args;
    if(index_to_delete >= num_employees) {
        printf("No employee found at index %d\n", index_to_delete);
    } else {
        free(database[index_to_delete]);
        for(int i = index_to_delete; i < num_employees - 1; i++) {
            database[i] = database[i+1];
        }
        num_employees--;
        printf("Employee deleted successfully\n");
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_mutex_init(&lock, NULL);

    struct db* emp1 = (struct db*) malloc(sizeof(struct db));
    emp1->id = 1;
    strcpy(emp1->name, "John Doe");
    emp1->age = 25;

    struct db* emp2 = (struct db*) malloc(sizeof(struct db));
    emp2->id = 2;
    strcpy(emp2->name, "Jane Smith");
    emp2->age = 30;

    printf("Adding employees to the database...\n");

    pthread_create(&thread_id, NULL, add_employee, (void*) emp1);
    pthread_join(thread_id, NULL);

    pthread_create(&thread_id, NULL, add_employee, (void*) emp2);
    pthread_join(thread_id, NULL);

    print_all_employees();

    int index_to_delete = 1;
    pthread_create(&thread_id, NULL, remove_employee, (void*) &index_to_delete);
    pthread_join(thread_id, NULL);

    print_all_employees();

    pthread_mutex_destroy(&lock);
    return 0;
}