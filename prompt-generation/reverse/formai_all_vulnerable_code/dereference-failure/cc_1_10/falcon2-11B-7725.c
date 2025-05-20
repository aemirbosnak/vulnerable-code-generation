//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: visionary
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  int optval = 1;

  if (argc < 3) {
    fprintf(stderr, "usage %s hostname port\n", argv[0]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  portno = atoi(argv[2]);

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (char *)&optval, sizeof(optval)) < 0) {
    perror("ERROR setting SO_REUSEADDR");
    exit(1);
  }

  char sendbuf[1024];
  memset(sendbuf, 0, sizeof(sendbuf));
  send(sockfd, sendbuf, sizeof(sendbuf), 0);

  char recvbuf[1024];
  memset(recvbuf, 0, sizeof(recvbuf));
  int n = recv(sockfd, recvbuf, sizeof(recvbuf), 0);

  if (n == 0) {
    printf("Ping to %s failed\n", argv[1]);
    exit(1);
  } else {
    printf("Ping to %s succeeded\n", argv[1]);
    exit(0);
  }

  close(sockfd);
  return 0;
}