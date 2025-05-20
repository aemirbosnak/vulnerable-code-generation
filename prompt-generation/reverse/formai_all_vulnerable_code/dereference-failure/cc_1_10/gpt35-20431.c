//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21

void error(char *msg) {
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[]) {
  int sockfd, n;
  struct sockaddr_in serv_addr;
  char buffer[256];

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    error("ERROR opening socket");
  }

  memset(&serv_addr, '0', sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
    error("ERROR invalid IP Address");
  }

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    error("ERROR connecting");
  }

  printf("Connected to FTP server\n");

  bzero(buffer, 256);

  n = read(sockfd, buffer, 255);
  if (n < 0) {
    error("ERROR reading from socket");
  }

  printf("%s", buffer);

  // Send user command
  char user[100];
  printf("Username: ");
  fgets(user, 100, stdin);
  char user_cmd[100];
  snprintf(user_cmd, sizeof(user_cmd), "USER %s", user);
  send(sockfd, user_cmd, strlen(user_cmd), 0);

  bzero(buffer, 256);

  n = read(sockfd, buffer, 255);
  if (n < 0) {
    error("ERROR reading from socket");
  }

  printf("%s", buffer);

  // Send password command
  char password[100];
  printf("Password: ");
  fgets(password, 100, stdin);
  char password_cmd[100];
  snprintf(password_cmd, sizeof(password_cmd), "PASS %s", password);
  send(sockfd, password_cmd, strlen(password_cmd), 0);

  bzero(buffer, 256);

  n = read(sockfd, buffer, 255);
  if (n < 0) {
    error("ERROR reading from socket");
  }

  printf("%s", buffer);

  // Send directory list command
  char list_cmd[] = "LIST\r\n";
  send(sockfd, list_cmd, strlen(list_cmd), 0);

  bzero(buffer, 256);

  n = read(sockfd, buffer, 255);
  if (n < 0) {
    error("ERROR reading from socket");
  }

  printf("%s", buffer);

  close(sockfd);

  return 0;
}