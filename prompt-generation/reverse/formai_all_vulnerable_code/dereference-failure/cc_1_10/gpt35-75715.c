//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>

#define BUF_SIZE 1000

void error(char *msg) {
  perror(msg);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

  if (argc < 3) {
    fprintf(stderr, "usage: %s <hostname> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  char *hostname = argv[1];
  char *port = argv[2];

  struct addrinfo hints;
  struct addrinfo *result;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_protocol = IPPROTO_TCP;

  int s = getaddrinfo(hostname, port, &hints, &result);
  if (s != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
    exit(EXIT_FAILURE);
  }

  int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
  if (sockfd == -1) {
    error("Error: Failed to create socket");
  }

  int connect_res = connect(sockfd, result->ai_addr, result->ai_addrlen);
  if (connect_res == -1) {
    error("Error: Failed to connect to server");
  }

  char command[BUF_SIZE];
  char filename[BUF_SIZE];
  char buffer[BUF_SIZE];

  while (1) {
    printf("ftp>> ");
    fgets(command, BUF_SIZE, stdin);

    strtok(command, "\n"); // remove trailing newline

    if (strcmp(command, "quit") == 0 || strcmp(command, "q") == 0) {
      printf("Exiting FTP client...\n");
      break;
    }
    else if (strcmp(command, "ls") == 0) {
      send(sockfd, "ls", 2, 0);

      bzero(buffer, BUF_SIZE);
      recv(sockfd, buffer, BUF_SIZE, 0);
      printf("%s", buffer);
    }
    else if (strncmp(command, "get", 3) == 0) {
      strcpy(filename, command + 4);

      send(sockfd, command, strlen(command), 0);

      /* receive file */
      FILE *fp = fopen(filename, "w");
      if (fp == NULL) {
        error("Failed to open file");
      }

      bzero(buffer, BUF_SIZE);
      int bytes_recv = recv(sockfd, buffer, BUF_SIZE, 0);
      while (bytes_recv > 0) {
        fwrite(buffer, sizeof(char), bytes_recv, fp);
        bzero(buffer, BUF_SIZE);
        bytes_recv = recv(sockfd, buffer, BUF_SIZE, 0);
      }

      fclose(fp);
      printf("File received successfully\n");
    }
    else {
      printf("Invalid command\n");
    }
  }

  close(sockfd);

  return 0;
}