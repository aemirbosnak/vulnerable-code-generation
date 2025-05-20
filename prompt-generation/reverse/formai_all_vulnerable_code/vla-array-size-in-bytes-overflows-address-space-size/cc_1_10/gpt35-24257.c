//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#define MAX_VALUE 100

/* Linked list node */
struct node {
    int data;
    struct node* next;
};

/* Insert node at head of linked list */
void insert(struct node** head, int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = (*head);
    (*head) = newNode;
}

/* Traverse linked list and print values */
void printList(struct node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
}

/* Bucket sort implementation */
void bucketSort(int array[], int n) {
    struct node* buckets[MAX_VALUE]; /* Create array of buckets */

    /* Initialize all buckets as empty linked lists */
    for (int i = 0; i < MAX_VALUE; i++) {
        buckets[i] = NULL;
    }

    /* Insert elements into appropriate buckets */
    for (int i = 0; i < n; i++) {
        int bucketIndex = MAX_VALUE * array[i] / (100 + 1); /* calculate bucket index */
        insert(&buckets[bucketIndex], array[i]);
    }

    /* Traverse buckets and sort individual linked lists */
    for (int i = 0; i < MAX_VALUE; i++) {
        if (buckets[i] != NULL) {
            struct node* head = buckets[i];
            /* Sort individual linked list using insertion sort */
            for (struct node* p = head; p->next != NULL; p = p->next) {
                for (struct node* q = p->next; q != NULL; q = q->next) {
                    if (p->data > q->data) {
                        int temp = p->data;
                        p->data = q->data;
                        q->data = temp;
                    }
                }
            }
            /* Print sorted linked list */
            printList(head);
            printf("\n");
        }
    }
}

/* Main function */
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    printf("Bucket sort: \n");
    bucketSort(array, n);
    return 0;
}