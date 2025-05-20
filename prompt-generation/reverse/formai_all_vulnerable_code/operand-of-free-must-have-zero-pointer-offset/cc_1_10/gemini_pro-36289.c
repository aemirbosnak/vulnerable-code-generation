//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: romantic
#include <stdio.h>
#include <netdb.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define PORT 80
#define MAX_SIZE 2000

char *trim(char *s) {
  char *p = s;
  while (*p && isspace(*p)) p++;
  if (*p == 0) return p;
  char *e = p + strlen(p) - 1;
  while (e > p && isspace(*e)) e--;
  int len = e - p + 1;
  if (len <= 0) return p;
  char *t = malloc(len + 1);
  if (t == NULL) return NULL;
  memcpy(t, p, len);
  t[len] = 0;
  return t;
}

int ping(const char *host) {
  struct hostent *he;
  struct sockaddr_in addr;
  int sockfd, ret;
  struct timeval start, end;

  he = gethostbyname(host);
  if (he == NULL) {
    herror("gethostbyname");
    return -1;
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return -1;
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr = *((struct in_addr *)he->h_addr);

  gettimeofday(&start, NULL);
  ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
  gettimeofday(&end, NULL);
  close(sockfd);

  if (ret < 0) {
    perror("connect");
    return -1;
  }

  return (int)((end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000);
}

int main() {
  char ssid[MAX_SIZE];
  int strength;
  FILE *fp;

  fp = fopen("/proc/net/wireless", "r");
  if (fp == NULL) {
    perror("fopen");
    return -1;
  }

  while (fgets(ssid, MAX_SIZE, fp) != NULL) {
    char *p;

    if (strstr(ssid, "SSID") != NULL) {
      p = trim(ssid + 6);
      printf("SSID: %s\n", p);
      free(p);
    } else if (strstr(ssid, "Link Quality") != NULL) {
      strength = atoi(ssid + 14);
      printf("Signal Strength: %d%% (%d/70 dBm)\n", strength, ((strength * 100) / 70) - 100);
    }
  }

  fclose(fp);

  int ping_result = ping("google.com");
  if (ping_result < 0) {
    printf("Ping failed\n");
  } else {
    printf("Ping: %d ms\n", ping_result);
  }

  return 0;
}