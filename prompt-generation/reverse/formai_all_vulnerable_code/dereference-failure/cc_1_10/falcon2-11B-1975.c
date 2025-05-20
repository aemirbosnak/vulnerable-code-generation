//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: ephemeral
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_MESSAGE_LENGTH 50
#define MAX_PACKET_SIZE 1500

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in serveraddr;
  int portno = 80;
  int n;
  char message[MAX_MESSAGE_LENGTH];
  char buffer[MAX_PACKET_SIZE];
  char hostname[MAX_MESSAGE_LENGTH];
  int flag = 1;

  // Initialize the socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Create a server address structure
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(portno);
  serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Send the request
  sprintf(message, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", hostname);
  if (send(sockfd, message, strlen(message), 0) < 0) {
    perror("Error sending request");
    exit(1);
  }

  // Receive the response
  if ((n = recv(sockfd, buffer, MAX_PACKET_SIZE, 0)) < 0) {
    perror("Error receiving response");
    exit(1);
  }

  // Print the response
  printf("Response:\n%s", buffer);

  // Close the socket
  close(sockfd);

  return 0;
}