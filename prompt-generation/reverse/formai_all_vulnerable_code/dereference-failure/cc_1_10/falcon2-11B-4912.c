//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  int server_fd, new_socket, portno;
  struct sockaddr_in server_addr, client_addr;
  char buffer[256];

  // Create the socket
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return 1;
  }

  // Create the address struct
  bzero((char *) &server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(atoi(argv[1]));

  // Bind the socket to the address
  if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("bind");
    return 1;
  }

  // Listen to the socket
  if (listen(server_fd, 5) < 0) {
    perror("listen");
    return 1;
  }

  while (1) {
    printf("Waiting for a connection...\n");

    // Accept the connection
    if ((new_socket = accept(server_fd, (struct sockaddr *) &client_addr, (socklen_t *) &portno)) < 0) {
      perror("accept");
      return 1;
    }

    // Get the input from the client
    printf("> ");
    fgets(buffer, sizeof(buffer), stdin);
    printf("Received: %s\n", buffer);

    // Send the response back to the client
    send(new_socket, buffer, strlen(buffer), 0);

    // Close the socket
    close(new_socket);
  }

  return 0;
}