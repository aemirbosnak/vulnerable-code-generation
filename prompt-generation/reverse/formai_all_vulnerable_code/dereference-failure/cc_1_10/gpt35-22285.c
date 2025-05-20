//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void insert(Node**, int);
int delete(Node**);
void printList(Node*);
void bucketSort(int*, int, int);

int main() {
    int n, maxVal, i;
    
    printf("Enter the number of elements to sort: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter the maximum value in the array: ");
    scanf("%d", &maxVal);
    
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    bucketSort(arr, n, maxVal);
    
    printf("\nSorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

void bucketSort(int* arr, int n, int maxVal) {
    int i, j;
    
    Node** buckets = (Node**) malloc(sizeof(Node*) * maxVal);
    for (i = 0; i < maxVal; i++) {
        buckets[i] = NULL;
    }
    
    // insert elements into buckets
    for (i = 0; i < n; i++) {
        int index = arr[i] / maxVal * (maxVal - 1);
        insert(&buckets[index], arr[i]);
    }
    
    // sort individual buckets and merge them
    int index = 0;
    for (i = 0; i < maxVal; i++) {
        Node* cur = buckets[i];
        while (cur != NULL) {
            arr[index++] = delete(&cur);
        }
    }
    
    // free memory of buckets
    for (i = 0; i < maxVal; i++) {
        Node* cur = buckets[i];
        while (cur != NULL) {
            Node* temp = cur->next;
            free(cur);
            cur = temp;
        }
    }
    free(buckets);
}

void insert(Node** head, int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    
    if (*head == NULL) {
        *head = new_node;
    }
    else {
        Node* cur = *head;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = new_node;
    }
}

int delete(Node** head) {
    if (*head == NULL) {
        return -1;
    }
    else {
        int data = (*head)->data;
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return data;
    }
}

void printList(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}