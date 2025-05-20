//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define MAX_HOSTS 10
#define MAX_PORTS 64

typedef struct Node {
  char host[MAX_HOSTS];
  int port;
  struct Node* next;
} Node;

void draw_topology(Node* head) {
  while (head) {
    printf("%s:%d ", head->host, head->port);
    if (head->next) {
      printf("-> ");
    } else {
      printf("\n");
    }
    head = head->next;
  }
}

int main() {
  Node* head = NULL;
  Node* tail = NULL;

  // Create a few nodes
  head = malloc(sizeof(Node));
  tail = head;
  tail->host[0] = 'a';
  tail->port = 8080;

  tail = malloc(sizeof(Node));
  tail->host[0] = 'b';
  tail->port = 8081;

  tail = malloc(sizeof(Node));
  tail->host[0] = 'c';
  tail->port = 8082;

  tail->next = NULL;

  // Draw the topology
  draw_topology(head);

  return 0;
}