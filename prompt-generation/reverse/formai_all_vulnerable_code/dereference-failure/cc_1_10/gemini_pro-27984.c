//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFERSIZE 1024
#define PORT 25

typedef struct __attribute__((__packed__)) {
  unsigned int sender_ip:32;
  unsigned int recipient_ip:32;
  unsigned int server_ip:32;
  unsigned char sender_port:8;
  unsigned char recipient_port:8;
  unsigned char server_port:8;
  unsigned char sender_addr[32];
  unsigned char recipient_addr[32];
  unsigned char server_addr[32];
} Header;

int main(void) {
  int client_socket;
  struct sockaddr_in server_address;
  char buffer[BUFFERSIZE];
  fd_set read_set;

  client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

  if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  while (true) {
    FD_ZERO(&read_set);
    FD_SET(client_socket, &read_set);

    if (select(client_socket + 1, &read_set, NULL, NULL, NULL) == -1) {
      perror("select");
      exit(EXIT_FAILURE);
    }

    if (FD_ISSET(client_socket, &read_set)) {
      int bytes_received = recv(client_socket, buffer, BUFFERSIZE, 0);
      if (bytes_received == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
      }

      if (bytes_received == 0) {
        printf("Connection closed by server.\n");
        break;
      }

      Header *header = (Header *)buffer;
      printf("Received message from %s:%d to %s:%d via %s:%d\n", header->sender_addr, header->sender_port, header->recipient_addr, header->recipient_port, header->server_addr, header->server_port);
    }
  }

  close(client_socket);
  return EXIT_SUCCESS;
}