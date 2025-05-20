//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netdb.h>

#define MAX_CONN 10
#define MAX_MSG_LEN 1024

typedef struct node {
  struct node* next;
  char name[MAX_MSG_LEN];
  int sockfd;
  int online;
} node;

node* head = NULL;

void add_node(char* name) {
  node* newNode = malloc(sizeof(node));
  newNode->next = head;
  head = newNode;
  strcpy(newNode->name, name);
  newNode->sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
  newNode->online = 1;
}

void remove_node(char* name) {
  node* prev = NULL;
  node* current = head;
  while (current) {
    if (strcmp(current->name, name) == 0) {
      if (prev) {
        prev->next = current->next;
      } else {
        head = current->next;
      }
      close(current->sockfd);
      free(current);
      return;
    }
    prev = current;
    current = current->next;
  }
  return;
}

void send_msg(char* msg, char* to) {
  node* current = head;
  while (current) {
    if (strcmp(current->name, to) == 0 && current->online) {
      send(current->sockfd, msg, strlen(msg), 0);
    }
    current = current->next;
  }
}

int main() {
  add_node("John");
  add_node("Mary");
  add_node("Bob");

  send_msg("Hello, world!", "Mary");

  remove_node("Bob");

  send_msg("How are you?", "John");

  return 0;
}