//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
    char *question;
    char **answers;
    int answerIndex;
} Question;

typedef struct Exam {
    Question **questions;
    int numQuestions;
    time_t startTime;
    time_t endTime;
} Exam;

void generateQuestions(Exam *exam) {
    for (int i = 0; i < exam->numQuestions; i++) {
        exam->questions[i] = malloc(sizeof(Question));
        exam->questions[i]->question = malloc(256);
        exam->questions[i]->answers = malloc(MAX_ANSWERS * sizeof(char *));
        exam->questions[i]->answerIndex = rand() % MAX_ANSWERS;
    }
}

void takeExam(Exam *exam) {
    time_t currentTime = time(NULL);
    if (currentTime - exam->startTime >= exam->numQuestions) {
        printf("Time up!");
        return;
    }

    for (int i = 0; i < exam->numQuestions; i++) {
        printf("%s\n", exam->questions[i]->question);

        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%s\n", exam->questions[i]->answers[j]);
        }

        char answer = getchar();

        if (answer - 'a' != exam->questions[i]->answerIndex) {
            printf("Incorrect answer!");
        } else {
            printf("Correct answer!");
        }
    }
}

int main() {
    Exam exam;
    exam.numQuestions = MAX_QUESTIONS;
    exam.questions = malloc(MAX_QUESTIONS * sizeof(Question *));

    generateQuestions(&exam);
    takeExam(&exam);

    return 0;
}