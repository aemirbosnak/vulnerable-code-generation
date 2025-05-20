//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Node Structure
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Linked List Operations
// 1. Create a Linked List
Node *createLinkedList(int arr[], int size)
{
    Node *head = NULL;
    Node *current = NULL;

    for (int i = 0; i < size; i++)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            current->next = newNode;
        }

        current = newNode;
    }

    return head;
}

// 2. Insert at Beginning
Node *insertAtBeginning(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;

    return newNode;
}

// 3. Insert at End
Node *insertAtEnd(Node *head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;

    return head;
}

// 4. Insert after a Node
Node *insertAfterNode(Node *head, int data, int key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    Node *current = head;
    while (current != NULL && current->data != key)
    {
        current = current->next;
    }

    if (current != NULL)
    {
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;
}

// 5. Delete at Beginning
Node *deleteAtBeginning(Node *head)
{
    if (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return head;
}

// 6. Delete at End
Node *deleteAtEnd(Node *head)
{
    if (head != NULL)
    {
        Node *current = head;
        while (current->next->next != NULL)
        {
            current = current->next;
        }

        free(current->next);
        current->next = NULL;
    }

    return head;
}

// 7. Delete a Node
Node *deleteNode(Node *head, int key)
{
    if (head != NULL)
    {
        Node *current = head;
        Node *prev = NULL;

        while (current != NULL && current->data != key)
        {
            prev = current;
            current = current->next;
        }

        if (current != NULL)
        {
            if (current == head)
            {
                head = head->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
        }
    }

    return head;
}

// 8. Search a Node
int searchNode(Node *head, int key)
{
    Node *current = head;
    int index = 0;

    while (current != NULL && current->data != key)
    {
        current = current->next;
        index++;
    }

    if (current != NULL)
    {
        return index;
    }
    else
    {
        return -1;
    }
}

// 9. Print Linked List
void printLinkedList(Node *head)
{
    Node *current = head;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

// 10. Free Linked List
void freeLinkedList(Node *head)
{
    Node *current = head;

    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Create Linked List
    Node *head = createLinkedList(arr, size);

    // Print Linked List
    printf("Original Linked List: ");
    printLinkedList(head);

    // Insert at Beginning
    head = insertAtBeginning(head, 0);

    // Print Linked List
    printf("Linked List after Insert at Beginning: ");
    printLinkedList(head);

    // Insert at End
    head = insertAtEnd(head, 6);

    // Print Linked List
    printf("Linked List after Insert at End: ");
    printLinkedList(head);

    // Insert after a Node
    head = insertAfterNode(head, 7, 3);

    // Print Linked List
    printf("Linked List after Insert after a Node: ");
    printLinkedList(head);

    // Delete at Beginning
    head = deleteAtBeginning(head);

    // Print Linked List
    printf("Linked List after Delete at Beginning: ");
    printLinkedList(head);

    // Delete at End
    head = deleteAtEnd(head);

    // Print Linked List
    printf("Linked List after Delete at End: ");
    printLinkedList(head);

    // Delete a Node
    head = deleteNode(head, 7);

    // Print Linked List
    printf("Linked List after Delete a Node: ");
    printLinkedList(head);

    // Search a Node
    int index = searchNode(head, 4);

    if (index != -1)
    {
        printf("Node found at index: %d\n", index);
    }
    else
    {
        printf("Node not found\n");
    }

    // Free Linked List
    freeLinkedList(head);

    return 0;
}