//FormAI DATASET v1.0 Category: Chat server ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

// Struct to represent a client connection
struct Client {
  int socket;
  struct sockaddr_in address;
  socklen_t addr_len;
};

// Forward declaration of the thread function
void *handle_client(void *client_socket);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Parse the port number
  int port = atoi(argv[1]);

  // Create a socket
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("Failed to create socket");
    exit(EXIT_FAILURE);
  }

  // Set socket options to enable reuse of the address and port
  int reuse = 1;
  if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1) {
    perror("Failed to set socket options");
    exit(EXIT_FAILURE);
  }

  // Bind the socket to the port
  struct sockaddr_in address = {
    .sin_family = AF_INET,
    .sin_addr.s_addr = INADDR_ANY,
    .sin_port = htons(port)
  };
  if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) == -1) {
    perror("Failed to bind to port");
    exit(EXIT_FAILURE);
  }

  // Start listening for incoming connections
  if (listen(server_socket, 10) == -1) {
    perror("Failed to listen for connections");
    exit(EXIT_FAILURE);
  }

  // Print a message indicating that the server is running
  printf("Server is listening on port %d...\n", port);

  // Start accepting client connections
  int client_socket;
  struct sockaddr_in client_address;
  socklen_t client_addr_len = sizeof(client_address);
  pthread_t thread;

  while ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_addr_len))) {
    struct Client *client = malloc(sizeof(struct Client));
    client->socket = client_socket;
    client->address = client_address;
    client->addr_len = client_addr_len;

    // Create a thread to handle the client connection
    if (pthread_create(&thread, NULL, handle_client, (void *)client) == -1) {
      perror("Failed to create thread");
      exit(EXIT_FAILURE);
    }

    // Detach the thread so that it can run independently of the main thread
    if (pthread_detach(thread) == -1) {
      perror("Failed to detach thread");
      exit(EXIT_FAILURE);
    }
  }

  // Close the server socket
  close(server_socket);

  return 0;
}

void *handle_client(void *args) {
  struct Client *client = (struct Client *)args;
  int client_socket = client->socket;

  // Print a message indicating that a new client has connected
  char *client_address = inet_ntoa(client->address.sin_addr);
  printf("Client connected: %s\n", client_address);

  // Send a welcome message to the client
  char *message = "Welcome to the chat server! Type \"exit\" to quit.\n";
  if (send(client_socket, message, strlen(message), 0) == -1) {
    perror("Failed to send welcome message");
    close(client_socket);
    return NULL;
  }

  // Receive messages from the client
  char buffer[BUFFER_SIZE];
  ssize_t recv_size;

  while ((recv_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
    // Null-terminate the received data
    buffer[recv_size] = '\0';

    if (strncmp(buffer, "exit", 4) == 0) {
      // If the client sent "exit", close the connection and break out of the loop
      printf("Client disconnected: %s\n", client_address);
      break;
    } else {
      // If the client sent anything else, broadcast the message to all other clients
      printf("%s: %s\n", client_address, buffer);

      // TODO: Implement broadcast function
    }
  }

  // Close the client socket and free the client struct
  close(client_socket);
  free(client);

  return NULL;
}