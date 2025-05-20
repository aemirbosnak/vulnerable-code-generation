//Gemma-7B DATASET v1.0 Category: Mailing list manager ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_ Mailing_LIST_SIZE 100

typedef struct MailingList
{
    char name[MAX_NAME_LENGTH];
    struct MailingList* next;
} MailingList;

MailingList* createMailingList(char* name)
{
    MailingList* newMailingList = malloc(sizeof(MailingList));
    strcpy(newMailingList->name, name);
    newMailingList->next = NULL;
    return newMailingList;
}

void addToMailingList(MailingList* list, char* name)
{
    if (list == NULL)
    {
        list = createMailingList(name);
    }
    else
    {
        MailingList* current = list;
        while (current->next)
        {
            current = current->next;
        }
        current->next = createMailingList(name);
    }
}

void printMailingList(MailingList* list)
{
    printf("List of recipients:\n");
    for (MailingList* current = list; current; current = current->next)
    {
        printf("%s\n", current->name);
    }
}

int main()
{
    MailingList* northSide = NULL;
    MailingList* southSide = NULL;

    addToMailingList(northSide, "Montague");
    addToMailingList(northSide, "Capulet");
    addToMailingList(southSide, "Montague");
    addToMailingList(southSide, "Capulet");

    printMailingList(northSide);
    printMailingList(southSide);

    return 0;
}