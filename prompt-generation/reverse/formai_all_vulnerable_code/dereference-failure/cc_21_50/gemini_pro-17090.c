//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netdb.h>
#include <sys/socket.h>

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <server> <port> <message>\n", argv[0]);
    return 1;
  }

  char *server = argv[1];
  int port = atoi(argv[2]);
  char *message = argv[3];

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(server);
  server_addr.sin_port = htons(port);

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    return 1;
  }

  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return 1;
  }

  char buf[1024];
  int n;

  while ((n = read(sock, buf, sizeof(buf))) > 0) {
    printf("%s", buf);
  }

  if (n == -1) {
    perror("read");
    return 1;
  }

  sprintf(buf, "HELO %s\r\n", server);
  if (send(sock, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  while ((n = read(sock, buf, sizeof(buf))) > 0) {
    printf("%s", buf);
  }

  if (n == -1) {
    perror("read");
    return 1;
  }

  sprintf(buf, "MAIL FROM: <%s>\r\n", argv[4]);
  if (send(sock, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  while ((n = read(sock, buf, sizeof(buf))) > 0) {
    printf("%s", buf);
  }

  if (n == -1) {
    perror("read");
    return 1;
  }

  sprintf(buf, "RCPT TO: <%s>\r\n", argv[5]);
  if (send(sock, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  while ((n = read(sock, buf, sizeof(buf))) > 0) {
    printf("%s", buf);
  }

  if (n == -1) {
    perror("read");
    return 1;
  }

  sprintf(buf, "DATA\r\n");
  if (send(sock, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  while ((n = read(sock, buf, sizeof(buf))) > 0) {
    printf("%s", buf);
  }

  if (n == -1) {
    perror("read");
    return 1;
  }

  sprintf(buf, "%s\r\n.\r\n", message);
  if (send(sock, buf, strlen(buf), 0) == -1) {
    perror("send");
    return 1;
  }

  while ((n = read(sock, buf, sizeof(buf))) > 0) {
    printf("%s", buf);
  }

  if (n == -1) {
    perror("read");
    return 1;
  }

  close(sock);

  return 0;
}