//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define IMAP_PORT 143

char *get_imap_host(char *domain) {
  struct hostent *host;
  host = gethostbyname(domain);
  if (host == NULL) {
    return NULL;
  }
  return inet_ntoa(*((struct in_addr *)host->h_addr));
}

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <domain> <username> <password>\n", argv[0]);
    return 1;
  }

  char *host = get_imap_host(argv[1]);
  if (host == NULL) {
    fprintf(stderr, "Invalid domain: %s\n", argv[1]);
    return 1;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(IMAP_PORT);
  server_addr.sin_addr.s_addr = inet_addr(host);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return 1;
  }

  char buf[1024];
  // Receive welcome message
  recv(sockfd, buf, sizeof(buf), 0);
  printf("%s", buf);

  // Send login command
  sprintf(buf, "A001 LOGIN %s %s\r\n", argv[2], argv[3]);
  send(sockfd, buf, strlen(buf), 0);

  // Receive login response
  recv(sockfd, buf, sizeof(buf), 0);
  printf("%s", buf);

  // Send select command
  sprintf(buf, "A002 SELECT inbox\r\n");
  send(sockfd, buf, strlen(buf), 0);

  // Receive select response
  recv(sockfd, buf, sizeof(buf), 0);
  printf("%s", buf);

  // Send fetch command
  sprintf(buf, "A003 FETCH 1:10 (UID BODY[TEXT])\r\n");
  send(sockfd, buf, strlen(buf), 0);

  // Receive fetch response
  while (1) {
    recv(sockfd, buf, sizeof(buf), 0);
    if (strstr(buf, "OK") != NULL) {
      break;
    }
    printf("%s", buf);
  }

  // Close connection
  close(sockfd);

  return 0;
}