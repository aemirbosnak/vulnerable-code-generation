//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of students
#define MAX_STUDENTS 100

// Define the maximum number of questions
#define MAX_QUESTIONS 50

// Define the maximum number of attempts for each student
#define MAX_ATTEMPTS 3

// Student structure
typedef struct Student {
    char name[20];
    int rollno;
    int marks[MAX_QUESTIONS];
    int attempts[MAX_ATTEMPTS];
} Student;

// Function to add a student
void addStudent(Student **students) {
    *students = (Student *)malloc(sizeof(Student) * MAX_STUDENTS);
    for (int i = 0; i < MAX_STUDENTS; i++) {
        (*students)[i].name[0] = '\0';
        (*students)[i].rollno = 0;
        for (int j = 0; j < MAX_QUESTIONS; j++) {
            (*students)[i].marks[j] = 0;
        }
        for (int k = 0; k < MAX_ATTEMPTS; k++) {
            (*students)[i].attempts[k] = 0;
        }
    }
}

// Function to take student marks
void takeMarks(Student *student) {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Enter marks for question %d:", i + 1);
        scanf("%d", &student->marks[i]);
    }
}

// Function to calculate student's total marks
int calculateTotalMarks(Student *student) {
    int totalMarks = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        totalMarks += student->marks[i];
    }
    return totalMarks;
}

// Function to calculate student's average marks
float calculateAverageMarks(Student *student) {
    int totalMarks = calculateTotalMarks(student);
    float averageMarks = (float)totalMarks / MAX_QUESTIONS;
    return averageMarks;
}

// Function to display student's marks
void displayMarks(Student *student) {
    printf("Name: %s\n", student->name);
    printf("Roll No: %d\n", student->rollno);
    printf("Total Marks: %d\n", calculateTotalMarks(student));
    printf("Average Marks: %.2f\n", calculateAverageMarks(student));
    printf("Attempts:\n");
    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        printf("Attempt %d: %d\n", i + 1, student->attempts[i]);
    }
}

int main() {
    Student *students;
    addStudent(&students);
    takeMarks(students);
    displayMarks(students);

    return 0;
}