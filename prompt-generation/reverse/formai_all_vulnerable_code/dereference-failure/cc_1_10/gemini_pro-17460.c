//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>

#define TIMEOUT 3
#define PORT 80

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <hostname>\n", argv[0]);
    return 1;
  }

  struct hostent *host = gethostbyname(argv[1]);
  if (!host) {
    printf("Could not resolve hostname: %s\n", argv[1]);
    return 1;
  }

  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr = *(struct in_addr *)host->h_addr;

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Could not create socket\n");
    return 1;
  }

  struct timeval timeout;
  timeout.tv_sec = TIMEOUT;
  timeout.tv_usec = 0;
  setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
  setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));

  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    printf("Could not connect to server\n");
    return 1;
  }

  char buffer[1024];
  int nbytes = 0;

  // Send a HTTP GET request
  char *request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
  sprintf(buffer, request, argv[1]);
  int len = strlen(buffer);
  if (send(sockfd, buffer, len, 0) < 0) {
    printf("Could not send request\n");
    return 1;
  }

  // Receive the response
  while ((nbytes = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
    printf("%s", buffer);
  }

  if (nbytes < 0) {
    printf("Could not receive response\n");
    return 1;
  }

  close(sockfd);
  return 0;
}