//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 21
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <filename>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *hostname = argv[1];
  char *filename = argv[2];

  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    fprintf(stderr, "Could not resolve hostname %s\n", hostname);
    exit(EXIT_FAILURE);
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Could not create socket");
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in serv_addr;
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  serv_addr.sin_addr = *(struct in_addr *)host->h_addr;

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Could not connect to server");
    exit(EXIT_FAILURE);
  }

  char buffer[MAX_BUFFER_SIZE];

  // Send the USER command
  snprintf(buffer, MAX_BUFFER_SIZE, "USER anonymous\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

  // Send the PASS command
  snprintf(buffer, MAX_BUFFER_SIZE, "PASS anonymous\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

  // Send the TYPE command
  snprintf(buffer, MAX_BUFFER_SIZE, "TYPE I\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

  // Send the PASV command
  snprintf(buffer, MAX_BUFFER_SIZE, "PASV\r\n");
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

  // Parse the PASV response
  char *ip_address = strtok(buffer, ",");
  int port = atoi(strtok(NULL, ","));

  // Connect to the data port
  struct sockaddr_in data_addr;
  data_addr.sin_family = AF_INET;
  data_addr.sin_port = htons(port);
  data_addr.sin_addr.s_addr = inet_addr(ip_address);

  int data_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (data_sockfd < 0) {
    perror("Could not create data socket");
    exit(EXIT_FAILURE);
  }

  if (connect(data_sockfd, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
    perror("Could not connect to data port");
    exit(EXIT_FAILURE);
  }

  // Send the RETR command
  snprintf(buffer, MAX_BUFFER_SIZE, "RETR %s\r\n", filename);
  send(sockfd, buffer, strlen(buffer), 0);
  recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

  // Receive the file
  FILE *fp = fopen(filename, "wb");
  if (fp == NULL) {
    perror("Could not open file");
    exit(EXIT_FAILURE);
  }

  while (1) {
    int bytes_received = recv(data_sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
      break;
    }

    fwrite(buffer, 1, bytes_received, fp);
  }

  fclose(fp);
  close(data_sockfd);
  close(sockfd);

  return 0;
}