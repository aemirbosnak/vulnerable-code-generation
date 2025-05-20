//MISTRAL-7B DATASET v1.0 Category: Socket programming ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char const *argv[]) {
  int socket_desc, client_sock, c, read_size;
  struct sockaddr_in server, client;
  char *hello = "Hello from server";
  char buffer[BUFFER_SIZE];
  char *message;

  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_desc == -1) {
    printf("Could not create socket");
    return 1;
  }

  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons(PORT);

  if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("bind failed. Error");
    return 1;
  }
  free(server.sin_addr.s_addr);

  listen(socket_desc, 3);

  puts("Waiting for incoming connections...");

  while ((client_sock = accept(socket_desc, NULL, NULL))) {
    puts("Connection accepted");

    read_size = recv(client_sock, buffer, BUFFER_SIZE, 0);
    if (read_size == -1) {
      perror("recv failed");
      return 1;
    }

    message = malloc(read_size);
    strncpy(message, buffer, read_size);
    message[read_size] = '\0';

    printf("Client message: %s\n", message);

    if (strstr(message, "exit") != NULL) {
      free(message);
      close(client_sock);
      continue;
    }

    for (c = 0; c < strlen(hello); c++) {
      send(client_sock, &hello[c], 1, 0);
    }
    send(client_sock, "\n", 1, 0);

    free(message);
    close(client_sock);
  }

  if (socket_desc >= 0) {
    close(socket_desc);
  }

  return 0;
}