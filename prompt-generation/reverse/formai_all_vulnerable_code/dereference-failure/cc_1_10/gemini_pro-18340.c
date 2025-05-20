//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Resolve the hostname
  char hostname[1024];
  if (gethostname(hostname, sizeof hostname) == -1) {
    perror("gethostname");
    return EXIT_FAILURE;
  }

  // Get the port number
  int port = atoi(argv[2]);

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Connect to the FTP server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof server_addr);
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) == -1) {
    perror("inet_pton");
    return EXIT_FAILURE;
  }

  if (connect(sock, (struct sockaddr *) &server_addr, sizeof server_addr) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send the FTP commands
  char command[1024];
  while (1) {
    printf("FTP> ");
    fgets(command, sizeof command, stdin);

    // Check if the user wants to quit
    if (strcmp(command, "quit\n") == 0) {
      break;
    }

    // Send the command to the FTP server
    if (send(sock, command, strlen(command), 0) == -1) {
      perror("send");
      return EXIT_FAILURE;
    }

    // Receive the response from the FTP server
    char response[1024];
    if (recv(sock, response, sizeof response, 0) == -1) {
      perror("recv");
      return EXIT_FAILURE;
    }

    // Print the response to the user
    printf("%s\n", response);
  }

  // Close the socket
  close(sock);

  return EXIT_SUCCESS;
}