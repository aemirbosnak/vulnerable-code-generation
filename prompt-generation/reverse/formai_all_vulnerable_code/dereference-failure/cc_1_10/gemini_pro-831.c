//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main() {
  // Initialize the socket structures
  struct sockaddr_in server_addr;
  struct hostent *server;
  int sockfd;
  
  // Create the socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set the server information
  server = gethostbyname("localhost");
  if (server == NULL) {
    perror("gethostbyname");
    exit(EXIT_FAILURE);
  }

  memset((char *)&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
  server_addr.sin_port = htons(9999);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send a message to the server
  char *message = "Greetings from the wasteland";
  if (write(sockfd, message, strlen(message)) < 0) {
    perror("write");
    exit(EXIT_FAILURE);
  }

  // Receive a message from the server
  char buffer[1024];
  if (read(sockfd, buffer, sizeof(buffer)) < 0) {
    perror("read");
    exit(EXIT_FAILURE);
  }

  // Print the message from the server
  printf("%s", buffer);

  // Close the socket
  close(sockfd);

  return 0;
}