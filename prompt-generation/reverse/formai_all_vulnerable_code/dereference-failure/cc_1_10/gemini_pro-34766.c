//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define PORT 21

int main(int argc, char *argv[]) {
  int sockfd, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  char buffer[MAX_LINE];
  char *command, *argument;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <host> <command> [argument]\n", argv[0]);
    exit(1);
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Error: no such host\n");
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Error: could not create socket\n");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
  serv_addr.sin_port = htons(PORT);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    fprintf(stderr, "Error: could not connect to host\n");
    exit(1);
  }

  n = read(sockfd, buffer, MAX_LINE);
  if (n < 0) {
    fprintf(stderr, "Error: could not read from host\n");
    exit(1);
  }

  printf("%s", buffer);

  command = strtok(argv[2], " ");
  argument = strtok(NULL, " ");

  snprintf(buffer, MAX_LINE, "%s %s\r\n", command, argument);

  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    fprintf(stderr, "Error: could not write to host\n");
    exit(1);
  }

  n = read(sockfd, buffer, MAX_LINE);
  if (n < 0) {
    fprintf(stderr, "Error: could not read from host\n");
    exit(1);
  }

  printf("%s", buffer);

  close(sockfd);

  return 0;
}