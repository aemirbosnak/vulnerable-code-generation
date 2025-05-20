//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data)
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
    }

    return head;
}

int main()
{
    Node* head = NULL;
    char* binary = "1010";

    for (int i = 0; binary[i] != '\0'; i++)
    {
        int digit = binary[i] - '0';
        insertAtTail(head, digit);
    }

    int decimal = 0;
    int power = 0;

    while (head)
    {
        int digit = head->data;
        int product = digit * pow(2, power);
        decimal += product;
        power++;
        head = head->next;
    }

    printf("Decimal: %d", decimal);

    return 0;
}