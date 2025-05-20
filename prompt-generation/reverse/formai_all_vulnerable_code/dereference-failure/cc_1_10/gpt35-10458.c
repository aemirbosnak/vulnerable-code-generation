//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <sys/types.h>

#define BUF_SIZE 1024
#define MAX_HOST_LEN 256
#define MAX_PORT_LEN 6
#define LOGIN_STR "LOGIN username password\r\n"
#define LIST_STR "LIST\r\n"
#define SELECT_STR "SELECT INBOX\r\n"

int connect_to_server(char *hostname, char *port) {
  struct addrinfo hints = { 0 };
  struct addrinfo *res, *ai;
  int sockfd, ret;

  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if ((ret = getaddrinfo(hostname, port, &hints, &res)) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
    return -1;
  }

  for (ai = res; ai != NULL; ai = ai->ai_next) {
    if ((sockfd = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol)) == -1) {
      perror("socket");
      continue;
    }

    if (connect(sockfd, ai->ai_addr, ai->ai_addrlen) == -1) {
      perror("connect");
      close(sockfd);
      continue;
    }

    freeaddrinfo(res);
    return sockfd;
  }

  return -1;
}

int imap_login(int sockfd, char *username, char *password) {
  char buf[BUF_SIZE] = { 0 };
  int n;

  sprintf(buf, LOGIN_STR, username, password);
  n = strlen(buf);
  if (write(sockfd, buf, n) != n) {
    perror("write");
    return -1;
  }

  n = read(sockfd, buf, BUF_SIZE - 1);
  if (n == -1) {
    perror("read");
    return -1;
  }

  if (strncmp(buf, "OK", 2)) {
    fprintf(stderr, "login failed: %s\n", buf);
    return -1;
  }

  return 0;
}

int imap_list(int sockfd) {
  char buf[BUF_SIZE] = { 0 };
  int n;

  sprintf(buf, LIST_STR);
  n = strlen(buf);
  if (write(sockfd, buf, n) != n) {
    perror("write");
    return -1;
  }

  n = read(sockfd, buf, BUF_SIZE - 1);
  if (n == -1) {
    perror("read");
    return -1;
  }

  printf("mailboxes:\n%s\n", buf);
  return 0;
}

int imap_select(int sockfd, char *mailbox) {
  char buf[BUF_SIZE] = { 0 };
  int n;

  sprintf(buf, SELECT_STR);
  n = strlen(buf);
  if (write(sockfd, buf, n) != n) {
    perror("write");
    return -1;
  }

  n = read(sockfd, buf, BUF_SIZE - 1);
  if (n == -1) {
    perror("read");
    return -1;
  }

  if (strncmp(buf, "OK", 2)) {
    fprintf(stderr, "select failed: %s\n", buf);
    return -1;
  }

  printf("selected mailbox: %s\n", mailbox);
  return 0;
}

int main(int argc, char **argv) {
  char hostname[MAX_HOST_LEN], port[MAX_PORT_LEN], username[MAX_HOST_LEN], password[MAX_HOST_LEN];

  if (argc != 5) {
    fprintf(stderr, "usage: %s hostname port username password\n", argv[0]);
    exit(1);
  }
  
  strncpy(hostname, argv[1], MAX_HOST_LEN - 1);
  strncpy(port, argv[2], MAX_PORT_LEN - 1);
  strncpy(username, argv[3], MAX_HOST_LEN - 1);
  strncpy(password, argv[4], MAX_HOST_LEN - 1);

  int sockfd = connect_to_server(hostname, port);
  if (sockfd == -1) {
    fprintf(stderr, "could not connect to server\n");
    exit(1);
  }

  if (imap_login(sockfd, username, password) == -1) {
    fprintf(stderr, "could not log in to server\n");
    exit(1);
  }

  if (imap_list(sockfd) == -1) {
    fprintf(stderr, "could not list mailboxes\n");
    exit(1);
  }

  if (imap_select(sockfd, "INBOX") == -1) {
    fprintf(stderr, "could not select mailbox\n");
    exit(1);
  }

  close(sockfd);
  return 0;
}