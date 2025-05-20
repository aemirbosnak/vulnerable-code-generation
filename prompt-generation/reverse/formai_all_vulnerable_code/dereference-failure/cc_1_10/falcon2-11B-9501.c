//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int server_sock, client_sock, n;
  struct sockaddr_in server, client;
  char buffer[256];
  struct hostent *hostp;

  if (argc!= 3) {
    printf("Usage: proxy <server> <port>\n");
    return 1;
  }

  server.sin_family = AF_INET;
  server.sin_port = htons(atoi(argv[1]));
  hostp = gethostbyname(argv[2]);
  if (hostp == NULL) {
    printf("Unknown host: %s\n", argv[2]);
    return 1;
  }
  bcopy((char *)hostp->h_addr, (char *)&server.sin_addr.s_addr, hostp->h_length);

  server_sock = socket(AF_INET, SOCK_STREAM, 0);
  if (server_sock < 0) {
    perror("socket");
    return 1;
  }

  if (connect(server_sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("connect");
    return 1;
  }

  client.sin_family = AF_INET;
  client.sin_port = htons(atoi(argv[2]));
  bzero((char *)&client.sin_addr, sizeof(client.sin_addr));
  client.sin_addr.s_addr = htonl(INADDR_ANY);

  client_sock = accept(server_sock, (struct sockaddr *)&client, (socklen_t*)&n);
  if (client_sock < 0) {
    perror("accept");
    return 1;
  }

  while (1) {
    n = recv(client_sock, buffer, sizeof(buffer), 0);
    if (n < 0) {
      perror("recv");
      break;
    }
    send(server_sock, buffer, n, 0);
    n = recv(server_sock, buffer, sizeof(buffer), 0);
    if (n < 0) {
      perror("recv");
      break;
    }
    send(client_sock, buffer, n, 0);
  }

  close(server_sock);
  close(client_sock);
  return 0;
}