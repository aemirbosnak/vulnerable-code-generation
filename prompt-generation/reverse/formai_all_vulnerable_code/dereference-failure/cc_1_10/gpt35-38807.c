//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void insert(Node** head, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = (*head);
    (*head) = newNode;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

void bucketSort(int arr[], int size, int numberOfBuckets) {
    Node** buckets = (Node**) malloc(sizeof(Node*) * numberOfBuckets);
    
    for (int i = 0; i < numberOfBuckets; i++) {
        buckets[i] = NULL;
    }
    
    for (int i = 0; i < size; i++) {
        int bucketIndex = numberOfBuckets * (float) arr[i] / (float) size;
        insert(&buckets[bucketIndex], arr[i]);
    }
    
    for (int i = 0; i < numberOfBuckets; i++) {
        if (buckets[i] != NULL) {
            int* tempArray = (int*) malloc(sizeof(int) * size);
            Node* temp = buckets[i];
            int j = 0;
            
            while (temp != NULL) {
                tempArray[j++] = temp->data;
                temp = temp->next;
            }
            
            for (int k = 1; k < j; k++) {
                int key = tempArray[k];
                int l = k - 1;
                
                while (l >= 0 && tempArray[l] > key) {
                    tempArray[l + 1] = tempArray[l];
                    l--;
                }
                
                tempArray[l + 1] = key;
            }
            
            temp = buckets[i];
            j = 0;
            
            while (temp != NULL) {
                temp->data = tempArray[j++];
                temp = temp->next;
            }
            
            free(tempArray);
        }
    }

    for (int i = 0; i < numberOfBuckets; i++) {
        if (buckets[i] != NULL) {
            Node* temp = buckets[i];

            while (temp != NULL) {
                printf("%d ", temp->data);
                temp = temp->next;
            }

            free(buckets[i]);
        }
    }

    free(buckets);
}

int main() {
    int arr[] = {19, 28, 12, 5, 30, 35, 40, 15};
    int size = sizeof(arr) / sizeof(arr[0]);
    int numberOfBuckets = 5;

    bucketSort(arr, size, numberOfBuckets);
    
    return 0;
}