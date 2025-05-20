//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct MailList
{
    char name[MAX_SIZE];
    char email[MAX_SIZE];
    struct MailList* next;
} MailList;

MailList* Insert(MailList* head, char* name, char* email)
{
    MailList* newNode = (MailList*)malloc(sizeof(MailList));
    strcpy(newNode->name, name);
    strcpy(newNode->email, email);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        head->next = newNode;
    }

    return head;
}

void PrintList(MailList* head)
{
    while (head)
    {
        printf("%s (%s)\n", head->name, head->email);
        head = head->next;
    }
}

int main()
{
    MailList* head = NULL;

    Insert(head, "John Doe", "john.doe@gmail.com");
    Insert(head, "Jane Doe", "jane.doe@gmail.com");
    Insert(head, "Peter Pan", "peter.pan@neverland.com");

    PrintList(head);

    return 0;
}