//FormAI DATASET v1.0 Category: Linked list operations ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert(struct node** head, int value){
    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->data = value;
    temp->next = NULL;
    if(*head == NULL){
        *head = temp;
    }
    else{
        struct node* current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = temp;
    }
}

void display(struct node* head){
    printf("List: ");
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void delete(struct node** head, int value){
    struct node* temp = *head;
    struct node* previous = NULL;
    if(temp != NULL && temp->data == value){
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != value){
        previous = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Value not found\n");
        return;
    }
    previous->next = temp->next;
    free(temp);
}

int count(struct node* head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}

int main(){
    struct node* head = NULL;
    
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);
    
    display(head);
    
    delete(&head, 3);
    
    display(head);
    
    int list_size = count(head);
    printf("List size: %d\n", list_size);
    
    return 0;
}