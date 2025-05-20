//Gemma-7B DATASET v1.0 Category: Error handling ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_PORT 8888
#define BUFFER_SIZE 1024

int main() {
  int sockfd, newsockfd, client_len;
  char buffer[BUFFER_SIZE];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));

  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Listen for clients
  listen(sockfd, &client_len);

  // Accept a client connection
  newsockfd = accept(sockfd, NULL, NULL);

  if (newsockfd < 0) {
    perror("Error accepting client connection");
    exit(1);
  }

  // Receive data from the client
  recv(newsockfd, buffer, BUFFER_SIZE, 0);

  if (recv < 0) {
    perror("Error receiving data");
    exit(1);
  }

  // Print the data received from the client
  printf("Data received: %s", buffer);

  // Send data back to the client
  send(newsockfd, buffer, BUFFER_SIZE, 0);

  if (send < 0) {
    perror("Error sending data");
    exit(1);
  }

  // Close the client connection
  close(newsockfd);

  // Close the socket
  close(sockfd);

  return 0;
}