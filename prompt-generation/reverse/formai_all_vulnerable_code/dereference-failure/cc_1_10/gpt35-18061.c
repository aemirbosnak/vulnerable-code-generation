//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if(argc < 3) {
    printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
    return 1;
  }

  char *server_ip = argv[1]; // IP address of server
  int server_port = atoi(argv[2]); // port number of server

  /* Creating a socket */
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if(socket_fd == -1) {
    printf("Error creating socket\n");
    return 1;
  }

  /* Setting up server address */
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(server_port);
  if(inet_pton(AF_INET, server_ip, &server_addr.sin_addr) < 0) {
    printf("Error setting server address\n");
    return 1;
  }

  /* Connecting to server */
  if(connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    printf("Error connecting to server\n");
    return 1;
  }

  /* Sending GET request */
  char message[1000] = "GET / HTTP/1.1\r\n";
  strcat(message, "Host: ");
  strcat(message, server_ip);
  strcat(message, "\r\n");
  strcat(message, "Connection: close\r\n");
  strcat(message, "\r\n");

  if(send(socket_fd, message, strlen(message), 0) < 0) {
    printf("Error sending request\n");
    return 1;
  }

  /* Receiving response */
  char response[10000];
  memset(response, 0, sizeof(response));
  int bytes_recv = recv(socket_fd, response, sizeof(response)-1, 0);
  if(bytes_recv < 0) {
    printf("Error receiving response\n");
    return 1;
  }

  response[bytes_recv] = '\0';
  printf("Server response:\n%s\n", response);

  close(socket_fd);
  return 0;
}