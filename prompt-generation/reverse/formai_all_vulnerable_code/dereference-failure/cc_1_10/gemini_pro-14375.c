//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define BUFSIZE 1024
#define MAX_URLS 100
#define TIME_BETWEEN_CHECKS 60

typedef struct {
  char *url;
  time_t last_checked;
  int status_code;
} website;

website websites[MAX_URLS];
int num_websites = 0;

void add_website(char *url) {
  if (num_websites >= MAX_URLS) {
    fprintf(stderr, "Error: too many websites added.\n");
    exit(1);
  }

  websites[num_websites].url = strdup(url);
  websites[num_websites].last_checked = time(NULL);
  websites[num_websites].status_code = 0;
  num_websites++;
}

int check_website(website *website) {
  char buf[BUFSIZE];
  struct timeval start, end;

  gettimeofday(&start, NULL);

  FILE *fp = popen(website->url, "r");
  if (fp == NULL) {
    perror("popen");
    return -1;
  }

  int status_code = 0;
  while (fgets(buf, BUFSIZE, fp) != NULL) {
    if (strstr(buf, "HTTP/1.1 ") != NULL) {
      status_code = atoi(buf + 9);
      break;
    }
  }

  pclose(fp);

  gettimeofday(&end, NULL);

  long long milliseconds = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;

  printf("%s: %d (%lld ms)\n", website->url, status_code, milliseconds);

  website->last_checked = time(NULL);
  website->status_code = status_code;

  return 0;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s url1 url2 ...\n", argv[0]);
    exit(1);
  }

  for (int i = 1; i < argc; i++) {
    add_website(argv[i]);
  }

  while (1) {
    for (int i = 0; i < num_websites; i++) {
      if (time(NULL) - websites[i].last_checked >= TIME_BETWEEN_CHECKS) {
        check_website(&websites[i]);
      }
    }

    sleep(TIME_BETWEEN_CHECKS);
  }

  return 0;
}