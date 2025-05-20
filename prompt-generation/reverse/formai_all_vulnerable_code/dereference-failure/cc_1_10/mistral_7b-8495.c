//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct Node {
 int data;
 char name[20];
 struct Node* next;
} Node;

Node* create_node(int data, char* name) {
 Node* new_node = (Node*)malloc(sizeof(Node));
 new_node->data = data;
 strcpy(new_node->name, name);
 new_node->next = NULL;
 return new_node;
}

Node* add_node(Node* head, Node* new_node) {
 Node* current = head;
 while(current->next != NULL) {
 current = current->next;
 }
 current->next = new_node;
 return head;
}

void print_list(Node* head) {
 Node* current = head;
 printf("Hey there buddy, let me introduce you to our Linked List!\n");
 while(current != NULL) {
 printf("Name: %s, Data: %d\n", current->name, current->data);
 current = current->next;
 sleep(1); // Just to make it funnier
 }
}

int main() {
 Node* head = NULL;
 Node* new_node1 = create_node(1, "One");
 Node* new_node2 = create_node(2, "Two");
 Node* new_node3 = create_node(3, "Three");

 head = add_node(head, new_node1);
 head = add_node(head, new_node2);
 head = add_node(head, new_node3);

 print_list(head);

 return 0;
}