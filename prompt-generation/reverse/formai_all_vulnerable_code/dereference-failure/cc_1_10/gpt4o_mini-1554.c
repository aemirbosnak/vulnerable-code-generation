//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for holding student information
typedef struct {
    char name[50];
    int age;
    float grades[5];
} Student;

// Function prototypes
Student* create_student(const char* name, int age, const float* grades);
void display_student(const Student* student);
void free_student(Student* student);

int main() {
    int number_of_students = 3;  // Number of students to create
    Student** students = (Student**) malloc(number_of_students * sizeof(Student*));
    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    // Sample grades for students
    float grades_1[] = {90.5, 85.2, 78.9, 92.0, 88.0};
    float grades_2[] = {65.0, 70.0, 72.5, 80.0, 75.5};
    float grades_3[] = {88.0, 90.0, 85.5, 87.0, 89.5};

    // Create student records
    students[0] = create_student("Alice", 20, grades_1);
    students[1] = create_student("Bob", 22, grades_2);
    students[2] = create_student("Charlie", 21, grades_3);

    // Display student information
    printf("Student Information:\n");
    for (int i = 0; i < number_of_students; i++) {
        display_student(students[i]);
    }

    // Free allocated memory
    for (int i = 0; i < number_of_students; i++) {
        free_student(students[i]);
    }
    free(students);

    return 0;
}

// Create a new student and return a pointer to the allocated memory
Student* create_student(const char* name, int age, const float* grades) {
    Student* new_student = (Student*) malloc(sizeof(Student));
    if (new_student == NULL) {
        fprintf(stderr, "Memory allocation for student failed!\n");
        exit(EXIT_FAILURE);
    }

    strncpy(new_student->name, name, sizeof(new_student->name) - 1);
    new_student->name[sizeof(new_student->name) - 1] = '\0'; // Ensure null termination
    new_student->age = age;
    memcpy(new_student->grades, grades, sizeof(new_student->grades));

    return new_student;
}

// Display student information
void display_student(const Student* student) {
    if (student == NULL) {
        printf("Invalid student data!\n");
        return;
    }
    
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("Grades: ");
    for (int i = 0; i < 5; i++) {
        printf("%.2f ", student->grades[i]);
    }
    printf("\n\n");
}

// Free the allocated memory for a student
void free_student(Student* student) {
    if (student != NULL) {
        free(student);
    }
}