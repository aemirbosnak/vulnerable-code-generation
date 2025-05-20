//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <time.h>

#define PORT 8080

int main(int argc, char *argv[]) {
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int n;

  if (argc < 2) {
    fprintf(stderr,"ERROR, no port provided\n");
    exit(1);
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Set up the server address
  bzero((char *) &serv_addr, sizeof(serv_addr));
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  // Bind the socket to the server address
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR on binding");
    exit(1);
  }

  // Listen for connections
  listen(sockfd,5);

  // Accept a connection
  clilen = sizeof(cli_addr);
  newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
  if (newsockfd < 0) {
    perror("ERROR on accept");
    exit(1);
  }

  // Read the message from the client
  bzero(buffer,256);
  n = read(newsockfd,buffer,255);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  // Print the message from the client
  printf("Received message: %s\n",buffer);

  // Send a message back to the client
  n = write(newsockfd,"I am alive",9);
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  // Close the socket
  close(newsockfd);
  close(sockfd);
  return 0;
}