//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

void visualize(Node* head)
{
    system("cls");
    printf("-----------------------------------------\n");
    printf("   | Data | Next |  \n");
    printf("-----------------------------------------\n");

    Node* temp = head;
    while (temp)
    {
        printf("   | %d | %p |  \n", temp->data, temp->next);
        temp = temp->next;
    }

    printf("-----------------------------------------\n");
    printf("\n");
}

int main()
{
    srand(time(NULL));

    Node* head = NULL;
    for (int i = 0; i < MAX; i++)
    {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = rand() % 100;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            head->next = newNode;
            head = newNode;
        }
    }

    visualize(head);

    return 0;
}