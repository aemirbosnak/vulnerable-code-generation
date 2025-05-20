//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
  const char *server = "imap.example.com";
  const char *username = "username";
  const char *password = "password";

  // create socket
  int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_fd < 0) {
    perror("Could not create socket");
    exit(EXIT_FAILURE);
  }

  // resolve hostname to IP address
  struct hostent *host = gethostbyname(server);
  if (host == NULL) {
    herror("Could not resolve hostname");
    exit(EXIT_FAILURE);
  }

  // initialize server address struct
  struct sockaddr_in server_addr = {
    .sin_family = AF_INET,
    .sin_port = htons(993),
    .sin_addr = *((struct in_addr*)host->h_addr)
  };

  // connect to server
  if (connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Could not connect to server");
    exit(EXIT_FAILURE);
  }

  // read server response
  char server_buffer[BUFFER_SIZE];
  ssize_t read_count = read(sock_fd, server_buffer, BUFFER_SIZE);
  if (read_count < 0) {
    perror("Could not read server response");
    exit(EXIT_FAILURE);
  }
  server_buffer[read_count] = '\0';

  // send login command and receive response
  char login_str[BUFFER_SIZE];
  snprintf(login_str, BUFFER_SIZE, "LOGIN %s %s\r\n", username, password);
  if (send(sock_fd, login_str, strlen(login_str), 0) < 0) {
    perror("Could not send login command");
    exit(EXIT_FAILURE);
  }

  read_count = read(sock_fd, server_buffer, BUFFER_SIZE);
  if (read_count < 0) {
    perror("Could not read server response");
    exit(EXIT_FAILURE);
  }
  server_buffer[read_count] = '\0';

  // send list command and receive response
  if (send(sock_fd, "LIST \"\" *\r\n", strlen("LIST \"\" *\r\n"), 0) < 0) {
    perror("Could not send list command");
    exit(EXIT_FAILURE);
  }

  read_count = read(sock_fd, server_buffer, BUFFER_SIZE);
  if (read_count < 0) {
    perror("Could not read server response");
    exit(EXIT_FAILURE);
  }
  server_buffer[read_count] = '\0';

  // print server response
  printf("%s", server_buffer);

  // close socket
  if (close(sock_fd) < 0) {
    perror("Could not close socket");
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}