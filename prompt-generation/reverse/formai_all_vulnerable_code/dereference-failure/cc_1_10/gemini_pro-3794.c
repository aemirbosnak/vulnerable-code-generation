//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define PORT 8080

char *get_hostname(char *host) {
  struct hostent *he;
  if ((he = gethostbyname(host)) == NULL) {
    herror("gethostbyname");
    return NULL;
  }
  return he->h_name;
}

int main() {
  int sockfd;
  char buffer[1024];
  struct sockaddr_in servaddr;

  // socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // hostname
  char *hostname = get_hostname("localhost");
  if (hostname == NULL) {
    perror("hostname");
    exit(EXIT_FAILURE);
  }

  // server address
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);
  if (inet_pton(AF_INET, hostname, &servaddr.sin_addr) <= 0) {
    perror("inet_pton");
    exit(EXIT_FAILURE);
  }

  // connect
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // endless loop
  while (1) {
    memset(buffer, 0, sizeof(buffer));
    printf("Enter a message: ");
    scanf("%s", buffer);

    // send
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
      perror("send");
      exit(EXIT_FAILURE);
    }

    // receive
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
      perror("recv");
      exit(EXIT_FAILURE);
    }

    // print
    printf("Received: %s\n", buffer);
  }

  return 0;
}