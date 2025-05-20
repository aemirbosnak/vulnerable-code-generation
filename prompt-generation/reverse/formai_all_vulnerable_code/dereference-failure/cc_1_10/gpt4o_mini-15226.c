//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold multiple attributes for sorting
typedef struct {
    int id;
    char name[50];
    float score;
} Student;

// Function to compare two students based on score, then name if scores are equal
int compareStudents(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;

    if (studentA->score < studentB->score) {
        return 1; // Higher score first
    } else if (studentA->score > studentB->score) {
        return -1; // Lower score later
    } else {
        return strcmp(studentA->name, studentB->name); // Alphabetical order if scores are the same
    }
}

// Function to print student details
void printStudents(Student *students, int count) {
    printf("ID\tName\t\tScore\n");
    printf("---------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-15s\t%.2f\n", students[i].id, students[i].name, students[i].score);
    }
}

int main() {
    int numberOfStudents = 5;
    Student *students = (Student *)malloc(numberOfStudents * sizeof(Student));
    
    // Input data
    students[0].id = 1; strcpy(students[0].name, "Alice"); students[0].score = 88.5;
    students[1].id = 2; strcpy(students[1].name, "Bob"); students[1].score = 92.0;
    students[2].id = 3; strcpy(students[2].name, "Charlie"); students[2].score = 88.5;
    students[3].id = 4; strcpy(students[3].name, "David"); students[3].score = 75.0;
    students[4].id = 5; strcpy(students[4].name, "Eve"); students[4].score = 92.0;

    printf("Before sorting:\n");
    printStudents(students, numberOfStudents);

    // Sort the students
    qsort(students, numberOfStudents, sizeof(Student), compareStudents);

    printf("\nAfter sorting:\n");
    printStudents(students, numberOfStudents);

    // Free allocated memory
    free(students);
    return 0;
}