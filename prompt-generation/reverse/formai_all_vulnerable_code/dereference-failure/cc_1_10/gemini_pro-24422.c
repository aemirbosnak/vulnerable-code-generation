//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store student data
typedef struct student {
    char name[50];
    int roll_number;
    int marks[5];
} student;

// Structure to store exam data
typedef struct exam {
    char subject[50];
    int duration;
    int total_marks;
    int passing_marks;
} exam;

// Function to create a new student
student* create_student(char* name, int roll_number) {
    student* new_student = (student*)malloc(sizeof(student));
    strcpy(new_student->name, name);
    new_student->roll_number = roll_number;
    for (int i = 0; i < 5; i++) {
        new_student->marks[i] = 0;
    }
    return new_student;
}

// Function to create a new exam
exam* create_exam(char* subject, int duration, int total_marks, int passing_marks) {
    exam* new_exam = (exam*)malloc(sizeof(exam));
    strcpy(new_exam->subject, subject);
    new_exam->duration = duration;
    new_exam->total_marks = total_marks;
    new_exam->passing_marks = passing_marks;
    return new_exam;
}

// Function to conduct an exam
void conduct_exam(student* student, exam* exam) {
    printf("Exam Details:\n");
    printf("Subject: %s\n", exam->subject);
    printf("Duration: %d minutes\n", exam->duration);
    printf("Total Marks: %d\n", exam->total_marks);
    printf("Passing Marks: %d\n", exam->passing_marks);

    printf("\nStudent Details:\n");
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->roll_number);

    // Generate random questions
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        int question = rand() % (exam->total_marks + 1);
        printf("\nQuestion %d: What is %d + %d?\n", i + 1, question, rand() % (exam->total_marks + 1));

        // Get student's answer
        int answer;
        printf("Answer: ");
        scanf("%d", &answer);

        // Check if the answer is correct
        if (answer == question) {
            student->marks[i] = 1;
        }
    }
}

// Function to calculate the total marks obtained by the student
int calculate_total_marks(student* student) {
    int total_marks = 0;
    for (int i = 0; i < 5; i++) {
        total_marks += student->marks[i];
    }
    return total_marks;
}

// Function to check if the student has passed the exam
int has_passed_exam(student* student, exam* exam) {
    int total_marks = calculate_total_marks(student);
    return total_marks >= exam->passing_marks;
}

// Function to print the result of the exam
void print_result(student* student, exam* exam) {
    int total_marks = calculate_total_marks(student);
    printf("\nResult:\n");
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->roll_number);
    printf("Total Marks: %d\n", total_marks);
    if (has_passed_exam(student, exam)) {
        printf("Status: Passed\n");
    } else {
        printf("Status: Failed\n");
    }
}

// Main function
int main() {
    // Create a new student
    student* student = create_student("John Doe", 12345);

    // Create a new exam
    exam* exam = create_exam("Mathematics", 60, 100, 50);

    // Conduct the exam
    conduct_exam(student, exam);

    // Print the result of the exam
    print_result(student, exam);

    return 0;
}