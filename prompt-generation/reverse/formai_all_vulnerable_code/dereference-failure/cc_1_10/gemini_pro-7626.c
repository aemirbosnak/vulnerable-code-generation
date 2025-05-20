//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define MAX_URL_SIZE 2048
#define MAX_DNS_QUERY_SIZE 2048

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char url[MAX_URL_SIZE];
  strcpy(url, argv[1]);

  struct hostent *host = gethostbyname(url);
  if (host == NULL)
  {
    fprintf(stderr, "Error: Could not resolve hostname '%s'\n", url);
    return EXIT_FAILURE;
  }

  struct in_addr **addr_list = (struct in_addr **)host->h_addr_list;
  char ip_address[INET_ADDRSTRLEN];
  inet_ntop(AF_INET, *addr_list, ip_address, INET_ADDRSTRLEN);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1)
  {
    fprintf(stderr, "Error: Could not create socket: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(80);
  server_addr.sin_addr.s_addr = inet_addr(ip_address);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
  {
    fprintf(stderr, "Error: Could not connect to server: %s\n", strerror(errno));
    close(sockfd);
    return EXIT_FAILURE;
  }

  char request[MAX_DNS_QUERY_SIZE];
  sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", url);

  if (send(sockfd, request, strlen(request), 0) == -1)
  {
    fprintf(stderr, "Error: Could not send request: %s\n", strerror(errno));
    close(sockfd);
    return EXIT_FAILURE;
  }

  char response[MAX_DNS_QUERY_SIZE];
  int bytes_received = recv(sockfd, response, MAX_DNS_QUERY_SIZE - 1, 0);
  if (bytes_received == -1)
  {
    fprintf(stderr, "Error: Could not receive response: %s\n", strerror(errno));
    close(sockfd);
    return EXIT_FAILURE;
  }

  response[bytes_received] = '\0';

  printf("Response:\n%s\n", response);

  close(sockfd);

  return EXIT_SUCCESS;
}