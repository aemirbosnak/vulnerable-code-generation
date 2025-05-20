//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_CLIENTS 10

struct Client {
  char name[20];
  int account_no;
  double balance;
  struct Client* next;
};

struct Client* insertClient(struct Client* head, char* name, int account_no, double balance) {
  struct Client* newNode = (struct Client*)malloc(sizeof(struct Client));
  strcpy(newNode->name, name);
  newNode->account_no = account_no;
  newNode->balance = balance;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    struct Client* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  return head;
}

int main() {
  int server_socket, client_socket, num_clients = 0;
  struct Client* head = NULL;

  // Create a socket
  server_socket = socket(AF_INET, SOCK_STREAM, htons(65535));

  // Listen for clients
  while (1) {
    client_socket = accept(server_socket, NULL, NULL);

    // Insert client into the list
    insertClient(head, "Client", num_clients, 1000);
    num_clients++;

    // Close client socket
    close(client_socket);
  }

  return 0;
}