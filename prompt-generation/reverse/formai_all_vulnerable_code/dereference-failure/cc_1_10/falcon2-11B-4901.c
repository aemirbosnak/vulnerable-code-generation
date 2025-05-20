//Falcon2-11B DATASET v1.0 Category: Networking ; Style: single-threaded
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netdb.h>
#include <time.h>

#define PORT 8080

int main() {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  char buffer[1024];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Assign socket to a port number
  portno = PORT;
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  serv_addr.sin_addr.s_addr = INADDR_ANY;

  // Establish connection
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("Connection Failed");
    exit(EXIT_FAILURE);
  }

  printf("Connection established\n");
  time_t timer = time(NULL);
  strftime(buffer, sizeof(buffer), "%A %B %d, %Y %r %Z", localtime(&timer));
  printf("Time: %s\n", buffer);

  // Read from the socket
  n = read(sockfd, buffer, sizeof(buffer));
  printf("Message from server: %s\n", buffer);

  // Write to the socket
  sprintf(buffer, "Hello, server!\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("Write failed");
    exit(EXIT_FAILURE);
  }
  printf("Message sent: %s\n", buffer);

  // Close the socket
  close(sockfd);

  return 0;
}