//GEMINI-pro DATASET v1.0 Category: Networking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  struct hostent *hostinfo;
  hostinfo = gethostbyname(argv[1]);
  if (hostinfo == NULL) {
    fprintf(stderr, "gethostbyname() failed: %s\n", hstrerror(h_errno));
    exit(EXIT_FAILURE);
  }

  int sockfd;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket() failed");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in serveraddr;
  memset(&serveraddr, 0, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(atoi(argv[2]));
  memcpy(&serveraddr.sin_addr.s_addr, hostinfo->h_addr_list[0], hostinfo->h_length);

  if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
    perror("connect() failed");
    exit(EXIT_FAILURE);
  }

  char buf[BUFSIZE];
  while (1) {
    printf("Enter a message: ");
    fgets(buf, BUFSIZE, stdin);

    if (send(sockfd, buf, strlen(buf), 0) == -1) {
      perror("send() failed");
      exit(EXIT_FAILURE);
    }

    if (recv(sockfd, buf, BUFSIZE, 0) == -1) {
      perror("recv() failed");
      exit(EXIT_FAILURE);
    }

    printf("Received: %s\n", buf);
  }

  close(sockfd);
  exit(EXIT_SUCCESS);
}