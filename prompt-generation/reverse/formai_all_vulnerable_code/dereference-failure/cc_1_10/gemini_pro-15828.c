//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of questions and choices
#define MAX_QUESTIONS 10
#define MAX_CHOICES 5

// Define the structure of a question
typedef struct {
    char question[100];
    char choices[MAX_CHOICES][100];
    int correct_answer;
} Question;

// Define the structure of an exam
typedef struct {
    int num_questions;
    Question questions[MAX_QUESTIONS];
} Exam;

// Create a new exam
Exam *create_exam() {
    Exam *exam = malloc(sizeof(Exam));
    exam->num_questions = 0;
    return exam;
}

// Add a question to an exam
void add_question(Exam *exam, char *question, char **choices, int correct_answer) {
    strcpy(exam->questions[exam->num_questions].question, question);
    for (int i = 0; i < MAX_CHOICES; i++) {
        strcpy(exam->questions[exam->num_questions].choices[i], choices[i]);
    }
    exam->questions[exam->num_questions].correct_answer = correct_answer;
    exam->num_questions++;
}

// Print an exam
void print_exam(Exam *exam) {
    for (int i = 0; i < exam->num_questions; i++) {
        printf("%s\n", exam->questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%d. %s\n", j + 1, exam->questions[i].choices[j]);
        }
        printf("\n");
    }
}

// Grade an exam
int grade_exam(Exam *exam, int *answers) {
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
    // Seed the random number generator
    srand(time(NULL));

    // Create a new exam
    Exam *exam = create_exam();

    // Add some questions to the exam
    add_question(exam, "What is the capital of France?", (char *[]){"Paris", "London", "Rome", "Madrid", "Berlin"}, 0);
    add_question(exam, "What is the largest ocean in the world?", (char *[]){"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Southern Ocean"}, 0);
    add_question(exam, "What is the chemical symbol for gold?", (char *[]){"Au", "Ag", "Cu", "Fe", "Pb"}, 0);
    add_question(exam, "What is the name of the largest moon in the solar system?", (char *[]){"Ganymede", "Titan", "Callisto", "Io", "Europa"}, 0);
    add_question(exam, "What is the name of the first computer programming language?", (char *[]){"FORTRAN", "COBOL", "BASIC", "Pascal", "C"}, 0);

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
    printf("Your score is: %d\n", score);

    return 0;
}