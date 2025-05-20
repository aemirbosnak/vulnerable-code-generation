//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
  int sockfd, newsockfd, portno;
  socklen_t clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;

  if (argc < 2) {
    fprintf(stderr, "Error: no port provided\n");
    exit(1);
  }

  // create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error: socket() failed");
    exit(1);
  }

  // set up the server address
  bzero((char *) &serv_addr, sizeof(serv_addr));
  portno = atoi(argv[1]);
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  // bind the socket to the server address
  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error: bind() failed");
    exit(1);
  }

  // listen for incoming connections
  listen(sockfd, 5);

  // accept incoming connections
  clilen = sizeof(cli_addr);
  while (1) {
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
      perror("Error: accept() failed");
      exit(1);
    }

    // fork a new process to handle the connection
    if (fork() == 0) {
      // child process
      close(sockfd);

      // read from the client
      bzero(buffer, 256);
      read(newsockfd, buffer, 255);

      // check if the request is valid
      if (strcmp(buffer, "Hello world") == 0) {
        // send a response to the client
        bzero(buffer, 256);
        strcpy(buffer, "Hello back!");
        write(newsockfd, buffer, strlen(buffer));
      } else {
        // send an error response to the client
        bzero(buffer, 256);
        strcpy(buffer, "Error: invalid request");
        write(newsockfd, buffer, strlen(buffer));
      }

      // close the connection
      close(newsockfd);
      exit(0);
    } else {
      // parent process
      close(newsockfd);
    }
  }

  // close the socket
  close(sockfd);

  return 0;
}