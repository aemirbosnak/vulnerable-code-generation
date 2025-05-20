//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
  int sockfd;
  struct sockaddr_in servaddr, cliaddr;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Initialize the server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  servaddr.sin_port = htons(PORT);

  // Bind the socket to the server address
  if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  // Receive a message from the client
  char buffer[1024];
  socklen_t len = sizeof(cliaddr);
  int n = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len);
  if (n == -1) {
    perror("recvfrom failed");
    exit(EXIT_FAILURE);
  }

  // Parse the message
  char *command = strtok(buffer, " ");
  char *argument = strtok(NULL, " ");

  // Handle the command
  if (strcmp(command, "ON") == 0) {
    // Turn on the light
    printf("Turning on the light\n");
  } else if (strcmp(command, "OFF") == 0) {
    // Turn off the light
    printf("Turning off the light\n");
  } else if (strcmp(command, "DIM") == 0) {
    // Dim the light
    printf("Dimming the light\n");
  } else {
    // Send an error message
    printf("Invalid command\n");
  }

  // Close the socket
  close(sockfd);

  return 0;
}