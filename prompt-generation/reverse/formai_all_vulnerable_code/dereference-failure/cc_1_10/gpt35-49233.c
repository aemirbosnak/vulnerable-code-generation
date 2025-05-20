//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]) {
  if(argc != 4) {
    fprintf(stderr, "usage: %s hostname port filename\n", argv[0]);
    exit(1);
  }

  char *host = argv[1];
  int port = atoi(argv[2]);
  char *filename = argv[3];

  // create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0)
    error("Error opening socket");

  // set up server address
  struct sockaddr_in server_addr;
  bzero((char *)&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(host);
  server_addr.sin_port = htons(port);

  // connect to server
  if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    error("Error connecting to server");

  // open file
  int filefd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if(filefd < 0)
    error("Error opening file");

  // send file request
  char request[BUFFER_SIZE];
  bzero(request, BUFFER_SIZE);
  sprintf(request, "RETR %s\n", filename);
  if(send(sockfd, request, strlen(request), 0) < 0)
    error("Error sending file request");

  // receive file
  char buffer[BUFFER_SIZE];
  bzero(buffer, BUFFER_SIZE);
  int bytes_received = 0;
  while((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
    if(write(filefd, buffer, bytes_received) < 0)
      error("Error writing to file");
    bzero(buffer, BUFFER_SIZE);
  }
  if(bytes_received < 0)
    error("Error receiving file");

  // close file
  if(close(filefd) < 0)
    error("Error closing file");

  // close socket
  if(close(sockfd) < 0)
    error("Error closing socket");

  printf("File transfer complete\n");
  return 0;
}