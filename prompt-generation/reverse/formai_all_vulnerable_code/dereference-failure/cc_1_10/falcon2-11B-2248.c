//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    // Create a student object
    struct student {
        char name[100];
        char roll_no[10];
        int age;
        int marks[5];
        char* result;
    } student;

    // Initialize the student object
    strcpy(student.name, "John Doe");
    strcpy(student.roll_no, "123456");
    student.age = 18;
    student.marks[0] = 90;
    student.marks[1] = 85;
    student.marks[2] = 95;
    student.marks[3] = 80;
    student.marks[4] = 75;
    strcpy(student.result, "Pass");

    // Print the student object
    printf("Name: %s\n", student.name);
    printf("Roll No: %s\n", student.roll_no);
    printf("Age: %d\n", student.age);
    printf("Marks: %d %d %d %d %d\n", student.marks[0], student.marks[1], student.marks[2], student.marks[3], student.marks[4]);
    printf("Result: %s\n", student.result);

    // Perform an online examination
    struct exam {
        char* question;
        char* answer;
        int marks;
    } exam;

    // Initialize the exam object
    strcpy(exam.question, "What is the capital of India?");
    strcpy(exam.answer, "New Delhi");
    exam.marks = 10;

    // Print the exam object
    printf("Question: %s\n", exam.question);
    printf("Answer: %s\n", exam.answer);
    printf("Marks: %d\n", exam.marks);

    // Calculate the student's total marks
    int total_marks = 0;
    for (int i = 0; i < 5; i++) {
        total_marks += student.marks[i];
    }

    // Calculate the student's percentage
    int percentage = (total_marks * 100) / 500;

    // Print the student's percentage
    printf("Percentage: %d%%\n", percentage);

    // Check if the student has passed or failed
    if (percentage >= 50) {
        strcpy(student.result, "Pass");
    } else {
        strcpy(student.result, "Fail");
    }

    // Print the student's final result
    printf("Result: %s\n", student.result);

    // Clean up
    free(student.name);
    free(student.roll_no);
    free(student.result);

    return 0;
}