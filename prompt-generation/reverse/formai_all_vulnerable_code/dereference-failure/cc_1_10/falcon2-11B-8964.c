//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: rigorous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Node struct
struct node
{
    int data;
    struct node *next;
};

// Linked list
struct node *head = NULL;

// Function to create node
struct node *createNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to insert a node at the beginning
void insertAtBeginning(int data)
{
    struct node *temp = createNode(data);

    if (head == NULL)
    {
        head = temp;
        return;
    }

    temp->next = head;
    head = temp;
}

// Function to print the list
void printList()
{
    struct node *ptr = head;

    while (ptr!= NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Function to create graph representation
void graph_rep()
{
    int n = 5;

    // Adjacency matrix
    int graph[n][n];

    // Fill the matrix with zeros
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    // Fill the matrix with edges
    graph[0][1] = 1;
    graph[0][3] = 1;
    graph[1][2] = 1;
    graph[1][3] = 1;
    graph[2][3] = 1;
    graph[3][4] = 1;

    // Print the matrix
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Test insert function
    insertAtBeginning(5);
    insertAtBeginning(4);
    insertAtBeginning(3);
    insertAtBeginning(2);
    insertAtBeginning(1);

    // Print the list
    printList();

    // Test graph_rep function
    graph_rep();

    return 0;
}