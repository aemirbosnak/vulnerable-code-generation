//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions and choices
#define MAX_QUESTIONS 10
#define MAX_CHOICES 5

// Define the structure of a question
typedef struct {
    char question[256];
    char choices[MAX_CHOICES][64];
    int correct_answer;
} Question;

// Define the structure of an examination
typedef struct {
    char name[64];
    int num_questions;
    Question questions[MAX_QUESTIONS];
} Examination;

// Create a new examination
Examination* create_examination(char* name) {
    Examination* exam = malloc(sizeof(Examination));
    strcpy(exam->name, name);
    exam->num_questions = 0;
    return exam;
}

// Add a question to an examination
void add_question(Examination* exam, Question* question) {
    exam->questions[exam->num_questions++] = *question;
}

// Print an examination
void print_examination(Examination* exam) {
    printf("Examination: %s\n", exam->name);
    for (int i = 0; i < exam->num_questions; i++) {
        printf("Question %d: %s\n", i + 1, exam->questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("Choice %d: %s\n", j + 1, exam->questions[i].choices[j]);
        }
    }
}

// Grade an examination
int grade_examination(Examination* exam) {
    int score = 0;
    for (int i = 0; i < exam->num_questions; i++) {
        int answer;
        printf("Question %d: %s\n", i + 1, exam->questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("Choice %d: %s\n", j + 1, exam->questions[i].choices[j]);
        }
        scanf("%d", &answer);
        if (answer == exam->questions[i].correct_answer) {
            score++;
        }
    }
    return score;
}

// Free the memory allocated for an examination
void free_examination(Examination* exam) {
    free(exam);
}

// Main function
int main() {
    // Create a new examination
    Examination* exam = create_examination("C Online Examination");

    // Add some questions to the examination
    Question question1;
    strcpy(question1.question, "What is the output of the following C code?\nint main() { printf(\"Hello, world!\n\"); }");
    strcpy(question1.choices[0], "Hello, world!");
    strcpy(question1.choices[1], "Hello, world!\n");
    strcpy(question1.choices[2], "Error");
    question1.correct_answer = 1;
    add_question(exam, &question1);

    Question question2;
    strcpy(question2.question, "What is the purpose of the following C code?\nint* p = malloc(sizeof(int));");
    strcpy(question2.choices[0], "To allocate memory for an integer variable");
    strcpy(question2.choices[1], "To free memory allocated for an integer variable");
    strcpy(question2.choices[2], "To create a pointer to an integer variable");
    question2.correct_answer = 0;
    add_question(exam, &question2);

    // Print the examination
    print_examination(exam);

    // Grade the examination
    int score = grade_examination(exam);

    // Print the score
    printf("Your score is %d out of %d\n", score, exam->num_questions);

    // Free the memory allocated for the examination
    free_examination(exam);

    return 0;
}