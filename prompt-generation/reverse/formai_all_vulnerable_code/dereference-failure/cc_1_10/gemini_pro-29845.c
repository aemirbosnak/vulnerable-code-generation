//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#define PORT 21

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in serveraddr;
  struct hostent *server;
  char buffer[1024];
  char command[1024];
  char filename[1024];

  if (argc != 3) {
    printf("Usage: %s <hostname> <filename>\n", argv[0]);
    return 1;
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    printf("Error: could not resolve hostname %s\n", argv[1]);
    return 1;
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error: could not create socket\n");
    return 1;
  }

  memset(&serveraddr, 0, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(PORT);
  serveraddr.sin_addr = *(struct in_addr *)server->h_addr;

  if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
    printf("Error: could not connect to server\n");
    return 1;
  }

  sprintf(command, "USER anonymous\r\n");
  write(sockfd, command, strlen(command));
  read(sockfd, buffer, 1024);
  printf("%s", buffer);

  sprintf(command, "PASS anonymous@example.com\r\n");
  write(sockfd, command, strlen(command));
  read(sockfd, buffer, 1024);
  printf("%s", buffer);

  sprintf(command, "TYPE I\r\n");
  write(sockfd, command, strlen(command));
  read(sockfd, buffer, 1024);
  printf("%s", buffer);

  sprintf(command, "RETR %s\r\n", argv[2]);
  write(sockfd, command, strlen(command));
  read(sockfd, buffer, 1024);
  printf("%s", buffer);

  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    printf("Error: could not open file %s\n", filename);
    return 1;
  }

  while (read(sockfd, buffer, 1024) > 0) {
    fwrite(buffer, 1, 1024, fp);
  }

  fclose(fp);
  close(sockfd);
  return 0;
}