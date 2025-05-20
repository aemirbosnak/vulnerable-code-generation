//Falcon-180B DATASET v1.0 Category: Memory management ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold information about a student
typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

// Function to allocate memory for a new student
Student* createStudent(char* name, int age, float gpa) {
    Student* newStudent = (Student*) malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->gpa = gpa;
    return newStudent;
}

// Function to print the details of a student
void printStudent(Student* student) {
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("GPA: %f\n", student->gpa);
}

// Function to free the memory allocated for a student
void deleteStudent(Student* student) {
    free(student);
}

int main() {
    // Allocate memory for 3 students
    Student* student1 = createStudent("John", 20, 3.5);
    Student* student2 = createStudent("Jane", 22, 4.0);
    Student* student3 = createStudent("Bob", 19, 3.8);

    // Print the details of each student
    printStudent(student1);
    printStudent(student2);
    printStudent(student3);

    // Free the memory allocated for each student
    deleteStudent(student1);
    deleteStudent(student2);
    deleteStudent(student3);

    return 0;
}