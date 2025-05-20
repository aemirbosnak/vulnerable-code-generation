//GEMINI-pro DATASET v1.0 Category: Educational ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 256
#define MAX_NUMBER_OF_STUDENTS 100

// Define the student struct
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    double gpa;
} student_t;

// Function to create a new student
student_t *create_student(char *name, int age, double gpa) {
    // Allocate memory for the student
    student_t *student = malloc(sizeof(student_t));

    // Copy the name, age, and gpa into the student struct
    strcpy(student->name, name);
    student->age = age;
    student->gpa = gpa;

    // Return the student
    return student;
}

// Function to print a student
void print_student(student_t *student) {
    // Print the student's name, age, and gpa
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("GPA: %.2f\n", student->gpa);
}

// Function to compare two students by their gpa
int compare_students_by_gpa(const void *a, const void *b) {
    // Cast the arguments to student pointers
    student_t *student1 = (student_t *)a;
    student_t *student2 = (student_t *)b;

    // Compare the students' gpas
    if (student1->gpa < student2->gpa) {
        return -1;
    } else if (student1->gpa > student2->gpa) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    // Create an array of students
    student_t *students[MAX_NUMBER_OF_STUDENTS];

    // Add some students to the array
    students[0] = create_student("John Doe", 20, 3.5);
    students[1] = create_student("Jane Doe", 21, 3.7);
    students[2] = create_student("Bob Smith", 22, 3.2);

    // Print the students
    for (int i = 0; i < 3; i++) {
        print_student(students[i]);
        printf("\n");
    }

    // Sort the students by their gpa
    qsort(students, 3, sizeof(student_t *), compare_students_by_gpa);

    // Print the sorted students
    printf("Sorted students:\n");
    for (int i = 0; i < 3; i++) {
        print_student(students[i]);
        printf("\n");
    }

    // Free the memory allocated for the students
    for (int i = 0; i < 3; i++) {
        free(students[i]);
    }

    return 0;
}