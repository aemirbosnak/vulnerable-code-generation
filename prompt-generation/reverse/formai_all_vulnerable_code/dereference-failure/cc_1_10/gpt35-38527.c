//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  printf("Oh my gosh, can you believe this? \n");
  
  // Let's start by defining our network topology data structure
  typedef struct node {
    char *name;
    int numConnections;
    struct node **connections;
  } Node;
  
  printf("We're going to create a network topology mapper!\n");
  
  // Let's create some nodes
  Node *a = (Node *) malloc(sizeof(Node));
  a->name = "Node A";
  a->numConnections = 2;
  a->connections = (Node **) malloc(a->numConnections * sizeof(Node *));
  
  Node *b = (Node *) malloc(sizeof(Node));
  b->name = "Node B";
  b->numConnections = 2;
  b->connections = (Node **) malloc(b->numConnections * sizeof(Node *));
  
  Node *c = (Node *) malloc(sizeof(Node));
  c->name = "Node C";
  c->numConnections = 1;
  c->connections = (Node **) malloc(c->numConnections * sizeof(Node *));
  
  Node *d = (Node *) malloc(sizeof(Node));
  d->name = "Node D";
  d->numConnections = 2;
  d->connections = (Node **) malloc(d->numConnections * sizeof(Node *));
  
  Node *e = (Node *) malloc(sizeof(Node));
  e->name = "Node E";
  e->numConnections = 1;
  e->connections = (Node **) malloc(e->numConnections * sizeof(Node *));
  
  Node *f = (Node *) malloc(sizeof(Node));
  f->name = "Node F";
  f->numConnections = 1;
  f->connections = (Node **) malloc(f->numConnections * sizeof(Node *));
  
  printf("We've created some nodes!\n");
  
  // Let's connect the nodes
  
  a->connections[0] = b;
  a->connections[1] = c;
  
  b->connections[0] = d;
  b->connections[1] = e;
  
  c->connections[0] = f;
  
  d->connections[0] = f;
  d->connections[1] = e;
  
  e->connections[0] = f;
  
  printf("We've connected the nodes!\n");
  
  // Let's print out all the nodes and their connections
  
  printf("Here is the network topology:\n");
  printf("%s\n", a->name);
  printf("    %s\n", b->name);
  printf("        %s\n", d->name);
  printf("        %s\n", e->name);
  printf("    %s\n", c->name);
  printf("        %s\n", f->name);

  printf("Wow, that was fun!\n");
  
  return 0;
}