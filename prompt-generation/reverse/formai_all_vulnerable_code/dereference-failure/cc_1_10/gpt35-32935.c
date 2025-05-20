//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Cyberpunk style Classical Circuit Simulator

typedef struct Node {
   int id;
   int voltage;
   struct Node* next;
} Node;

Node* createNode(int id, int voltage) {
   Node* node = (Node*)malloc(sizeof(Node));
   node->id = id;
   node->voltage = voltage;
   node->next = NULL;
   return node;
}

Node* insertNode(Node* head, Node* node) {
   if (head == NULL) {
      return node;
   }

   Node* temp = head;
   while (temp->next != NULL) {
      temp = temp->next;
   }
   temp->next = node;
   return head;
}

void printNodes(Node* head) {
   printf("Node\tVoltage\n");
   Node* temp = head;
   while (temp != NULL) {
      printf("%d\t%d\n", temp->id, temp->voltage);
      temp = temp->next;
   }
}

int main() {
   Node* head = NULL;

   head = insertNode(head, createNode(1, 12));
   head = insertNode(head, createNode(2, 5));
   head = insertNode(head, createNode(3, 6));
   head = insertNode(head, createNode(4, 8));
   head = insertNode(head, createNode(5, 9));

   printf("<--- Welcome to Cyberpunk Style Classical Circuit Simulator --->\n");
   printf("\nNode Voltages before simulation:\n");
   printNodes(head);

   // Simulate Circuit here!

   printf("\nNode Voltages after simulation:\n");
   printNodes(head);
   
   return 0;
}