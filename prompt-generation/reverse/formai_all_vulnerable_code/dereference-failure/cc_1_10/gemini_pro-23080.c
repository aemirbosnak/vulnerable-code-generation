//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: retro
// Fire up the ol' HTTP client, boss!
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Our trusty HTTP client
int main() {
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char hostname[100], request[1000], response[1000], buffer[1024];
  printf("Enter hostname: ");
  scanf("%s", hostname);
  printf("Enter port number: ");
  scanf("%d", &portno);
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Socket creation failed");
    exit(1);
  }
  server = gethostbyname(hostname);
  if (server == NULL) {
    perror("Hostname not found");
    exit(1);
  }
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  serv_addr.sin_port = htons(portno);
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Connection failed");
    exit(1);
  }
  printf("Enter request: ");
  scanf("%s", request);
  strcpy(buffer, request);
  strcat(buffer, "\r\n\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
    perror("Send failed");
    exit(1);
  }
  memset(response, 0, sizeof(response));
  if (recv(sockfd, response, sizeof(response), 0) < 0) {
    perror("Receive failed");
    exit(1);
  }
  printf("Response:\n%s\n", response);
  close(sockfd);
  return 0;
}