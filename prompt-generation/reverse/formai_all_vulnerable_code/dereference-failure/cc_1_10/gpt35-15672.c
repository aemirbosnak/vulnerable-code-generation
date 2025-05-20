//FormAI DATASET v1.0 Category: Data structures visualization ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* Function to generate a random number */
int random_number() {
    int random;
    srand(time(NULL));
    random = rand() % 100;
    return random;
}

/* Definition of the node */
struct node {
    int value;
    struct node *next;
};

/* Function to create a new node */
struct node *create_node() {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->value = random_number();
    temp->next = NULL;
    return temp;
}

/* Function to print the linked list */
void print_list(struct node *head) {
    struct node *current = head;
    while(current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
}

/* Function to insert a node at the front of the linked list */
void insert_front(struct node **head_ref) {
    struct node *new_node = create_node();
    new_node->next = *head_ref;
    *head_ref = new_node;
}

/* Function to insert a node at the end of the linked list */
void insert_end(struct node **head_ref) {
    struct node *current = *head_ref;
    struct node *new_node = create_node();
    if(*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

/* Function to delete a node from the linked list */
void delete_node(struct node **head_ref, int key) {
    struct node *temp = *head_ref, *prev;
    if(temp != NULL && temp->value == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->value != key) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

int main() {
    struct node *head = NULL;
    int i, num_nodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    for(i = 0; i < num_nodes; i++) {
        insert_end(&head);
    }
    printf("The linked list is: ");
    print_list(head);
    delete_node(&head, head->value);
    printf("\nThe linked list after deleting the first node is: ");
    print_list(head);
    delete_node(&head, head->next->value);
    printf("\nThe linked list after deleting the second node is: ");
    print_list(head);
    delete_node(&head, head->next->next->value);
    printf("\nThe linked list after deleting the third node is: ");
    print_list(head);
    return 0;
}