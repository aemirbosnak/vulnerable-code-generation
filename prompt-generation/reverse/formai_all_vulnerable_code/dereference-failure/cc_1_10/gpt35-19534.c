//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: irregular
/* ~~~Begin HTTP Client Example Program~~~ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int create_socket(char *host, char *port) {
  // Get host info
  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  getaddrinfo(host, port, &hints, &res);

  // Create socket
  int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  // Connect to server
  connect(sockfd, res->ai_addr, res->ai_addrlen);

  // Free memory
  freeaddrinfo(res);

  return sockfd;
}

void send_request(int sockfd, char *message) {
  // Send message to server
  send(sockfd, message, strlen(message), 0);
}

void receive_response(int sockfd) {
  // Receive response from server
  char buf[1024];
  int bytes_received = recv(sockfd, buf, 1024, 0);

  // Print response
  printf("%.*s",bytes_received,buf);
}

int main(int argc, char **argv) {
  // Check arguments
  if (argc < 4) {
    fprintf(stderr,"Usage: %s <host> <port> <message>\n", argv[0]);
    exit(1);
  }

  // Create socket
  int sockfd = create_socket(argv[1], argv[2]);

  // Send request
  send_request(sockfd, argv[3]);

  // Receive response
  receive_response(sockfd);

  // Close socket
  close(sockfd);

  return 0;
}

/* ~~~End HTTP Client Example Program~~~ */