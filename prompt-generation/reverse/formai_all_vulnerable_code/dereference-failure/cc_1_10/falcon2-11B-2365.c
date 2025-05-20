//Falcon2-11B DATASET v1.0 Category: Database Indexing System ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10

struct node
{
    char data[MAX_SIZE];
    struct node *next;
};

struct node *head = NULL;

void insert(char *data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct node *temp = head;
    while (temp->next!= NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printList()
{
    struct node *temp = head;
    while (temp!= NULL)
    {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    insert("Hello");
    insert("World");
    insert("How");
    insert("Are");
    insert("You");
    insert("What");
    insert("Is");
    insert("Your");
    insert("Name");
    insert("Age");
    insert("Height");

    printList();

    return 0;
}