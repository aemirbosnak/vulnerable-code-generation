//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    return 1;
  }

  char *hostname = argv[1];
  int port = atoi(argv[2]);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return 1;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(hostname);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return 1;
  }

  char buffer[1024];
  while (1) {
    printf("FTP> ");
    fgets(buffer, sizeof(buffer), stdin);

    if (strcmp(buffer, "quit\n") == 0) {
      break;
    }

    write(sockfd, buffer, strlen(buffer));

    memset(buffer, 0, sizeof(buffer));
    read(sockfd, buffer, sizeof(buffer));

    printf("%s", buffer);
  }

  close(sockfd);
  return 0;
}