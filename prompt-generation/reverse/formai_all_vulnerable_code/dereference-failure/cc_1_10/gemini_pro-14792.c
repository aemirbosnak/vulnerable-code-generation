//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// A mysterious dance of sockets, they sway and spin,
// A symphony of bytes, a captivating din.

// Define the port, where messages reside,
// A gateway to realms where secrets hide.
#define PORT 8080

// Create a socket, a portal to connect,
// Where data flows and dreams intersect.
int create_socket() {
  int sockfd;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }
  return sockfd;
}

// Bind the socket to the port, a rendezvous site,
// Where messages gather, ready for flight.
void bind_socket(int sockfd) {
  struct sockaddr_in servaddr;
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(PORT);
  if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
    perror("Socket bind failed");
    exit(EXIT_FAILURE);
  }
}

// Listen for connections, a beacon's call,
// Awaiting whispers that will enthrall.
void listen_socket(int sockfd) {
  if (listen(sockfd, 5) != 0) {
    perror("Socket listen failed");
    exit(EXIT_FAILURE);
  }
}

// Accept a connection, a handshake's embrace,
// Two souls entwined in a digital space.
int accept_connection(int sockfd) {
  int connfd;
  struct sockaddr_in cliaddr;
  int len = sizeof(cliaddr);
  connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
  if (connfd == -1) {
    perror("Socket accept failed");
    exit(EXIT_FAILURE);
  }
  return connfd;
}

// Read from the socket, a whisper in the air,
// Unraveling secrets that it bears.
char *read_from_socket(int connfd) {
  char *buffer = malloc(1024);
  int n = read(connfd, buffer, 1024);
  if (n == -1) {
    perror("Socket read failed");
    exit(EXIT_FAILURE);
  }
  return buffer;
}

// Write to the socket, a message takes flight,
// Into the digital realm, where dreams ignite.
void write_to_socket(int connfd, char *msg) {
  write(connfd, msg, strlen(msg));
}

// Close the socket, a farewell embrace,
// Ending the connection, leaving no trace.
void close_socket(int sockfd) {
  close(sockfd);
}

// The main function, where the dance unfolds,
// A symphony of sockets, stories untold.
int main() {
  int sockfd = create_socket();
  bind_socket(sockfd);
  listen_socket(sockfd);
  int connfd = accept_connection(sockfd);
  char *msg = read_from_socket(connfd);
  printf("Received message: %s\n", msg);
  write_to_socket(connfd, "Hello from the server!");
  close_socket(connfd);
  close_socket(sockfd);
  return 0;
}