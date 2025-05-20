//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  // Variables declaration
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];
  char request[512];
  
  // Socket creation
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    return EXIT_FAILURE;
  }
  
  // Getting the server name and port number
  server = gethostbyname(argv[1]);
  portno = atoi(argv[2]);

  bzero((char *)&serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,
  (char *)&serv_addr.sin_addr.s_addr,
  server->h_length);
  serv_addr.sin_port = htons(portno);
  
  // Connecting to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    return EXIT_FAILURE;
  }

  // Building and sending the HTTP request to the server
  sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
  n = write(sockfd, request, strlen(request));
  if (n < 0) {
    perror("ERROR writing to socket");
    return EXIT_FAILURE;
  }

  // Reading the server response
  bzero(buffer, 256);
  while ((n = read(sockfd, buffer, 255)) > 0) {
    printf("%s", buffer);
    bzero(buffer, 256);
  }
  if (n < 0) {
    perror("ERROR reading from socket");
    return EXIT_FAILURE;
  }

  // Closing the socket
  close(sockfd);
  
  return EXIT_SUCCESS;
}