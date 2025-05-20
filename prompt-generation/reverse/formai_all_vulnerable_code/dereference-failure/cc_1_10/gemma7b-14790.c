//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define MAX_HOSTS 5

typedef struct HOST_DATA {
  char name[256];
  char ip[256];
  int port;
  struct HOST_DATA* next;
} HOST_DATA;

HOST_DATA* head = NULL;

void add_host(char* name, char* ip, int port) {
  HOST_DATA* new_host = malloc(sizeof(HOST_DATA));
  strcpy(new_host->name, name);
  strcpy(new_host->ip, ip);
  new_host->port = port;
  new_host->next = NULL;

  if (head == NULL) {
    head = new_host;
  } else {
    head->next = new_host;
  }
}

int main() {
  add_host("google.com", "8.8.8.8", 80);
  add_host("amazon.com", "169.254.16.5", 80);
  add_host("facebook.com", "10.14.1.1", 80);

  HOST_DATA* current_host = head;
  while (current_host) {
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(current_host->port);
    server_addr.sin_addr.s_addr = inet_addr(current_host->ip);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
      printf("%s is down.\n", current_host->name);
    } else {
      printf("%s is up.\n", current_host->name);
    }

    close(sockfd);
    current_host = current_host->next;
  }

  return 0;
}