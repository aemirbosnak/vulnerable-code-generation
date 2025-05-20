//GEMINI-pro DATASET v1.0 Category: Educational ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a student
struct student {
    char name[50];
    int age;
    float gpa;
};

// Define a function to create a new student
struct student *create_student(char *name, int age, float gpa) {
    // Allocate memory for the new student
    struct student *new_student = malloc(sizeof(struct student));

    // Check if memory was allocated successfully
    if (new_student == NULL) {
        printf("Error: Could not allocate memory for new student.\n");
        return NULL;
    }

    // Copy the student's information into the new student
    strcpy(new_student->name, name);
    new_student->age = age;
    new_student->gpa = gpa;

    // Return the new student
    return new_student;
}

// Define a function to print a student's information
void print_student(struct student *student) {
    // Print the student's information
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("GPA: %.2f\n", student->gpa);
}

// Define a function to free the memory allocated for a student
void free_student(struct student *student) {
    // Free the memory allocated for the student
    free(student);
}

// Main function
int main() {
    // Create a new student
    struct student *student1 = create_student("John Doe", 20, 3.5);

    // Print the student's information
    print_student(student1);

    // Free the memory allocated for the student
    free_student(student1);

    return 0;
}