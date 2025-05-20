//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ClientState {
  char username[256];
  char password[256];
  char hostname[256];
  char filename[256];
  int socketfd;
  struct ClientState *next;
} ClientState;

ClientState *head = NULL;

void addClientState(char *username, char *password, char *hostname, char *filename) {
  ClientState *newState = malloc(sizeof(ClientState));
  strcpy(newState->username, username);
  strcpy(newState->password, password);
  strcpy(newState->hostname, hostname);
  strcpy(newState->filename, filename);
  newState->socketfd = -1;
  newState->next = NULL;

  if (head == NULL) {
    head = newState;
  } else {
    ClientState *prevState = head;
    while (prevState->next) {
      prevState = prevState->next;
    }
    prevState->next = newState;
  }
}

int main() {
  addClientState("donald", "knuth", "localhost", "my-file.txt");
  addClientState("john", "doe", "localhost", "another-file.txt");

  ClientState *state = head;
  while (state) {
    printf("Username: %s, Password: %s, Hostname: %s, Filename: %s\n", state->username, state->password, state->hostname, state->filename);
    state = state->next;
  }

  return 0;
}