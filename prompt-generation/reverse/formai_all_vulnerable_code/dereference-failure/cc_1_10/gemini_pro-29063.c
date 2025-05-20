//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions and choices per question
#define MAX_QUESTIONS 10
#define MAX_CHOICES 5

// Define the structure of a question
typedef struct {
    char question[100];
    char choices[MAX_CHOICES][100];
    int correct_choice;
} Question;

// Define the structure of an exam
typedef struct {
    Question questions[MAX_QUESTIONS];
    int num_questions;
} Exam;

// Create a new exam
Exam* create_exam() {
    Exam* exam = malloc(sizeof(Exam));
    exam->num_questions = 0;
    return exam;
}

// Add a question to an exam
void add_question(Exam* exam, char* question, char** choices, int correct_choice) {
    strcpy(exam->questions[exam->num_questions].question, question);
    for (int i = 0; i < MAX_CHOICES; i++) {
        strcpy(exam->questions[exam->num_questions].choices[i], choices[i]);
    }
    exam->questions[exam->num_questions].correct_choice = correct_choice;
    exam->num_questions++;
}

// Take an exam
int take_exam(Exam* exam) {
    int score = 0;
    for (int i = 0; i < exam->num_questions; i++) {
        // Print the question and choices
        printf("%s\n", exam->questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%d. %s\n", j + 1, exam->questions[i].choices[j]);
        }

        // Get the user's answer
        int answer;
        printf("Enter your answer: ");
        scanf("%d", &answer);

        // Check if the answer is correct
        if (answer == exam->questions[i].correct_choice) {
            score++;
        }
    }

    return score;
}

// Print the results of an exam
void print_results(Exam* exam, int score) {
    printf("Your score is %d out of %d.\n", score, exam->num_questions);
}

// Free the memory allocated for an exam
void free_exam(Exam* exam) {
    free(exam);
}

// Main function
int main() {
    // Create a new exam
    Exam* exam = create_exam();

    // Add some questions to the exam
    add_question(exam, "What is the capital of France?", (char*[]){"Paris", "London", "Rome", "Madrid", "Berlin"}, 0);
    add_question(exam, "What is the largest ocean in the world?", (char*[]){"Atlantic Ocean", "Pacific Ocean", "Indian Ocean", "Arctic Ocean", "Southern Ocean"}, 1);
    add_question(exam, "What is the chemical symbol for gold?", (char*[]){"Au", "Ag", "Cu", "Fe", "Al"}, 0);

    // Take the exam
    int score = take_exam(exam);

    // Print the results
    print_results(exam, score);

    // Free the memory allocated for the exam
    free_exam(exam);

    return 0;
}