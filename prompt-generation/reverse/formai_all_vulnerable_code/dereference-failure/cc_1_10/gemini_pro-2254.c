//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: asynchronous
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <poll.h>
#include <pthread.h>

typedef struct url_data {
  char *url;
  int port;
  int sockfd;
  bool is_up;
  pthread_mutex_t mutex;
} url_data;

typedef struct global_data {
  int num_urls;
  url_data *urls;
} global_data;

void *monitor_thread(void *arg) {
  global_data *data = (global_data *)arg;
  while (true) {
    for (int i = 0; i < data->num_urls; i++) {
      url_data *url = &data->urls[i];
      pthread_mutex_lock(&url->mutex);
      if (url->is_up) {
        url->is_up = send_request(url->sockfd);
        if (!url->is_up) {
          printf("%s is now down\n", url->url);
        }
      } else {
        url->is_up = send_request(url->sockfd);
        if (url->is_up) {
          printf("%s is now up\n", url->url);
        }
      }
      pthread_mutex_unlock(&url->mutex);
    }
    sleep(1);
  }
}

int send_request(int sockfd) {
  char request[] = "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n";
  int n = write(sockfd, request, strlen(request));
  if (n < 0) {
    return false;
  }
  char buf[1024];
  n = read(sockfd, buf, sizeof(buf));
  if (n < 0) {
    return false;
  }
  return (strstr(buf, "HTTP/1.1 200 OK") != NULL);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <url> [<url> ...]\n", argv[0]);
    return 1;
  }
  global_data data;
  data.num_urls = argc - 1;
  data.urls = (url_data *)malloc(sizeof(url_data) * data.num_urls);
  for (int i = 0; i < data.num_urls; i++) {
    data.urls[i].url = argv[i + 1];
    data.urls[i].port = 80;
    data.urls[i].is_up = false;
    pthread_mutex_init(&data.urls[i].mutex, NULL);
    struct sockaddr_in addr;
    struct hostent *host = gethostbyname(data.urls[i].url);
    if (host == NULL) {
      printf("Invalid hostname: %s\n", data.urls[i].url);
      free(data.urls);
      return 1;
    }
    addr.sin_family = AF_INET;
    addr.sin_port = htons(data.urls[i].port);
    memcpy(&addr.sin_addr, host->h_addr_list[0], host->h_length);
    data.urls[i].sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (data.urls[i].sockfd == -1) {
      perror("socket");
      free(data.urls);
      return 1;
    }
    if (connect(data.urls[i].sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
      perror("connect");
      free(data.urls);
      return 1;
    }
  }
  pthread_t tid;
  if (pthread_create(&tid, NULL, monitor_thread, &data) != 0) {
    perror("pthread_create");
    free(data.urls);
    return 1;
  }
  pthread_join(tid, NULL);
  free(data.urls);
  return 0;
}