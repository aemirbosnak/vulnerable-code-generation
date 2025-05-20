//FormAI DATASET v1.0 Category: Data mining ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

/* Definition of struct Node */
struct Node {
    int data;
    struct Node* next;
};

/* Function to generate sample linked list from input array */
struct Node* generateList(int arr[], int size){
    struct Node* head = NULL;
    struct Node* tail = NULL;

    for (int i = 0; i < size; i++) {
        struct Node* newNode =
            (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

/* Function to print linked list */
void printList(struct Node* head){
    struct Node* current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
}

/* Function to mine data from linked list */
void dataMining(struct Node* head){
    int count = 0;
    int sum = 0;
    int max = head->data;
    int min = head->data;

    struct Node* current = head;

    while (current != NULL) {
        count++;
        sum += current->data;
        if (current->data > max) {
            max = current->data;
        }
        if (current->data < min) {
            min = current->data;
        }
        current = current->next;
    }

    printf("\n\nData Mining Results: \n");
    printf("\tNumber of elements: %d\n", count);
    printf("\tSum of elements: %d\n", sum);
    printf("\tMaximum element: %d\n", max);
    printf("\tMinimum element: %d\n", min);
}

/* Main function */
int main(){
    int arr[] = { 5, 2, 9, 1, 8, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);

    struct Node* head = generateList(arr, size);

    printf("Original Linked List: ");
    printList(head);

    dataMining(head);

    return 0;
}