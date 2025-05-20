//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

  // check command line arguments
  if (argc < 4) {
    fprintf(stderr, "Usage: %s hostname port filename\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // get hostname, port, and filename from command line arguments
  char *hostname = argv[1];
  int port = atoi(argv[2]);
  char *filename = argv[3];

  // create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Failed to create socket.");
    exit(EXIT_FAILURE);
  }

  // get host by name
  struct hostent *server = gethostbyname(hostname);
  if (server == NULL) {
    perror("Failed to get host by name.");
    exit(EXIT_FAILURE);
  }

  // set up server address struct
  struct sockaddr_in server_addr;
  bzero((char *) &server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
  server_addr.sin_port = htons(port);

  // connect to server
  if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("Failed to connect to server.");
    exit(EXIT_FAILURE);
  }

  // open file for writing
  FILE *file = fopen(filename, "wb");
  if (file == NULL) {
    perror("Failed to open file for writing.");
    exit(EXIT_FAILURE);
  }

  // send GET command to server
  char buffer[BUFFER_SIZE];
  bzero(buffer, BUFFER_SIZE);
  sprintf(buffer, "GET %s\n", filename);
  int n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    perror("Failed to write to socket.");
    exit(EXIT_FAILURE);
  }

  // receive file contents from server
  bzero(buffer, BUFFER_SIZE);
  while ((n = read(sockfd, buffer, BUFFER_SIZE)) > 0) {
    fwrite(buffer, sizeof(char), n, file);
    bzero(buffer, BUFFER_SIZE);
  }

  // close file
  fclose(file);
  printf("File transfer complete.\n");

  // close socket
  close(sockfd);

  return 0;

}