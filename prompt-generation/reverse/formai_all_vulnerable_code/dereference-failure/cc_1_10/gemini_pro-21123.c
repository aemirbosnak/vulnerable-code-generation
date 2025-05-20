//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions and choices
#define MAX_QUESTIONS 10
#define MAX_CHOICES 5

// Define the structure of a question
typedef struct {
    char question[256];
    char choices[MAX_CHOICES][256];
    int correct_answer;
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
void add_question(Exam* exam, char* question, char** choices, int correct_answer) {
    strcpy(exam->questions[exam->num_questions].question, question);
    for (int i = 0; i < MAX_CHOICES; i++) {
        strcpy(exam->questions[exam->num_questions].choices[i], choices[i]);
    }
    exam->questions[exam->num_questions].correct_answer = correct_answer;
    exam->num_questions++;
}

// Print an exam
void print_exam(Exam* exam) {
    for (int i = 0; i < exam->num_questions; i++) {
        printf("Question %d: %s\n", i + 1, exam->questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("Choice %d: %s\n", j + 1, exam->questions[i].choices[j]);
        }
        printf("Correct answer: %d\n\n", exam->questions[i].correct_answer);
    }
}

// Grade an exam
int grade_exam(Exam* exam, int* answers) {
    int score = 0;
    for (int i = 0; i < exam->num_questions; i++) {
        if (answers[i] == exam->questions[i].correct_answer) {
            score++;
        }
    }
    return score;
}

// Main function
int main() {
    // Create a new exam
    Exam* exam = create_exam();

    // Add questions to the exam
    add_question(exam, "What is the capital of France?", (char*[]){"Paris", "London", "Rome", "Madrid", "Berlin"}, 1);
    add_question(exam, "What is the largest ocean in the world?", (char*[]){"Atlantic Ocean", "Pacific Ocean", "Indian Ocean", "Arctic Ocean", "Southern Ocean"}, 2);
    add_question(exam, "Who is the author of the Harry Potter series?", (char*[]){"J.K. Rowling", "Stephen King", "George R.R. Martin", "Suzanne Collins", "Rick Riordan"}, 1);

    // Print the exam
    print_exam(exam);

    // Get the answers from the user
    int answers[MAX_QUESTIONS];
    for (int i = 0; i < exam->num_questions; i++) {
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%d", &answers[i]);
    }

    // Grade the exam
    int score = grade_exam(exam, answers);

    // Print the score
    printf("Your score is %d out of %d\n", score, exam->num_questions);

    return 0;
}