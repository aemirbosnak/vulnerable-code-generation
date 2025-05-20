//Falcon2-11B DATASET v1.0 Category: Database simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to represent a student record
typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

// Define a struct to represent a database
typedef struct {
    int numStudents;
    Student students[100];
} Database;

// Function to initialize a new database
void initDatabase(Database *db) {
    db->numStudents = 0;
}

// Function to add a new student to the database
void addStudent(Database *db, int id, char name[], float gpa) {
    if (db->numStudents >= 100) {
        printf("Database is full, cannot add more students.\n");
        return;
    }
    Student newStudent;
    newStudent.id = id;
    strcpy(newStudent.name, name);
    newStudent.gpa = gpa;
    db->students[db->numStudents] = newStudent;
    db->numStudents++;
}

// Function to display the student records in the database
void displayStudents(Database *db) {
    printf("Student ID, Name, GPA\n");
    for (int i = 0; i < db->numStudents; i++) {
        printf("%d, %s, %.2f\n", db->students[i].id, db->students[i].name, db->students[i].gpa);
    }
}

int main() {
    // Create a new database
    Database db;
    initDatabase(&db);

    // Add some students to the database
    addStudent(&db, 1, "John Doe", 3.5);
    addStudent(&db, 2, "Jane Smith", 4.0);
    addStudent(&db, 3, "Bob Johnson", 3.8);

    // Display the student records in the database
    displayStudents(&db);

    // Clean up the database
    for (int i = 0; i < db.numStudents; i++) {
        free(db.students[i].name);
    }
    free(db.students);

    return 0;
}