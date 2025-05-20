//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  char buffer[256];

  if (argc!= 2) {
    fprintf(stderr, "usage: %s <port>\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[1]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket failed");
    exit(1);
  }

  memset((char *)&serv_addr, '0', sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind failed");
    exit(1);
  }

  listen(sockfd, 5);

  while (1) {
    socklen_t clilen = sizeof(struct sockaddr_in);
    n = accept(sockfd, (struct sockaddr *)&serv_addr, &clilen);
    if (n < 0) {
      perror("accept failed");
      exit(1);
    }

    printf("New connection: %s\n", inet_ntoa(serv_addr.sin_addr));

    while ((n = recv(n, buffer, 256, 0)) > 0) {
      printf("Received %d bytes: %s\n", n, buffer);
      send(n, buffer, n, 0);
    }

    printf("Connection closed\n");
    close(n);
  }

  close(sockfd);
  return 0;
}