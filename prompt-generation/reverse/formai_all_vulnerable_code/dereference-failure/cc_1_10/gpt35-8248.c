//FormAI DATASET v1.0 Category: Linked list operations ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert(int value) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
    printf("Adding %d to the linked list.\n", value);
}

void delete(int value) {
    struct node* temp = head;
    struct node* prev = NULL;
    int found = 0;
    
    while (temp != NULL) {
        if (temp->data == value) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            printf("Deleting %d from the linked list.\n", value);
            found = 1;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    
    if (found == 0) {
        printf("%d is not found in the linked list.\n", value);
    }
}

void search(int value) {
    struct node* temp = head;
    int pos = 1;
    int found = 0;
    
    while (temp != NULL) {
        if (temp->data == value) {
            printf("%d is found at position %d in the linked list.\n", value, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }
    
    if (found == 0) {
        printf("%d is not found in the linked list.\n", value);
    }
}

void display() {
    struct node* temp = head;
    printf("The linked list is: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    display();
    delete(20);
    display();
    search(30);
    search(20);
    delete(70);
    return 0;
}