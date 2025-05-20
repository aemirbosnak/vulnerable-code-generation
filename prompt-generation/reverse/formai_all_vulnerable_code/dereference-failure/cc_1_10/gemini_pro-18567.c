//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Create a socket and bind it to a port
int create_socket(int port) {
  int sockfd;
  struct sockaddr_in addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);

  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind");
    exit(1);
  }

  return sockfd;
}

// Listen for connections on a socket
void listen_socket(int sockfd) {
  if (listen(sockfd, 5) < 0) {
    perror("listen");
    exit(1);
  }
}

// Accept a connection on a socket
int accept_connection(int sockfd) {
  int newsockfd;
  struct sockaddr_in addr;
  socklen_t addrlen = sizeof(addr);

  newsockfd = accept(sockfd, (struct sockaddr *)&addr, &addrlen);
  if (newsockfd < 0) {
    perror("accept");
    exit(1);
  }

  return newsockfd;
}

// Read data from a socket
char *read_data(int sockfd) {
  char *buffer;
  int nbytes;

  buffer = malloc(1024);
  if (buffer == NULL) {
    perror("malloc");
    exit(1);
  }

  nbytes = read(sockfd, buffer, 1023);
  if (nbytes < 0) {
    perror("read");
    exit(1);
  }

  buffer[nbytes] = '\0';

  return buffer;
}

// Write data to a socket
void write_data(int sockfd, char *data) {
  int nbytes;

  nbytes = write(sockfd, data, strlen(data));
  if (nbytes < 0) {
    perror("write");
    exit(1);
  }
}

// Close a socket
void close_socket(int sockfd) {
  close(sockfd);
}

// Main function
int main(int argc, char **argv) {
  int sockfd, newsockfd;
  char *data;

  // Check if the port was specified
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  // Create the socket
  sockfd = create_socket(atoi(argv[1]));

  // Listen for connections
  listen_socket(sockfd);

  // Accept a connection
  newsockfd = accept_connection(sockfd);

  // Read the data from the socket
  data = read_data(newsockfd);

  // Check if the data is valid
  if (strcmp(data, "Hello from the client") != 0) {
    fprintf(stderr, "Invalid data received: %s\n", data);
    exit(1);
  }

  // Write data to the socket
  write_data(newsockfd, "Hello from the server");

  // Close the socket
  close_socket(newsockfd);
  close_socket(sockfd);

  return 0;
}