//FormAI DATASET v1.0 Category: Database simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

typedef struct {
    int size;
    Student* students[MAX_SIZE];
} Database;

void add_student(Database* db, Student* student) {
    if (db->size >= MAX_SIZE) {
        printf("Database is full.\n");
    } else {
        db->students[db->size] = student;
        db->size++;
    }
}

void print_database(Database* db) {
    printf("ID\tName\t\tGPA\n");
    for (int i = 0; i < db->size; i++) {
        Student* student = db->students[i];
        printf("%d\t%s\t\t%.2f\n", student->id, student->name, student->gpa);
    }
}

int main() {
    // Initialize database
    Database db = { 0 };

    // Add students to the database
    Student s1 = { 1, "John Doe", 3.5 };
    Student s2 = { 2, "Jane Doe", 3.2 };
    Student s3 = { 3, "Bob Smith", 3.9 };
    add_student(&db, &s1);
    add_student(&db, &s2);
    add_student(&db, &s3);

    // Print database
    printf("Database:\n");
    print_database(&db);

    // Delete a student from the database
    printf("\nDeleting student with ID 2...\n");
    for (int i = 0; i < db.size; i++) {
        Student* student = db.students[i];
        if (student->id == 2) {
            db.students[i] = NULL;
            db.size--;
            break;
        }
    }

    // Print database again
    printf("\nDatabase after deletion:\n");
    print_database(&db);

    return 0;
}