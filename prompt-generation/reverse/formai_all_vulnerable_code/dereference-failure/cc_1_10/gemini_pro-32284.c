//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a node in a linked list
struct node {
char data;
struct node *next;
};

// A function to create a new node
struct node *create_node(char data) {
struct node *new_node = (struct node *)malloc(sizeof(struct node));
new_node->data = data;
new_node->next = NULL;
return new_node;
}

// A function to insert a node at the beginning of a linked list
void insert_at_beginning(struct node **head, char data) {
struct node *new_node = create_node(data);
new_node->next = *head;
*head = new_node;
}

// A function to insert a node at the end of a linked list
void insert_at_end(struct node **head, char data) {
struct node *new_node = create_node(data);
if (*head == NULL) {
*head = new_node;
return;
}

struct node *current = *head;
while (current->next != NULL) {
current = current->next;
}

current->next = new_node;
}

// A function to delete a node from the beginning of a linked list
void delete_from_beginning(struct node **head) {
if (*head == NULL) {
return;
}

struct node *temp = *head;
*head = (*head)->next;
free(temp);
}

// A function to delete a node from the end of a linked list
void delete_from_end(struct node **head) {
if (*head == NULL) {
return;
}

struct node *current = *head;
struct node *previous = NULL;
while (current->next != NULL) {
previous = current;
current = current->next;
}

if (previous == NULL) {
*head = NULL;
} else {
previous->next = NULL;
}

free(current);
}

// A function to print a linked list
void print_list(struct node *head) {
struct node *current = head;
while (current != NULL) {
printf("%c ", current->data);
current = current->next;
}

printf("\n");
}

int main() {
// Create a linked list
struct node *head = NULL;
insert_at_beginning(&head, 'H');
insert_at_beginning(&head, 'e');
insert_at_beginning(&head, 'l');
insert_at_beginning(&head, 'l');
insert_at_beginning(&head, 'o');

// Print the linked list
printf("Original linked list: ");
print_list(head);

// Delete a node from the beginning of the linked list
delete_from_beginning(&head);

// Print the linked list
printf("Linked list after deleting a node from the beginning: ");
print_list(head);

// Delete a node from the end of the linked list
delete_from_end(&head);

// Print the linked list
printf("Linked list after deleting a node from the end: ");
print_list(head);

return 0;
}