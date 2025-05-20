//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions and choices
#define MAX_QUESTIONS 10
#define MAX_CHOICES 4

// Define the data structure for a question
typedef struct {
    char question[100];
    char choices[MAX_CHOICES][100];
    int correct_answer;
} Question;

// Define the data structure for an exam
typedef struct {
    char name[100];
    int num_questions;
    Question questions[MAX_QUESTIONS];
} Exam;

// Create a new exam
Exam *create_exam() {
    Exam *exam = malloc(sizeof(Exam));
    strcpy(exam->name, "My Funny Exam");
    exam->num_questions = 0;
    return exam;
}

// Add a question to an exam
void add_question(Exam *exam, char *question, char *choices[], int correct_answer) {
    strcpy(exam->questions[exam->num_questions].question, question);
    for (int i = 0; i < MAX_CHOICES; i++) {
        strcpy(exam->questions[exam->num_questions].choices[i], choices[i]);
    }
    exam->questions[exam->num_questions].correct_answer = correct_answer;
    exam->num_questions++;
}

// Print an exam
void print_exam(Exam *exam) {
    printf("Exam: %s\n", exam->name);
    for (int i = 0; i < exam->num_questions; i++) {
        printf("Question %d:\n", i + 1);
        printf("  %s\n", exam->questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("  %d. %s\n", j + 1, exam->questions[i].choices[j]);
        }
    }
}

// Grade an exam
int grade_exam(Exam *exam, int answers[]) {
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
    Exam *exam = create_exam();

    // Add some questions to the exam
    add_question(exam, "What is the funniest animal?", (char *[]) {"Dog", "Cat", "Snake", "Elephant"}, 1);
    add_question(exam, "What is the best way to make a joke?", (char *[]) {"Tell a funny story", "Make a funny face", "Use a prop", "All of the above"}, 4);
    add_question(exam, "What is the funniest thing you have ever seen?", (char *[]) {"A clown falling off a unicycle", "A dog chasing its tail", "A cat playing with a laser pointer", "A baby laughing"}, 4);

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

    // Free the memory allocated for the exam
    free(exam);

    return 0;
}