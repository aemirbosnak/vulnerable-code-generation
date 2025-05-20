//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
  // Create a socket
  int sockfd;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    return 1;
  }
  
  // Resolve the server address
  struct addrinfo hints, *servinfo, *p;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  
  getaddrinfo("www.example.com", NULL, &hints, &servinfo);
  
  // Connect to the server
  if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) < 0) {
    perror("Error connecting");
    return 1;
  }
  
  // Send data to the server
  char message[] = "Hello, world!";
  send(sockfd, message, strlen(message), 0);
  
  // Receive data from the server
  char buffer[256];
  int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_received < 0) {
    perror("Error receiving data");
    return 1;
  }
  
  // Print the received data
  printf("Received data: %s\n", buffer);
  
  // Close the socket
  close(sockfd);
  
  return 0;
}