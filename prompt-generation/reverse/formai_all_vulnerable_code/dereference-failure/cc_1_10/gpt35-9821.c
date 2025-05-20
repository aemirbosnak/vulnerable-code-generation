//FormAI DATASET v1.0 Category: Data mining ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct node{
    int data;
    struct node* next;
} Node;

typedef struct{
    Node* head;
    Node* tail;
    int size;
} LinkedList;

// Function to create a new node
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the linked list
LinkedList* initializeList(){
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Function to add a node to the list
void addNode(LinkedList* list, int data){
    Node* newNode = createNode(data);
    if(list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
    }
    else{
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

// Function to print the list
void printList(LinkedList* list){
    Node* temp = list->head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Function to find the maximum value in the list
int findMax(LinkedList* list){
    Node* temp = list->head;
    int max = temp->data;
    while(temp != NULL){
        if(temp->data > max){
            max = temp->data;
        }
        temp = temp->next;
    }
    return max;
}

// Function to find the minimum value in the list
int findMin(LinkedList* list){
    Node* temp = list->head;
    int min = temp->data;
    while(temp != NULL){
        if(temp->data < min){
            min = temp->data;
        }
        temp = temp->next;
    }
    return min;
}

// Function to calculate the average value of the list
float findAverage(LinkedList* list){
    Node* temp = list->head;
    int sum = 0;
    while(temp != NULL){
        sum += temp->data;
        temp = temp->next;
    }
    float average = (float)sum / list->size;
    return average;
}

int main(){

    LinkedList* list = initializeList();

    // Add some data to the list
    addNode(list, 10);
    addNode(list, 25);
    addNode(list, 7);
    addNode(list, 18);
    addNode(list, 32);
    addNode(list, 5);

    // Print the list
    printf("The list is: ");
    printList(list);

    // Find the maximum value
    int max = findMax(list);
    printf("\nThe maximum value is: %d", max);

    // Find the minimum value
    int min = findMin(list);
    printf("\nThe minimum value is: %d", min);

    // Find the average value
    float avg = findAverage(list);
    printf("\nThe average value is: %f", avg);

    return 0;
}