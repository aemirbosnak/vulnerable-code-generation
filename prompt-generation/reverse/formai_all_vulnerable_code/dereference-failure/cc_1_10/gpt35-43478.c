//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
  if(argc < 2) {
    printf("Usage: %s <url>\n", argv[0]);
    return -1;
  }

  char *url = argv[1];

  // parse the given url
  char hostname[256], path[1024];
  int port = 80;
  bzero(hostname, 256);
  bzero(path, 1024);
  sscanf(url, "http://%[^/]/%s", hostname, path);

  // create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("socket failed");
    return -1;
  }

  // resolve the hostname to an IP address
  struct hostent *he = gethostbyname(hostname);
  if(he == NULL) {
    perror("gethostbyname failed");
    return -1;
  }

  // prepare the server address structure
  struct sockaddr_in server;
  bzero(&server, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  memcpy(&server.sin_addr, he->h_addr_list[0], he->h_length);

  // connect to the server
  if(connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
    perror("connect failed");
    return -1;
  }

  // send a GET request to the server
  char buffer[BUFFER_SIZE];
  bzero(buffer, BUFFER_SIZE);
  sprintf(buffer, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, hostname);
  if(send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("send failed");
    return -1;
  }

  // receive the response from the server
  bzero(buffer, BUFFER_SIZE);
  int total_received = 0;
  int received = 0;
  while((received = recv(sockfd, buffer+total_received, BUFFER_SIZE-total_received, 0)) > 0) {
    total_received += received;
    if(total_received >= BUFFER_SIZE) {
      printf("error: response too long\n");
      return -1;
    }
  }
  if(received < 0) {
    perror("recv failed");
    return -1;
  }

  printf("%s", buffer);

  // close the socket
  close(sockfd);

  return 0;
}