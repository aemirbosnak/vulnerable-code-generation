//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    struct Node
    {
        int data;
        struct Node* next;
    } *head = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->next = NULL;

    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    second->data = 20;
    second->next = NULL;

    head->next = second;

    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    third->data = 30;
    third->next = NULL;

    second->next = third;

    struct Node* fourth = (struct Node*)malloc(sizeof(struct Node));
    fourth->data = 40;
    fourth->next = NULL;

    third->next = fourth;

    struct Node* fifth = (struct Node*)malloc(sizeof(struct Node));
    fifth->data = 50;
    fifth->next = NULL;

    fourth->next = fifth;

    struct Node* sixth = (struct Node*)malloc(sizeof(struct Node));
    sixth->data = 60;
    sixth->next = NULL;

    fifth->next = sixth;

    struct Node* seventh = (struct Node*)malloc(sizeof(struct Node));
    seventh->data = 70;
    seventh->next = NULL;

    sixth->next = seventh;

    struct Node* eighth = (struct Node*)malloc(sizeof(struct Node));
    eighth->data = 80;
    eighth->next = NULL;

    seventh->next = eighth;

    struct Node* ninth = (struct Node*)malloc(sizeof(struct Node));
    ninth->data = 90;
    ninth->next = NULL;

    eighth->next = ninth;

    struct Node* tenth = (struct Node*)malloc(sizeof(struct Node));
    tenth->data = 100;
    tenth->next = NULL;

    ninth->next = tenth;

    struct Node* current = head;

    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}