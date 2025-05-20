//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char question[200];
    char answer[200];
    int marks;
    struct Question* next;
} Question;

void createQuestion(Question** head) {
    *head = malloc(sizeof(Question));
    (*head)->marks = 0;
    (*head)->next = NULL;
    return;
}

void addQuestion(Question** head, char* question, char* answer, int marks) {
    Question* newQuestion = malloc(sizeof(Question));
    newQuestion->marks = marks;
    strcpy(newQuestion->question, question);
    strcpy(newQuestion->answer, answer);
    newQuestion->next = NULL;

    if (*head) {
        (*head)->next = newQuestion;
    } else {
        *head = newQuestion;
    }
}

void takeExam(Question* head) {
    int i = 0;
    for (i = 0; i < MAX_QUESTIONS && head; i++) {
        printf("%s\n", head->question);
        printf("Enter your answer: ");
        char answer[200];
        scanf("%s", answer);

        if (strcmp(answer, head->answer) == 0) {
            head->marks++;
        }

        head = head->next;
    }
}

int main() {
    Question* head = NULL;
    createQuestion(&head);
    addQuestion(&head, "What is the meaning of the word 'entrepreneur'?", "Someone who starts and manages a business", 5);
    addQuestion(&head, "Who invented the computer?", "Charles Babbage", 3);
    addQuestion(&head, "What is the capital of Australia?", "Melbourne", 2);

    takeExam(head);

    printf("Your total marks are: %d", head->marks);

    return 0;
}