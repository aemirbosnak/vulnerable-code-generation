//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum number of connections
#define MAX_CONNECTIONS 10

// Define the maximum size of a packet
#define MAX_PACKET_SIZE 1024

// Create a socket
int create_socket() {
  int sockfd;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }
  return sockfd;
}

// Bind the socket to an address
void bind_socket(int sockfd, struct sockaddr_in *addr, int port) {
  addr->sin_family = AF_INET;
  addr->sin_addr.s_addr = INADDR_ANY;
  addr->sin_port = htons(port);
  if (bind(sockfd, (struct sockaddr *)addr, sizeof(*addr)) == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }
}

// Listen for connections on the socket
void listen_socket(int sockfd) {
  if (listen(sockfd, MAX_CONNECTIONS) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }
}

// Accept a connection on the socket
int accept_connection(int sockfd) {
  int newsockfd;
  struct sockaddr_in cli_addr;
  socklen_t clilen;
  clilen = sizeof(cli_addr);
  newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
  if (newsockfd == -1) {
    perror("accept");
    exit(EXIT_FAILURE);
  }
  return newsockfd;
}

// Read data from a socket
int read_socket(int sockfd, char *buffer, int len) {
  int n;
  n = read(sockfd, buffer, len);
  if (n == -1) {
    perror("read");
    exit(EXIT_FAILURE);
  }
  return n;
}

// Write data to a socket
int write_socket(int sockfd, char *buffer, int len) {
  int n;
  n = write(sockfd, buffer, len);
  if (n == -1) {
    perror("write");
    exit(EXIT_FAILURE);
  }
  return n;
}

// Close a socket
void close_socket(int sockfd) {
  close(sockfd);
}

// Main function
int main(int argc, char *argv[]) {
  int sockfd, newsockfd, port;
  struct sockaddr_in addr;
  char buffer[MAX_PACKET_SIZE];
  int n;

  // Check the number of arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Get the port number
  port = atoi(argv[1]);

  // Create a socket
  sockfd = create_socket();

  // Bind the socket to an address
  bind_socket(sockfd, &addr, port);

  // Listen for connections on the socket
  listen_socket(sockfd);

  // Main loop
  while (1) {
    // Accept a connection on the socket
    newsockfd = accept_connection(sockfd);

    // Read data from the socket
    n = read_socket(newsockfd, buffer, MAX_PACKET_SIZE);

    // Check if the data is valid
    if (n == -1) {
      perror("read");
      close_socket(newsockfd);
      continue;
    }

    // Print the data to the console
    printf("%s", buffer);

    // Close the connection
    close_socket(newsockfd);
  }

  // Close the socket
  close_socket(sockfd);

  return 0;
}