//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: artistic
#include<stdio.h>
#include<stdlib.h>

#define MAX_VAL 100000
#define BUCKET_SIZE 100

// node for the linked list
typedef struct node{
    int data;
    struct node* next;
} node;

// checking if the value entered is valid or not
void checkValue(int value){
    if(value < 0 || value > MAX_VAL){
        printf("Error: Value out of valid range\n");
        exit(1);
    }
}

// adding node to the linked list
void addNode(node* head, int data){
    node* current = head;
    if(current->data == -1){
        current->data = data;
        return;
    }
    while(current->next != NULL){
        current = current->next;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    current->next = temp;
}

// printing the sorted array
void print(int* arr, int size){
    printf("\nSorted Array:\n");
    for(int i=0; i<size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

// sorting using bucket sort
void bucketSort(int* arr, int size){
    node* buckets[BUCKET_SIZE];
    for(int i=0; i<BUCKET_SIZE; i++){
        buckets[i] = (node*)malloc(sizeof(node));
        buckets[i]->data = -1;
        buckets[i]->next = NULL;
    }
    for(int i=0; i<size; i++){
        checkValue(arr[i]);
        addNode(buckets[arr[i]/BUCKET_SIZE], arr[i]);
    }
    int k=0;
    for(int i=0; i<BUCKET_SIZE; i++){
        int* temp = (int*)malloc(BUCKET_SIZE*sizeof(int));
        node* current = buckets[i];
        int j=0;
        while(current!=NULL){
            if(current->data != -1){
                temp[j] = current->data;
                j++;
            }
            current = current->next;
        }
        int tempSize = j;
        for(int j=1; j<tempSize; j++){
            int key = temp[j];
            int l=j-1;
            while(l>=0 && temp[l]>key){
                temp[l+1] = temp[l];
                l--;
            }
            temp[l+1] = key;
        }
        for(int j=0; j<tempSize; j++){
            arr[k] = temp[j];
            k++;
        }
    }
}

int main(){
    int arr[] = {100, 67, 89, 12, 98, 56, 23, 45, 76, 87, 34, 49, 29, 15, 72, 39, 61, 11, 1, 3};
    int size = sizeof(arr)/sizeof(int);
    bucketSort(arr, size);
    print(arr, size);
    return 0;
}