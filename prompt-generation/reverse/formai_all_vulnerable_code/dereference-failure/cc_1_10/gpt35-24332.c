//FormAI DATASET v1.0 Category: Client Server Application ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  int server_socket, client_socket, read_status;
  struct sockaddr_in server_address, client_address;
  char buffer[BUFFER_SIZE] = {0};

  if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    fprintf(stderr, "Error: Could not create socket. %s\n", strerror(errno));
    return errno;
  }

  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = INADDR_ANY;
  server_address.sin_port = htons(8080);

  if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    fprintf(stderr, "Error: Could not bind socket. %s\n", strerror(errno));
    return errno;
  }

  if (listen(server_socket, 10) < 0) {
    fprintf(stderr, "Error: Could not listen on socket. %s\n", strerror(errno));
    return errno;
  }

  while (1) {
    printf("Waiting for incoming connections...\n");

    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&client_address)) < 0 ) {
      fprintf(stderr, "Error: Could not accept incoming connection. %s\n", strerror(errno));
      continue;
    }

    printf("Incoming connection accepted.\n");

    // Read incoming message
    memset(buffer, 0, BUFFER_SIZE);
    if ((read_status = read(client_socket, buffer, BUFFER_SIZE)) < 0) {
      fprintf(stderr, "Error: Could not read incoming message. %s\n", strerror(errno));
      return errno;
    }

    printf("Received message from client: %s\n", buffer);

    // Process message
    char response[] = "The message was received.";
    if (send(client_socket, response, strlen(response), 0) < 0) {
      fprintf(stderr, "Error: Could not send response to client. %s\n", strerror(errno));
      return errno;
    }

    printf("Sent response to client.\n");
  }

  close(server_socket);
  return 0;
}