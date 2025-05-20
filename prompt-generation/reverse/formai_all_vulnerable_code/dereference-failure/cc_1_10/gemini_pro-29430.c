//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  char *hostname = argv[1];
  int port = atoi(argv[2]);

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  inet_aton(hostname, &server_addr.sin_addr);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    exit(1);
  }

  char buf[BUFSIZE];
  int nbytes;

  while ((nbytes = read(sockfd, buf, BUFSIZE)) > 0) {
    write(STDOUT_FILENO, buf, nbytes);
  }

  if (nbytes == -1) {
    perror("read");
    exit(1);
  }

  close(sockfd);

  return 0;
}