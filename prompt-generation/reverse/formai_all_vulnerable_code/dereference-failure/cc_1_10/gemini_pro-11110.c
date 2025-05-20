//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the number of questions in the exam
#define NUM_QUESTIONS 10

// Define the maximum length of a question
#define MAX_QUESTION_LENGTH 256

// Define the maximum length of an answer
#define MAX_ANSWER_LENGTH 256

// Define the number of choices for each question
#define NUM_CHOICES 4

// Define the data structure for a question
typedef struct question {
    char question[MAX_QUESTION_LENGTH];
    char choices[NUM_CHOICES][MAX_ANSWER_LENGTH];
    int correct_answer;
} question;

// Define the data structure for an exam
typedef struct exam {
    question questions[NUM_QUESTIONS];
    int num_questions;
} exam;

// Create a new exam
exam *create_exam() {
    exam *e = malloc(sizeof(exam));
    e->num_questions = NUM_QUESTIONS;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        // Generate a random question
        sprintf(e->questions[i].question, "Question %d?", i + 1);
        
        // Generate random choices for the question
        for (int j = 0; j < NUM_CHOICES; j++) {
            sprintf(e->questions[i].choices[j], "Choice %d", j + 1);
        }
        
        // Set the correct answer for the question
        e->questions[i].correct_answer = rand() % NUM_CHOICES;
    }
    
    return e;
}

// Free the memory allocated for an exam
void free_exam(exam *e) {
    free(e);
}

// Print an exam to the console
void print_exam(exam *e) {
    for (int i = 0; i < e->num_questions; i++) {
        printf("Question %d: %s\n", i + 1, e->questions[i].question);
        for (int j = 0; j < NUM_CHOICES; j++) {
            printf("    Choice %d: %s\n", j + 1, e->questions[i].choices[j]);
        }
    }
}

// Grade an exam
int grade_exam(exam *e, int *answers) {
    int score = 0;
    for (int i = 0; i < e->num_questions; i++) {
        if (answers[i] == e->questions[i].correct_answer) {
            score++;
        }
    }
    
    return score;
}

// Main function
int main() {
    // Create a new exam
    exam *e = create_exam();
    
    // Print the exam to the console
    print_exam(e);
    
    // Get the user's answers to the exam
    int answers[NUM_QUESTIONS];
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%d", &answers[i]);
    }
    
    // Grade the exam
    int score = grade_exam(e, answers);
    
    // Print the score to the console
    printf("Your score is %d out of %d\n", score, NUM_QUESTIONS);
    
    // Free the memory allocated for the exam
    free_exam(e);
    
    return 0;
}