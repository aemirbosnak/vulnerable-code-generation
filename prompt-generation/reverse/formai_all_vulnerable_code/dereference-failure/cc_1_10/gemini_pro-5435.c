//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum number of clients that can connect to the server
#define MAX_CLIENTS 10

// Define the maximum length of a message that can be sent by a client
#define MAX_MESSAGE_LENGTH 1024

// Create a structure to represent a client
typedef struct client {
  int socket_fd;
  char username[16];
} client;

// Create an array of clients to store the connected clients
client clients[MAX_CLIENTS];

// Create a socket for the server to listen on
int create_server_socket(int port) {
  int server_socket;
  struct sockaddr_in server_address;

  // Create a socket for the server
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("Error creating server socket");
    exit(1);
  }

  // Set the server address
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port);
  server_address.sin_addr.s_addr = INADDR_ANY;

  // Bind the socket to the server address
  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("Error binding server socket to address");
    exit(1);
  }

  // Listen for connections on the server socket
  if (listen(server_socket, MAX_CLIENTS) == -1) {
    perror("Error listening on server socket");
    exit(1);
  }

  return server_socket;
}

// Accept a connection from a client
int accept_client(int server_socket) {
  int client_socket;
  struct sockaddr_in client_address;
  socklen_t client_address_length;

  // Accept a connection from a client
  client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
  if (client_socket == -1) {
    perror("Error accepting client connection");
    exit(1);
  }

  // Return the client socket
  return client_socket;
}

// Add a client to the array of clients
void add_client(client client) {
  // Find the first empty slot in the array of clients
  int i;
  for (i = 0; i < MAX_CLIENTS; i++) {
    if (clients[i].socket_fd == -1) {
      break;
    }
  }

  // If there is no empty slot, print an error message and exit
  if (i == MAX_CLIENTS) {
    printf("Error: Maximum number of clients reached\n");
    exit(1);
  }

  // Add the client to the array of clients
  clients[i] = client;
}

// Remove a client from the array of clients
void remove_client(int client_socket) {
  // Find the client in the array of clients
  int i;
  for (i = 0; i < MAX_CLIENTS; i++) {
    if (clients[i].socket_fd == client_socket) {
      break;
    }
  }

  // If the client is not found, print an error message and exit
  if (i == MAX_CLIENTS) {
    printf("Error: Client not found\n");
    exit(1);
  }

  // Remove the client from the array of clients
  clients[i].socket_fd = -1;
}

// Send a message to all clients
void send_message_to_all_clients(char *message) {
  // Iterate through the array of clients and send the message to each client
  int i;
  for (i = 0; i < MAX_CLIENTS; i++) {
    if (clients[i].socket_fd != -1) {
      send(clients[i].socket_fd, message, strlen(message), 0);
    }
  }
}

// Main function
int main(int argc, char **argv) {
  // Check if the number of arguments is correct
  if (argc != 2) {
    printf("Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  // Get the port number from the command line arguments
  int port = atoi(argv[1]);

  // Create a server socket
  int server_socket = create_server_socket(port);

  // Main loop
  while (1) {
    // Accept a connection from a client
    int client_socket = accept_client(server_socket);

    // Get the username of the client
    char username[16];
    recv(client_socket, username, sizeof(username), 0);

    // Add the client to the array of clients
    client client;
    client.socket_fd = client_socket;
    strcpy(client.username, username);
    add_client(client);

    // Send a message to all clients to welcome the new client
    char message[MAX_MESSAGE_LENGTH];
    sprintf(message, "%s has joined the chat!\n", username);
    send_message_to_all_clients(message);

    // Loop until the client disconnects
    while (1) {
      // Receive a message from the client
      char message[MAX_MESSAGE_LENGTH];
      int num_bytes_received = recv(client_socket, message, sizeof(message), 0);

      // If the client has disconnected, remove them from the array of clients
      if (num_bytes_received == 0) {
        remove_client(client_socket);
        break;
      }

      // Send the message to all clients
      sprintf(message, "%s: %s\n", username, message);
      send_message_to_all_clients(message);
    }
  }

  // Close the server socket
  close(server_socket);

  return 0;
}