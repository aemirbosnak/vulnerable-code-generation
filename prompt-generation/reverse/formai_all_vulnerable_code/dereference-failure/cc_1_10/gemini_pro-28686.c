//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions and choices
#define MAX_QUESTIONS 100
#define MAX_CHOICES 4

// Define the structure of a question
typedef struct {
    char question[256];
    char choices[MAX_CHOICES][256];
    int correct_answer;
} Question;

// Define the structure of an exam
typedef struct {
    int num_questions;
    Question questions[MAX_QUESTIONS];
} Exam;

// Create a new exam
Exam* create_exam() {
    Exam* exam = malloc(sizeof(Exam));
    exam->num_questions = 0;
    return exam;
}

// Add a question to an exam
void add_question(Exam* exam, Question question) {
    exam->questions[exam->num_questions++] = question;
}

// Load questions from a file
void load_questions(Exam* exam, char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        // Parse the question
        char* question_text = strtok(line, "|");
        char* choices[MAX_CHOICES];
        int correct_answer;
        for (int i = 0; i < MAX_CHOICES; i++) {
            choices[i] = strtok(NULL, "|");
            if (choices[i] == NULL) {
                break;
            }
        }
        correct_answer = atoi(strtok(NULL, "|"));

        // Add the question to the exam
        Question question;
        strcpy(question.question, question_text);
        for (int i = 0; i < MAX_CHOICES; i++) {
            strcpy(question.choices[i], choices[i]);
        }
        question.correct_answer = correct_answer;
        add_question(exam, question);
    }

    fclose(file);
}

// Print the exam
void print_exam(Exam* exam) {
    for (int i = 0; i < exam->num_questions; i++) {
        Question question = exam->questions[i];
        printf("Question %d: %s\n", i + 1, question.question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("  %c. %s\n", 'A' + j, question.choices[j]);
        }
        printf("\n");
    }
}

// Grade the exam
int grade_exam(Exam* exam, int* answers) {
    int score = 0;
    for (int i = 0; i < exam->num_questions; i++) {
        Question question = exam->questions[i];
        if (answers[i] == question.correct_answer) {
            score++;
        }
    }
    return score;
}

// Main function
int main() {
    // Create a new exam
    Exam* exam = create_exam();

    // Load questions from a file
    load_questions(exam, "questions.txt");

    // Print the exam
    print_exam(exam);

    // Get the answers from the user
    int answers[MAX_QUESTIONS];
    for (int i = 0; i < exam->num_questions; i++) {
        printf("Enter the answer for question %d: ", i + 1);
        scanf(" %c", &answers[i]);
    }

    // Grade the exam
    int score = grade_exam(exam, answers);
    printf("Your score is %d out of %d\n", score, exam->num_questions);

    return 0;
}