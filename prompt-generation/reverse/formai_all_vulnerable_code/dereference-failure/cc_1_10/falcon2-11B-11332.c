//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  // check if correct number of arguments are passed
  if (argc!= 3) {
    fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // create socket
  int socket_fd;
  if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // create address structure
  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_port = htons(atoi(argv[2]));
  address.sin_addr.s_addr = inet_addr(argv[1]);

  // connect to server
  if (connect(socket_fd, (struct sockaddr*)&address, sizeof(address)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // send data
  char data[100];
  printf("Enter data to send: ");
  fgets(data, sizeof(data), stdin);
  if (send(socket_fd, data, strlen(data), 0) == -1) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // receive data
  char received_data[100];
  if (recv(socket_fd, received_data, sizeof(received_data), 0) == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  printf("Received data: %s\n", received_data);

  // close connection
  if (close(socket_fd) == -1) {
    perror("close");
    exit(EXIT_FAILURE);
  }

  return 0;
}