//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store student data
typedef struct Student {
    char name[50];
    int roll_no;
    float marks;
} Student;

// Function to insert a student into the database
void insertStudent(Student *student) {
    printf("Enter student's name: ");
    scanf("%s", student->name);

    printf("Enter student's roll number: ");
    scanf("%d", &student->roll_no);

    printf("Enter student's marks: ");
    scanf("%f", &student->marks);
}

// Function to display all students in the database
void displayStudents(Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].roll_no);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }
}

int main() {
    // Create an array of students
    Student *students = NULL;

    // Allocate memory for the students array
    students = (Student *)malloc(10 * sizeof(Student));

    // Insert students into the database
    insertStudent(students);
    insertStudent(students);
    insertStudent(students);

    // Display all students in the database
    displayStudents(students, 3);

    // Free the memory allocated for the students array
    free(students);

    return 0;
}