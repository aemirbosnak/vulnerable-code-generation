//GEMINI-pro DATASET v1.0 Category: Educational ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a student
typedef struct student {
    char *name;
    int age;
    float gpa;
} student;

// Create a new student
student *new_student(char *name, int age, float gpa) {
    student *s = malloc(sizeof(student));
    s->name = strdup(name);
    s->age = age;
    s->gpa = gpa;
    return s;
}

// Print the details of a student
void print_student(student *s) {
    printf("Name: %s\n", s->name);
    printf("Age: %d\n", s->age);
    printf("GPA: %.2f\n", s->gpa);
}

// Compare two students by age
int compare_students_by_age(const void *a, const void *b) {
    student *sa = (student *)a;
    student *sb = (student *)b;
    return sa->age - sb->age;
}

// Compare two students by GPA
int compare_students_by_gpa(const void *a, const void *b) {
    student *sa = (student *)a;
    student *sb = (student *)b;
    return sa->gpa - sb->gpa;
}

// Main function
int main() {
    // Create an array of students
    student *students[] = {
        new_student("Alice", 20, 3.5),
        new_student("Bob", 21, 3.7),
        new_student("Charlie", 22, 3.9),
        new_student("Dave", 23, 3.3),
        new_student("Eve", 24, 3.1),
    };

    // Print the original array of students
    printf("Original array of students:\n");
    for (int i = 0; i < 5; i++) {
        print_student(students[i]);
        printf("\n");
    }

    // Sort the array of students by age
    qsort(students, 5, sizeof(student *), compare_students_by_age);

    // Print the array of students sorted by age
    printf("\nArray of students sorted by age:\n");
    for (int i = 0; i < 5; i++) {
        print_student(students[i]);
        printf("\n");
    }

    // Sort the array of students by GPA
    qsort(students, 5, sizeof(student *), compare_students_by_gpa);

    // Print the array of students sorted by GPA
    printf("\nArray of students sorted by GPA:\n");
    for (int i = 0; i < 5; i++) {
        print_student(students[i]);
        printf("\n");
    }

    // Free the memory allocated for the students
    for (int i = 0; i < 5; i++) {
        free(students[i]->name);
        free(students[i]);
    }

    return 0;
}