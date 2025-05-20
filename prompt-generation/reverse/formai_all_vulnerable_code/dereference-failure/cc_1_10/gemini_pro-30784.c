//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *hostname = argv[1];
  int port = atoi(argv[2]);

  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    fprintf(stderr, "Could not resolve hostname: %s\n", hostname);
    exit(EXIT_FAILURE);
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr = *(struct in_addr *)host->h_addr;

  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  char buffer[256];
  while (1) {
    printf("[?] Enter a command: ");
    fgets(buffer, sizeof(buffer), stdin);

    if (strcmp(buffer, "exit\n") == 0) {
      break;
    }

    int n = send(sockfd, buffer, strlen(buffer), 0);
    if (n == -1) {
      perror("send");
      exit(EXIT_FAILURE);
    }

    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n == -1) {
      perror("recv");
      exit(EXIT_FAILURE);
    }

    printf("[+] Received: %s\n", buffer);
  }

  close(sockfd);

  return EXIT_SUCCESS;
}