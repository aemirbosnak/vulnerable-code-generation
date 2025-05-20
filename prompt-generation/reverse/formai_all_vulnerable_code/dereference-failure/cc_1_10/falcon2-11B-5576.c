//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent an exam question
typedef struct {
    char* question;
    int answer;
} ExamQuestion;

// Structure to represent an exam paper
typedef struct {
    ExamQuestion* questions;
    int numQuestions;
} ExamPaper;

// Function to add a question to the exam paper
void addQuestion(ExamPaper* paper, char* question, int answer) {
    paper->questions = (ExamQuestion*)realloc(paper->questions, (paper->numQuestions + 1) * sizeof(ExamQuestion));
    paper->questions[paper->numQuestions].question = question;
    paper->questions[paper->numQuestions].answer = answer;
    paper->numQuestions++;
}

// Function to print the exam paper
void printExamPaper(ExamPaper* paper) {
    for (int i = 0; i < paper->numQuestions; i++) {
        printf("Question %d: %s\n", i + 1, paper->questions[i].question);
        printf("Answer: %d\n", paper->questions[i].answer);
    }
}

// Function to grade the exam paper
int gradeExamPaper(ExamPaper* paper) {
    int score = 0;
    for (int i = 0; i < paper->numQuestions; i++) {
        if (paper->questions[i].answer == i + 1) {
            score++;
        }
    }
    return score;
}

int main() {
    // Create an exam paper
    ExamPaper paper;
    paper.numQuestions = 5;
    paper.questions = (ExamQuestion*)malloc(sizeof(ExamQuestion) * paper.numQuestions);

    // Add some questions to the exam paper
    addQuestion(&paper, "What is the capital of France?", 1);
    addQuestion(&paper, "What is the capital of Spain?", 2);
    addQuestion(&paper, "What is the capital of Italy?", 3);
    addQuestion(&paper, "What is the capital of Germany?", 4);
    addQuestion(&paper, "What is the capital of Brazil?", 5);

    // Print the exam paper
    printf("Exam paper:\n");
    printExamPaper(&paper);

    // Grade the exam paper
    int score = gradeExamPaper(&paper);
    printf("Score: %d out of 5\n", score);

    return 0;
}