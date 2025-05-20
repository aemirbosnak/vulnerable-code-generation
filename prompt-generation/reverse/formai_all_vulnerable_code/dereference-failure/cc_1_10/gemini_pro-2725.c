//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define IMAP_PORT 143

struct imap_client {
  int sockfd;
  char *server;
  int port;
};

int imap_client_connect(struct imap_client *client) {
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(client->port);
  inet_pton(AF_INET, client->server, &server_addr.sin_addr);

  client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (client->sockfd == -1) {
    fprintf(stderr, "Error: could not create socket (%s)\n", strerror(errno));
    return -1;
  }

  if (connect(client->sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    fprintf(stderr, "Error: could not connect to server (%s)\n", strerror(errno));
    return -1;
  }

  return 0;
}

int imap_client_send_command(struct imap_client *client, char *command) {
  ssize_t bytes_sent = send(client->sockfd, command, strlen(command), 0);
  if (bytes_sent == -1) {
    fprintf(stderr, "Error: could not send command (%s)\n", strerror(errno));
    return -1;
  }

  return 0;
}

int imap_client_receive_response(struct imap_client *client, char *buffer, size_t buffer_size) {
  ssize_t bytes_received = recv(client->sockfd, buffer, buffer_size - 1, 0);
  if (bytes_received == -1) {
    fprintf(stderr, "Error: could not receive response (%s)\n", strerror(errno));
    return -1;
  }

  buffer[bytes_received] = '\0';

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
    return 1;
  }

  struct imap_client client;
  client.server = argv[1];
  client.port = atoi(argv[2]);

  if (imap_client_connect(&client) == -1) {
    return 1;
  }

  char buffer[1024];

  if (imap_client_receive_response(&client, buffer, sizeof(buffer)) == -1) {
    return 1;
  }

  printf("%s\n", buffer);

  if (imap_client_send_command(&client, "CAPABILITY\r\n") == -1) {
    return 1;
  }

  if (imap_client_receive_response(&client, buffer, sizeof(buffer)) == -1) {
    return 1;
  }

  printf("%s\n", buffer);

  if (imap_client_send_command(&client, "LOGIN username password\r\n") == -1) {
    return 1;
  }

  if (imap_client_receive_response(&client, buffer, sizeof(buffer)) == -1) {
    return 1;
  }

  printf("%s\n", buffer);

  if (imap_client_send_command(&client, "LIST \"\" *\r\n") == -1) {
    return 1;
  }

  while (1) {
    if (imap_client_receive_response(&client, buffer, sizeof(buffer)) == -1) {
      return 1;
    }

    if (strcmp(buffer, "* OK\r\n") == 0) {
      break;
    }

    printf("%s\n", buffer);
  }

  close(client.sockfd);

  return 0;
}