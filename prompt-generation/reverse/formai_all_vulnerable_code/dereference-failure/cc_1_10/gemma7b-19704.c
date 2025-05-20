//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

struct Question
{
    char question[256];
    char answer[256];
    int marks;
    struct Question* next;
};

void createQuestion(struct Question** head)
{
    struct Question* newQuestion = (struct Question*)malloc(sizeof(struct Question));
    newQuestion->marks = 0;
    newQuestion->next = NULL;

    if (*head == NULL)
    {
        *head = newQuestion;
    }
    else
    {
        (*head)->next = newQuestion;
    }
}

void displayQuestions(struct Question* head)
{
    while (head)
    {
        printf("%s", head->question);
        printf("\n");
        printf("Answer: %s", head->answer);
        printf("\n");
        printf("Marks: %d", head->marks);
        printf("\n");
        printf("\n");
        head = head->next;
    }
}

int main()
{
    struct Question* head = NULL;

    createQuestion(&head);
    createQuestion(&head);
    createQuestion(&head);

    displayQuestions(head);

    return 0;
}