//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024 // Maximum length for incoming messages

int main(int argc, char *argv[]) {
  // Get the server address and port number from the command line arguments
  if (argc != 3) {
    printf("Usage: %s server_address port_number\n", argv[0]);
    return 1;
  }

  // Set up the connection to the server
  struct hostent *server = gethostbyname(argv[1]);
  if (server == NULL) {
    printf("Error: could not resolve server address.\n");
    return 1;
  }
  struct sockaddr_in server_addr;
  bzero((char *) &server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
  server_addr.sin_port = htons(atoi(argv[2]));
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error: could not create socket.\n");
    return 1;
  }
  if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    printf("Error: could not connect to server.\n");
    return 1;
  }

  // Log in to the server
  char buffer[BUFFER_SIZE];
  memset(buffer, 0, BUFFER_SIZE);
  if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
    printf("Error: could not read from socket.\n");
    return 1;
  }
  printf("%s", buffer);
  printf("User: ");
  fgets(buffer, BUFFER_SIZE, stdin);
  char *username = strtok(buffer, "\n");
  dprintf(sockfd, "USER %s\r\n", username);
  memset(buffer, 0, BUFFER_SIZE);
  if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
    printf("Error: could not read from socket.\n");
    return 1;
  }
  printf("%s", buffer);
  printf("Password: ");
  fgets(buffer, BUFFER_SIZE, stdin);
  char *password = strtok(buffer, "\n");
  dprintf(sockfd, "PASS %s\r\n", password);
  memset(buffer, 0, BUFFER_SIZE);
  if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
    printf("Error: could not read from socket.\n");
    return 1;
  }
  printf("%s", buffer);

  // Retrieve the list of messages on the server
  dprintf(sockfd, "LIST\r\n");
  memset(buffer, 0, BUFFER_SIZE);
  if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
    printf("Error: could not read from socket.\n");
    return 1;
  }
  printf("%s", buffer);

  // Quit the session
  dprintf(sockfd, "QUIT\r\n");
  memset(buffer, 0, BUFFER_SIZE);
  if (read(sockfd, buffer, BUFFER_SIZE) < 0) {
    printf("Error: could not read from socket.\n");
    return 1;
  }
  printf("%s", buffer);

  // Close the TCP connection
  close(sockfd);
  return 0;
}