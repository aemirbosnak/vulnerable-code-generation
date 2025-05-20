//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

void error(const char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]) {
  int sockfd, port, n;
  struct sockaddr_in serv_addr;
  char buffer[BUFSIZE];

  if (argc < 3) {
    fprintf(stderr,"usage %s hostname port\n", argv[0]);
    exit(0);
  }

  port = atoi(argv[2]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    error("ERROR opening socket");
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));

  serv_addr.sin_family = AF_INET;

  serv_addr.sin_port = htons(port);

  if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
    error("ERROR invalid server IP address");
  }

  if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
    error("ERROR connecting to server");
  }

  n = read(sockfd,buffer,BUFSIZE-1);
  if (n < 0) {
    error("ERROR reading from server");
  }
  buffer[n] = '\0';
  printf("%s",buffer);

  char user[50];
  char pass[50];
  char command[BUFSIZE];
  int msg_num = 0;

  printf("Enter your username: ");
  fgets(user, 50, stdin);
  strtok(user, "\n");

  printf("Enter your password: ");
  fgets(pass, 50, stdin);
  strtok(pass, "\n");

  // Send username to server
  sprintf(command, "USER %s\r\n", user);
  write(sockfd, command, strlen(command));
  n = read(sockfd, buffer, BUFSIZE - 1);
  buffer[n] = '\0';
  printf("%s", buffer);

  // Send password to server
  sprintf(command, "PASS %s\r\n", pass);
  write(sockfd, command, strlen(command));
  n = read(sockfd, buffer, BUFSIZE - 1);
  buffer[n] = '\0';
  printf("%s", buffer);

  // Send command to list messages
  sprintf(command, "LIST\r\n");
  write(sockfd, command, strlen(command));
  n = read(sockfd, buffer, BUFSIZE - 1);
  buffer[n] = '\0';
  printf("%s", buffer);

  char *token;

  // Get message numbers
  token = strtok(buffer, "\r\n");
  while (token != NULL) {
    if (token[0] >= '0' && token[0] <= '9') {
      msg_num++;
    }
    token = strtok(NULL, "\r\n");
  }

  // Retrieve each message
  for (int i = 1; i <= msg_num; i++) {
    // Send command to retrieve message
    sprintf(command, "RETR %d\r\n", i);
    write(sockfd, command, strlen(command));
    n = read(sockfd, buffer, BUFSIZE - 1);
    buffer[n] = '\0';
    printf("%s", buffer);
  }

  sprintf(command, "QUIT\r\n");
  write(sockfd, command, strlen(command));
  close(sockfd);

  return 0;
}