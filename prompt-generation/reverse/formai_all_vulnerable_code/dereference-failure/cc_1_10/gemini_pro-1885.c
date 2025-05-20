//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 12345
#define BUFFER_SIZE 1024

typedef struct {
  int sockfd;
  struct sockaddr_in addr;
  char buffer[BUFFER_SIZE];
  int len;
} Client;

Client *create_client() {
  Client *client = malloc(sizeof(Client));
  client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (client->sockfd < 0) {
    perror("socket");
    exit(1);
  }
  client->addr.sin_family = AF_INET;
  client->addr.sin_port = htons(PORT);
  client->addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
  client->len = sizeof(client->addr);
  return client;
}

void close_client(Client *client) {
  close(client->sockfd);
  free(client);
}

void send_message(Client *client, char *message) {
  int n = sendto(client->sockfd, message, strlen(message), 0, (struct sockaddr *)&client->addr, client->len);
  if (n < 0) {
    perror("sendto");
    exit(1);
  }
}

void receive_message(Client *client) {
  int n = recvfrom(client->sockfd, client->buffer, BUFFER_SIZE - 1, 0, (struct sockaddr *)&client->addr, &client->len);
  if (n < 0) {
    perror("recvfrom");
    exit(1);
  }
  client->buffer[n] = '\0';
}

int main() {
  Client *client = create_client();
  connect(client->sockfd, (struct sockaddr *)&client->addr, client->len);
  printf("Connected to chat server\n");
  while (1) {
    char message[BUFFER_SIZE];
    printf("Enter message: ");
    fgets(message, BUFFER_SIZE, stdin);
    send_message(client, message);
    receive_message(client);
    printf("Message from server: %s\n", client->buffer);
  }
  close_client(client);
  return 0;
}