//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX_CONN 10

typedef struct Node {
  int sockfd;
  struct Node* next;
} Node;

void broadcast(Node* head, int data) {
  Node* current = head;
  while (current) {
    write(current->sockfd, &data, sizeof(int));
    current = current->next;
  }
}

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in server_addr, client_addr;
  Node* head = NULL;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket to a port
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for connections
  while (1) {
    // Accept a connection
    newsockfd = accept(sockfd, (struct sockaddr*)&client_addr, NULL);
    if (newsockfd < 0) {
      perror("Error accepting connection");
      continue;
    }

    // Create a new node
    Node* newNode = malloc(sizeof(Node));
    newNode->sockfd = newsockfd;
    newNode->next = NULL;

    // Add the new node to the head of the list
    if (head == NULL) {
      head = newNode;
    } else {
      newNode->next = head;
      head = newNode;
    }

    // Broadcast the data to all clients
    broadcast(head, 10);
  }

  return 0;
}