//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: funny
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <string.h>

int main() {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  server = gethostbyname("localhost");
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(1);
  }

  portno = htons(80);
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = portno;

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  printf("Connected to server!\n");

  char buf[256];
  bzero(buf, 256);

  n = read(sockfd, buf, 255);
  if (n < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }
  printf("Received: %s\n", buf);

  n = write(sockfd, "Hello, world!", 13);
  if (n < 0) {
    perror("ERROR writing to socket");
    exit(1);
  }

  close(sockfd);

  return 0;
}