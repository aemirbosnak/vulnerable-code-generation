//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insertNode(struct node** head_ref, int new_data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    printf("New node with value %d inserted\n", new_data);
}

void deleteNode(struct node** head_ref, int key){
    struct node* temp = *head_ref;
    if(temp!= NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        printf("Node with value %d deleted\n", key);
    }
    else{
        while(temp!= NULL && temp->data!= key){
            temp = temp->next;
        }
        if(temp == NULL){
            printf("Node with value %d not found\n", key);
        }
        else{
            struct node* node = temp->next;
            temp->next = node->next;
            free(node);
            printf("Node with value %d deleted\n", key);
        }
    }
}

void searchNode(struct node* head, int key){
    struct node* current = head;
    while(current!= NULL){
        if(current->data == key){
            printf("Node with value %d found\n", key);
            return;
        }
        current = current->next;
    }
    printf("Node with value %d not found\n", key);
}

void displayList(struct node* head){
    struct node* current = head;
    while(current!= NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    struct node* head = NULL;
    insertNode(&head, 5);
    insertNode(&head, 4);
    insertNode(&head, 3);
    insertNode(&head, 2);
    insertNode(&head, 1);
    displayList(head);
    searchNode(head, 4);
    deleteNode(&head, 3);
    displayList(head);
    searchNode(head, 3);
    return 0;
}