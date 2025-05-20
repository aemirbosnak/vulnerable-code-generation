//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {

  char *server_address;
  int port;
  
  if (argc < 3) {
      fprintf(stderr, "Usage: %s ip_address port\n", argv[0]);
      exit(1);
  }

  server_address = argv[1];
  port = atoi(argv[2]);

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(server_address);
  server.sin_port = htons(port);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  char send_buffer[MAX_BUF_SIZE], receive_buffer[MAX_BUF_SIZE];
  memset(send_buffer, 0, MAX_BUF_SIZE);
  memset(receive_buffer, 0, MAX_BUF_SIZE);

  // Send request to the server
  snprintf(send_buffer, MAX_BUF_SIZE, "GET / HTTP/1.0\r\n\r\n");
  send(sockfd, send_buffer, strlen(send_buffer), 0);

  // Receive the response from the server
  int bytes_received = recv(sockfd, receive_buffer, MAX_BUF_SIZE, 0);
  if (bytes_received == -1) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  printf("Response:\n%.*s\n", bytes_received, receive_buffer);

  close(sockfd);

  return 0;
}