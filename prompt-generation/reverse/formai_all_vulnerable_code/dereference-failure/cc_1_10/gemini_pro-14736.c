//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define DEFAULT_PORT 110
#define MAX_BUF 1024

void welcome(int sockfd) {
  char buf[MAX_BUF];

  recv(sockfd, buf, MAX_BUF, 0);
  printf("%s", buf);
}

int login(int sockfd, const char *username, const char *password) {
  char buf[MAX_BUF];
  int len;

  snprintf(buf, MAX_BUF, "USER %s\r\n", username);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send USER");
    return -1;
  }

  recv(sockfd, buf, MAX_BUF, 0);
  printf("%s", buf);

  snprintf(buf, MAX_BUF, "PASS %s\r\n", password);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send PASS");
    return -1;
  }

  recv(sockfd, buf, MAX_BUF, 0);
  if (strncmp(buf, "+OK", 3) != 0) {
    printf("Login failed\n");
    return -1;
  }

  return 0;
}

void stat(int sockfd) {
  char buf[MAX_BUF];

  snprintf(buf, MAX_BUF, "STAT\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send STAT");
    return;
  }

  recv(sockfd, buf, MAX_BUF, 0);
  printf("%s", buf);
}

void list(int sockfd) {
  char buf[MAX_BUF];

  snprintf(buf, MAX_BUF, "LIST\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send LIST");
    return;
  }

  while (1) {
    recv(sockfd, buf, MAX_BUF, 0);
    if (strncmp(buf, ".", 1) == 0) {
      break;
    }
    printf("%s", buf);
  }
}

void retr(int sockfd, int num) {
  char buf[MAX_BUF];
  int len;

  snprintf(buf, MAX_BUF, "RETR %d\r\n", num);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send RETR");
    return;
  }

  while (1) {
    recv(sockfd, buf, MAX_BUF, 0);
    if (strncmp(buf, ".", 1) == 0) {
      break;
    }
    printf("%s", buf);
  }
}

void dele(int sockfd, int num) {
  char buf[MAX_BUF];
  int len;

  snprintf(buf, MAX_BUF, "DELE %d\r\n", num);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send DELE");
    return;
  }

  recv(sockfd, buf, MAX_BUF, 0);
  printf("%s", buf);
}

void quit(int sockfd) {
  char buf[MAX_BUF];

  snprintf(buf, MAX_BUF, "QUIT\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send QUIT");
    return;
  }

  recv(sockfd, buf, MAX_BUF, 0);
  printf("%s", buf);
}

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  int port;

  if (argc < 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  port = atoi(argv[2]);
  if (port <= 0) {
    fprintf(stderr, "Invalid port number\n");
    exit(1);
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Error resolving hostname\n");
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  serv_addr.sin_addr = *((struct in_addr *)server->h_addr);
  memset(&(serv_addr.sin_zero), '\0', 8);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
    perror("connect");
    exit(1);
  }

  welcome(sockfd);
  if (login(sockfd, "username", "password") == -1) {
    exit(1);
  }

  stat(sockfd);
  list(sockfd);

  retr(sockfd, 1);
  dele(sockfd, 1);

  quit(sockfd);

  close(sockfd);

  return 0;
}