//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char email[50];
    struct Node *next;
};

struct mailingList
{
    struct Node *head;
    int size;
};

void initList(struct mailingList *list)
{
    list->head = NULL;
    list->size = 0;
}

void addEmail(struct mailingList *list, char *email)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->email, email);
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void removeEmail(struct mailingList *list, char *email)
{
    struct Node *currentNode = list->head;
    struct Node *previousNode = NULL;

    while (currentNode != NULL)
    {
        if (strcmp(currentNode->email, email) == 0)
        {
            if (previousNode == NULL)
            {
                list->head = currentNode->next;
            }
            else
            {
                previousNode->next = currentNode->next;
            }
            free(currentNode);
            list->size--;
            return;
        }
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
}

void printList(struct mailingList *list)
{
    struct Node *currentNode = list->head;
    while (currentNode != NULL)
    {
        printf("%s\n", currentNode->email);
        currentNode = currentNode->next;
    }
}

int main()
{
    struct mailingList list;
    initList(&list);
    int choice;
    char email[50];

    do
    {
        printf("1. Add an email\n");
        printf("2. Remove an email\n");
        printf("3. Print the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the email to add: ");
            scanf("%s", email);
            addEmail(&list, email);
            break;
        case 2:
            printf("Enter the email to remove: ");
            scanf("%s", email);
            removeEmail(&list, email);
            break;
        case 3:
            printList(&list);
            break;
        case 4:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}