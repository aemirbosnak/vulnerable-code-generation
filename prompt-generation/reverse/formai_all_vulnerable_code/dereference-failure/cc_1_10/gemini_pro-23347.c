//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <hostname> <port>\n", argv[0]);
    return 1;
  }

  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    perror("gethostbyname");
    return 1;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(atoi(argv[2]));
  memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    return 1;
  }

  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    return 1;
  }

  char buffer[1024];
  int bytes_received;

  while ((bytes_received = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
    printf("%s", buffer);
  }

  if (bytes_received == -1) {
    perror("recv");
    return 1;
  }

  close(sock);
  return 0;
}