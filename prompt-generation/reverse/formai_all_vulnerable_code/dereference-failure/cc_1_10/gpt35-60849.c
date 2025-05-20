//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  char buffer[BUFFER_SIZE];
  int port = 110;
  int sock = 0;
  int bytes_read = 0;
  struct sockaddr_in server;

  if (argc < 2) {
    printf("Usage: ./pop3client <server_address>\n");
    return 1;
  }

  // create socket
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Error creating socket");
    return 1;
  }

  // set server address and port
  memset(&server, '0', sizeof(server));
  server.sin_family = AF_INET;
  server.sin_port = htons(port);

  if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
    printf("Invalid address/ Address not supported\n");
    return 1;
  }

  // connect to server
  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("Error connecting to server");
    return 1;
  }

  // read welcome message
  bytes_read = read(sock, buffer, BUFFER_SIZE);
  buffer[bytes_read] = '\0';
  printf("%s", buffer);

  // send user command
  printf("Enter username: ");
  scanf("%s", buffer);
  write(sock, buffer, strlen(buffer));
  write(sock, "\r\n", 2);
  bytes_read = read(sock, buffer, BUFFER_SIZE);
  buffer[bytes_read] = '\0';
  printf("%s", buffer);

  // send pass command
  printf("Enter password: ");
  scanf("%s", buffer);
  write(sock, buffer, strlen(buffer));
  write(sock, "\r\n", 2);
  bytes_read = read(sock, buffer, BUFFER_SIZE);
  buffer[bytes_read] = '\0';
  printf("%s", buffer);

  // send list command
  write(sock, "list\r\n", 6);
  bytes_read = read(sock, buffer, BUFFER_SIZE);
  buffer[bytes_read] = '\0';
  printf("%s", buffer);

  // send quit command
  write(sock, "QUIT\r\n", 6);
  bytes_read = read(sock, buffer, BUFFER_SIZE);
  buffer[bytes_read] = '\0';
  printf("%s", buffer);

  // close socket
  close(sock);

  return 0;
}