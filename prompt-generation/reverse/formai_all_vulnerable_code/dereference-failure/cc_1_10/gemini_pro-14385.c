//GEMINI-pro DATASET v1.0 Category: Networking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Define the maximum buffer size
#define MAX_BUFFER_SIZE 1024

// Create a socket
int create_socket(int domain, int type, int protocol) {
  int sockfd;

  // Create a socket using the specified domain, type, and protocol
  sockfd = socket(domain, type, protocol);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Return the socket file descriptor
  return sockfd;
}

// Bind a socket to a specified address and port
void bind_socket(int sockfd, struct sockaddr *addr, socklen_t addrlen) {
  // Bind the socket to the specified address and port
  if (bind(sockfd, addr, addrlen) == -1) {
    perror("bind");
    exit(EXIT_FAILURE);
  }
}

// Listen for incoming connections on a socket
void listen_socket(int sockfd, int backlog) {
  // Listen for incoming connections on the socket with the specified backlog
  if (listen(sockfd, backlog) == -1) {
    perror("listen");
    exit(EXIT_FAILURE);
  }
}

// Accept an incoming connection on a socket
int accept_connection(int sockfd) {
  int newsockfd;
  struct sockaddr_in cliaddr;
  socklen_t clilen;

  // Accept an incoming connection on the socket
  clilen = sizeof(cliaddr);
  newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &clilen);
  if (newsockfd == -1) {
    perror("accept");
    exit(EXIT_FAILURE);
  }

  // Return the new socket file descriptor
  return newsockfd;
}

// Receive data from a socket
int receive_data(int sockfd, void *buf, size_t bufsize) {
  // Receive data from the socket into the specified buffer
  int nbytes;

  nbytes = recv(sockfd, buf, bufsize, 0);
  if (nbytes == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Return the number of bytes received
  return nbytes;
}

// Send data to a socket
int send_data(int sockfd, void *buf, size_t bufsize) {
  // Send data from the specified buffer to the socket
  int nbytes;

  nbytes = send(sockfd, buf, bufsize, 0);
  if (nbytes == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Return the number of bytes sent
  return nbytes;
}

// Close a socket
void close_socket(int sockfd) {
  // Close the socket
  if (close(sockfd) == -1) {
    perror("close");
    exit(EXIT_FAILURE);
  }
}

// Main program
int main(int argc, char *argv[]) {
  int sockfd, newsockfd;
  struct sockaddr_in servaddr, cliaddr;
  char buffer[MAX_BUFFER_SIZE];
  int nbytes;

  // Create a socket
  sockfd = create_socket(AF_INET, SOCK_STREAM, 0);

  // Bind the socket to the specified address and port
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(atoi(argv[1]));
  bind_socket(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

  // Listen for incoming connections on the socket
  listen_socket(sockfd, 5);

  // Accept an incoming connection on the socket
  newsockfd = accept_connection(sockfd);

  // Receive data from the socket
  nbytes = receive_data(newsockfd, buffer, MAX_BUFFER_SIZE);

  // Send data to the socket
  send_data(newsockfd, buffer, nbytes);

  // Close the socket
  close_socket(sockfd);
  close_socket(newsockfd);

  return 0;
}