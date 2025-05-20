//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: lively
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 255
#define MAX_ Mailing_LIST_SIZE 100

typedef struct MailingListEntry
{
    char name[MAX_NAME_LENGTH];
    struct MailingListEntry* next;
} MailingListEntry;

MailingListEntry* InsertMailingListEntry(MailingListEntry* head, char* name)
{
    MailingListEntry* newEntry = (MailingListEntry*)malloc(sizeof(MailingListEntry));
    strcpy(newEntry->name, name);
    newEntry->next = NULL;

    if (head == NULL)
    {
        head = newEntry;
    }
    else
    {
        head->next = newEntry;
    }

    return head;
}

void PrintMailingList(MailingListEntry* head)
{
    while (head)
    {
        printf("%s\n", head->name);
        head = head->next;
    }
}

int main()
{
    MailingListEntry* head = NULL;

    InsertMailingListEntry(head, "John Doe");
    InsertMailingListEntry(head, "Jane Doe");
    InsertMailingListEntry(head, "Bill Smith");
    InsertMailingListEntry(head, "Mary Johnson");

    PrintMailingList(head);

    return 0;
}