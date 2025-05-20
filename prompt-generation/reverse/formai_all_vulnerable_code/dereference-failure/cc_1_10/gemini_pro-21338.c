//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

// Defines the maximum length of a message
#define MAX_MESSAGE_LENGTH 1024

// Entry point of the program
int main(int argc, char *argv[]) {
  // Check if the number of arguments is valid
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  // Get the hostname and port number from the command line arguments
  char *hostname = argv[1];
  int port = atoi(argv[2]);

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  // Get the IP address of the hostname
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    fprintf(stderr, "Unknown hostname: %s\n", hostname);
    exit(1);
  }

  // Set up the socket address
  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  // Main loop
  while (1) {
    // Get a message from the user
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter a message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Send the message to the server
    int bytes_sent = send(sockfd, message, strlen(message), 0);
    if (bytes_sent < 0) {
      perror("send");
      exit(1);
    }

    // Receive a message from the server
    char buffer[MAX_MESSAGE_LENGTH];
    int bytes_received = recv(sockfd, buffer, MAX_MESSAGE_LENGTH, 0);
    if (bytes_received < 0) {
      perror("recv");
      exit(1);
    }

    // Print the message from the server
    printf("Received message: %s\n", buffer);
  }

  // Close the socket
  close(sockfd);

  return 0;
}