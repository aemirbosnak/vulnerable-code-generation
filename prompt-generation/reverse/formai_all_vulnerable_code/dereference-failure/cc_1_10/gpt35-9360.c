//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Define a structure to hold information about a node */
typedef struct node {
   char label[20];       // Name of the node
   char ip[16];          // IP address of the node
   struct node* next;    // Pointer to next node in network topology
} node_t;

/* Define a function to add a new node to the network topology */
void add_node(node_t** head, char* label, char* ip) {
   // Allocate memory for a new node
   node_t* new_node = (node_t*)malloc(sizeof(node_t));
   
   // Copy label and IP address to the new node
   strncpy(new_node->label, label, 20);
   strncpy(new_node->ip, ip, 16);
   
   // Insert new node at the beginning of the linked list
   new_node->next = *head;
   *head = new_node;
}

/* Define a function to print the network topology */
void print_topology(node_t* head) {
   node_t* curr = head;
   
   while (curr != NULL) {
      printf("%s (%s) -> ", curr->label, curr->ip);
      curr = curr->next;
   }
   
   printf("NULL\n");
}

int main() {
   // Declare a pointer to the head of the linked list
   node_t* head = NULL;
   
   // Add some nodes to the network topology
   add_node(&head, "Router", "192.168.1.1");
   add_node(&head, "Switch 1", "192.168.1.2");
   add_node(&head, "Switch 2", "192.168.1.3");
   add_node(&head, "Server", "192.168.1.4");
   add_node(&head, "Desktop 1", "192.168.1.5");
   add_node(&head, "Desktop 2", "192.168.1.6");
   
   // Print the network topology
   print_topology(head);
   
   return 0;
}