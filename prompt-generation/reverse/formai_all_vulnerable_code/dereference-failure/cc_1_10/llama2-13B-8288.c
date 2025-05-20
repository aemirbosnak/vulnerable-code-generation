//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 1024
#define PORT_RANGE 1024

int main(int argc, char *argv[]) {
  int sock_fd, client_fd;
  struct sockaddr_in server, client;
  socklen_t client_len = sizeof(client);
  char buffer[256];
  int port;

  if (argc < 2) {
    printf("Oh my gosh, you forgot to specify the port range! \n");
    return 1;
  }

  port = atoi(argv[1]);
  if (port < 0 || port > 65535) {
    printf("Whoa, that's not a valid port range! \n");
    return 1;
  }

  if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    printf("Gasp, could not create socket! \n");
    return 1;
  }

  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(port);

  if (bind(sock_fd, (struct sockaddr *)&server, sizeof(server)) < 0) {
    printf("Yikes, binding failed! \n");
    return 1;
  }

  if (listen(sock_fd, MAX_CLIENTS) < 0) {
    printf("Oops, listen failed! \n");
    return 1;
  }

  printf("Whoa, listening on port %d...\n", port);

  while (1) {
    if ((client_fd = accept(sock_fd, (struct sockaddr *)&client, &client_len)) < 0) {
      printf("Boo, accept failed! \n");
      continue;
    }

    printf("Wow, got a new client connection from IP %s, port %d! \n",
           inet_ntoa(client.sin_addr), ntohs(client.sin_port));

    // Handle client connection here
    recvfrom(client_fd, buffer, 256, 0, (struct sockaddr *)&client, &client_len);
    sendto(client_fd, "Hello, client!", 13, 0, (struct sockaddr *)&client, sizeof(client));

    close(client_fd);
  }

  close(sock_fd);

  return 0;
}