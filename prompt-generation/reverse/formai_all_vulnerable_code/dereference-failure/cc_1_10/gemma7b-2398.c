//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_HOSTS 255

typedef struct HostEntry {
  char hostname[255];
  int port;
  struct HostEntry* next;
} HostEntry;

HostEntry* addHostEntry(HostEntry* head, char* hostname, int port) {
  HostEntry* newEntry = (HostEntry*)malloc(sizeof(HostEntry));
  strcpy(newEntry->hostname, hostname);
  newEntry->port = port;
  newEntry->next = NULL;

  if (head == NULL) {
    return newEntry;
  }

  head->next = newEntry;
  return head;
}

int main() {
  HostEntry* hosts = NULL;

  // Add hosts to the list
  addHostEntry(hosts, "localhost", 80);
  addHostEntry(hosts, "192.168.1.1", 80);
  addHostEntry(hosts, "10.0.0.1", 80);

  // Ping each host
  for (HostEntry* host = hosts; host; host = host->next) {
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(2));
    struct sockaddr_in servaddr;

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(host->port);
    servaddr.sin_addr.s_addr = inet_addr(host->hostname);

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == 0) {
      printf("Host: %s, Port: %d, Status: Online\n", host->hostname, host->port);
    } else {
      printf("Host: %s, Port: %d, Status: Offline\n", host->hostname, host->port);
    }

    close(sockfd);
  }

  return 0;
}