//Falcon2-11B DATASET v1.0 Category: Greedy Algorithms ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(struct node** head_ref, int data) {
    struct node* new_node = create_node(data);
    struct node* temp = *head_ref;
    while(temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void print_list(struct node* head) {
    struct node* temp = head;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    print_list(head); // Output: 1 2 3
    
    insert_node(&head, 4);
    print_list(head); // Output: 1 2 3 4
    
    insert_node(&head, 5);
    print_list(head); // Output: 1 2 3 4 5
    
    insert_node(&head, 6);
    print_list(head); // Output: 1 2 3 4 5 6
    
    insert_node(&head, 7);
    print_list(head); // Output: 1 2 3 4 5 6 7
    
    return 0;
}