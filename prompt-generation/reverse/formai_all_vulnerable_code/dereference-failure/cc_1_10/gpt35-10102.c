//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

int connect_to_imap_server(char *hostname, int portnum) {
  int sockfd;
  struct sockaddr_in server_addr;
  struct hostent *server;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error opening socket");
    exit(1);
  }

  server = gethostbyname(hostname);
  if (server == NULL) {
    fprintf(stderr, "Error: could not resolve hostname: %s\n", hostname);
    exit(1);
  }

  memset((char *)&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(portnum);
  memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  return sockfd;
}

void send_command(int sockfd, char *command) {
  char buffer[MAX_BUFFER_SIZE];
  memset(buffer, 0, MAX_BUFFER_SIZE);
  sprintf(buffer, "%s\r\n", command);
  printf("> %s\n", buffer);
  write(sockfd, buffer, strlen(buffer));
}

void read_response(int sockfd) {
  char buffer[MAX_BUFFER_SIZE];
  memset(buffer, 0, MAX_BUFFER_SIZE);
  read(sockfd, buffer, MAX_BUFFER_SIZE);
  printf("< %s\n", buffer);
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Usage: ./imap_client [hostname] [portnum] [username]\n");
    exit(1);
  }

  char *hostname = argv[1];
  int portnum = atoi(argv[2]);
  char *username = argv[3];
  char password[MAX_BUFFER_SIZE];

  printf("Enter password for %s: ", username);
  fflush(stdout);
  fgets(password, MAX_BUFFER_SIZE, stdin);
  password[strcspn(password, "\n")] = 0;

  int sockfd = connect_to_imap_server(hostname, portnum);
  read_response(sockfd);

  send_command(sockfd, "LOGIN");
  send_command(sockfd, username);
  send_command(sockfd, password);
  read_response(sockfd);

  send_command(sockfd, "SELECT INBOX");
  read_response(sockfd);

  send_command(sockfd, "FETCH 1 BODY[HEADER.FIELDS (FROM TO SUBJECT DATE)]");
  read_response(sockfd);

  send_command(sockfd, "LOGOUT");
  read_response(sockfd);

  close(sockfd);

  return 0;
}