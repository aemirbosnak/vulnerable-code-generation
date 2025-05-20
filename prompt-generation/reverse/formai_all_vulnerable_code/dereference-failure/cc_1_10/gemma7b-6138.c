//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_CONN 5
#define SERVER_PORT 8080

struct Node {
  char name[20];
  struct Node* next;
  int sockfd;
  struct sockaddr_in sockaddr;
};

struct Node* head = NULL;

void addNode(char* name) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  strcpy(newNode->name, name);
  newNode->next = head;
  head = newNode;
  newNode->sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
  newNode->sockaddr.sin_family = AF_INET;
  newNode->sockaddr.sin_port = htons(SERVER_PORT);
  bind(newNode->sockfd, (struct sockaddr*)&newNode->sockaddr, sizeof(struct sockaddr_in));
}

int main() {
  addNode("Alice");
  addNode("Bob");
  addNode("Charlie");
  addNode("Dave");
  addNode("Eve");

  struct Node* current = head;
  while (current) {
    printf("%s is connected to ", current->name);
    struct Node* next = current->next;
    while (next) {
      printf("%s ", next->name);
      next = next->next;
    }
    printf("\n");
    current = current->next;
  }

  return 0;
}