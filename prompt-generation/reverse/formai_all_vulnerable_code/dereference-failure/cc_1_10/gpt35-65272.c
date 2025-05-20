//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_BUFFER 8192

int main(int argc, char *argv[]) {
  char *user, *pass, *server, *mailbox;
  char buffer[MAX_BUFFER];
  struct hostent *host;
  struct sockaddr_in server_address;
  int socket_fd;

  // Check for correct usage
  if (argc != 5) {
    fprintf(stderr, "Usage: %s user pass server mailbox\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Save arguments
  user = argv[1];
  pass = argv[2];
  server = argv[3];
  mailbox = argv[4];

  // Get server IP address
  host = gethostbyname(server);
  if (!host) {
    fprintf(stderr, "Error: Could not resolve host %s\n", server);
    exit(EXIT_FAILURE);
  }

  // Setup server address
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  memcpy(&server_address.sin_addr, host->h_addr_list[0], host->h_length);
  server_address.sin_port = htons(993); // IMAP port

  // Connect to server
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }
  if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Read welcome message from server
  if (read(socket_fd, buffer, MAX_BUFFER) == -1) {
    perror("read");
    exit(EXIT_FAILURE);
  }
  printf("%s", buffer);

  // Login to server
  sprintf(buffer, "a001 LOGIN %s %s\r\n", user, pass);
  write(socket_fd, buffer, strlen(buffer));
  if (read(socket_fd, buffer, MAX_BUFFER) == -1) {
    perror("read");
    exit(EXIT_FAILURE);
  }
  printf("%s", buffer);

  // Select mailbox
  sprintf(buffer, "a002 SELECT %s\r\n", mailbox);
  write(socket_fd, buffer, strlen(buffer));
  if (read(socket_fd, buffer, MAX_BUFFER) == -1) {
    perror("read");
    exit(EXIT_FAILURE);
  }
  printf("%s", buffer);

  // Logout and close connection
  sprintf(buffer, "a003 LOGOUT\r\n");
  write(socket_fd, buffer, strlen(buffer));
  if (read(socket_fd, buffer, MAX_BUFFER) == -1) {
    perror("read");
    exit(EXIT_FAILURE);
  }
  printf("%s", buffer);

  close(socket_fd);
  return 0;
}