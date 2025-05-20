//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[])
{
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[MAX_BUF_SIZE];

  if (argc < 3)
  {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
  {
    fprintf(stderr, "Error opening socket: %s\n", strerror(errno));
    exit(1);
  }

  server = gethostbyname(argv[1]);
  if (server == NULL)
  {
    fprintf(stderr, "Error getting host by name: %s\n", strerror(errno));
    exit(1);
  }

  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  {
    fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
    exit(1);
  }

  memset(buffer, 0, MAX_BUF_SIZE);
  strcpy(buffer, "A000 LOGIN USERNAME_HERE PASSWORD_HERE\r\n");
  n = write(sockfd, buffer, strlen(buffer));
  if (n < 0)
  {
    fprintf(stderr, "Error writing to socket: %s\n", strerror(errno));
    exit(1);
  }

  memset(buffer, 0, MAX_BUF_SIZE);
  n = read(sockfd, buffer, MAX_BUF_SIZE - 1);
  if (n < 0)
  {
    fprintf(stderr, "Error reading from socket: %s\n", strerror(errno));
    exit(1);
  }

  printf("%s\n", buffer);

  close(sockfd);

  return 0;
}