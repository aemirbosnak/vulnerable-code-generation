//LLAMA2-13B DATASET v1.0 Category: Simple Web Server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(void) {
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket failed");
    exit(1);
  }

  struct sockaddr_in server_addr = {
    .sin_family = AF_INET,
    .sin_port = htons(PORT),
    .sin_addr.s_addr = INADDR_ANY
  };

  if (bind(sock, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
    perror("bind failed");
    exit(1);
  }

  if (listen(sock, 3) < 0) {
    perror("listen failed");
    exit(1);
  }

  printf("Listening on port %d...\n", PORT);

  while (1) {
    int client_sock = accept(sock, NULL, NULL);
    if (client_sock < 0) {
      perror("accept failed");
      exit(1);
    }

    char buffer[1024];
    recv(client_sock, buffer, 1024, 0);
    printf("Received request: %s\n", buffer);

    char* request = strtok(buffer, " ");
    if (strcmp(request, "GET /") == 0) {
      char* response = "Hello, world!";
      send(client_sock, response, strlen(response), 0);
      printf(" Sent response: %s\n", response);
    } else {
      char* error = "Invalid request";
      send(client_sock, error, strlen(error), 0);
      printf(" Sent error: %s\n", error);
    }

    close(client_sock);
  }

  close(sock);

  return 0;
}