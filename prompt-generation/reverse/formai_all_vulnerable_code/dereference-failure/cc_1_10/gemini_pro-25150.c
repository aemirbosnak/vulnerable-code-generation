//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
  // Create a socket.
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    exit(1);
  }

  // Get the server's address.
  struct hostent *server = gethostbyname("localhost");
  if (server == NULL) {
    perror("gethostbyname");
    exit(1);
  }

  // Connect to the server.
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(9999);
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  // Send data to the server.
  char *data = "Hello, world!";
  if (send(sock, data, strlen(data), 0) < 0) {
    perror("send");
    exit(1);
  }

  // Receive data from the server.
  char buffer[256];
  memset(buffer, 0, sizeof(buffer));
  if (recv(sock, buffer, sizeof(buffer), 0) < 0) {
    perror("recv");
    exit(1);
  }

  // Print the data from the server.
  printf("%s\n", buffer);

  // Close the socket.
  close(sock);

  return 0;
}