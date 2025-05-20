//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

typedef struct Question
{
    char question[256];
    char answer[256];
    int marks;
    struct Question* next;
} Question;

void createQuestion(Question** head)
{
    *head = (Question*)malloc(sizeof(Question));
    (*head)->marks = 0;
    (*head)->next = NULL;
}

void addQuestion(Question** head, char* question, char* answer, int marks)
{
    Question* newQuestion = (Question*)malloc(sizeof(Question));
    newQuestion->marks = marks;
    strcpy(newQuestion->question, question);
    strcpy(newQuestion->answer, answer);
    newQuestion->next = NULL;

    if (*head == NULL)
    {
        *head = newQuestion;
    }
    else
    {
        (*head)->next = newQuestion;
        *head = newQuestion;
    }
}

void displayQuestions(Question* head)
{
    while (head)
    {
        printf("%s\n", head->question);
        printf("Answer: %s\n", head->answer);
        printf("Marks: %d\n", head->marks);
        printf("\n");
        head = head->next;
    }
}

int main()
{
    Question* head = NULL;

    createQuestion(&head);
    addQuestion(&head, "What is the meaning of the word 'entrepreneur'?", "A person who starts and manages their own business", 5);
    addQuestion(&head, "Which planet is the largest?", "Mars", 3);
    addQuestion(&head, "What is the capital of France?", "Paris", 4);

    displayQuestions(head);

    return 0;
}