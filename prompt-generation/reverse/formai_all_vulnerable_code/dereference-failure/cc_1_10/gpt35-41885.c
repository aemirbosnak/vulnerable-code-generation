//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#define BucketSize 10

struct node {
    int data;
    struct node *next;
};

void BucketSort(int[], int);
void InsertionSort(struct node *);
int hash(int);

int main() {
    int arr[] = {55, 23, 98, 7, 49, 12, 27, 36, 62, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    BucketSort(arr, n);
    printf("\nSorted array is: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

void BucketSort(int arr[], int n) {
    int i, j, k;
    struct node **buckets;

    buckets = (struct node **) malloc(BucketSize * sizeof(struct node *));
    for (i = 0; i < BucketSize; i++) {
        buckets[i] = NULL;
    }

    for (i = 0; i < n; i++) {
        struct node *newNode = (struct node *) malloc(sizeof(struct node));
        newNode->data = arr[i];
        newNode->next = NULL;

        k = hash(arr[i]);
        if (buckets[k] == NULL) {
            buckets[k] = newNode;
        } else {
            struct node *temp = buckets[k];
            if (newNode->data < temp->data) {
                newNode->next = temp;
                buckets[k] = newNode;
            } else {
                while (temp->next != NULL && newNode->data > temp->next->data) {
                    temp = temp->next;
                }
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    for (i = 0; i < BucketSize; i++) {
        if (buckets[i] != NULL) {
            InsertionSort(buckets[i]);
        }
    }

    k = 0;
    for (i = 0; i < BucketSize; i++) {
        struct node *node = buckets[i];
        while (node != NULL) {
            arr[k++] = node->data;
            node = node->next;
        }
    }

    for (i = 0; i < BucketSize; i++) {
        struct node *node = buckets[i];
        while (node != NULL) {
            struct node *temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(buckets);
}

void InsertionSort(struct node *head) {
    struct node *i, *j;
    for (i = head->next; i != NULL; i = i->next) {
        int key = i->data;
        j = i->next;
        while (j != NULL && j->data < key) {
            i->data = j->data;
            i = i->next;
            j = j->next;
        }
        i->data = key;
    }
}

int hash(int value) {
    return value/BucketSize;
}