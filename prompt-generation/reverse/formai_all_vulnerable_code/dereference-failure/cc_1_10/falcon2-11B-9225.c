//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create an examination system
void createExaminationSystem(int numQuestions, int numStudents) {
    // Allocate memory for examination system
    char **students = (char **)malloc(numStudents * sizeof(char *));
    char **questions = (char **)malloc(numQuestions * sizeof(char *));
    
    // Initialize students and questions
    for (int i = 0; i < numStudents; i++) {
        students[i] = (char *)malloc(sizeof(char) * 50);
        strcpy(students[i], "Student ");
        students[i][strlen(students[i])-1] = '\0';
        students[i][strlen(students[i])-2] = '\0';
    }
    
    for (int i = 0; i < numQuestions; i++) {
        questions[i] = (char *)malloc(sizeof(char) * 50);
        strcpy(questions[i], "Question ");
        questions[i][strlen(questions[i])-1] = '\0';
        questions[i][strlen(questions[i])-2] = '\0';
    }
    
    // Display students and questions
    for (int i = 0; i < numStudents; i++) {
        printf("Student: %s\n", students[i]);
    }
    
    for (int i = 0; i < numQuestions; i++) {
        printf("Question: %s\n", questions[i]);
    }
    
    // Free memory
    for (int i = 0; i < numStudents; i++) {
        free(students[i]);
    }
    
    for (int i = 0; i < numQuestions; i++) {
        free(questions[i]);
    }
    
    free(students);
    free(questions);
}

// Main function
int main() {
    int numQuestions = 5;
    int numStudents = 3;
    
    createExaminationSystem(numQuestions, numStudents);
    
    return 0;
}