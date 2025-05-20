//Gemma-7B DATASET v1.0 Category: Wireless Network Scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080

struct ss_node {
  char ss_name[256];
  struct ss_node* next;
};

struct ss_node* head = NULL;

void add_node(char* ss_name) {
  struct ss_node* new_node = malloc(sizeof(struct ss_node));
  strcpy(new_node->ss_name, ss_name);
  new_node->next = head;
  head = new_node;
}

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in serv_addr, client_addr;
  char buffer[1024];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
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

    // Receive data
    recv(newsockfd, buffer, 1024, 0);

    // Process data
    char* ss_name = buffer;
    add_node(ss_name);

    // Send data
    send(newsockfd, buffer, 1024, 0);

    // Close the connection
    close(newsockfd);
  }

  return 0;
}