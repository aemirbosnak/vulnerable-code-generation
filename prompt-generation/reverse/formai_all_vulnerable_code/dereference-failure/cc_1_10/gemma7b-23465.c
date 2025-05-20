//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_HOSTS 10

typedef struct HOST {
  char name[256];
  int port;
  struct HOST *next;
} HOST;

void draw_topology(HOST *host) {
  printf("Drawing topology...\n");
  while (host) {
    printf("%s (port %d) --> ", host->name, host->port);
    if (host->next) {
      printf("%s (port %d)\n", host->next->name, host->next->port);
    } else {
      printf("End\n");
    }
    host = host->next;
  }
}

int main() {
  HOST *head = NULL;
  HOST *host = NULL;

  // Create a few hosts
  for (int i = 0; i < MAX_HOSTS; i++) {
    host = (HOST *)malloc(sizeof(HOST));
    strcpy(host->name, "Host ");
    host->port = i + 10;
    host->next = NULL;

    if (head) {
      head->next = host;
      head = host;
    } else {
      head = host;
    }
  }

  // Draw the topology
  draw_topology(head);

  return 0;
}