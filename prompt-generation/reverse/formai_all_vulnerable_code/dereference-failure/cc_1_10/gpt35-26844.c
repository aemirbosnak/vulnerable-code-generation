//FormAI DATASET v1.0 Category: Database querying ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int id;
    char name[50];
    char address[100];
    float gpa;
} Student;

void initializeDatabase(Student **database) {
    // Allocate memory for 5 Student structs
    *database = malloc(5 * sizeof(Student));

    // Add some data to the database
    (*database)[0].id = 1;
    strcpy((*database)[0].name, "John Smith");
    strcpy((*database)[0].address, "123 Main St, Anytown, USA");
    (*database)[0].gpa = 3.5;

    (*database)[1].id = 2;
    strcpy((*database)[1].name, "Jane Doe");
    strcpy((*database)[1].address, "456 Elm St, Somewhere, USA");
    (*database)[1].gpa = 4.0;

    // Add 3 more students...
}

void printStudent(Student student) {
    printf("ID: %d\nName: %s\nAddress: %s\nGPA: %.2f\n", student.id, student.name, student.address, student.gpa);
}

void queryById(Student *database, int id) {
    printf("--- Querying for Student ID %d ---\n", id);
    for (int i = 0; i < 5; i++) {
        if (database[i].id == id) {
            printStudent(database[i]);
            return;
        }
    }
    printf("Student not found.\n");
}

void queryByGpa(Student *database, float gpa) {
    printf("--- Querying for Students with GPA %.2f ---\n", gpa);
    for (int i = 0; i < 5; i++) {
        if (database[i].gpa == gpa) {
            printStudent(database[i]);
        }
    }
}

void queryByName(Student *database, char *name) {
    printf("--- Querying for Students with Name %s ---\n", name);
    for (int i = 0; i < 5; i++) {
        if (strcmp(database[i].name, name) == 0) {
            printStudent(database[i]);
        }
    }
}

int main() {
    Student *database;
    initializeDatabase(&database);

    queryById(database, 2);
    queryByGpa(database, 3.5);
    queryByName(database, "John Smith");

    free(database);
    return 0;
}