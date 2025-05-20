//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

// Define the maximum number of clients
#define MAX_CLIENTS 100

// Create a structure to hold client information
typedef struct {
  int socket;
  char name[256];
} client_t;

// Create an array of clients
client_t clients[MAX_CLIENTS];

// Create a mutex to protect the client array
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

// Create a function to handle client connections
void* handle_client(void* arg) {
  int client_socket = *(int*)arg;
  char buffer[256];

  // Receive the client's name
  recv(client_socket, buffer, sizeof(buffer), 0);
  strcpy(clients[client_socket].name, buffer);

  // Send a welcome message to the client
  sprintf(buffer, "Welcome to the chat server, %s!", clients[client_socket].name);
  send(client_socket, buffer, strlen(buffer), 0);

  // Loop until the client disconnects
  while (1) {
    // Receive a message from the client
    recv(client_socket, buffer, sizeof(buffer), 0);

    // Check if the client has disconnected
    if (strcmp(buffer, "quit") == 0) {
      break;
    }

    // Send the message to all other clients
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < MAX_CLIENTS; i++) {
      if (clients[i].socket != client_socket && clients[i].socket != -1) {
        sprintf(buffer, "%s: %s", clients[client_socket].name, buffer);
        send(clients[i].socket, buffer, strlen(buffer), 0);
      }
    }
    pthread_mutex_unlock(&clients_mutex);
  }

  // Close the client's socket
  close(client_socket);

  // Remove the client from the array
  pthread_mutex_lock(&clients_mutex);
  clients[client_socket].socket = -1;
  pthread_mutex_unlock(&clients_mutex);

  return NULL;
}

int main(int argc, char** argv) {
  int server_socket, client_socket;
  struct sockaddr_in server_address, client_address;
  socklen_t client_address_len;
  pthread_t client_thread;

  // Create the server socket
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    return 1;
  }

  // Set the server address
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(5000);
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);

  // Bind the server socket to the address
  if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
    perror("bind");
    return 1;
  }

  // Listen for client connections
  if (listen(server_socket, 5) == -1) {
    perror("listen");
    return 1;
  }

  // Accept client connections
  while (1) {
    client_address_len = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_len);
    if (client_socket == -1) {
      perror("accept");
      continue;
    }

    // Create a new thread to handle the client connection
    if (pthread_create(&client_thread, NULL, handle_client, &client_socket) != 0) {
      perror("pthread_create");
      close(client_socket);
      continue;
    }
  }

  // Close the server socket
  close(server_socket);

  return 0;
}