//FormAI DATASET v1.0 Category: Smart home automation ; Style: distributed
//This is an example C program for a smart home automation system which operates in a distributed style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODE_COUNT 4
#define LIGHT_ON 1
#define LIGHT_OFF 0
#define MAX_MSG_SIZE 128

//Defining the node
typedef struct node {
  int id;
  int light_status;
  struct node* next;
} Node;

Node* head = NULL;

//Creating a function to add nodes to our linked list of nodes
void add_node(int id) {
  Node* new_node = (Node*) malloc(sizeof(Node));
  new_node->id = id;
  new_node->light_status = LIGHT_OFF;
  new_node->next = head;
  head = new_node;
}

//Creating a function to turn the light on in a node given its id
void turn_on_light(int node_id) {
  Node* current = head;
  while (current != NULL) {
    if (current->id == node_id) {
      current->light_status = LIGHT_ON;
      printf("Node %d: Light turned ON\n", node_id);
    }
    current = current->next;
  }
}

//Creating a function to turn the light off in a node given its id
void turn_off_light(int node_id) {
  Node* current = head;
  while (current != NULL) {
    if (current->id == node_id) {
      current->light_status = LIGHT_OFF;
      printf("Node %d: Light turned OFF\n", node_id);
    }
    current = current->next;
  }
}

//Creating a function to send a message to a node given its id
void send_message(int sender_id, int receiver_id, char* message) {
  printf("Message from node %d to node %d: %s\n", sender_id, receiver_id, message);
}

//Main function
int main(void) {
  //Adding nodes to our linked list of nodes
  for (int i = 0; i < NODE_COUNT; i++) {
    add_node(i+1);
  }

  //Testing the system by turning lights on and off in different nodes
  turn_on_light(2);
  turn_off_light(4);
  turn_on_light(1);
  turn_off_light(3);

  //Sending messages between nodes
  send_message(1, 2, "Hey, how are you?");
  send_message(2, 4, "Can you turn your light off?");
  send_message(3, 1, "I need your help!");

  return 0;
}