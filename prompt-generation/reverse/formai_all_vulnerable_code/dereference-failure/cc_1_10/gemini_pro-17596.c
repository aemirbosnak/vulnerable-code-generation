//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions
#define MAX_QUESTIONS 100

// Define the maximum length of a question
#define MAX_QUESTION_LENGTH 100

// Define the maximum number of choices per question
#define MAX_CHOICES 4

// Define the maximum length of a choice
#define MAX_CHOICE_LENGTH 100

// Define the enum for the question types
typedef enum {
    QUESTION_TYPE_MULTIPLE_CHOICE,
    QUESTION_TYPE_TRUE_FALSE,
    QUESTION_TYPE_SHORT_ANSWER
} question_type_t;

// Define the struct for a question
typedef struct {
    question_type_t type;
    char question[MAX_QUESTION_LENGTH];
    char choices[MAX_CHOICES][MAX_CHOICE_LENGTH];
    int correct_answer;
} question_t;

// Define the struct for an exam
typedef struct {
    char name[100];
    int num_questions;
    question_t questions[MAX_QUESTIONS];
} exam_t;

// Create a new exam
exam_t *create_exam() {
    exam_t *exam = malloc(sizeof(exam_t));
    strcpy(exam->name, "My Awesome Exam");
    exam->num_questions = 0;
    return exam;
}

// Add a question to an exam
void add_question(exam_t *exam, question_t question) {
    exam->questions[exam->num_questions++] = question;
}

// Print an exam
void print_exam(exam_t *exam) {
    printf("Exam: %s\n", exam->name);
    printf("Number of questions: %d\n", exam->num_questions);
    for (int i = 0; i < exam->num_questions; i++) {
        question_t question = exam->questions[i];
        printf("Question %d:\n", i + 1);
        printf("Type: %d\n", question.type);
        printf("Question: %s\n", question.question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("Choice %d: %s\n", j + 1, question.choices[j]);
        }
        printf("Correct answer: %d\n", question.correct_answer);
    }
}

// Grade an exam
int grade_exam(exam_t *exam, int *answers) {
    int score = 0;
    for (int i = 0; i < exam->num_questions; i++) {
        question_t question = exam->questions[i];
        int answer = answers[i];
        if (question.type == QUESTION_TYPE_MULTIPLE_CHOICE || question.type == QUESTION_TYPE_TRUE_FALSE) {
            if (answer == question.correct_answer) {
                score++;
            }
        } else if (question.type == QUESTION_TYPE_SHORT_ANSWER) {
            // TODO: Grade short answer questions
        }
    }
    return score;
}

// Main function
int main() {
    // Create a new exam
    exam_t *exam = create_exam();

    // Add some questions to the exam
    question_t question1 = {
        .type = QUESTION_TYPE_MULTIPLE_CHOICE,
        .question = "What is the capital of France?",
        .choices = {
            "Paris",
            "London",
            "Rome",
            "Berlin"
        },
        .correct_answer = 0
    };
    add_question(exam, question1);

    question_t question2 = {
        .type = QUESTION_TYPE_TRUE_FALSE,
        .question = "The Earth is flat.",
        .choices = {
            "True",
            "False"
        },
        .correct_answer = 1
    };
    add_question(exam, question2);

    question_t question3 = {
        .type = QUESTION_TYPE_SHORT_ANSWER,
        .question = "What is the meaning of life?",
        .correct_answer = -1
    };
    add_question(exam, question3);

    // Print the exam
    print_exam(exam);

    // Grade the exam
    int answers[] = {0, 1, 42};
    int score = grade_exam(exam, answers);

    // Print the score
    printf("Score: %d\n", score);

    return 0;
}