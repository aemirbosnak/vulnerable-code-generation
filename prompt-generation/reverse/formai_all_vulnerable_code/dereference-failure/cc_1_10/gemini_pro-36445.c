//GEMINI-pro DATASET v1.0 Category: Networking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Define some constants
#define PORT 8080
#define MAX_CLIENTS 10

// Create a socket
int create_socket() {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Could not create socket");
    exit(EXIT_FAILURE);
  }
  return sockfd;
}

// Bind the socket to an address and port
void bind_socket(int sockfd) {
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(PORT);
  int bind_status = bind(sockfd, (struct sockaddr *) &addr, sizeof(addr));
  if (bind_status == -1) {
    perror("Could not bind socket");
    exit(EXIT_FAILURE);
  }
}

// Listen for incoming connections
void listen_for_connections(int sockfd) {
  int listen_status = listen(sockfd, MAX_CLIENTS);
  if (listen_status == -1) {
    perror("Could not listen for connections");
    exit(EXIT_FAILURE);
  }
}

// Accept an incoming connection
int accept_connection(int sockfd) {
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);
  int client_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
  if (client_sockfd == -1) {
    perror("Could not accept connection");
    exit(EXIT_FAILURE);
  }
  return client_sockfd;
}

// Send a message to a client
void send_message(int client_sockfd, char *message) {
  int send_status = send(client_sockfd, message, strlen(message), 0);
  if (send_status == -1) {
    perror("Could not send message");
    exit(EXIT_FAILURE);
  }
}

// Receive a message from a client
char *receive_message(int client_sockfd) {
  char *buffer = malloc(1024);
  int receive_status = recv(client_sockfd, buffer, 1024, 0);
  if (receive_status == -1) {
    perror("Could not receive message");
    exit(EXIT_FAILURE);
  }
  return buffer;
}

// Close a socket
void close_socket(int sockfd) {
  int close_status = close(sockfd);
  if (close_status == -1) {
    perror("Could not close socket");
    exit(EXIT_FAILURE);
  }
}

// Main function
int main() {
  // Create a socket
  int sockfd = create_socket();

  // Bind the socket to an address and port
  bind_socket(sockfd);

  // Listen for incoming connections
  listen_for_connections(sockfd);

  // Accept an incoming connection
  int client_sockfd = accept_connection(sockfd);

  // Send a welcome message to the client
  char *welcome_message = "Welcome to the server!\n";
  send_message(client_sockfd, welcome_message);

  // Receive a message from the client
  char *client_message = receive_message(client_sockfd);
  printf("Client message: %s\n", client_message);

  // Close the client socket
  close_socket(client_sockfd);

  // Close the server socket
  close_socket(sockfd);

  return 0;
}