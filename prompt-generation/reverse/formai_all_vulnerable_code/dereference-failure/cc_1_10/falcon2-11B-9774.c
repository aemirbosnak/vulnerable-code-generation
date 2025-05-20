//Falcon2-11B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char sequence[1000];
    int length;
    struct node* next;
} Node;

Node* createNode(char* sequence, int length)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Error: Out of memory\n");
        return NULL;
    }
    strcpy(newNode->sequence, sequence);
    newNode->length = length;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node* head, char* sequence, int length)
{
    Node* newNode = createNode(sequence, length);
    if (newNode == NULL)
    {
        return;
    }
    Node* current = head;
    while (current->next!= NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

void printSequence(Node* head)
{
    Node* current = head;
    while (current!= NULL)
    {
        printf("%s\n", current->sequence);
        current = current->next;
    }
}

int main()
{
    Node* head = NULL;
    insertNode(head, "AATGCTAG", 9);
    insertNode(head, "CTAGCTGA", 8);
    insertNode(head, "TAGCTGCA", 8);
    insertNode(head, "GCTGCAA", 8);
    insertNode(head, "GCAACGTG", 9);
    insertNode(head, "CGTGCTAG", 9);
    insertNode(head, "GTAGCGTG", 9);
    insertNode(head, "GTGCTAGC", 9);
    insertNode(head, "GCTAGCTA", 9);
    insertNode(head, "GTAGCGTA", 9);
    insertNode(head, "CGTGCTAG", 9);
    printSequence(head);
    return 0;
}