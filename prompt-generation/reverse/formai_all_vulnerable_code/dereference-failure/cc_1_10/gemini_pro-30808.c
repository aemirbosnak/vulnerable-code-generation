//GEMINI-pro DATASET v1.0 Category: Networking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <poll.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <stddef.h>
#include <errno.h>
#include <string.h>

// Set up a socket and connect to a remote host
int connect_to_host(const char *host, const char *port) {
  int sockfd, err;
  struct addrinfo hints, *result;

  // Initialize hints
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;

  // Get address information for the host
  err = getaddrinfo(host, port, &hints, &result);
  if (err != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(err));
    return -1;
  }

  // Create a socket
  sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  if (sockfd < 0) {
    perror("socket");
    freeaddrinfo(result);
    return -1;
  }

  // Connect to the remote host
  err = connect(sockfd, result->ai_addr, result->ai_addrlen);
  freeaddrinfo(result);
  if (err < 0) {
    perror("connect");
    close(sockfd);
    return -1;
  }

  return sockfd;
}

// Send data to the remote host
int send_data(int sockfd, const void *buf, size_t len) {
  ssize_t sent;
  sent = send(sockfd, buf, len, MSG_NOSIGNAL);
  if (sent < 0) {
    perror("send");
    return -1;
  }
  return (int)sent;
}

// Receive data from the remote host
int receive_data(int sockfd, void *buf, size_t len) {
  ssize_t received;
  received = recv(sockfd, buf, len, MSG_NOSIGNAL);
  if (received < 0) {
    perror("recv");
    return -1;
  }
  return (int)received;
}

// Poll the socket for events
int poll_socket(int sockfd) {
  struct pollfd fds;
  int timeout = 5000;  // 5 second timeout
  int poll_status;

  // Set up the pollfd structure
  fds.fd = sockfd;
  fds.events = POLLIN;

  // Poll the socket
  poll_status = poll(&fds, 1, timeout);
  if (poll_status < 0) {
    perror("poll");
    return -1;
  }

  return poll_status;
}

// Close the socket
void close_socket(int sockfd) {
  close(sockfd);
}

int main(int argc, char **argv) {
  int sockfd, poll_status;
  char buffer[1024];

  // Get the host and port from the command line
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return 1;
  }

  // Connect to the remote host
  sockfd = connect_to_host(argv[1], argv[2]);
  if (sockfd < 0) {
    fprintf(stderr, "Error connecting to host\n");
    return 1;
  }

  // Send data to the remote host
  strcpy(buffer, "Hello, world!\n");
  int sent = send_data(sockfd, buffer, strlen(buffer));
  if (sent < 0) {
    fprintf(stderr, "Error sending data\n");
    close_socket(sockfd);
    return 1;
  }

  // Receive data from the remote host
  int received = receive_data(sockfd, buffer, sizeof(buffer));
  if (received < 0) {
    fprintf(stderr, "Error receiving data\n");
    close_socket(sockfd);
    return 1;
  }

  // Print the received data
  printf("Received: %s\n", buffer);

  // Poll the socket for events
  poll_status = poll_socket(sockfd);
  if (poll_status < 0) {
    fprintf(stderr, "Error polling socket\n");
    close_socket(sockfd);
    return 1;
  }

  // Close the socket
  close_socket(sockfd);

  return 0;
}