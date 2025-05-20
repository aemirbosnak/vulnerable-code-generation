//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
  int sockfd, port_no, n;
  char buffer[MAX_LINE];

  struct sockaddr_in server_address;
  struct hostent *server;

  if (argc != 3) {
    fprintf(stderr, "usage: %s <hostname> <port_no>\n", argv[0]);
    exit(1);
  }

  port_no = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {
    perror("error opening socket");
    exit(1);
  }

  server = gethostbyname(argv[1]);

  if (server == NULL) {
    fprintf(stderr,"error: no such host\n");
    exit(1);
  }

  bzero((char *) &server_address, sizeof(server_address));
  server_address.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
  server_address.sin_port = htons(port_no);

  if (connect(sockfd,(struct sockaddr *) &server_address,sizeof(server_address)) < 0) {
    perror("error connecting");
    exit(1);
  }

  printf("connected to server\n");

  while(1) {
    bzero(buffer, MAX_LINE);
    printf("> ");
    fgets(buffer, MAX_LINE, stdin);

    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
      perror("error writing to socket");
      exit(1);
    }

    if (strcmp(buffer,"quit\n") == 0) {
      printf("quitting client\n");
      break;
    }

    bzero(buffer, MAX_LINE);
    n = read(sockfd, buffer, MAX_LINE);

    if (n < 0) {
      perror("error reading from socket");
      exit(1);
    }

    printf("< %s", buffer);
  }

  close(sockfd);
  return 0;
}