//Gemma-7B DATASET v1.0 Category: Interprocess communication ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 10

struct ClientInfo {
  int clientSocket;
  char clientName[20];
  struct ClientInfo* nextClient;
};

struct ClientInfo* headClient = NULL;

void addClient(int clientSocket, char* clientName) {
  struct ClientInfo* newClient = (struct ClientInfo*)malloc(sizeof(struct ClientInfo));
  newClient->clientSocket = clientSocket;
  strcpy(newClient->clientName, clientName);
  newClient->nextClient = headClient;
  headClient = newClient;
}

void broadcastMessage(char* message) {
  struct ClientInfo* currentClient = headClient;
  while (currentClient) {
    if (currentClient->clientSocket != -1) {
      send(currentClient->clientSocket, message, strlen(message), 0);
    }
    currentClient = currentClient->nextClient;
  }
}

int main() {
  int serverSocket, clientSocket;
  char message[256];
  struct ClientInfo* clientList = NULL;

  // Create a socket
  serverSocket = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));

  // Listen for clients
  while (1) {
    clientSocket = accept(serverSocket, NULL, NULL);
    char clientName[20];
    printf("Client connected: %s\n", clientName);
    addClient(clientSocket, clientName);
  }

  // Broadcast a message to all clients
  broadcastMessage("Hello, world!");

  // Close the server socket
  close(serverSocket);

  return 0;
}