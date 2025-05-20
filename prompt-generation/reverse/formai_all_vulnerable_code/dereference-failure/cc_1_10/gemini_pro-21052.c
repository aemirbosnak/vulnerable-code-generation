//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Resolve the hostname and port
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    fprintf(stderr, "Error: could not resolve hostname %s\n", argv[1]);
    return EXIT_FAILURE;
  }
  int port = atoi(argv[2]);

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Error: could not create socket");
    return EXIT_FAILURE;
  }

  // Connect to the server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr = *(struct in_addr *)host->h_addr;

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("Error: could not connect to server");
    return EXIT_FAILURE;
  }

  // Send the user command
  char command[256];
  printf("Enter a command: ");
  fgets(command, sizeof(command), stdin);

  if (send(sockfd, command, strlen(command), 0) == -1) {
    perror("Error: could not send command to server");
    return EXIT_FAILURE;
  }

  // Receive the server response
  char response[1024];
  if (recv(sockfd, response, sizeof(response), 0) == -1) {
    perror("Error: could not receive response from server");
    return EXIT_FAILURE;
  }

  // Print the server response
  printf("Server response: %s\n", response);

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}