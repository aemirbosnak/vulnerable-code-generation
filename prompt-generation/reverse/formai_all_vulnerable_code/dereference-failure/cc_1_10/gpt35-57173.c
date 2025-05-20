//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

void error(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]) {
  int client_sock, server_sock, port_no, n;
  struct sockaddr_in server_addr, client_addr;
  struct hostent *server;
  char buffer[4096];
  if(argc < 2) {
    fprintf(stderr, "Usage: %s hostname\n", argv[0]);
    exit(0);
  }
  client_sock = socket(AF_INET, SOCK_STREAM, 0);
  if(client_sock < 0) {
    error("Error opening socket");
  }
  server = gethostbyname(argv[1]);
  if(server == NULL) {
    fprintf(stderr, "Error: no such host as %s\n", argv[1]);
    exit(0);
  }
  bzero((char *) &server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
  server_addr.sin_port = htons(PORT);
  if(connect(client_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    error("Error connecting");
  }
  printf("Connected to %s:%d\n", argv[1], PORT);
  while(1) {
    bzero(buffer, 4096);
    n = read(client_sock, buffer, 4096);
    if(n < 0) {
      error("Error reading from socket");
    }
    if(n == 0) {
      break;
    }
    printf("Request from %s:%d: %s", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(server_sock < 0) {
      error("Error opening socket");
    }
    if(connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      error("Error connecting");
    }
    n = write(server_sock, buffer, strlen(buffer));
    if(n < 0) {
      error("Error writing to socket");
    }
    bzero(buffer, 4096);
    while((n = read(server_sock, buffer, 4096)) > 0) {
      printf("Response from %s:%d: %s", argv[1], PORT, buffer);
      n = write(client_sock, buffer, strlen(buffer));
      if(n < 0) {
        error("Error writing to socket");
      }
      bzero(buffer, 4096);
    }
    if(n < 0) {
      error("Error reading from socket");
    }
    close(server_sock);
  }
  close(client_sock);
  return 0;
}