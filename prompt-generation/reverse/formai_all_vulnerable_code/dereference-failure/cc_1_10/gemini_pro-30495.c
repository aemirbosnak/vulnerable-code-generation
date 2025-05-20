//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to store the exam details
typedef struct {
    int id;
    char *name;
    int duration;
    int num_questions;
    int *questions;
} Exam;

// Structure to store the student's answers
typedef struct {
    int id;
    char *name;
    int score;
    int *answers;
} Student;

// Function to create a new exam
Exam *create_exam(int id, char *name, int duration, int num_questions) {
    Exam *exam = malloc(sizeof(Exam));
    exam->id = id;
    exam->name = name;
    exam->duration = duration;
    exam->num_questions = num_questions;
    exam->questions = malloc(sizeof(int) * num_questions);
    for (int i = 0; i < num_questions; i++) {
        exam->questions[i] = rand() % 100;
    }
    return exam;
}

// Function to create a new student
Student *create_student(int id, char *name) {
    Student *student = malloc(sizeof(Student));
    student->id = id;
    student->name = name;
    student->score = 0;
    student->answers = malloc(sizeof(int) * 100);
    for (int i = 0; i < 100; i++) {
        student->answers[i] = -1;
    }
    return student;
}

// Function to take the exam
void take_exam(Exam *exam, Student *student) {
    for (int i = 0; i < exam->num_questions; i++) {
        int answer;
        printf("Question %d: %d\n", i + 1, exam->questions[i]);
        scanf("%d", &answer);
        student->answers[i] = answer;
    }
}

// Function to grade the exam
void grade_exam(Exam *exam, Student *student) {
    for (int i = 0; i < exam->num_questions; i++) {
        if (student->answers[i] == exam->questions[i]) {
            student->score++;
        }
    }
}

// Function to print the results
void print_results(Student *student) {
    printf("Student %s scored %d out of 100\n", student->name, student->score);
}

// Main function
int main() {
    // Create a new exam
    Exam *exam = create_exam(1, "Math Exam", 60, 10);

    // Create a new student
    Student *student = create_student(1, "John Doe");

    // Take the exam
    take_exam(exam, student);

    // Grade the exam
    grade_exam(exam, student);

    // Print the results
    print_results(student);

    return 0;
}