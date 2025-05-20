//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student details
typedef struct student {
    char name[50];
    int roll_no;
    float marks;
} student;

// Function to create a new student
student *create_student(char *name, int roll_no, float marks) {
    student *new_student = (student *)malloc(sizeof(student));
    strcpy(new_student->name, name);
    new_student->roll_no = roll_no;
    new_student->marks = marks;
    return new_student;
}

// Function to display student details
void display_student(student *student) {
    printf("Name: %s\n", student->name);
    printf("Roll No: %d\n", student->roll_no);
    printf("Marks: %.2f\n", student->marks);
}

// Function to compare two students based on their marks
int compare_students(student *a, student *b) {
    return (a->marks > b->marks) ? -1 : 1;
}

// Function to sort students in descending order of marks
void sort_students(student **students, int num_students) {
    qsort(students, num_students, sizeof(student *), compare_students);
}

// Function to conduct an online examination
void conduct_exam() {
    // Create an array of students
    student *students[] = {
        create_student("John Doe", 1, 90.0),
        create_student("Jane Doe", 2, 85.0),
        create_student("Bob Smith", 3, 95.0),
        create_student("Alice Smith", 4, 88.0),
        create_student("Tom Jones", 5, 92.0),
    };

    // Get the number of students
    int num_students = sizeof(students) / sizeof(students[0]);

    // Sort the students in descending order of marks
    sort_students(students, num_students);

    // Display the sorted list of students
    printf("Sorted List of Students:\n");
    for (int i = 0; i < num_students; i++) {
        display_student(students[i]);
        printf("\n");
    }

    // Free the memory allocated for each student
    for (int i = 0; i < num_students; i++) {
        free(students[i]);
    }
}

int main() {
    conduct_exam();
    return 0;
}