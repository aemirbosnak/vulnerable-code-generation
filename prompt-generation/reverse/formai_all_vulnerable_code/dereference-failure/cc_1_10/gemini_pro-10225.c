//GEMINI-pro DATASET v1.0 Category: Networking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 8080

// A mind-bending function that reverses a string
char *reverseString(char *str) {
  char *p1, *p2;

  if (!str || *str == '\0') {
    return str;
  }

  // Get the length of the string
  int length = strlen(str);

  // Allocate memory for the reversed string
  char *reversedString = malloc(length + 1);

  // Set the pointers to the beginning and end of the string
  p1 = str;
  p2 = reversedString + length - 1;

  // Reverse the string character by character
  while (p1 <= p2) {
    *p2 = *p1;
    p1++;
    p2--;
  }

  // Null-terminate the reversed string
  *p2 = '\0';

  // Return the reversed string
  return reversedString;
}

int main() {
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Set the port number
  portno = PORT;

  // Set the server address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  // Bind the socket to the server address
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

  // Listen for connections
  listen(sockfd, 5);

  // Accept a connection
  clilen = sizeof(cli_addr);
  newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
  if (newsockfd < 0) {
    perror("ERROR on accept");
    exit(1);
  }

  // Read the message from the client
  memset(buffer, 0, 256);
  int n = read(newsockfd, buffer, 255);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  // Reverse the message
  char *reversedMessage = reverseString(buffer);

  // Send the reversed message back to the client
  n = write(newsockfd, reversedMessage, strlen(reversedMessage));
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // Close the connection
  close(newsockfd);
  close(sockfd);

  return 0;
}