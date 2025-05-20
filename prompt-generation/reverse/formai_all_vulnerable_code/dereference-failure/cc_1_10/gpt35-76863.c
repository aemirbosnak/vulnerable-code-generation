//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 4) {
    printf("Usage: %s <server_ip> <server_port> <file_path>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Parse command-line arguments
  char *server_ip = argv[1];
  int server_port = atoi(argv[2]);
  char *file_path = argv[3];

  // Create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Connect to server
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(server_ip);
  serv_addr.sin_port = htons(server_port);
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Send request
  char request[BUFFER_SIZE];
  snprintf(request, sizeof(request), "GET %s\r\n", file_path);
  if (send(sockfd, request, strlen(request), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }

  // Receive response
  char response[BUFFER_SIZE];
  int num_bytes = 0;
  while ((num_bytes = recv(sockfd, response, BUFFER_SIZE, 0)) > 0) {
    fwrite(response, 1, num_bytes, stdout);
  }
  if (num_bytes < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }

  // Clean up
  close(sockfd);
  
  return 0;
}