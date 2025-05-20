//MISTRAL-7B DATASET v1.0 Category: Network Ping Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

void die(const char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]) {
  int sockfd, i;
  char ipstr[INET_ADDRSTRLEN];
  struct sockaddr_in serv_addr;
  struct hostent *server;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <hostname or IP address>\n", argv[0]);
    exit(1);
  }

  if ((server = gethostbyname(argv[1])) == NULL) {
    herror("gethostbyname");
    exit(1);
  }

  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    die("socket");

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(0);
  inet_pton(AF_INET, server->h_addr_list[0], &serv_addr.sin_addr);

  printf("\n----------------------------------------\n");
  printf("| Welcome to the Curious Ping Test!      |\n");
  printf("| This program sends a ping packet to   |\n");
  printf("| the specified host and waits for a    |\n");
  printf("| response.                            |\n");
  printf("----------------------------------------|\n\n");

  printf("Pinging %s (%s)...\n", argv[1], inet_ntop(AF_INET, &serv_addr.sin_addr, ipstr, sizeof(ipstr)));

  for (i = 0; i < 5; i++) {
    if (sendto(sockfd, "ping", strlen("ping"), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
      die("sendto");

    fd_set masterfds, readfds;
    FD_ZERO(&masterfds);
    FD_ZERO(&readfds);

    FD_SET(sockfd, &masterfds);
    struct timeval timeout = {.tv_sec = 1, .tv_usec = 0};

    int ret = select(sockfd + 1, &readfds, NULL, NULL, &timeout);

    if (ret < 0) {
      perror("select");
      exit(1);
    }

    if (FD_ISSET(sockfd, &readfds)) {
      char buf[256];
      socklen_t len = sizeof(struct sockaddr_in);
      int received = recvfrom(sockfd, buf, sizeof(buf), 0, NULL, &len);

      if (received > 0) {
        printf("Received reply from %s:%d\n", ipstr, ntohs(serv_addr.sin_port));
        printf("%s\n", buf);
      }
    } else {
      printf("Request timed out\n");
    }
  }

  close(sockfd);
  return 0;
}