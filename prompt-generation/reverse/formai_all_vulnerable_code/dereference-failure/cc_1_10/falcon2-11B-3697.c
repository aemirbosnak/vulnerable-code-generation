//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Define number of questions
    int num_questions = 10;
    
    // Create an array of question pointers
    char** questions = malloc(num_questions * sizeof(char*));
    
    // Create an array of answer pointers
    char** answers = malloc(num_questions * sizeof(char*));
    
    // Create an array of grades
    int** grades = malloc(num_questions * sizeof(int*));
    
    // Initialize questions
    questions[0] = "What is the capital of France?";
    questions[1] = "Who invented the telephone?";
    questions[2] = "What is the largest planet in our solar system?";
    //...
    // Initialize answers
    answers[0] = "Paris";
    answers[1] = "Alexander Graham Bell";
    answers[2] = "Jupiter";
    //...
    // Initialize grades
    grades[0][0] = 'A';
    grades[1][0] = 'A';
    grades[2][0] = 'A';
    //...
    
    // Start the exam
    printf("Welcome to the Online Examination System!\n");
    printf("Please answer the following questions:\n");
    
    // Loop through the questions
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d:\n%s\n", i + 1, questions[i]);
        printf("Enter your answer: ");
        fgets(answers[i], sizeof(answers[i]), stdin);
        printf("Your answer: %s\n", answers[i]);
        
        // Check the answer
        if (strcmp(answers[i], answers[i]) == 0) {
            grades[i][0] = 'A';
            printf("Correct!\n");
        } else {
            grades[i][0] = 'F';
            printf("Incorrect!\n");
        }
    }
    
    // Print the grades
    printf("Your grades are:\n");
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: %c\n", i + 1, grades[i][0]);
    }
    
    // Free memory
    free(questions);
    free(answers);
    free(grades);
    
    return 0;
}