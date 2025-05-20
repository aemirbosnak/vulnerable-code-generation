//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  char buffer[MAX_MSG_SIZE];

  if(argc < 3){
    printf("Usage: %s hostname port\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[2]);
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if(sockfd < 0){
    perror("Error opening socket");
    exit(1);
  }

  memset((char*)&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);

  if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0){
    printf("Invalid address/ Address not supported\n");
    exit(1);
  }

  if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
    perror("Error connecting to server");
    exit(1);
  }

  while(1){
    printf("FTP> ");
    fgets(buffer, MAX_MSG_SIZE, stdin); // get user input

    if(strncmp(buffer, "exit", 4) == 0){ // user wants to quit
      break;
    }

    // Send FTP command to server
    n = write(sockfd, buffer, strlen(buffer));

    if(n < 0){
      perror("Error writing to socket");
      exit(1);
    }

    // read server response
    memset(buffer, 0, MAX_MSG_SIZE);
    n = read(sockfd, buffer, MAX_MSG_SIZE - 1);

    if(n < 0){
      perror("Error reading from socket");
      exit(1);
    }

    printf("%s", buffer);
  }

  // close socket
  close(sockfd);
  return 0;
}