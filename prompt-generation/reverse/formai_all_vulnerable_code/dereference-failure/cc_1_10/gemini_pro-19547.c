//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

#define URL_SIZE 256
#define MAX_URLS 10

char urls[MAX_URLS][URL_SIZE];
int num_urls;
int interval;

void read_config() {
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  FILE *config = fopen("uptime.conf", "r");
  if (config == NULL) {
    perror("fopen");
    exit(1);
  }

  while ((read = getline(&line, &len, config)) != -1) {
    if (line[0] == '#') {
      continue;
    }

    if (strncmp(line, "url=", 4) == 0) {
      if (num_urls >= MAX_URLS) {
        fprintf(stderr, "Too many URLs in config file.\n");
        exit(1);
      }

      strncpy(urls[num_urls], line + 4, URL_SIZE - 1);
      urls[num_urls][URL_SIZE - 1] = '\0';
      num_urls++;
    } else if (strncmp(line, "interval=", 9) == 0) {
      interval = atoi(line + 9);
      if (interval <= 0) {
        fprintf(stderr, "Invalid interval in config file.\n");
        exit(1);
      }
    }
  }

  fclose(config);
}

int check_url(char *url) {
  int fd;
  char buffer[1024];
  ssize_t bytes_read;

  fd = open(url, O_RDONLY);
  if (fd == -1) {
    return -1;
  }

  bytes_read = read(fd, buffer, sizeof(buffer) - 1);
  if (bytes_read == -1) {
    close(fd);
    return -1;
  }

  buffer[bytes_read] = '\0';

  close(fd);

  return 0;
}

int main() {
  int i;
  int status;

  read_config();

  while (1) {
    for (i = 0; i < num_urls; i++) {
      status = check_url(urls[i]);
      if (status != 0) {
        fprintf(stderr, "URL %s is down.\n", urls[i]);
      }
    }

    sleep(interval);
  }

  return 0;
}