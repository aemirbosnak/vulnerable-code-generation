//Gemma-7B DATASET v1.0 Category: Binary Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct HexNode {
    int data;
    struct HexNode* next;
};

typedef struct HexNode HexNode;

void insertAtTail(HexNode** head, int data)
{
    HexNode* newNode = (HexNode*)malloc(sizeof(HexNode));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

void traverseHex(HexNode* head)
{
    while (head)
    {
        printf("%x ", head->data);
        head = head->next;
    }
}

int main()
{
    HexNode* head = NULL;

    char input[1024] = "";

    printf("Enter a binary number: ");
    scanf("%s", input);

    // Convert binary number to hexadecimal
    for (int i = 0; input[i] != '\0'; i++)
    {
        int digit = input[i] - '0';
        insertAtTail(&head, digit / 16);
        insertAtTail(&head, digit % 16);
    }

    // Traverse the hexadecimal list
    traverseHex(head);

    printf("\n");

    return 0;
}