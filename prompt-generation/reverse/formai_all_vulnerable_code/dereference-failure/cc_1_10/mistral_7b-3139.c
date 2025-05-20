//MISTRAL-7B DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

void die(const char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <target> <port>\n", argv[0]);
    exit(1);
  }

  const char *target = argv[1];
  int port = atoi(argv[2]);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) die("socket");

  struct hostent *he = gethostbyname(target);
  if (!he) die("gethostbyname");

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  bcopy(he->h_addr, &server_addr.sin_addr.s_addr, he->h_length);

  int connfd = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (connfd < 0) {
    close(sockfd);
    die("connect");
  }

  const char *greeting = "Hello, World!";
  int n = send(connfd, greeting, strlen(greeting), 0);
  if (n < 0) die("send");

  char buf[1024];
  int m = recv(connfd, buf, sizeof(buf), 0);
  if (m > 0) {
    printf("Received: %s\n", buf);
  } else if (m < 0) {
    perror("recv");
  }

  close(connfd);
  close(sockfd);

  time_t now = time(NULL);
  char *timestamp = ctime(&now);
  printf("Scanned %s:%d at %s\n", target, port, timestamp);

  return 0;
}