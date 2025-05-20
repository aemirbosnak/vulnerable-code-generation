//Falcon2-11B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
    int data;
    struct node* next;
} Node;

typedef struct
{
    Node* head;
    Node* tail;
} LinkedList;

void append(LinkedList* list, int num)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = num;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void printList(LinkedList* list)
{
    Node* current = list->head;
    while (current!= NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void fibonacci(int n)
{
    if (n <= 1)
    {
        return;
    }

    Node* head = NULL;
    Node* tail = NULL;

    append(&head, 0);
    append(&tail, 1);

    for (int i = 2; i < n; i++)
    {
        append(&tail, head->data + tail->data);
        head = tail;
        tail = tail->next;
    }

    printList(head);
}

int main()
{
    int n;
    printf("Enter the number of Fibonacci sequence elements to generate: ");
    scanf("%d", &n);

    fibonacci(n);

    return 0;
}