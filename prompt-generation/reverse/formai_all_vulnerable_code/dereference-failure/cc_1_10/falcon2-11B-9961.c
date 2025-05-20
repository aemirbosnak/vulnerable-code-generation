//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char **argv) {
  int sockfd, n;
  struct sockaddr_in serveraddr;
  struct hostent *server;
  char buffer[MAX_BUFFER_SIZE];

  if (argc!= 3) {
    fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
    exit(1);
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Hostname not found\n");
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Socket creation error");
    exit(1);
  }

  serveraddr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
  serveraddr.sin_port = htons(atoi(argv[2]));

  if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
    perror("Connection error");
    exit(1);
  }

  n = read(sockfd, buffer, MAX_BUFFER_SIZE);
  printf("Received message: %s\n", buffer);

  if (n < 0) {
    perror("Read error");
    exit(1);
  }

  n = write(sockfd, "Hello, World!", strlen("Hello, World!"));
  if (n < 0) {
    perror("Write error");
    exit(1);
  }

  close(sockfd);
  return 0;
}