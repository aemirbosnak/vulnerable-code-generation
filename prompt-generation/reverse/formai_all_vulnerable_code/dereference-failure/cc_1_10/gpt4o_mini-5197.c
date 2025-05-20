//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold student information
typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

// Function to create a new student
Student* create_student(int id, const char *name, float gpa) {
    Student *new_student = (Student *)malloc(sizeof(Student));
    if (new_student == NULL) {
        fprintf(stderr, "Error allocating memory for a new student.\n");
        exit(EXIT_FAILURE);
    }
    new_student->id = id;
    strncpy(new_student->name, name, sizeof(new_student->name));
    new_student->gpa = gpa;
    return new_student;
}

// Function to print student information
void print_student(Student *student) {
    if (student == NULL) {
        fprintf(stderr, "Cannot print a NULL student.\n");
        return;
    }
    printf("ID: %d, Name: %s, GPA: %.2f\n", student->id, student->name, student->gpa);
}

// Function to free the memory allocated for a student
void free_student(Student *student) {
    if (student == NULL) {
        fprintf(stderr, "Cannot free a NULL student.\n");
        return;
    }
    free(student);
}

// Function to create an array of students
Student** create_student_array(int num_students) {
    Student **students = (Student **)malloc(num_students * sizeof(Student *));
    if (students == NULL) {
        fprintf(stderr, "Error allocating memory for student array.\n");
        exit(EXIT_FAILURE);
    }
    return students;
}

// Function to populate the student array
void populate_students(Student **students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        int id = i + 1;
        char name[50];
        snprintf(name, sizeof(name), "Student %d", id);
        float gpa = 2.0f + (rand() % 300) / 100.0f; // Random GPA between 2.0 and 5.0
        students[i] = create_student(id, name, gpa);
    }
}

// Function to print all students in the array
void print_students(Student **students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        print_student(students[i]);
    }
}

// Function to free the student array
void free_student_array(Student **students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        free_student(students[i]);
    }
    free(students);
}

int main() {
    int num_students = 5;
    
    // Seed random number generator
    srand((unsigned)time(NULL));
    
    // Create an array of students
    Student **students = create_student_array(num_students);
    
    // Populate the students
    populate_students(students, num_students);
    
    // Print the students
    print_students(students, num_students);
    
    // Free the student array
    free_student_array(students, num_students);
    
    return 0;
}