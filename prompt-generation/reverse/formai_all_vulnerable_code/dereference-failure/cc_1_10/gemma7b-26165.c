//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXAM_QUESTIONS 10

typedef struct ExamQuestion {
    char *question;
    int marks;
    struct ExamQuestion *next;
} ExamQuestion;

void createQuestion(ExamQuestion **head) {
    *head = malloc(sizeof(ExamQuestion));
    (*head)->question = malloc(200);
    (*head)->marks = 0;
    (*head)->next = NULL;
}

void addQuestion(ExamQuestion *head, char *question, int marks) {
    ExamQuestion *newQuestion = malloc(sizeof(ExamQuestion));
    newQuestion->question = malloc(200);
    newQuestion->marks = marks;
    newQuestion->next = NULL;

    if (head == NULL) {
        head = newQuestion;
    } else {
        head->next = newQuestion;
        head = newQuestion;
    }
}

void takeExam(ExamQuestion *head) {
    int i = 0;
    for (ExamQuestion *currentQuestion = head; currentQuestion; currentQuestion = currentQuestion->next) {
        printf("%d. %s (marks: %d)\n", i + 1, currentQuestion->question, currentQuestion->marks);
        i++;
    }
}

int main() {
    ExamQuestion *examQuestions = NULL;
    createQuestion(&examQuestions);
    addQuestion(examQuestions, "What is the meaning of life?", 10);
    addQuestion(examQuestions, "Who invented the telephone?", 5);
    addQuestion(examQuestions, "What is the capital of France?", 7);
    takeExam(examQuestions);

    return 0;
}