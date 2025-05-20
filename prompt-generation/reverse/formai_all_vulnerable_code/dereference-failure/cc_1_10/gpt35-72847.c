//FormAI DATASET v1.0 Category: Client Server Application ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 5000
#define MSG_LEN 1024

void error(const char *message) {
  perror(message);
  exit(1);
}

int main(int argc, char *argv[]) {
  int client_socket, server_socket, n;
  struct sockaddr_in server_addr, client_addr;
  struct hostent *server;

  char message[MSG_LEN];
  if (argc < 2) {
    fprintf(stderr, "Usage: %s SERVER_ADDRESS\n", argv[0]);
    exit(1);
  }

  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Unable to resolve server %s\n", argv[1]);
    exit(1);
  }

  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket < 0) {
    error("Unable to create client socket");
  }

  bzero((char *)&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr_list[0],
        (char *)&server_addr.sin_addr.s_addr,
        server->h_length);
  server_addr.sin_port = htons(PORT);

  if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    error("Unable to connect to server");
  }

  while (1) {
    printf("Enter message to send: ");
    bzero(message, MSG_LEN);
    fgets(message, MSG_LEN-1, stdin);

    n = write(client_socket, message, strlen(message));
    if (n < 0) {
      error("Unable to write to server");
    }

    bzero(message, MSG_LEN);
    n = read(client_socket, message, MSG_LEN-1);
    if (n < 0) {
      error("Unable to read from server");
    }

    printf("Received message: %s\n", message);
  }

  close(client_socket);
  return 0;
}