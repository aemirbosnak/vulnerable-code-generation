//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 4096

typedef struct ProxyStruct {
  char hostname[256];
  int port;
  struct ProxyStruct* next;
} ProxyStruct;

ProxyStruct* proxy_head = NULL;

void add_proxy(char* hostname, int port) {
  ProxyStruct* new_proxy = malloc(sizeof(ProxyStruct));
  strcpy(new_proxy->hostname, hostname);
  new_proxy->port = port;
  new_proxy->next = NULL;

  if (proxy_head == NULL) {
    proxy_head = new_proxy;
  } else {
    ProxyStruct* current_proxy = proxy_head;
    while (current_proxy->next) {
      current_proxy = current_proxy->next;
    }
    current_proxy->next = new_proxy;
  }
}

void proxy_handler(int sockfd) {
  char buffer[MAX_BUFFER_SIZE];
  int read_bytes = read(sockfd, buffer, MAX_BUFFER_SIZE);
  if (read_bytes > 0) {
    int i = 0;
    for (i = 0; i < read_bytes; i++) {
      printf("%c", buffer[i]);
    }
  }
  close(sockfd);
}

int main() {
  add_proxy("localhost", 8080);
  add_proxy("127.0.0.1", 8080);

  int sockfd;
  struct sockaddr_in client_addr;
  socklen_t client_len;

  while (1) {
    sockfd = accept(proxy_head->port, (struct sockaddr *)&client_addr, &client_len);
    if (sockfd > 0) {
      proxy_handler(sockfd);
    }
  }

  return 0;
}