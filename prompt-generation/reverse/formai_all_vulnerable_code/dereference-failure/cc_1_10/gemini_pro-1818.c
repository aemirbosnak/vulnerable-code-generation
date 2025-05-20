//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions and choices
#define MAX_QUESTIONS 10
#define MAX_CHOICES 4

// Define the structure of a question
typedef struct question {
    char question[256];  // The question text
    char choices[MAX_CHOICES][64];  // The choices for the question
    int correct_answer;  // The index of the correct answer
} question;

// Define the structure of an exam
typedef struct exam {
    question questions[MAX_QUESTIONS];  // The questions in the exam
    int num_questions;  // The number of questions in the exam
} exam;

// Create a new exam
exam *create_exam() {
    exam *new_exam = malloc(sizeof(exam));
    new_exam->num_questions = 0;
    return new_exam;
}

// Add a question to an exam
void add_question(exam *exam, char *question, char **choices, int correct_answer) {
    strcpy(exam->questions[exam->num_questions].question, question);
    for (int i = 0; i < MAX_CHOICES; i++) {
        strcpy(exam->questions[exam->num_questions].choices[i], choices[i]);
    }
    exam->questions[exam->num_questions].correct_answer = correct_answer;
    exam->num_questions++;
}

// Print an exam
void print_exam(exam *exam) {
    for (int i = 0; i < exam->num_questions; i++) {
        printf("%d. %s\n", i + 1, exam->questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("    (%c) %s\n", 'A' + j, exam->questions[i].choices[j]);
        }
    }
}

// Grade an exam
int grade_exam(exam *exam, int *answers) {
    int score = 0;
    for (int i = 0; i < exam->num_questions; i++) {
        if (answers[i] == exam->questions[i].correct_answer) {
            score++;
        }
    }
    return score;
}

// Free the memory allocated for an exam
void free_exam(exam *exam) {
    free(exam);
}

// Main function
int main() {
    // Create a new exam
    exam *my_exam = create_exam();

    // Add some questions to the exam
    add_question(my_exam, "What is the capital of France?", (char *[]){"Paris", "London", "Rome", "Berlin"}, 0);
    add_question(my_exam, "What is the largest ocean in the world?", (char *[]){"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"}, 0);
    add_question(my_exam, "What is the chemical symbol for gold?", (char *[]){"Au", "Ag", "Cu", "Fe"}, 0);

    // Print the exam
    print_exam(my_exam);

    // Get the answers from the user
    int answers[MAX_QUESTIONS];
    for (int i = 0; i < my_exam->num_questions; i++) {
        printf("Enter your answer for question %d: ", i + 1);
        scanf(" %d", &answers[i]);
    }

    // Grade the exam
    int score = grade_exam(my_exam, answers);

    // Print the score
    printf("Your score is: %d\n", score);

    // Free the memory allocated for the exam
    free_exam(my_exam);

    return 0;
}