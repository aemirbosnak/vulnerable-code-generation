//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Global variables
int sockfd, portno, clilen;
struct sockaddr_in serveraddr;

int main(int argc, char *argv[]) {
  // Check command line arguments
  if (argc!= 3) {
    printf("Usage: %s <server-ip> <server-port>\n", argv[0]);
    return 1;
  }

  // Convert IP address and port number to network format
  struct hostent *server = gethostbyname(argv[1]);
  if (server == NULL) {
    printf("Error: Invalid server address.\n");
    return 1;
  }

  // Store server address and port number
  bzero((char *) &serveraddr, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
  serveraddr.sin_port = htons(atoi(argv[2]));

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
    printf("Error: Failed to connect to the server.\n");
    return 1;
  }

  // Send a command
  char command[100];
  bzero(command, 100);
  strcpy(command, "USER anonymous\r\n");
  if (send(sockfd, command, strlen(command), 0) < 0) {
    printf("Error: Failed to send command.\n");
    return 1;
  }

  // Read response
  char response[100];
  bzero(response, 100);
  if (recv(sockfd, response, sizeof(response), 0) < 0) {
    printf("Error: Failed to receive response.\n");
    return 1;
  }

  // Close the socket
  close(sockfd);
  printf("Response: %s\n", response);

  return 0;
}