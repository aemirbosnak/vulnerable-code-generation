//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXSIZE 1024

int main(int argc, char *argv[]) {
  
  if (argc < 2) {
    fprintf(stderr,"usage: %s hostname\n", argv[0]);
    exit(0);
  }
  
  char *hostname = argv[1];
  int portno = 80;
  char request[MAXSIZE];
  char buf[MAXSIZE];
  int sockfd, i, read_size;
  struct sockaddr_in server_addr;
  struct hostent *server;
  
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  
  server = gethostbyname(hostname);
  
  if (server == NULL) {
    fprintf(stderr,"ERROR, no such host\n");
    exit(0);
  }
  
  memset(&server_addr, sizeof(server_addr), 0);
  
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(portno);
  server_addr.sin_addr = *((struct in_addr *)server->h_addr);
  
  if (connect(sockfd,(struct sockaddr *) &server_addr,sizeof(server_addr)) < 0) {
    fprintf(stderr,"ERROR, connection failed\n");
    exit(0);
  }
  
  sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", hostname);
  
  if (write(sockfd, request, strlen(request)) < 0) {
    fprintf(stderr,"ERROR, writing to socket failed\n");
    exit(0);
  }
  
  memset(buf, 0, sizeof(buf));
  
  while((read_size = recv(sockfd, buf, sizeof(buf), 0)) > 0) {
    for(i = 0; i < read_size; i++) {
      printf("%c", buf[i]);
    }
    memset(buf, 0, sizeof(buf));
  }
  
  if (read_size < 0) {
    fprintf(stderr,"ERROR, reading from socket failed\n");
    exit(0);
  }
  
  close(sockfd);
  
  return 0;
}