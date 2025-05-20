//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

/*
 * Bucket Sort Algorithm implemented in C
 * 
 * This implementation assumes that the input elements are uniformly distributed. 
 * A proper value of 'MAX' must be chosen based on the input data and the number of buckets used.
 * If the input elements are not uniformly distributed, other sorting algorithms may be used before using Bucket Sort.
 *
 * Written by: [Your Name Here]
 * Date: [Date Here]
 */

// Define the maximum value of input elements
#define MAX 100

/*
 * Create a new singly linked list node to store each element
 */
struct node {
    int data;
    struct node* next;
};

/*
 * Insert an element into the bucket (singly linked list)
 */
void insertion_sort(struct node* head) {
    struct node *i, *j, *temp;
    int swapped = 1;
    for (i = head; i != NULL && swapped; i = i->next) {
        swapped = 0;
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = (struct node*)malloc(sizeof(struct node));
                temp->data = i->data;
                i->data = j->data;
                j->data = temp->data;
                free(temp);
                swapped = 1;
            }
        }
    }
}

/*
 * Insert an element into the bucket (singly linked list)
 */
void insert(struct node** head_ref, int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
    }
    else if ((*head_ref)->data >= new_node->data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else {
        struct node* current = *head_ref;
        while (current->next != NULL && current->next->data < new_node->data) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

/*
 * Print all elements in each bucket (singly linked list)
 */
void print_buckets(struct node** buckets, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Bucket #%d: ", i);
        struct node* current = buckets[i];
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

/*
 * Sort all elements in all buckets using Insertion Sort
 */
void sort_buckets(struct node** buckets, int n) {
    int i;
    for (i = 0; i < n; i++) {
        insertion_sort(buckets[i]);
    }
}

/*
 * Bucket Sort Algorithm
 */
void bucket_sort(int* arr, int n, int k) {
    int i, j;
    struct node** buckets = (struct node**)malloc(k * sizeof(struct node*));
    for (i = 0; i < k; i++) {
        buckets[i] = NULL;
    }
    for (i = 0; i < n; i++) {
        int index = (k * arr[i]) / (MAX + 1);
        insert(&buckets[index], arr[i]);
    }
    sort_buckets(buckets, k);
    print_buckets(buckets, k);
    free(buckets);
}

/*
 * Test the Bucket Sort Algorithm
 */
int main() {
    int i, n, k;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter %d elements of the array: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number of buckets to use (recommended value is sqrt(n)): ");
    scanf("%d", &k);
    bucket_sort(arr, n, k);
    free(arr);
    return 0;
}