//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

void fatal(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char **argv) {
  struct sockaddr_in serv_addr;
  struct hostent *serv_host;
  int sockfd, n;
  char buffer[256];

  if (argc != 3) {
    fatal("Usage: ftp <host> <port>");
  }

  // Get the host by name
  serv_host = gethostbyname(argv[1]);
  if (serv_host == NULL) {
    fatal("Error: no such host");
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fatal("Error: could not create socket");
  }

  // Fill in the server's address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy(&serv_addr.sin_addr, serv_host->h_addr, serv_host->h_length);
  serv_addr.sin_port = htons(atoi(argv[2]));

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    fatal("Error: could not connect to host");
  }

  // Send a message to the server
  n = write(sockfd, "Hello world\n", 12);
  if (n < 0) {
    fatal("Error: could not send message to host");
  }

  // Receive a message from the server
  n = read(sockfd, buffer, 255);
  if (n < 0) {
    fatal("Error: could not receive message from host");
  }

  // Print the message from the server
  printf("%s", buffer);

  // Close the socket
  close(sockfd);

  return 0;
}