//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

/* 
   A knight shall not send an unencrypted HTTP request
   lest it be intercepted by an enemy.
*/
void encrypt(char *s) {
  for (int i = 0; s[i] != '\0'; i++) {
    s[i] = (char)((int)s[i] + 3);
  }
}

/* 
   A knight shall not enter a village uninvited.
*/
void announce(char *hostname, int port) {
  printf("I, Sir Bot, am about to send an HTTP request to %s:%d.\n", hostname, port);
}

/* 
   A knight shall not talk to strangers without proper introduction.
*/
void introduction() {
  printf("Greetings, fair server! I am Sir Bot, a humble knight in service of King Arthur.\n");
}

/* 
   A knight shall not send a request without proper headers.
*/
void add_headers(char *request) {
  strcat(request, "Host: localhost:8000\r\n");
  strcat(request, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.36\r\n");
  strcat(request, "Connection: close\r\n\r\n");
}

/* 
   A knight must always thank their host for their hospitality.
*/
void farewell() {
  printf("Thank you for your hospitality, fair server.\n");
}

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s hostname port\n", argv[0]);
    return 1;
  }

  int port = atoi(argv[2]);
  if (port <= 0 || port >= 65536) {
    printf("%s: Invalid port: %s\n", argv[0], argv[2]);
    return 2;
  }

  char *hostname = argv[1];
  struct hostent *he = gethostbyname(hostname);
  if (he == NULL) {
    printf("%s: Unknown host: %s\n", argv[0], hostname);
    return 3;
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr = *((struct in_addr *)he->h_addr_list[0]);
  server_addr.sin_port = htons(port);

  int client_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (client_fd == -1) {
    printf("%s: Could not create socket: %m\n", argv[0]);
    return 4;
  }

  if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    printf("%s: Could not connect: %m\n", argv[0]);
    return 5;
  }

  char request[1024];
  sprintf(request, "GET / HTTP/1.1\r\n");
  encrypt(request); /* For security reasons */
  add_headers(request);

  announce(hostname, port);
  write(client_fd, request, strlen(request));
  introduction();

  char response[1024];
  while (read(client_fd, response, 1023) > 0) {
    printf("%s", response);
    memset(&response, 0, sizeof(response));
  }

  close(client_fd);
  farewell();

  return 0;
}