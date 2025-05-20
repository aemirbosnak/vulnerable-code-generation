//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* createLinkedList(int size){
    Node* head = NULL;
    Node* temp = NULL;
    int i;
    srand(time(NULL));
    for(i=0;i<size;i++){
        temp = (Node*)malloc(sizeof(Node));
        temp->data = rand()%100;
        temp->next = NULL;
        if(head == NULL){
            head = temp;
        }
        else{
            Node* current = head;
            while(current->next!= NULL){
                current = current->next;
            }
            current->next = temp;
        }
    }
    return head;
}

void printLinkedList(Node* head){
    Node* current = head;
    while(current!= NULL){
        printf("%d -> ",current->data);
        current = current->next;
    }
    printf("NULL");
}

void reverseLinkedList(Node** head){
    Node* prev = NULL;
    Node* current = *head;
    while(current!= NULL){
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main(){
    int size;
    printf("Enter the size of the linked list: ");
    scanf("%d",&size);
    Node* head = createLinkedList(size);
    printf("\nOriginal Linked List:\n");
    printLinkedList(head);
    reverseLinkedList(&head);
    printf("\nReversed Linked List:\n");
    printLinkedList(head);
    return 0;
}