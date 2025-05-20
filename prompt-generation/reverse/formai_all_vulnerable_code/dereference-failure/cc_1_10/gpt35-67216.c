//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>

//Node structure to represent each element in the bucket
typedef struct node{
    int data;
    struct node *next;
}node;

//Sorting function to sort elements within each bucket
void InsertionSort(node *head){
    node *i, *j;
    int temp;
    for(i = head -> next; i != NULL; i = i -> next){
        temp = i -> data;
        for(j = i -> next; j != NULL; j = j -> next){
            if(j -> data < temp){
                temp = j -> data;
                j -> data = i -> data;
                i -> data = temp;
            }
        }
    }
}

//Function to add elements into the bucket
void AddToBucket(int index, int data, node **Bucket){
    node *newnode = (node*)malloc(sizeof(node));
    newnode -> data = data;
    newnode -> next = NULL;
    node *temp = Bucket[index]; 
    if(temp == NULL){
        Bucket[index] = newnode;
        return;
    }
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newnode;   
}

//Bucket sort function
void BucketSort(int arr[], int n){
    node **Bucket = (node**)malloc(n * sizeof(node*));
    for(int i = 0; i < n; i++){
        Bucket[i] = NULL;
    }
    int max = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    for(int i = 0; i < n; i++){
        int index = (arr[i] * n) / (max + 1);
        AddToBucket(index, arr[i], Bucket);
    }
    for(int i = 0; i < n; i++){
        InsertionSort(Bucket[i]);
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        node *temp = Bucket[i];
        while(temp){
            arr[count++] = temp -> data;
            temp = temp -> next;
        }
    }
}

//Main function to test the Bucket Sort function 
int main(void){
    int arr[] = {9, 4, 1, 7, 6, 5};
    int n = sizeof(arr) / sizeof(int);
    BucketSort(arr, n);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}