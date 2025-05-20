//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a student
struct student {
    char name[50];
    int id;
    float gpa;
};

// Define a function to add a new student to the database
void add_student(struct student* student) {
    int index = 0;
    while (student[index].id!= -1) {
        index++;
    }
    student[index].id = student->id;
    strcpy(student[index].name, student->name);
    student[index].gpa = student->gpa;
}

// Define a function to remove a student from the database
void remove_student(struct student* student, int id) {
    for (int i = 0; i < 50; i++) {
        if (student[i].id == id) {
            for (int j = i; j < 50; j++) {
                student[j] = student[j+1];
            }
            student[49].id = -1;
            break;
        }
    }
}

// Define a function to search for a student in the database
struct student* search_student(struct student* student, int id) {
    for (int i = 0; i < 50; i++) {
        if (student[i].id == id) {
            return &student[i];
        }
    }
    return NULL;
}

// Define a function to update a student's information in the database
void update_student(struct student* student, int id, char* name, float gpa) {
    for (int i = 0; i < 50; i++) {
        if (student[i].id == id) {
            strcpy(student[i].name, name);
            student[i].gpa = gpa;
            return;
        }
    }
}

// Define a function to print the contents of the database
void print_students(struct student* student) {
    for (int i = 0; i < 50; i++) {
        printf("Student ID: %d, Name: %s, GPA: %f\n", student[i].id, student[i].name, student[i].gpa);
    }
}

int main() {
    // Create an array to represent the database
    struct student students[50];

    // Initialize the database with some sample students
    students[0].id = 1;
    strcpy(students[0].name, "Alice");
    students[0].gpa = 3.5;

    students[1].id = 2;
    strcpy(students[1].name, "Bob");
    students[1].gpa = 3.8;

    students[2].id = 3;
    strcpy(students[2].name, "Charlie");
    students[2].gpa = 4.0;

    // Add a new student to the database
    struct student new_student = { "David", 4, 3.6 };
    add_student(&new_student);

    // Remove a student from the database
    remove_student(students, 2);

    // Search for a student in the database
    struct student* found_student = search_student(students, 2);
    if (found_student!= NULL) {
        printf("Found student with ID %d\n", found_student->id);
    } else {
        printf("Student not found\n");
    }

    // Update a student's information in the database
    update_student(students, 3, "David", 3.9);

    // Print the contents of the database
    print_students(students);

    return 0;
}