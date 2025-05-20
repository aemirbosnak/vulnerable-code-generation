//Gemma-7B DATASET v1.0 Category: Classical Circuit Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1024

typedef struct Node
{
    int index;
    double value;
    struct Node* next;
} Node;

void simulate(Node* head)
{
    double sum = 0.0;
    double average = 0.0;
    int i = 0;

    while (head)
    {
        sum += head->value;
        i++;
        head = head->next;
    }

    average = sum / i;

    printf("The sum of the values is: %.2lf\n", sum);
    printf("The average value is: %.2lf\n", average);
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    // Create a few nodes
    head = malloc(sizeof(Node));
    tail = head;
    tail->index = 0;
    tail->value = 10.0;
    tail->next = malloc(sizeof(Node));
    tail = tail->next;
    tail->index = 1;
    tail->value = 20.0;
    tail->next = malloc(sizeof(Node));
    tail = tail->next;
    tail->index = 2;
    tail->value = 30.0;
    tail->next = NULL;

    simulate(head);

    return 0;
}