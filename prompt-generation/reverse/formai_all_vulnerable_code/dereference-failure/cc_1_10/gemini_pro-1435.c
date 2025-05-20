//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  char buffer[BUFSIZE];

  if (argc < 3) {
    fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[2]);

  /* Create a socket point */
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  /* Get the server's DNS entry */
  struct hostent *server = gethostbyname(argv[1]);
  if (!server) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(1);
  }

  /* Fill in the server's address */
  memset((char *)&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  /* Connect to the server */
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  /* Do stuff */
  while (1) {
    memset(buffer, 0, BUFSIZE);
    printf("Enter command: ");
    fgets(buffer, BUFSIZE - 1, stdin);

    /* Send command to the server */
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
    }

    /* Receive the server's response */
    memset(buffer, 0, BUFSIZE);
    n = recv(sockfd, buffer, BUFSIZE - 1, 0);
    if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
    }

    printf("%s", buffer);
  }

  /* Close the socket */
  close(sockfd);

  return 0;
}