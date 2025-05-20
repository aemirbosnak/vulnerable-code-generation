//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the graph
typedef struct Node
{
    char name[50];
    int degree;
    int friendCount;
    struct Node* next;
} Node;

// Function to add a friend to a user
void addFriend(Node* root, char* name)
{
    Node* temp = root;
    while (temp)
    {
        if (strcmp(temp->name, name) == 0)
        {
            temp->friendCount++;
            return;
        }
        temp = temp->next;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->degree = 1;
    newNode->friendCount = 1;
    newNode->next = NULL;

    if (root == NULL)
        root = newNode;
    else
    {
        Node* temp = root;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to print the graph
void printGraph(Node* root)
{
    if (root == NULL)
        return;

    printf("%s %d %d\n", root->name, root->degree, root->friendCount);

    Node* temp = root->next;
    while (temp)
    {
        printGraph(temp);
        temp = temp->next;
    }
}

int main()
{
    Node* root = NULL;
    addFriend(root, "John");
    addFriend(root, "Alice");
    addFriend(root, "Bob");
    addFriend(root, "Charlie");
    addFriend(root, "David");

    printGraph(root);

    return 0;
}