//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of questions and choices per question
#define MAX_QUESTIONS 10
#define MAX_CHOICES 5

// Define the structure of a question
typedef struct Question {
    char question[256];
    char choices[MAX_CHOICES][256];
    int correctAnswer;
} Question;

// Define the structure of an exam
typedef struct Exam {
    Question questions[MAX_QUESTIONS];
    int numQuestions;
    int totalScore;
} Exam;

// Create a new exam
Exam* createExam() {
    Exam* exam = malloc(sizeof(Exam));
    exam->numQuestions = 0;
    exam->totalScore = 0;
    return exam;
}

// Add a question to an exam
void addQuestion(Exam* exam, char* question, char* choices[], int correctAnswer) {
    strcpy(exam->questions[exam->numQuestions].question, question);
    for (int i = 0; i < MAX_CHOICES; i++) {
        strcpy(exam->questions[exam->numQuestions].choices[i], choices[i]);
    }
    exam->questions[exam->numQuestions].correctAnswer = correctAnswer;
    exam->numQuestions++;
}

// Print an exam
void printExam(Exam* exam) {
    for (int i = 0; i < exam->numQuestions; i++) {
        printf("%s\n", exam->questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%d. %s\n", j + 1, exam->questions[i].choices[j]);
        }
        printf("\n");
    }
}

// Grade an exam
int gradeExam(Exam* exam) {
    int score = 0;
    for (int i = 0; i < exam->numQuestions; i++) {
        int answer = 0;
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%d", &answer);
        if (answer == exam->questions[i].correctAnswer) {
            score++;
        }
    }
    return score;
}

// Main function
int main() {
    // Create a new exam
    Exam* exam = createExam();

    // Add questions to the exam
    addQuestion(exam, "What is the capital of France?", (char*[]) {"Paris", "London", "Rome", "Madrid", "Berlin"}, 0);
    addQuestion(exam, "What is the largest ocean in the world?", (char*[]) {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Southern Ocean"}, 0);
    addQuestion(exam, "What is the most populous country in the world?", (char*[]) {"China", "India", "United States", "Indonesia", "Brazil"}, 0);

    // Print the exam
    printExam(exam);

    // Grade the exam
    int score = gradeExam(exam);

    // Print the score
    printf("Your score is %d out of %d\n", score, exam->numQuestions);

    return 0;
}