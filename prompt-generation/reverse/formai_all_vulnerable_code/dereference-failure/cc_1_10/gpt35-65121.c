//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<errno.h>
#include<string.h>

#define BUFLEN 8192

void error(const char *msg)
{
  perror(msg);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
  if(argc != 3)
  {
    printf("Usage: %s <listen_port> <server_ip:port>\n", argv[0]);
    return 1;
  }

  int listen_sockfd;
  struct sockaddr_in listen_addr, server_addr;

  // Create socket
  if((listen_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    error("ERROR: socket creation failed");

  // Prepare listening socket address
  listen_addr.sin_family = AF_INET;
  listen_addr.sin_addr.s_addr = INADDR_ANY;
  listen_addr.sin_port = htons(atoi(argv[1]));

  // Bind socket to address
  if(bind(listen_sockfd, (struct sockaddr*)&listen_addr, sizeof(listen_addr)) == -1)
    error("ERROR: socket bind failed");

  // Listen for connections
  if(listen(listen_sockfd, 10) == -1)
    error("ERROR: socket listen failed");

  printf("HTTP proxy server started listening on port %d...\n", atoi(argv[1]));

  while(1)
  {

    int client_sockfd;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Accept incoming connection from client
    if((client_sockfd = accept(listen_sockfd, (struct sockaddr*)&client_addr, &client_len)) == -1)
      error("ERROR: socket accept failed");

    printf("Incoming connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    int server_sockfd;

    // Create socket for connection with server
    if((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
      error("ERROR: socket creation failed");

    // Set server address
    char *serverIp = strtok(argv[2], ":");
    int serverPort = atoi(strtok(NULL, ":"));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(serverIp);
    server_addr.sin_port = htons(serverPort);

    // Connect to server
    if(connect(server_sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
      error("ERROR: server connect failed");

    printf("Connected to server %s:%d\n", serverIp, serverPort);

    // Read request from client
    char buf[BUFLEN];
    int buflen = 0, n;
    memset(buf, 0, BUFLEN);

    if((n = read(client_sockfd, buf, BUFLEN)) > 0)
    {
      printf("Received from client:\n%s\n", buf);
      buflen += n;
    }

    // Write request to server
    if(write(server_sockfd, buf, buflen) == -1)
      error("ERROR: server write failed");

    // Read response from server
    buflen = 0;
    memset(buf, 0, BUFLEN);

    if((n = read(server_sockfd, buf, BUFLEN)) > 0)
    {
      printf("Received from server:\n%s\n", buf);
      buflen += n;
    }

    // Write response to client
    if(write(client_sockfd, buf, buflen) == -1)
      error("ERROR: client write failed");

    close(client_sockfd);
    close(server_sockfd);

    printf("Connection closed.\n");

  }

  return 0;

}