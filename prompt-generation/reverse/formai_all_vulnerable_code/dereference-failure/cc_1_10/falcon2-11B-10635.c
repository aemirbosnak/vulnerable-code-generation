//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Student {
    char name[50];
    int age;
    float gpa;
} Student;

typedef struct {
    Student* students;
    int size;
    int capacity;
} Database;

void insert_student(Database* db, Student* student) {
    if (db->size == db->capacity) {
        printf("Database is full\n");
        return;
    }
    db->students[db->size] = *student;
    db->size++;
}

void display_students(Database* db) {
    printf("Students in the database: \n");
    for (int i = 0; i < db->size; i++) {
        printf("Name: %s, Age: %d, GPA: %f\n", db->students[i].name, db->students[i].age, db->students[i].gpa);
    }
}

int main() {
    srand(time(NULL));

    Database db;
    db.size = 0;
    db.capacity = 10;
    db.students = malloc(db.capacity * sizeof(Student));

    Student student;
    strcpy(student.name, "John Doe");
    student.age = rand() % 18 + 18;
    student.gpa = rand() / (float)RAND_MAX;

    insert_student(&db, &student);

    display_students(&db);

    free(db.students);
    return 0;
}