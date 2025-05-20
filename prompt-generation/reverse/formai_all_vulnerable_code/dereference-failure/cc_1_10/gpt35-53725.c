//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>

#define MAXDATASIZE 1000

int main(int argc, char* argv[])
{
  if(argc < 3)
  {
    printf("[ProxyBot] I'm a simple HTTP proxy server, you need to tell me where to connect!\n");
    printf("[ProxyBot] Usage: %s hostname port\n", argv[0]);
    return 1;
  }

  printf("[ProxyBot] Ready to serve! Let's connect to %s on port %s\n", argv[1], argv[2]);

  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  getaddrinfo(argv[1], argv[2], &hints, &res);

  int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  connect(sockfd, res->ai_addr, res->ai_addrlen);

  freeaddrinfo(res);

  printf("[ProxyBot] Connection established! Ready to serve requests!\n");

  while(1)
  {
    char buffer[MAXDATASIZE];
    memset(buffer, 0, MAXDATASIZE);

    printf("[ProxyBot] Waiting for request...\n");
    recv(sockfd, buffer, MAXDATASIZE, 0);

    if(strlen(buffer) == 0)
    {
      printf("[ProxyBot] Client disconnected!\n");
      break;
    }

    printf("[ProxyBot] Received request: %s\n", buffer);

    printf("[ProxyBot] Sending request to destination server...\n");
    send(sockfd, buffer, strlen(buffer), 0);

    printf("[ProxyBot] Response received!\n");

    while(1)
    {
      memset(buffer, 0, MAXDATASIZE);
      recv(sockfd, buffer, MAXDATASIZE, 0);

      if(strlen(buffer) == 0)
      {
        printf("[ProxyBot] Response completed!\n");
        break;
      }

      printf("[ProxyBot] Forwarding response to client: %s\n", buffer);
      send(0, buffer, strlen(buffer), 0);
    }
  }

  printf("[ProxyBot] Closing connection\n");
  close(sockfd);

  return 0;

}