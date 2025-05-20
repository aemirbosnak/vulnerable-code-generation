//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

#define MAX_URLS 100
#define MAX_URL_LENGTH 256
#define DEFAULT_INTERVAL 60
#define DEFAULT_TIMEOUT 10

struct url {
  char *url;
  int interval;
  int timeout;
  time_t last_check;
  int status;
};

struct url urls[MAX_URLS];
int num_urls = 0;

int sockfd;

void sigint_handler(int signum)
{
  close(sockfd);
  exit(0);
}

int main(int argc, char **argv)
{
  int i, j;
  char *filename;
  FILE *fp;
  char line[MAX_URL_LENGTH];
  char *url;
  int interval;
  int timeout;
  struct sockaddr_in servaddr;
  char buf[1024];
  int n;
  int status;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s filename\n", argv[0]);
    exit(1);
  }

  filename = argv[1];

  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("fopen");
    exit(1);
  }

  while (fgets(line, sizeof(line), fp) != NULL) {
    if (sscanf(line, "%s %d %d", &url, &interval, &timeout) != 3) {
      fprintf(stderr, "Invalid line: %s\n", line);
      continue;
    }

    if (strlen(url) > MAX_URL_LENGTH) {
      fprintf(stderr, "URL too long: %s\n", url);
      continue;
    }

    if (interval <= 0) {
      fprintf(stderr, "Invalid interval: %d\n", interval);
      continue;
    }

    if (timeout <= 0) {
      fprintf(stderr, "Invalid timeout: %d\n", timeout);
      continue;
    }

    urls[num_urls].url = strdup(url);
    urls[num_urls].interval = interval;
    urls[num_urls].timeout = timeout;
    urls[num_urls].last_check = 0;
    urls[num_urls].status = -1;

    num_urls++;
  }

  fclose(fp);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(80);

  signal(SIGINT, sigint_handler);

  while (1) {
    for (i = 0; i < num_urls; i++) {
      if (time(NULL) - urls[i].last_check >= urls[i].interval) {
        if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
          perror("connect");
          urls[i].status = -1;
        } else {
          sprintf(buf, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", urls[i].url, urls[i].url);
          if (send(sockfd, buf, strlen(buf), 0) == -1) {
            perror("send");
            urls[i].status = -1;
          } else {
            n = recv(sockfd, buf, sizeof(buf), 0);
            if (n == -1) {
              perror("recv");
              urls[i].status = -1;
            } else {
              buf[n] = '\0';
              if (strstr(buf, "200 OK") != NULL) {
                urls[i].status = 0;
              } else {
                urls[i].status = -1;
              }
            }
          }
        }

        close(sockfd);

        urls[i].last_check = time(NULL);
      }
    }

    for (i = 0; i < num_urls; i++) {
      if (urls[i].status == -1) {
        printf("%s: down\n", urls[i].url);
      } else {
        printf("%s: up\n", urls[i].url);
      }
    }

    sleep(DEFAULT_INTERVAL);
  }

  return 0;
}