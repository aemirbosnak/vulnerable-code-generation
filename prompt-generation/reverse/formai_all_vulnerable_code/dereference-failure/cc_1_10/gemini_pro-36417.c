//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define BUFSIZE 1024
#define PORT 8080

struct sockaddr_in servaddr;

void *send_data(void *arg) {
  int sockfd = *(int *)arg;
  char buf[BUFSIZE];

  while (1) {
    memset(buf, 0, BUFSIZE);
    snprintf(buf, BUFSIZE, "Hello from client %d\n", sockfd);
    sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    sleep(1);
  }

  return NULL;
}

void *recv_data(void *arg) {
  int sockfd = *(int *)arg;
  char buf[BUFSIZE];
  struct sockaddr_in cliaddr;
  socklen_t len = sizeof(cliaddr);

  while (1) {
    memset(buf, 0, BUFSIZE);
    recvfrom(sockfd, buf, BUFSIZE, 0, (struct sockaddr *)&cliaddr, &len);
    printf("%s", buf);
  }

  return NULL;
}

int main(int argc, char **argv) {
  int sockfd;
  pthread_t send_tid, recv_tid;
  struct hostent *host;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <server IP address>\n", argv[0]);
    exit(1);
  }

  host = gethostbyname(argv[1]);
  if (host == NULL) {
    fprintf(stderr, "Error: could not resolve hostname %s\n", argv[1]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
    perror("Error: could not create socket");
    exit(1);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);

  if (pthread_create(&send_tid, NULL, &send_data, (void *)&sockfd) != 0) {
    perror("Error: could not create send thread");
    exit(1);
  }

  if (pthread_create(&recv_tid, NULL, &recv_data, (void *)&sockfd) != 0) {
    perror("Error: could not create receive thread");
    exit(1);
  }

  pthread_join(send_tid, NULL);
  pthread_join(recv_tid, NULL);

  close(sockfd);

  return 0;
}