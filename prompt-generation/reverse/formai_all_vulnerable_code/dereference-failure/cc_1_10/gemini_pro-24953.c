//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define MAX_BUF_SIZE 8192

int main(int argc, char **argv) {
  struct sockaddr_in server_addr;
  int sockfd, fd, x, y;
  char buffer[MAX_BUF_SIZE];
  char *host, *file;

  if (argc != 4) {
    fprintf(stderr, "Usage: %s <host> <file> <port>\n", argv[0]);
    exit(1);
  }

  host = argv[1];
  file = argv[2];
  y = atoi(argv[3]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Socket creation failed\n");
    exit(1);
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr =inet_addr(host);
  server_addr.sin_port = htons(y);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    fprintf(stderr, "Connection failed\n");
    exit(1);
  }

  fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fd < 0) {
    fprintf(stderr, "File open failed\n");
    exit(1);
  }

  while ((x = read(sockfd, buffer, MAX_BUF_SIZE)) > 0) {
    write(fd, buffer, x);
  }

  close(fd);
  close(sockfd);

  return 0;
}