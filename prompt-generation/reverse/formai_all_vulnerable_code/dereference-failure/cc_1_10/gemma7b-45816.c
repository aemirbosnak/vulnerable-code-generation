//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Node
{
    char data;
    struct Node* next;
} Node;

void visualize(Node* head)
{
    system("clear");
    printf("--------------------------------------------------------\n");
    printf("           /|\\_/)  /|\\_/)  /|\\_/) \n");
    printf("          || |\\__)  || |\\__)  || |\\__) \n");
    printf("           \\__)   \__)   \__) \n");
    printf("--------------------------------------------------------\n");
    printf("Data: %c\n", head->data);
    printf("Next: %p\n", head->next);
    printf("--------------------------------------------------------\n");
    sleep(2);
}

int main()
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = 'A';
    head->next = NULL;

    visualize(head);

    Node* second = (Node*)malloc(sizeof(Node));
    second->data = 'B';
    second->next = NULL;

    head->next = second;

    visualize(head);

    Node* third = (Node*)malloc(sizeof(Node));
    third->data = 'C';
    third->next = NULL;

    second->next = third;

    visualize(head);

    return 0;
}