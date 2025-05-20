//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: mind-bending
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>
#include <errno.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_URLS 100
#define MAX_URL_LEN 256
#define MAX_TIME_SECS 3600
#define MAX_CONNS 10

typedef struct {
  char url[MAX_URL_LEN];
  int time_secs;
  bool active;
} url_t;

url_t urls[MAX_URLS];
int num_urls;
int num_conns;
int interval;

void *monitor_thread(void *arg) {
  int sockfd, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];
  int i = 0;
  while (1) {
    if (i == num_urls) {
      i = 0;
    }
    if (!urls[i].active) {
      i++;
      continue;
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
      perror("ERROR opening socket");
      exit(1);
    }
    server = gethostbyname(urls[i].url);
    if (server == NULL) {
      perror("ERROR, no such host");
      exit(1);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
      perror("ERROR connecting");
      exit(1);
    }
    n = write(sockfd, "HEAD / HTTP/1.1\r\nHost: ", 27);
    if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
    }
    n = write(sockfd, urls[i].url, strlen(urls[i].url));
    if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
    }
    n = write(sockfd, "\r\n\r\n", 4);
    if (n < 0) {
      perror("ERROR writing to socket");
      exit(1);
    }
    n = read(sockfd, buffer, 255);
    if (n < 0) {
      perror("ERROR reading from socket");
      exit(1);
    }
    buffer[n] = '\0';
    if (strstr(buffer, "200 OK") != NULL) {
      printf("%s is up\n", urls[i].url);
    } else {
      printf("%s is down\n", urls[i].url);
    }
    close(sockfd);
    i++;
    sleep(interval);
  }
}

int main(int argc, char *argv[]) {
  int i;
  if (argc < 4) {
    printf("Usage: %s <urls> <interval> <num_conns>\n", argv[0]);
    exit(1);
  }
  num_urls = argc - 3;
  if (num_urls > MAX_URLS) {
    printf("Too many URLs. Max: %d\n", MAX_URLS);
    exit(1);
  }
  for (i = 0; i < num_urls; i++) {
    strncpy(urls[i].url, argv[i + 1], MAX_URL_LEN);
    urls[i].active = true;
  }
  interval = atoi(argv[argc - 2]);
  if (interval > MAX_TIME_SECS) {
    printf("Interval too large. Max: %d\n", MAX_TIME_SECS);
    exit(1);
  }
  num_conns = atoi(argv[argc - 1]);
  if (num_conns > MAX_CONNS) {
    printf("Too many connections. Max: %d\n", MAX_CONNS);
    exit(1);
  }
  pthread_t threads[num_conns];
  for (i = 0; i < num_conns; i++) {
    pthread_create(&threads[i], NULL, monitor_thread, NULL);
  }
  for (i = 0; i < num_conns; i++) {
    pthread_join(threads[i], NULL);
  }
  return 0;
}