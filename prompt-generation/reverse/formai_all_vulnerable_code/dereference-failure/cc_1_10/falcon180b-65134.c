//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
  if (argc!= 2) {
    printf("Usage: %s <hostname>\n", argv[0]);
    exit(1);
  }

  char hostname[BUFFER_SIZE];
  strcpy(hostname, argv[1]);

  struct hostent* host = gethostbyname(hostname);
  if (host == NULL) {
    printf("Host not found.\n");
    exit(1);
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("Socket creation failed.\n");
    exit(1);
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(80);
  inet_pton(AF_INET, host->h_addr, &server_addr.sin_addr);

  if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
    printf("Connection failed.\n");
    exit(1);
  }

  char buffer[BUFFER_SIZE];
  memset(buffer, 0, BUFFER_SIZE);
  send(sockfd, "GET / HTTP/1.1\r\nHost: ", strlen("GET / HTTP/1.1\r\nHost: "), 0);
  int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
  close(sockfd);

  if (bytes_received <= 0) {
    printf("No response received.\n");
    exit(1);
  }

  printf("Response:\n%s\n", buffer);
  exit(0);
}