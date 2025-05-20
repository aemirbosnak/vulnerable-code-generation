//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUF_SIZE 1024

typedef struct {
  int sockfd;
  struct sockaddr_in addr;
} client_t;

typedef struct {
  int x;
  int y;
  int z;
  int w;
} controls_t;

client_t client;
controls_t controls;

void *client_thread(void *arg) {
  int n;
  char buf[BUF_SIZE];

  while ((n = read(client.sockfd, buf, BUF_SIZE)) > 0) {
    if (strncmp(buf, "up", 2) == 0) {
      controls.z++;
    } else if (strncmp(buf, "down", 4) == 0) {
      controls.z--;
    } else if (strncmp(buf, "left", 4) == 0) {
      controls.x--;
    } else if (strncmp(buf, "right", 5) == 0) {
      controls.x++;
    } else if (strncmp(buf, "forward", 7) == 0) {
      controls.y++;
    } else if (strncmp(buf, "backward", 8) == 0) {
      controls.y--;
    } else if (strncmp(buf, "cw", 2) == 0) {
      controls.w++;
    } else if (strncmp(buf, "ccw", 3) == 0) {
      controls.w--;
    } else if (strncmp(buf, "stop", 4) == 0) {
      controls.x = 0;
      controls.y = 0;
      controls.z = 0;
      controls.w = 0;
    } else if (strncmp(buf, "exit", 4) == 0) {
      close(client.sockfd);
      exit(0);
    }
  }

  if (n == 0) {
    printf("Client disconnected\n");
    close(client.sockfd);
    exit(0);
  } else if (n < 0) {
    perror("read");
    close(client.sockfd);
    exit(1);
  }

  return NULL;
}

int main(int argc, char **argv) {
  int sockfd;
  struct sockaddr_in addr;
  pthread_t thread;

  if (argc != 3) {
    fprintf(stderr, "usage: %s <ip> <port>\n", argv[0]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(argv[2]));
  addr.sin_addr.s_addr = inet_addr(argv[1]);

  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("connect");
    close(sockfd);
    exit(1);
  }

  client.sockfd = sockfd;
  client.addr = addr;

  pthread_create(&thread, NULL, client_thread, NULL);

  while (1) {
    printf("Controls: x=%d, y=%d, z=%d, w=%d\n", controls.x, controls.y, controls.z, controls.w);
    usleep(100000);  // 100ms
  }

  close(sockfd);

  return 0;
}