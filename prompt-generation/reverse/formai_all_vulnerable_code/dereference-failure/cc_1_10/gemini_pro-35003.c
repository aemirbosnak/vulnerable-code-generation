//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: Dennis Ritchie
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;

  /* Create a socket. */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  /* Set the server address. */
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  /* Bind the socket to the server address. */
  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind");
    exit(EXIT_FAILURE);
  }

  /* Listen for incoming connections. */
  if (listen(sockfd, 5) < 0) {
    perror("listen");
    exit(EXIT_FAILURE);
  }

  /* Accept an incoming connection. */
  clilen = sizeof(cli_addr);
  newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
  if (newsockfd < 0) {
    perror("accept");
    exit(EXIT_FAILURE);
  }

  /* Read the message from the client. */
  bzero(buffer, 256);
  if (read(newsockfd, buffer, 255) < 0) {
    perror("read");
    exit(EXIT_FAILURE);
  }

  /* Print the message. */
  printf("%s\n", buffer);

  /* Write a message to the client. */
  bzero(buffer, 256);
  strcpy(buffer, "Hello, world!");
  if (write(newsockfd, buffer, strlen(buffer)) < 0) {
    perror("write");
    exit(EXIT_FAILURE);
  }

  /* Close the connection. */
  close(newsockfd);
  close(sockfd);

  return 0;
}