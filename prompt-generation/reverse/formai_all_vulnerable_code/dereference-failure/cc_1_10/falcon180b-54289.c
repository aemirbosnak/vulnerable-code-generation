//Falcon-180B DATASET v1.0 Category: Bucket Sort Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct node {
    int data;
    struct node* next;
};

typedef struct node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* insertNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    Node* temp = head;
    while (temp->next!= NULL)
        temp = temp->next;
    temp->next = newNode;
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    Node** buckets = (Node**)malloc(MAX_SIZE * sizeof(Node*));
    for (int i = 0; i < MAX_SIZE; i++)
        buckets[i] = NULL;

    Node* head = NULL;
    int input;
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &input);
        head = insertNode(head, input);
    }

    printf("Before sorting:\n");
    printList(head);

    int min = head->data;
    int max = head->data;
    for (int i = 0; i < n; i++) {
        Node* temp = head;
        while (temp!= NULL) {
            if (temp->data < min)
                min = temp->data;
            if (temp->data > max)
                max = temp->data;
            temp = temp->next;
        }
    }

    int range = max - min + 1;
    int bucketSize = MAX_SIZE / range;

    printf("Range: %d\n", range);
    printf("Bucket size: %d\n", bucketSize);

    head = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &input);
        head = insertNode(head, input);
    }

    printf("After sorting:\n");
    printList(head);

    return 0;
}