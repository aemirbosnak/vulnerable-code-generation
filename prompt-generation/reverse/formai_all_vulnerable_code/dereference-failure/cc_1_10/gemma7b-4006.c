//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_URL_LENGTH 255

typedef struct Monitor {
  char *url;
  int status_code;
  struct Monitor *next;
} Monitor;

void add_monitor(Monitor **head, char *url, int status_code) {
  Monitor *new_monitor = malloc(sizeof(Monitor));
  new_monitor->url = strdup(url);
  new_monitor->status_code = status_code;
  new_monitor->next = NULL;

  if (*head == NULL) {
    *head = new_monitor;
  } else {
    (*head)->next = new_monitor;
  }
}

void check_monitors(Monitor *head) {
  for (Monitor *monitor = head; monitor; monitor = monitor->next) {
    int actual_status_code = check_website_status(monitor->url);
    if (actual_status_code != monitor->status_code) {
      printf("Error: URL %s has changed status code from %d to %d\n", monitor->url, monitor->status_code, actual_status_code);
    }
  }
}

int check_website_status(char *url) {
  int sockfd, port = 80;
  struct sockaddr_in serv_addr;

  if ((sockfd = socket(AF_INET, SOCK_STREAM, htons(port))) < 0) {
    return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  serv_addr.sin_addr.s_addr = inet_addr(url);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    return -1;
  }

  close(sockfd);
  return 200;
}

int main() {
  Monitor *head = NULL;

  add_monitor(&head, "google.com", 200);
  add_monitor(&head, "facebook.com", 200);
  add_monitor(&head, "amazon.com", 200);

  check_monitors(head);

  return 0;
}