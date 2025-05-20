//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define the maximum number of questions in the exam
#define MAX_QUESTIONS 100

// Define the structure of a question
typedef struct {
    char question[100];
    char options[4][50];
    int correct_answer;
} Question;

// Define the structure of the exam
typedef struct {
    Question questions[MAX_QUESTIONS];
    int num_questions;
} Exam;

// Load the questions from a file into the exam structure
void load_questions(Exam *exam, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[100];
    int i = 0;
    while (fgets(line, sizeof(line), fp)) {
        // Parse the question
        char *question = strtok(line, "|");
        strcpy(exam->questions[i].question, question);

        // Parse the options
        for (int j = 0; j < 4; j++) {
            char *option = strtok(NULL, "|");
            strcpy(exam->questions[i].options[j], option);
        }

        // Parse the correct answer
        char *correct_answer = strtok(NULL, "|");
        exam->questions[i].correct_answer = atoi(correct_answer);

        i++;
    }

    fclose(fp);
    exam->num_questions = i;
}

// Print the questions and options to the console
void print_questions(Exam *exam) {
    for (int i = 0; i < exam->num_questions; i++) {
        printf("Question %d:\n", i + 1);
        printf("%s\n", exam->questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, exam->questions[i].options[j]);
        }
    }
}

// Get the user's answers to the questions
void get_answers(Exam *exam) {
    for (int i = 0; i < exam->num_questions; i++) {
        int answer;
        printf("Enter your answer for question %d (1-4): ", i + 1);
        scanf("%d", &answer);
        exam->questions[i].correct_answer = answer;
    }
}

// Grade the exam
int grade_exam(Exam *exam) {
    int score = 0;
    for (int i = 0; i < exam->num_questions; i++) {
        if (exam->questions[i].correct_answer == exam->questions[i].correct_answer) {
            score++;
        }
    }

    return score;
}

// Print the exam results to the console
void print_results(Exam *exam) {
    int score = grade_exam(exam);
    printf("Your score is: %d out of %d\n", score, exam->num_questions);
}

int main() {
    // Create a new exam
    Exam exam;

    // Load the questions from a file
    load_questions(&exam, "questions.txt");

    // Print the questions and options to the console
    print_questions(&exam);

    // Get the user's answers to the questions
    get_answers(&exam);

    // Grade the exam
    int score = grade_exam(&exam);

    // Print the exam results to the console
    print_results(&exam);

    return 0;
}