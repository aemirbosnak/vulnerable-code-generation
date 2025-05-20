//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_SITES 10

typedef struct site {
  char name[255];
  int port;
  struct site *next;
} site_t;

site_t *head = NULL;

void add_site(char *name, int port) {
  site_t *new_site = malloc(sizeof(site_t));
  strcpy(new_site->name, name);
  new_site->port = port;
  new_site->next = head;
  head = new_site;
}

int main() {
  add_site("google.com", 80);
  add_site("facebook.com", 80);
  add_site("amazon.com", 80);

  for (site_t *site = head; site; site = site->next) {
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(site->port));
    if (sockfd < 0) {
      perror("Error creating socket");
      exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(site->port);
    server_addr.sin_addr.s_addr = inet_addr(site->name);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      perror("Error connecting to server");
      exit(1);
    }

    printf("Site: %s, Port: %d, Status: Up\n", site->name, site->port);
  }

  return 0;
}