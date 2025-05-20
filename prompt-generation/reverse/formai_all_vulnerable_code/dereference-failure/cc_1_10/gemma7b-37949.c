//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define MAX_HOSTS 10

typedef struct Host {
  char name[256];
  int port;
  struct Host* next;
} Host;

Host* host_list = NULL;

void add_host(char* name, int port) {
  Host* new_host = malloc(sizeof(Host));
  strcpy(new_host->name, name);
  new_host->port = port;
  new_host->next = NULL;

  if (host_list == NULL) {
    host_list = new_host;
  } else {
    host_list->next = new_host;
    host_list = new_host;
  }
}

int main() {
  add_host("localhost", 80);
  add_host("google.com", 80);
  add_host("facebook.com", 80);

  for (Host* host = host_list; host; host = host->next) {
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(host->port));
    if (sockfd == -1) {
      perror("Error creating socket");
      exit(1);
    }

    char buffer[1024];
    if (send(sockfd, "HELLO WORLD", 13, 0) == -1) {
      perror("Error sending message");
      close(sockfd);
      exit(1);
    }

    if (recv(sockfd, buffer, 1024, 0) == -1) {
      perror("Error receiving message");
      close(sockfd);
      exit(1);
    }

    printf("Host: %s, Message: %s\n", host->name, buffer);
    close(sockfd);
  }

  return 0;
}