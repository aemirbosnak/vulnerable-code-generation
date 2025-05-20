//FormAI DATASET v1.0 Category: Linked list operations ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

//define the structure of a node
typedef struct node {
    int data;
    struct node *next;
} Node;

//function to create a new node
Node* create_node(int data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

//function to search and return the node with given data
Node* search_node(Node *head, int data) {
    Node *current = head;
    while(current != NULL) {
        if(current->data == data) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

//function to insert a node at the beginning of the list
Node* insert_beginning(Node *head, int data) {
    Node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

//function to insert a node at the end of the list
void insert_end(Node *head, int data) {
    Node *current = head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = create_node(data);
}

//function to insert a node after a given node
void insert_after(Node *head, Node *node, int data) {
    if(node == NULL) {
        printf("Cannot insert after NULL\n");
        return;
    }
    Node *new_node = create_node(data);
    new_node->next = node->next;
    node->next = new_node;
}

//function to delete the first node with given data
Node* delete_node(Node *head, int data) {
    if(head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if(head->data == data) {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *current = head;
    while(current->next != NULL) {
        if(current->next->data == data) {
            Node *temp = current->next;
            current->next = temp->next;
            free(temp);
            return head;
        }
        current = current->next;
    }
    printf("Node with data %d not found\n", data);
    return head;
}

//function to display the linked list
void display_list(Node *head) {
    printf("List: ");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;

    //insert nodes at the beginning
    head = insert_beginning(head, 10);
    head = insert_beginning(head, 20);
    head = insert_beginning(head, 30);

    display_list(head);

    //insert nodes at the end
    insert_end(head, 40);
    insert_end(head, 50);

    display_list(head);

    //insert node after a given node
    Node *node = search_node(head, 20);
    insert_after(head, node, 25);

    display_list(head);

    //delete node with data 30
    head = delete_node(head, 30);

    display_list(head);

    return 0;
}