//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define MAX_SITES 10

typedef struct Site {
  char name[256];
  int status;
  struct Site *next;
} Site;

Site *head = NULL;

void addSite(char *name) {
  Site *newSite = malloc(sizeof(Site));
  strcpy(newSite->name, name);
  newSite->status = 0;
  newSite->next = NULL;

  if (head == NULL) {
    head = newSite;
  } else {
    head->next = newSite;
  }
}

void checkSites() {
  Site *currentSite = head;
  while (currentSite) {
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
    struct sockaddr_in serverAddr;
    serverAddr.sin_port = htons(80);
    serverAddr.sin_family = AF_INET;
    inet_pton(AF_INET, currentSite->name, &serverAddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == 0) {
      currentSite->status = 1;
    } else {
      currentSite->status = 0;
    }

    close(sockfd);
    currentSite = currentSite->next;
  }
}

void drawSites() {
  Site *currentSite = head;
  printf("------------------------------------------------------------------------\n");
  printf("                                 Sites Status\n");
  printf("------------------------------------------------------------------------\n");

  while (currentSite) {
    printf("%s: ", currentSite->name);
    if (currentSite->status) {
      printf("Online\n");
    } else {
      printf("Offline\n");
    }

    currentSite = currentSite->next;
  }

  printf("------------------------------------------------------------------------\n");
}

int main() {
  addSite("google.com");
  addSite("facebook.com");
  addSite("amazon.com");

  checkSites();
  drawSites();

  return 0;
}