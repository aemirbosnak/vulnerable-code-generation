//GEMINI-pro DATASET v1.0 Category: Networking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Create a TCP server socket
int create_tcp_server_socket(int port) {
  int sockfd;
  struct sockaddr_in servaddr;

  // Create a TCP socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set the socket options
  int optval = 1;
  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
    perror("setsockopt");
    exit(EXIT_FAILURE);
  }

  // Bind the socket to the port
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  servaddr.sin_port = htons(port);
  if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  // Listen for incoming connections
  if (listen(sockfd, SOMAXCONN) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  return sockfd;
}

// Accept an incoming TCP connection
int accept_tcp_connection(int sockfd) {
  int connfd;
  struct sockaddr_in cliaddr;
  socklen_t len = sizeof(cliaddr);

  // Accept the incoming connection
  if ((connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len)) < 0) {
    perror("accept");
    exit(EXIT_FAILURE);
  }

  printf("New connection from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

  return connfd;
}

// Send a message to a TCP client
void send_tcp_message(int connfd, char *message) {
  int len = strlen(message);

  // Send the message
  if (send(connfd, message, len, 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }
}

// Receive a message from a TCP client
char *receive_tcp_message(int connfd) {
  char buffer[1024];
  int len;

  // Receive the message
  if ((len = recv(connfd, buffer, sizeof(buffer), 0)) < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Return the message
  return strndup(buffer, len);
}

int main(int argc, char **argv) {
  // Check the arguments
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Create the server socket
  int sockfd = create_tcp_server_socket(atoi(argv[1]));

  // Accept connections and send messages
  while (1) {
    // Accept an incoming connection
    int connfd = accept_tcp_connection(sockfd);

    // Send a welcome message
    send_tcp_message(connfd, "Welcome to my server!\n");

    // Receive a message from the client
    char *message = receive_tcp_message(connfd);

    // Print the message
    printf("Message from client: %s\n", message);

    // Send a goodbye message
    send_tcp_message(connfd, "Goodbye!\n");

    // Close the connection
    close(connfd);
  }

  // Close the server socket
  close(sockfd);

  return 0;
}