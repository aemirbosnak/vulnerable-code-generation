//FormAI DATASET v1.0 Category: Linked list operations ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert_at_end(struct node** head_ref, int new_data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}

void reverse(struct node** head_ref){
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next = NULL;
    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void display_list(struct node* node){
    while (node != NULL){
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(){
    struct node* head = NULL;
    insert_at_end(&head, 10);
    insert_at_end(&head, 20);
    insert_at_end(&head, 30);
    insert_at_end(&head, 40);
    printf("Original linked list: ");
    display_list(head);
    reverse(&head);
    printf("\nReversed linked list: ");
    display_list(head);
    return 0;
}