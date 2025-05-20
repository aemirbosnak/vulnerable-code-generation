//FormAI DATASET v1.0 Category: Linked list operations ; Style: innovative
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void insert_at_beginning(struct Node **head_ref, int val){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insert_at_end(struct Node **head_ref, int val){
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = NULL;
    
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    
    struct Node *last_node = *head_ref;
    while(last_node->next != NULL){
        last_node = last_node->next;
    }
    
    last_node->next = new_node;
}

void insert_after_node(struct Node *prev_node, int val){
    if(prev_node == NULL){
        printf("Previous node cannot be NULL.\n");
        return;
    }
    
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void delete_node(struct Node **head_ref, int key){
    struct Node *temp = *head_ref, *prev_node;
    
    if(temp != NULL && temp->data == key){
        *head_ref = temp->next;
        free(temp);
        return;
    }
    
    while(temp != NULL && temp->data != key){
        prev_node = temp;
        temp = temp->next;
    }
    
    if(temp == NULL){
        printf("Node with value %d not found.\n", key);
        return;
    }
    
    prev_node->next = temp->next;
    free(temp);
}

void print_list(struct Node *head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    struct Node *head = NULL;
    insert_at_end(&head, 10);
    insert_at_beginning(&head, 20);
    insert_at_end(&head, 30);
    insert_after_node(head->next, 40);
    insert_at_end(&head, 50);
    
    printf("Linked List: ");
    print_list(head);
    
    delete_node(&head, 20);
    delete_node(&head, 30);
    
    printf("Linked List after deletion: ");
    print_list(head);
    
    return 0;
}