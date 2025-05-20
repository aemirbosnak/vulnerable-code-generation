//GEMINI-pro DATASET v1.0 Category: Networking ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

// Function to handle client connections
void handle_client(int client_socket) {
  // Buffer to receive and send data
  char buf[MAX_BUF_SIZE];

  // Receive data from the client
  recv(client_socket, buf, MAX_BUF_SIZE, 0);

  // Print the received data
  printf("Received: %s\n", buf);

  // Process the received data
  char *msg = "Hello from the server!";
  strcpy(buf, msg);

  // Send the processed data back to the client
  send(client_socket, buf, strlen(buf), 0);

  // Close the client socket
  close(client_socket);
}

int main(int argc, char **argv) {
  // Check if the required arguments are provided
  if (argc != 3) {
    printf("Usage: %s <IP address> <port>\n", argv[0]);
    exit(1);
  }

  // Parse the IP address and port
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);
  server_addr.sin_port = htons(atoi(argv[2]));

  // Create a server socket
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket == -1) {
    perror("Error creating server socket");
    exit(1);
  }

  // Bind the server socket to the specified IP address and port
  if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("Error binding server socket");
    exit(1);
  }

  // Listen for incoming client connections
  if (listen(server_socket, 5) == -1) {
    perror("Error listening for client connections");
    exit(1);
  }

  printf("Server is listening on %s:%d\n", argv[1], atoi(argv[2]));

  // Accept incoming client connections
  while (1) {
    // Accept a client connection
    int client_socket = accept(server_socket, NULL, NULL);
    if (client_socket == -1) {
      perror("Error accepting client connection");
      continue;
    }

    // Create a new thread to handle the client connection
    pid_t pid = fork();
    if (pid == -1) {
      perror("Error creating child process");
      continue;
    }

    if (pid == 0) {
      // Child process handles the client connection
      handle_client(client_socket);
      exit(0);
    }

    // Parent process continues to accept new client connections
  }

  // Close the server socket
  close(server_socket);

  return 0;
}