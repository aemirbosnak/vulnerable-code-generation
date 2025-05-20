//GEMINI-pro DATASET v1.0 Category: Networking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <ip address> <port>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(argv[1]);
  server_addr.sin_port = htons(atoi(argv[2]));

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  char buffer[1024];
  while (1) {
    memset(buffer, 0, sizeof(buffer));
    printf("Enter a command: ");
    fgets(buffer, sizeof(buffer), stdin);

    if (strcmp(buffer, "exit\n") == 0) {
      break;
    }

    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
      perror("send");
      return EXIT_FAILURE;
    }

    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
      perror("recv");
      return EXIT_FAILURE;
    }

    printf("Received: %s", buffer);
  }

  close(sockfd);
  return EXIT_SUCCESS;
}