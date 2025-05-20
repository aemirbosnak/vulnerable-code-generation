//FormAI DATASET v1.0 Category: Data structures visualization ; Style: active
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node **head_ref, int data){
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void print_list(struct node *head){
    struct node *current = head;
    printf("Linked List: ");
    while(current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void delete_head(struct node **head_ref){
    struct node *temp_node = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp_node);
}

void delete_position(struct node **head_ref, int position){
    struct node *current_node = *head_ref;
    struct node *previous_node = NULL;
    for(int i=1; current_node!=NULL && i<position; i++){
        previous_node = current_node;
        current_node = current_node->next;
    }
    previous_node->next = current_node->next;
    free(current_node);
}

int main(){
    struct node *head = NULL;

    insert(&head, 5);
    insert(&head, 7);
    insert(&head, 9);
    insert(&head, 11);
    insert(&head, 13);

    print_list(head);
    delete_head(&head);
    print_list(head);
    delete_position(&head, 3);
    print_list(head);

    return 0;
}