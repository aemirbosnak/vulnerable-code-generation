//GEMINI-pro DATASET v1.0 Category: Performance-Critical Component ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of nodes in the network
#define MAX_NODES 100

// Define the message types
typedef enum {
  MSG_TYPE_JOIN,
  MSG_TYPE_LEAVE,
  MSG_TYPE_DATA
} msg_type_t;

// Define the message structure
typedef struct {
  msg_type_t type;
  int src;
  int dst;
  char data[1024];
} msg_t;

// Define the node structure
typedef struct {
  int id;
  int num_neighbors;
  int neighbors[MAX_NODES];
  int num_messages;
  msg_t messages[MAX_NODES];
} node_t;

// Create a new node
node_t *create_node(int id) {
  node_t *node = malloc(sizeof(node_t));
  node->id = id;
  node->num_neighbors = 0;
  node->num_messages = 0;
  return node;
}

// Add a neighbor to a node
void add_neighbor(node_t *node, int neighbor) {
  node->neighbors[node->num_neighbors++] = neighbor;
}

// Send a message from one node to another
void send_message(node_t *src, node_t *dst, msg_type_t type, char *data) {
  msg_t msg;
  msg.type = type;
  msg.src = src->id;
  msg.dst = dst->id;
  strcpy(msg.data, data);
  dst->messages[dst->num_messages++] = msg;
}

// Process messages for a node
void process_messages(node_t *node) {
  for (int i = 0; i < node->num_messages; i++) {
    msg_t msg = node->messages[i];
    switch (msg.type) {
      case MSG_TYPE_JOIN:
        // Add the source node as a neighbor
        add_neighbor(node, msg.src);
        break;
      case MSG_TYPE_LEAVE:
        // Remove the source node as a neighbor
        for (int j = 0; j < node->num_neighbors; j++) {
          if (node->neighbors[j] == msg.src) {
            node->neighbors[j] = node->neighbors[node->num_neighbors - 1];
            node->num_neighbors--;
            break;
          }
        }
        break;
      case MSG_TYPE_DATA:
        // Print the message data
        printf("Node %d received message from node %d: %s\n", node->id, msg.src, msg.data);
        break;
    }
  }
  node->num_messages = 0;
}

// Main function
int main() {
  // Create a network of nodes
  node_t *nodes[MAX_NODES];
  for (int i = 0; i < MAX_NODES; i++) {
    nodes[i] = create_node(i);
  }

  // Add neighbors to each node
  for (int i = 0; i < MAX_NODES; i++) {
    for (int j = i + 1; j < MAX_NODES; j++) {
      add_neighbor(nodes[i], j);
      add_neighbor(nodes[j], i);
    }
  }

  // Send messages between nodes
  for (int i = 0; i < MAX_NODES; i++) {
    for (int j = i + 1; j < MAX_NODES; j++) {
      char data[1024];
      sprintf(data, "Hello from node %d to node %d", i, j);
      send_message(nodes[i], nodes[j], MSG_TYPE_DATA, data);
    }
  }

  // Process messages for each node
  for (int i = 0; i < MAX_NODES; i++) {
    process_messages(nodes[i]);
  }

  // Free the nodes
  for (int i = 0; i < MAX_NODES; i++) {
    free(nodes[i]);
  }

  return 0;
}