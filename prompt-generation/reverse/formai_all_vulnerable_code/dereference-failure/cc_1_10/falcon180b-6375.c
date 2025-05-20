//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* newNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void push(Node** head_ref, int new_data){
    Node* new_node = newNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(Node* node){
    while(node!= NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

int search(Node* head, int x){
    Node* current = head;
    while(current!= NULL){
        if(current->data == x)
            return 1;
        current = current->next;
    }
    return 0;
}

void deleteNode(Node **head_ref, int key){
    Node* temp = *head_ref, *prev;

    if(temp!= NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while(temp!= NULL && temp->data!= key){
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

int main(){
    Node* head = NULL;
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 6);
    push(&head, 5);

    printf("Created Linked List: ");
    printList(head);

    int x = 5;
    int pos = search(head, x);
    if(pos == 1)
        printf("\n%d is present in the linked list", x);
    else
        printf("\n%d is not present in the linked list", x);

    deleteNode(&head, 1);
    printf("\nLinked List after deleting 1: ");
    printList(head);

    deleteNode(&head, 6);
    printf("\nLinked List after deleting 6: ");
    printList(head);

    return 0;
}