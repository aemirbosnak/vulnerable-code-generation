//Falcon2-11B DATASET v1.0 Category: Queue Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void enqueue(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
        return;
    }

    Node *curr = head;

    while (curr->next!= NULL)
    {
        curr = curr->next;
    }

    curr->next = temp;
}

int dequeue()
{
    if (head == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }

    Node *temp = head;
    head = head->next;

    free(temp);

    return temp->data;
}

void display()
{
    Node *curr = head;

    while (curr!= NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    printf("\n");
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);

    display();

    printf("%d\n", dequeue());

    display();

    return 0;
}