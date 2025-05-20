//FormAI DATASET v1.0 Category: Linked list operations ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node node;

node* head = NULL;

// function to insert at the beginning of the list
void insert_beginning(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// function to insert at the end of the list
void insert_end(int data){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL){
        head = newNode;
    }else{
        node* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

// function to insert at a certain position of the list
void insert_position(int data, int position){
    node* temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;

    if (position == 1){
        temp->next = head;
        head = temp;
        return;
    }

    node* current = head;
    for (int i=1; i<position-1; i++){
        current = current->next;
    }

    temp->next = current->next;
    current->next = temp;
}

// function to delete the first element of the list
void delete_beginning(){
    if (head == NULL){
        printf("List is empty!");
        return;
    }

    node* temp = head;
    head = head->next;
    free(temp);
}

// function to delete the last element of the list
void delete_end(){
    if (head == NULL){
        printf("List is empty!");
        return;
    }

    if (head->next == NULL){
        free(head);
        head = NULL;
        return;
    }

    node* current = head;
    while(current->next->next != NULL){
        current = current->next;
    }

    free(current->next);
    current->next = NULL;

}

// function to delete a certain element of the list
void delete_position(int position){
    if (head == NULL){
        printf("List is empty!");
        return;
    }

    if (position == 1){
        node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    node* current = head;
    for (int i=1; i<position-1; i++){
        current = current->next;
    }

    node* temp = current->next;
    current->next = temp->next;
    free(temp);
}

// function to display the list
void display(){
    node* current = head;
    if (head == NULL){
        printf("List is empty!");
        return;
    }

    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}

int main(){
    insert_beginning(10);
    insert_beginning(20);
    insert_beginning(30);
    display();
    printf("\n");

    insert_end(40);
    insert_end(50);
    display();
    printf("\n");

    insert_position(25, 2);
    insert_position(35, 4);
    insert_position(45, 6);
    display();
    printf("\n");

    delete_beginning();
    delete_end();
    delete_position(3);
    display();
    printf("\n");

    return 0;
}