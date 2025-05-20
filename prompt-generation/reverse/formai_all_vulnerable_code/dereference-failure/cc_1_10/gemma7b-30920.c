//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <time.h>

#define MAX_HOSTS 10

struct Host {
  char name[256];
  int port;
  struct Host* next;
};

void monitor(struct Host* hosts) {
  time_t now = time(NULL);
  for (struct Host* h = hosts; h; h = h->next) {
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(h->port));
    if (sockfd == -1) {
      perror("Error creating socket");
      continue;
    }
    struct sockaddr_in srv_addr;
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(h->port);
    srv_addr.sin_addr.s_addr = inet_addr(h->name);

    if (connect(sockfd, (struct sockaddr*)&srv_addr, sizeof(srv_addr)) == -1) {
      perror("Error connecting to host");
      close(sockfd);
      continue;
    }
    close(sockfd);
    printf("%s is alive at %ld\n", h->name, now);
  }
}

int main() {
  struct Host* hosts = malloc(sizeof(struct Host) * MAX_HOSTS);
  hosts->next = NULL;

  // Add some hosts
  strcpy(hosts->name, "localhost");
  hosts->port = 8080;
  hosts->next = malloc(sizeof(struct Host) * MAX_HOSTS);

  strcpy(hosts->next->name, "example.com");
  hosts->next->port = 8081;
  hosts->next->next = NULL;

  monitor(hosts);

  return 0;
}