//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10

typedef struct node {
    char data[10];
    struct node* next;
} funny_node;

funny_node* create_node(const char* funny_data) {
    funny_node* new_node = (funny_node*) malloc(sizeof(funny_node));
    strcpy(new_node->data, funny_data);
    new_node->next = NULL;
    return new_node;
}

funny_node* insert_at_beginning(funny_node* head, funny_node* new_node) {
    new_node->next = head;
    head = new_node;
    return head;
}

funny_node* insert_at_end(funny_node* head, funny_node* new_node) {
    if (head == NULL) {
        head = new_node;
        return head;
    }

    funny_node* last = head;
    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return head;
}

void print_list(funny_node* head) {
    funny_node* current = head;
    printf("The funny list goes: \n");
    while (current != NULL) {
        printf("%s -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    funny_node* head = NULL;

    // Inserting some funny data into the list
    head = insert_at_beginning(head, create_node("Why the chicken crossed the road?"));
    head = insert_at_end(head, create_node("To get to the other side, my dear interlocutor!"));
    head = insert_at_end(head, create_node("For an existentialist reason!"));
    head = insert_at_beginning(head, create_node("Mmmm... Chicken! Let me have a bite!"));

    // Printing the list
    print_list(head);

    // Freeing memory
    funny_node* current = head;
    while (current != NULL) {
        funny_node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}