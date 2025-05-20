//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_PACKET_SIZE 1024

int main() {
  int sockfd, newsockfd, clientlen, n, bytes_read, start_time, end_time;
  struct sockaddr_in server_addr, client_addr;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Bind the socket to a port
  server_addr.sin_port = htons(5000);
  if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for clients
  clientlen = sizeof(client_addr);
  newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen);
  if (newsockfd < 0) {
    perror("Error accepting client");
    exit(1);
  }

  // Start the timer
  start_time = time(NULL);

  // Read data from the client
  bytes_read = read(newsockfd, (char *)malloc(MAX_PACKET_SIZE), MAX_PACKET_SIZE);
  if (bytes_read < 0) {
    perror("Error reading data");
    exit(1);
  }

  // End the timer
  end_time = time(NULL);

  // Calculate the time taken
  int time_taken = end_time - start_time;

  // Print the time taken
  printf("Time taken: %d seconds\n", time_taken);

  // Close the socket
  close(newsockfd);
  close(sockfd);

  return 0;
}