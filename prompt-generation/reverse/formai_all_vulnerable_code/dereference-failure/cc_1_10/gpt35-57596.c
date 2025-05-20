//FormAI DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char* name;
    int age;
    int* grades;
};

int main() {
    // Create a new student
    struct Student* student1 = malloc(sizeof(struct Student));
    if (student1 == NULL) {
        printf("Error: Failed to allocate memory for student1\n");
        return 1;
    }

    // Initialize the student properties
    student1->name = "John";
    student1->age = 20;
    student1->grades = malloc(sizeof(int) * 3);
    if (student1->grades == NULL) {
        printf("Error: Failed to allocate memory for student1's grades\n");
        return 1;
    }
    student1->grades[0] = 90;
    student1->grades[1] = 80;
    student1->grades[2] = 95;

    // Print the student's information
    printf("Name: %s\n", student1->name);
    printf("Age: %d\n", student1->age);
    printf("Grades: %d, %d, %d\n", 
        student1->grades[0], 
        student1->grades[1], 
        student1->grades[2]);

    // Free the memory allocated for the student's grades
    free(student1->grades);

    // Create a new student
    struct Student* student2 = malloc(sizeof(struct Student));
    if (student2 == NULL) {
        printf("Error: Failed to allocate memory for student2\n");
        return 1;
    }

    // Initialize the student properties
    student2->name = "Mary";
    student2->age = 22;
    student2->grades = malloc(sizeof(int) * 2);
    if (student2->grades == NULL) {
        printf("Error: Failed to allocate memory for student2's grades\n");
        return 1;
    }
    student2->grades[0] = 85;
    student2->grades[1] = 95;

    // Print the student's information
    printf("Name: %s\n", student2->name);
    printf("Age: %d\n", student2->age);
    printf("Grades: %d, %d\n", 
        student2->grades[0], 
        student2->grades[1]);

    // Free the memory allocated for the student's grades and the student itself
    free(student2->grades);
    free(student2);
    
    // Free the memory allocated for the first student
    free(student1);

    return 0;
}