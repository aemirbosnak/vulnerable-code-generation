//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#define MAX_DATA_SIZE 1024

int create_socket(int *sockfd) {
  *sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (*sockfd < 0) {
    perror("Error creating socket");
    return -1;
  }
  return 0;
}

int connect_socket(int sockfd, char *host, int port) {
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(host);
  server_addr.sin_port = htons(port);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting to server");
    return -1;
  }
  return 0;
}

int send_data(int sockfd, char *data, int data_size) {
  if (send(sockfd, data, data_size, 0) < 0) {
    perror("Error sending data");
    return -1;
  }
  return 0;
}

int receive_data(int sockfd, char *data, int data_size) {
  if (recv(sockfd, data, data_size, 0) < 0) {
    perror("Error receiving data");
    return -1;
  }
  return 0;
}

int ping_host(char *host, int port) {
  int sockfd;
  char data[MAX_DATA_SIZE];
  struct timeval start, end;

  if (create_socket(&sockfd) < 0) {
    return -1;
  }

  if (connect_socket(sockfd, host, port) < 0) {
    close(sockfd);
    return -1;
  }

  strcpy(data, "PING");
  if (send_data(sockfd, data, strlen(data)) < 0) {
    close(sockfd);
    return -1;
  }

  gettimeofday(&start, NULL);
  if (receive_data(sockfd, data, strlen(data)) < 0) {
    close(sockfd);
    return -1;
  }
  gettimeofday(&end, NULL);

  close(sockfd);

  long elapsed_time = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
  printf("Ping to %s: %ld microseconds\n", host, elapsed_time);

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <host> <port>\n", argv[0]);
    return -1;
  }

  if (ping_host(argv[1], atoi(argv[2])) < 0) {
    return -1;
  }

  return 0;
}