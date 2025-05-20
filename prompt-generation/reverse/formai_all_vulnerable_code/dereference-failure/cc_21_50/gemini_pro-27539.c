//GEMINI-pro DATASET v1.0 Category: Educational ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10
#define MAX_NAME_LENGTH 20

typedef struct {
  int socket;
  char name[MAX_NAME_LENGTH];
} Client;

int main(int argc, char *argv[]) {
  // Parse command line arguments
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <port> <name>\n", argv[0]);
    return 1;
  }

  int port = atoi(argv[1]);
  char *name = argv[2];

  // Create the server socket
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("socket");
    return 1;
  }

  // Bind the server socket to the specified port
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  server_addr.sin_port = htons(port);

  if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("bind");
    return 1;
  }

  // Listen for incoming connections
  if (listen(server_socket, MAX_CLIENTS) == -1) {
    perror("listen");
    return 1;
  }

  // Initialize the clients array
  Client clients[MAX_CLIENTS];
  for (int i = 0; i < MAX_CLIENTS; i++) {
    clients[i].socket = -1;
    strcpy(clients[i].name, "");
  }

  // Main game loop
  while (1) {
    // Accept incoming connections
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(server_socket, &read_fds);

    for (int i = 0; i < MAX_CLIENTS; i++) {
      if (clients[i].socket != -1) {
        FD_SET(clients[i].socket, &read_fds);
      }
    }

    int activity = select(FD_SETSIZE, &read_fds, NULL, NULL, NULL);
    if (activity < 0) {
      perror("select");
      return 1;
    }

    // Handle new connections
    if (FD_ISSET(server_socket, &read_fds)) {
      int new_socket = accept(server_socket, NULL, NULL);
      if (new_socket == -1) {
        perror("accept");
        continue;
      }

      // Find an empty slot for the new client
      int empty_slot = -1;
      for (int i = 0; i < MAX_CLIENTS; i++) {
        if (clients[i].socket == -1) {
          empty_slot = i;
          break;
        }
      }

      if (empty_slot == -1) {
        // Server is full, send a message to the client
        char *message = "Server is full, please try again later.\n";
        send(new_socket, message, strlen(message), 0);
        close(new_socket);
        continue;
      }

      // Add the new client to the clients array
      clients[empty_slot].socket = new_socket;
      strcpy(clients[empty_slot].name, name);

      // Send a welcome message to the new client
      char *welcome_message = "Welcome to the server!\n";
      send(new_socket, welcome_message, strlen(welcome_message), 0);
      printf("%s has joined the server.\n", clients[empty_slot].name);
    }

    // Handle data from existing clients
    for (int i = 0; i < MAX_CLIENTS; i++) {
      if (clients[i].socket != -1 && FD_ISSET(clients[i].socket, &read_fds)) {
        char buffer[256];
        int bytes_received = recv(clients[i].socket, buffer, sizeof(buffer), 0);

        if (bytes_received == 0) {
          // Client has disconnected
          printf("%s has disconnected from the server.\n", clients[i].name);
          close(clients[i].socket);
          clients[i].socket = -1;
          strcpy(clients[i].name, "");
          continue;
        } else if (bytes_received < 0) {
          // Error while receiving data
          perror("recv");
          continue;
        }

        // Process the received data
        char *message = buffer;
        if (strncmp(message, "/quit", 5) == 0) {
          // Client wants to quit
          send(clients[i].socket, "Goodbye!\n", strlen("Goodbye!\n"), 0);
          close(clients[i].socket);
          clients[i].socket = -1;
          strcpy(clients[i].name, "");
          printf("%s has left the server.\n", clients[i].name);
        } else {
          // Broadcast the message to all other clients
          char *broadcast_message = malloc(strlen(clients[i].name) + strlen(message) + 2);
          sprintf(broadcast_message, "%s: %s", clients[i].name, message);

          for (int j = 0; j < MAX_CLIENTS; j++) {
            if (clients[j].socket != -1 && i != j) {
              send(clients[j].socket, broadcast_message, strlen(broadcast_message), 0);
            }
          }
          free(broadcast_message);
        }
      }
    }
  }

  // Close the server socket
  close(server_socket);

  return 0;
}