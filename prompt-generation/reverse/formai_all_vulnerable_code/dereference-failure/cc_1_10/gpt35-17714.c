//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAXLINE 1024

int open_clientfd(char *hostname, int port);

int main(int argc, char **argv) {
  int clientfd, n;
  char buf[MAXLINE];
  char *username, *password;
  char tag[MAXLINE], command[MAXLINE], parameters[MAXLINE];
  
  if (argc != 3) {
    printf("usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }
  
  username = malloc(MAXLINE);
  password = malloc(MAXLINE);
  
  printf("Enter your username: ");
  fgets(username, MAXLINE, stdin);
  printf("Enter your password: ");
  fgets(password, MAXLINE, stdin);
  
  // Remove newlines from username and password
  strtok(username, "\n");
  strtok(password, "\n");
  
  clientfd = open_clientfd(argv[1], atoi(argv[2]));
  
  // Send login command with user credentials
  sprintf(tag, "A1");
  sprintf(command, "LOGIN %s %s", username, password);
  write(clientfd, tag, strlen(tag));
  write(clientfd, " ", 1);
  write(clientfd, command, strlen(command));
  write(clientfd, "\r\n", 2);
  
  // Wait for server response
  n = read(clientfd, buf, MAXLINE);
  buf[n] = '\0';
  printf("%s\n", buf);
  
  // Send select mailbox command
  sprintf(tag, "A2");
  sprintf(command, "SELECT inbox");
  write(clientfd, tag, strlen(tag));
  write(clientfd, " ", 1);
  write(clientfd, command, strlen(command));
  write(clientfd, "\r\n", 2);
  
  // Wait for server response
  n = read(clientfd, buf, MAXLINE);
  buf[n] = '\0';
  printf("%s\n", buf);
  
  // Send fetch command for first 10 messages
  for (int i = 1; i <= 10; i++) {
    sprintf(tag, "A%d", i + 2);
    sprintf(parameters, "%d (BODY[HEADER.FIELDS (FROM SUBJECT DATE)])", i);
    sprintf(command, "FETCH %s", parameters);
    write(clientfd, tag, strlen(tag));
    write(clientfd, " ", 1);
    write(clientfd, command, strlen(command));
    write(clientfd, "\r\n", 2);
  }
  
  // Wait for server response for each message
  for (int i = 1; i <= 10; i++) {
    n = read(clientfd, buf, MAXLINE);
    buf[n] = '\0';
    printf("%s\n", buf);
  }
  
  // Logout and close connection
  sprintf(tag, "A13");
  sprintf(command, "LOGOUT");
  write(clientfd, tag, strlen(tag));
  write(clientfd, " ", 1);
  write(clientfd, command, strlen(command));
  write(clientfd, "\r\n", 2);
  
  close(clientfd);
  
  free(username);
  free(password);
  
  return 0;
}

int open_clientfd(char *hostname, int port) {
  int clientfd;
  struct hostent *hp;
  struct sockaddr_in serveraddr;
  
  if ((clientfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    return -1;
  }
  
  if ((hp = gethostbyname(hostname)) == NULL) {
    return -2;
  }
  
  memset(&serveraddr, 0, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  memcpy(&serveraddr.sin_addr.s_addr, hp->h_addr, hp->h_length);
  serveraddr.sin_port = htons(port);
  
  if (connect(clientfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
    return -1;
  }
  
  return clientfd;
}