//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int sockfd;
  struct addrinfo hints, *servinfo, *p;
  int retcode;
  char server[100], port[10], page[1000];
  char request[2000];
  char buffer[2000];
  int bytes_received, total_bytes_received;
  
  if (argc != 2) {
    printf("Usage: httpclient <url>\n");
    return 1;
  }
  
  sscanf(argv[1], "http://%99[^:]:%9[^/]/%999[^\n]", server, port, page);
  
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  
  if ((retcode = getaddrinfo(server, port, &hints, &servinfo)) != 0) {
    printf("getaddrinfo: %s\n", gai_strerror(retcode));
    return 2;
  }
  
  for(p = servinfo; p != NULL; p = p->ai_next) {
    if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
      perror("socket");
      continue;
    }
    
    if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
      close(sockfd);
      perror("connect");
      continue;
    }
    
    break;
  }
  
  if (p == NULL) {
    printf("Failed to connect.\n");
    return 3;
  }
  
  freeaddrinfo(servinfo);
  
  memset(request, 0, sizeof(request));
  strcat(request, "GET /");
  strcat(request, page);
  strcat(request, " HTTP/1.1\r\n");
  strcat(request, "Host: ");
  strcat(request, server);
  strcat(request, "\r\n");
  strcat(request, "Connection: close\r\n");
  strcat(request, "\r\n");
  
  if (send(sockfd, request, strlen(request), 0) == -1) {
    perror("send");
    return 4;
  }
  
  total_bytes_received = 0;
  
  while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
    total_bytes_received += bytes_received;
    buffer[bytes_received] = '\0';
    printf("%s", buffer);
  }
  
  printf("\nTotal bytes received: %d\n", total_bytes_received);
  
  close(sockfd);
  
  return 0;
}