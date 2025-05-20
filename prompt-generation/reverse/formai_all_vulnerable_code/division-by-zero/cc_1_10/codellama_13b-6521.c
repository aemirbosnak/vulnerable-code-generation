//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: calm
// Online Examination System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure to store exam information
typedef struct {
    char name[50];
    char subject[50];
    int duration;
    int total_marks;
    int marks_obtained;
    char exam_date[20];
} Exam;

// Function to calculate the total marks
int calculate_total_marks(Exam exam) {
    return exam.total_marks;
}

// Function to calculate the percentage score
int calculate_percentage_score(Exam exam) {
    return (exam.marks_obtained / calculate_total_marks(exam)) * 100;
}

// Function to display the exam result
void display_exam_result(Exam exam) {
    printf("Exam Result:\n");
    printf("Name: %s\n", exam.name);
    printf("Subject: %s\n", exam.subject);
    printf("Duration: %d minutes\n", exam.duration);
    printf("Total Marks: %d\n", calculate_total_marks(exam));
    printf("Marks Obtained: %d\n", exam.marks_obtained);
    printf("Percentage Score: %d%%\n", calculate_percentage_score(exam));
}

// Main function
int main() {
    Exam exam;
    printf("Enter the exam details:\n");
    printf("Name: ");
    scanf("%s", exam.name);
    printf("Subject: ");
    scanf("%s", exam.subject);
    printf("Duration (in minutes): ");
    scanf("%d", &exam.duration);
    printf("Total Marks: ");
    scanf("%d", &exam.total_marks);
    printf("Marks Obtained: ");
    scanf("%d", &exam.marks_obtained);
    printf("Exam Date (DD-MM-YYYY): ");
    scanf("%s", exam.exam_date);
    display_exam_result(exam);
    return 0;
}