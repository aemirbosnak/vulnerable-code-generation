//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100

typedef struct MailList
{
    char name[50];
    char email[50];
    struct MailList* next;
} MailList;

MailList* addToList(MailList* head, char* name, char* email)
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

void printList(MailList* head)
{
    while (head)
    {
        printf("Name: %s, Email: %s\n", head->name, head->email);
        head = head->next;
    }
}

int main()
{
    MailList* head = NULL;

    head = addToList(head, "John Doe", "john.doe@gmail.com");
    head = addToList(head, "Jane Doe", "jane.doe@gmail.com");
    head = addToList(head, "Bob Smith", "bob.smith@gmail.com");

    printList(head);

    return 0;
}