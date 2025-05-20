//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char** argv) {
  if (argc != 3) {
    printf("Usage: %s <ip address> <port>\n", argv[0]);
    return 1;
  }

  int sockfd;
  struct sockaddr_in servaddr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 2;
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    return 3;
  }

  if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    return 4;
  }

  char buffer[1024];
  memset(buffer, 0, sizeof(buffer));

  while (1) {
    printf("Enter message: ");
    fgets(buffer, sizeof(buffer), stdin);

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
      perror("send");
      return 5;
    }

    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
      perror("recv");
      return 6;
    }

    printf("Received message: %s\n", buffer);
  }

  return 0;
}