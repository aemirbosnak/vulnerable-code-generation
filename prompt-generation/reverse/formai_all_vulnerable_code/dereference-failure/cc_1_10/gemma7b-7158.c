//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node
{
    char data;
    struct Node* next;
} Node;

Node* insert_at_tail(Node* head, char data)
{
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        head->next = new_node;
    }

    return head;
}

int main()
{
    char message[] = "Hello, world!";
    int message_length = strlen(message);

    Node* head = NULL;

    for (int i = 0; i < message_length; i++)
    {
        insert_at_tail(head, message[i] + 1);
    }

    printf("Original message:");
    for (Node* node = head; node; node = node->next)
    {
        printf("%c ", node->data - 1);
    }

    printf("\nSteganographed message:");
    for (Node* node = head; node; node = node->next)
    {
        printf("%c ", node->data);
    }

    return 0;
}