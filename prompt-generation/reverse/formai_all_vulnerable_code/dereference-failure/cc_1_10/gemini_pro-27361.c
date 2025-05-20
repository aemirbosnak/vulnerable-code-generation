//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80
#define TIMEOUT 3
#define MAX_RESULTS 100

struct result {
  char *ip;
  char *hostname;
};

struct result *results;
int num_results;

void init_results() {
  results = malloc(sizeof(struct result) * MAX_RESULTS);
  num_results = 0;
}

void free_results() {
  for (int i = 0; i < num_results; i++) {
    free(results[i].ip);
    free(results[i].hostname);
  }
  free(results);
}

int scan_network(char *interface) {
  int sockfd;
  struct sockaddr_in addr;
  struct hostent *host;
  char *ip;
  char *hostname;

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return -1;
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);

  if (setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &sockfd, sizeof(sockfd)) == -1) {
    perror("setsockopt");
    return -1;
  }

  if (sendto(sockfd, "ping", 4, 0, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("sendto");
    return -1;
  }

  fd_set rfds;
  struct timeval tv;

  tv.tv_sec = TIMEOUT;
  tv.tv_usec = 0;

  while (1) {
    FD_ZERO(&rfds);
    FD_SET(sockfd, &rfds);

    if (select(sockfd + 1, &rfds, NULL, NULL, &tv) == -1) {
      perror("select");
      return -1;
    }

    if (FD_ISSET(sockfd, &rfds)) {
      char buf[1024];
      int addrlen = sizeof(addr);

      if (recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&addr, &addrlen) == -1) {
        perror("recvfrom");
        return -1;
      }

      ip = inet_ntoa(addr.sin_addr);
      host = gethostbyaddr((char *)&addr.sin_addr, sizeof(addr.sin_addr), AF_INET);
      if (host != NULL) {
        hostname = host->h_name;
      } else {
        hostname = "(unknown)";
      }

      results[num_results].ip = strdup(ip);
      results[num_results].hostname = strdup(hostname);
      num_results++;

      if (num_results >= MAX_RESULTS) {
        break;
      }
    } else {
      break;
    }
  }

  close(sockfd);

  return 0;
}

void print_results() {
  printf("Found %d devices:\n", num_results);
  for (int i = 0; i < num_results; i++) {
    printf("%s (%s)\n", results[i].ip, results[i].hostname);
  }
}

int main(int argc, char **argv) {
  init_results();

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <interface>", argv[0]);
    return 1;
  }

  if (scan_network(argv[1]) == -1) {
    return 1;
  }

  print_results();
  free_results();

  return 0;
}