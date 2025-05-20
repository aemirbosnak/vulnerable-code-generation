//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char *question;
    int marks;
    struct Question *next;
} Question;

void createQuestion(Question **head) {
    *head = malloc(sizeof(Question));
    (*head)->question = malloc(100);
    (*head)->marks = 0;
    (*head)->next = NULL;
}

void addQuestion(Question *head, char *question, int marks) {
    Question *newQuestion = malloc(sizeof(Question));
    newQuestion->question = malloc(100);
    newQuestion->marks = marks;
    newQuestion->next = NULL;

    if (head == NULL) {
        head = newQuestion;
    } else {
        head->next = newQuestion;
    }

    head = newQuestion;
}

int main() {
    Question *head = NULL;
    createQuestion(&head);
    addQuestion(head, "What is the meaning of life?", 20);
    addQuestion(head, "Who invented the telephone?", 15);
    addQuestion(head, "What is the capital of France?", 10);

    int i = 0;
    for (Question *currentQuestion = head; currentQuestion; currentQuestion = currentQuestion->next) {
        printf("Question %d: %s\n", i + 1, currentQuestion->question);
        printf("Marks: %d\n", currentQuestion->marks);
        i++;
    }

    return 0;
}