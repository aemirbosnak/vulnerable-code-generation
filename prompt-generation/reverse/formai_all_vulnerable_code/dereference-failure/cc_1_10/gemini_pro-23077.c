//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the number of questions in the exam
#define NUM_QUESTIONS 10

// Define the maximum length of a question
#define MAX_QUESTION_LENGTH 100

// Define the maximum number of choices per question
#define MAX_CHOICES 5

// Define the maximum length of a choice
#define MAX_CHOICE_LENGTH 50

// Define the data structure for a question
typedef struct question {
    char text[MAX_QUESTION_LENGTH];
    char choices[MAX_CHOICES][MAX_CHOICE_LENGTH];
    int correct_answer;
} question;

// Define the data structure for the exam
typedef struct exam {
    question questions[NUM_QUESTIONS];
    int num_questions;
} exam;

// Create a new exam
exam *create_exam() {
    exam *e = malloc(sizeof(exam));
    e->num_questions = 0;
    return e;
}

// Add a question to an exam
void add_question(exam *e, question q) {
    e->questions[e->num_questions++] = q;
}

// Print an exam
void print_exam(exam *e) {
    for (int i = 0; i < e->num_questions; i++) {
        printf("Question %d:\n", i + 1);
        printf("  %s\n", e->questions[i].text);
        for (int j = 0; j < MAX_CHOICES; j++) {
            if (strlen(e->questions[i].choices[j]) > 0) {
                printf("  %c. %s\n", 'A' + j, e->questions[i].choices[j]);
            }
        }
    }
}

// Free an exam
void free_exam(exam *e) {
    free(e);
}

// Get the user's answer to a question
int get_answer(question q) {
    char answer;
    printf("Your answer: ");
    scanf(" %c", &answer);
    return answer - 'A';
}

// Grade an exam
int grade_exam(exam *e) {
    int score = 0;
    for (int i = 0; i < e->num_questions; i++) {
        int answer = get_answer(e->questions[i]);
        if (answer == e->questions[i].correct_answer) {
            score++;
        }
    }
    return score;
}

// Main function
int main() {
    // Create a new exam
    exam *e = create_exam();

    // Add questions to the exam
    question q1 = {"What is the capital of France?", {"Paris", "London", "Rome", "Berlin", ""}, 0};
    add_question(e, q1);

    question q2 = {"What is the largest ocean in the world?", {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Southern Ocean"}, 0};
    add_question(e, q2);

    question q3 = {"What is the highest mountain in the world?", {"Mount Everest", "K2", "Kangchenjunga", "Lhotse", "Makalu"}, 0};
    add_question(e, q3);

    // Print the exam
    print_exam(e);

    // Grade the exam
    int score = grade_exam(e);

    // Print the score
    printf("Your score is %d/%d\n", score, e->num_questions);

    // Free the exam
    free_exam(e);

    return 0;
}