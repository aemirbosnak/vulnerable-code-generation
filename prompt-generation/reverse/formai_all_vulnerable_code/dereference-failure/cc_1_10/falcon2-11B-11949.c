//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
  // create socket
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    perror("socket failed");
    exit(EXIT_FAILURE);
  }

  // set up address structure
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(8080);
  struct hostent *server = gethostbyname("127.0.0.1");
  if (server == NULL) {
    fprintf(stderr, "gethostbyname: Unknown host\n");
    exit(EXIT_FAILURE);
  }
  memcpy((char*) &server_address.sin_addr.s_addr,
        (char*) server->h_addr, server->h_length);

  // connect to the server
  if (connect(socket_fd, (struct sockaddr*) &server_address,
        sizeof(server_address)) == -1) {
    perror("connect failed");
    exit(EXIT_FAILURE);
  }

  // send a message
  char message[] = "Hello, world!";
  send(socket_fd, message, strlen(message), 0);

  // receive a response
  char response[256];
  int bytes_received = recv(socket_fd, response, 255, 0);
  if (bytes_received <= 0) {
    perror("recv failed");
    exit(EXIT_FAILURE);
  }
  response[bytes_received] = '\0';
  printf("Received: %s\n", response);

  // close the socket
  close(socket_fd);
  return 0;
}