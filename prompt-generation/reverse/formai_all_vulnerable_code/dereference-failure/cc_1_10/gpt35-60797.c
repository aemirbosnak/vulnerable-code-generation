//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: distributed
/* This is an example program for building a distributed IMAP client. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 143 // IMAP port
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <username>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *host = argv[1];
  char *username = argv[2];
  char buffer[BUF_SIZE];
  int sock;

  // Create socket
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Get server IP address
  struct hostent *server = gethostbyname(host);
  if (!server) {
    fprintf(stderr, "Error: could not resolve host: %s\n", host);
    close(sock);
    exit(EXIT_FAILURE);
  }

  // Set up server address struct
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  // Connect to server
  if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    close(sock);
    exit(EXIT_FAILURE);
  }

  // Receive server greeting
  recv(sock, buffer, BUF_SIZE, 0);
  printf("%s\n", buffer);

  // Login
  sprintf(buffer, "LOGIN %s \"\"\n", username);
  send(sock, buffer, strlen(buffer), 0);
  recv(sock, buffer, BUF_SIZE, 0);
  printf("%s\n", buffer);

  // Send command: LIST
  sprintf(buffer, "LIST \"\" *\n");
  send(sock, buffer, strlen(buffer), 0);

  // Receive response: LIST
  while (recv(sock, buffer, BUF_SIZE, 0) > 0) {
    printf("%s\n", buffer);
  }

  // Logout
  sprintf(buffer, "LOGOUT\n");
  send(sock, buffer, strlen(buffer), 0);
  recv(sock, buffer, BUF_SIZE, 0);
  printf("%s\n", buffer);

  // Close socket
  close(sock);

  return 0;
}