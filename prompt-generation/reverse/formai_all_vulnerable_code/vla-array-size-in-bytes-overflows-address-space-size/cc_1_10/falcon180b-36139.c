//Falcon-180B DATASET v1.0 Category: Sorting ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a student's name and grade
typedef struct {
    char name[50];
    int grade;
} Student;

// Function to compare two students based on their grades
int compareGrades(const void *a, const void *b) {
    const Student *studentA = a;
    const Student *studentB = b;

    if (studentA->grade > studentB->grade) {
        return 1;
    } else if (studentA->grade < studentB->grade) {
        return -1;
    } else {
        return 0;
    }
}

// Function to print the list of students in ascending order of their grades
void printStudents(Student students[], int numStudents) {
    qsort(students, numStudents, sizeof(Student), compareGrades);

    printf("List of students in ascending order of their grades:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s: %d\n", students[i].name, students[i].grade);
    }
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    Student students[numStudents];

    for (int i = 0; i < numStudents; i++) {
        printf("Enter the name and grade for student %d:\n", i + 1);
        scanf("%s %d", students[i].name, &students[i].grade);
    }

    printStudents(students, numStudents);

    return 0;
}