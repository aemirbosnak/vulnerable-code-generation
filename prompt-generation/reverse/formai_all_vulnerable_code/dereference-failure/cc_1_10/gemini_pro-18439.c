//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CONNECTIONS 5
#define BUFFER_SIZE 1024

// Create a socket
int create_socket() {
  int sockfd;
  struct sockaddr_in serv_addr;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Set the server address
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(PORT);

  // Bind the socket to the server address
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen for connections
  if (listen(sockfd, MAX_CONNECTIONS) == -1) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

  return sockfd;
}

// Accept a connection
int accept_connection(int sockfd) {
  int newsockfd;
  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);

  // Accept a connection
  newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
  if (newsockfd == -1) {
    perror("accept failed");
    exit(EXIT_FAILURE);
  }

  return newsockfd;
}

// Receive a message
char *receive_message(int sockfd) {
  char *buffer = malloc(BUFFER_SIZE);
  int n;

  // Receive a message
  n = read(sockfd, buffer, BUFFER_SIZE);
  if (n == -1) {
    perror("read failed");
    exit(EXIT_FAILURE);
  }

  return buffer;
}

// Send a message
void send_message(int sockfd, char *message) {
  int n;

  // Send a message
  n = write(sockfd, message, strlen(message));
  if (n == -1) {
    perror("write failed");
    exit(EXIT_FAILURE);
  }
}

// Close a connection
void close_connection(int sockfd) {
  // Close the connection
  close(sockfd);
}

// Main function
int main() {
  int sockfd, newsockfd;
  char *message;

  // Create a socket
  sockfd = create_socket();

  // Accept a connection
  newsockfd = accept_connection(sockfd);

  // Receive a message
  message = receive_message(newsockfd);

  // Send a message
  send_message(newsockfd, message);

  // Close the connection
  close_connection(newsockfd);

  // Close the socket
  close(sockfd);

  return 0;
}