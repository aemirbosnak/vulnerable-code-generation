//FormAI DATASET v1.0 Category: Sorting ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1000 // Maximum length of the input array

/*
 * Structure definition of a node in the linked list
 */
typedef struct node {
    int data;
    struct node *next;
} Node;

/*
 * Function to insert a node at the end of the linked list
 */
void insert(Node **head, int data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    Node *ptr = *head;
    if (ptr == NULL) {
        *head = newNode;
        return;
    }

    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newNode;
}

/*
 * Function to sort a linked list using bubble sort algorithm
 */
void bubbleSort(Node **head) {
    int swapped = 1;
    while (swapped) {
        swapped = 0;

        Node *ptr = *head;
        while (ptr->next != NULL) {
            if (ptr->data > ptr->next->data) {
                // swap the data of two nodes
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;

                swapped = 1; // set swapped flag
            }
            ptr = ptr->next;
        }
    }
}

/*
 * Main function to get input array, sort it using bubble sort and print the sorted array
 */
int main() {
    int arr[MAX_LEN], n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Convert array to linked list
    Node *head = NULL;
    for (int i = 0; i < n; i++)
        insert(&head, arr[i]);

    // Sort the linked list using bubble sort
    bubbleSort(&head);

    // Print the sorted linked list
    printf("The sorted array is:\n");
    Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");

    return 0;
}