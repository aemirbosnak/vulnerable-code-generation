//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[BUFSIZE];

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[2]);
  server = gethostbyname(argv[1]);

  if (server == NULL) {
    fprintf(stderr, "Error: No such host\n");
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {
    fprintf(stderr, "Error: Opening socket\n");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "Error: Connecting\n");
    exit(1);
  }

  printf("Connected to %s on port %d\n", argv[1], portno);

  while (1) {
    bzero(buffer, BUFSIZE);
    printf("ftp> ");
    fgets(buffer, BUFSIZE, stdin);

    if (strcmp(buffer, "quit\n") == 0) {
      break;
    }

    if (write(sockfd, buffer, strlen(buffer)) < 0) {
      fprintf(stderr, "Error: Writing to socket\n");
      exit(1);
    }

    bzero(buffer, BUFSIZE);
    if (read(sockfd, buffer, BUFSIZE) < 0) {
      fprintf(stderr, "Error: Reading from socket\n");
      exit(1);
    }

    printf("%s", buffer);
  }

  close(sockfd);
  return 0;
}