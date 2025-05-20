//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>

int main() {
  char email[100], password[100];
  printf("Enter your email address: ");
  scanf("%s", email);
  printf("Enter your password: ");
  scanf("%s", password);

  // connect to the POP3 server
  struct sockaddr_in server;
  struct hostent *hp;
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    exit(1);
  }
  hp = gethostbyname("pop3.emailprovider.com");
  if (hp == NULL) {
    perror("gethostbyname");
    exit(1);
  }
  memset(&server, 0, sizeof(server));
  server.sin_family = AF_INET;
  memcpy(&server.sin_addr, hp->h_addr, hp->h_length);
  server.sin_port = htons(110);
  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    perror("connect");
    exit(1);
  }

  // send login credentials
  char buffer[1024];
  int n = read(sock, buffer, sizeof(buffer));
  buffer[n] = 0;
  printf("%s", buffer); // server greeting
  sprintf(buffer, "USER %s\r\n", email);
  write(sock, buffer, strlen(buffer));
  n = read(sock, buffer, sizeof(buffer));
  buffer[n] = 0;
  printf("%s", buffer); // response to "USER" command
  sprintf(buffer, "PASS %s\r\n", password);
  write(sock, buffer, strlen(buffer));
  n = read(sock, buffer, sizeof(buffer));
  buffer[n] = 0;
  printf("%s", buffer); // response to "PASS" command

  // list emails
  write(sock, "LIST\r\n", 6);
  n = read(sock, buffer, sizeof(buffer));
  buffer[n] = 0;
  printf("%s", buffer);
  if (strstr(buffer, "-ERR") != NULL) {
    exit(1);
  }

  // retrieve email
  int id;
  printf("Enter the ID of the email you want to retrieve: ");
  scanf("%d", &id);
  sprintf(buffer, "RETR %d\r\n", id);
  write(sock, buffer, strlen(buffer));
  n = read(sock, buffer, sizeof(buffer));
  buffer[n] = 0;
  printf("%s", buffer);

  // quit
  write(sock, "QUIT\r\n", 6);
  n = read(sock, buffer, sizeof(buffer));
  buffer[n] = 0;
  printf("%s", buffer);
  close(sock);

  return 0;
}