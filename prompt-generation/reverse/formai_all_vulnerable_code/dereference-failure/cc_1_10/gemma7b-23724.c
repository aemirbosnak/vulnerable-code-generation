//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

typedef struct Question
{
    char *question;
    int marks;
    struct Question *next;
} Question;

void createQuestion(Question **head)
{
    *head = (Question *)malloc(sizeof(Question));
    (*head)->question = (char *)malloc(100);
    (*head)->marks = 0;
    (*head)->next = NULL;
}

void addQuestion(Question **head, char *question, int marks)
{
    Question *newQuestion = (Question *)malloc(sizeof(Question));
    newQuestion->question = (char *)malloc(100);
    newQuestion->marks = marks;
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

void displayQuestions(Question *head)
{
    while (head)
    {
        printf("%s ( %d marks )\n", head->question, head->marks);
        head = head->next;
    }
}

int main()
{
    Question *head = NULL;

    createQuestion(&head);
    addQuestion(&head, "What is the meaning of life?", 10);
    addQuestion(&head, "Who invented the computer?", 5);
    addQuestion(&head, "What is the capital of France?", 7);

    displayQuestions(head);

    return 0;
}