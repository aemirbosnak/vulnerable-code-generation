//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node
{
    char data;
    struct Node* next;
} Node;

void insert_at_tail(Node* head, char data)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
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

char extract_from_tail(Node* head)
{
    if (head == NULL)
    {
        return -1;
    }

    char data = head->data;
    free(head);
    head = NULL;

    return data;
}

int main()
{
    Node* head = NULL;

    // Insert data into the tail
    insert_at_tail(head, 'a');
    insert_at_tail(head, 'b');
    insert_at_tail(head, 'c');
    insert_at_tail(head, 'd');

    // Extract data from the tail
    char extractedData = extract_from_tail(head);

    // Print extracted data
    printf("%c", extractedData);

    return 0;
}