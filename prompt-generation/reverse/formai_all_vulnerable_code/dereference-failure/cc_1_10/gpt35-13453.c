//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024
#define MAX_RESPONSE_LENGTH 100000

typedef enum {
  IDLE,
  CONNECTED,
  LOGGED_IN,
  SELECTED_MAILBOX,
} imap_state;

typedef struct {
  imap_state state;
  int socket_fd;
  ssize_t bytes_read;
  char *response;
  size_t response_size;
  int tag;
} IMAP;

int read_response(IMAP *imap) {
  imap->response_size = 0;
  memset(imap->response, 0, MAX_RESPONSE_LENGTH);

  char c;
  while ((imap->bytes_read = read(imap->socket_fd, &c, 1)) > 0) {
    imap->response[imap->response_size++] = c;
    if (imap->response_size > MAX_RESPONSE_LENGTH - 1) {
      fprintf(stderr, "Response too long.\n");
      return -1;
    } else if (c == '\n') {
      imap->response[imap->response_size] = '\0';
      return 0;
    }
  }

  if (imap->bytes_read == -1) {
    if (errno == EAGAIN) {
      return -2;
    } else {
      perror("read");
      return -1;
    }
  }

  fprintf(stderr, "Connection closed by peer.\n");
  return -1;
}

int send_command(IMAP *imap, const char *command) {
  char buf[MAX_LINE_LENGTH];
  sprintf(buf, "%d %s\r\n", imap->tag++, command);

  if (send(imap->socket_fd, buf, strlen(buf), 0) == -1) {
    perror("send");
    return -1;
  }

  return 0;
}

int connect_to_server(IMAP *imap, const char *hostname, const char *port) {
  struct addrinfo hints, *results;
  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  if (getaddrinfo(hostname, port, &hints, &results) != 0) {
    perror("getaddrinfo");
    return -1;
  }

  int socket_fd = -1;
  struct addrinfo *p;
  for (p = results; p != NULL; p = p->ai_next) {
    socket_fd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
    if (socket_fd == -1) {
      continue;
    }

    int flags = fcntl(socket_fd, F_GETFL);
    fcntl(socket_fd, F_SETFL, flags | O_NONBLOCK);

    if (connect(socket_fd, p->ai_addr, p->ai_addrlen) == -1 && errno != EINPROGRESS) {
      perror("connect");
      close(socket_fd);
      socket_fd = -1;
      continue;
    }

    break;
  }

  freeaddrinfo(results);

  if (socket_fd == -1) {
    return -1;
  }

  imap->state = CONNECTED;
  imap->socket_fd = socket_fd;
  return 0;
}

int login(IMAP *imap, const char *username, const char *password) {
  char command[MAX_LINE_LENGTH];
  sprintf(command, "LOGIN %s %s", username, password);
  if (send_command(imap, command) == -1) {
    return -1;
  }

  if (read_response(imap) == -1) {
    return -1;
  }

  if (imap->response[0] == 'A' && imap->response[1] == '1' && imap->response[2] == '0' && imap->response[3] == '0') {
    imap->state = LOGGED_IN;
    return 0;
  }

  fprintf(stderr, "Authentication failed.\n");
  return -1;
}

int select_mailbox(IMAP *imap, const char *mailbox) {
  char command[MAX_LINE_LENGTH];
  sprintf(command, "SELECT %s", mailbox);
  if (send_command(imap, command) == -1) {
    return -1;
  }

  if (read_response(imap) == -1) {
    return -1;
  }

  if (imap->response[0] == 'A' && imap->response[1] == '1' && imap->response[2] == '0' && imap->response[3] == '0') {
    imap->state = SELECTED_MAILBOX;
    return 0;
  }

  fprintf(stderr, "Mailbox selection failed.\n");
  return -1;
}

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: imap_client hostname port mailbox\n");
    exit(1);
  }

  const char *hostname = argv[1];
  const char *port = argv[2];
  const char *mailbox = argv[3];

  IMAP imap = {IDLE, -1, 0, malloc(MAX_RESPONSE_LENGTH), MAX_RESPONSE_LENGTH, 1};

  if (connect_to_server(&imap, hostname, port) == -1) {
    fprintf(stderr, "Failed to connect to server.\n");
    exit(1);
  }

  if (login(&imap, "user", "password") == -1) {
    fprintf(stderr, "Failed to authenticate.\n");
    exit(1);
  }

  if (select_mailbox(&imap, mailbox) == -1) {
    fprintf(stderr, "Failed to select mailbox.\n");
    exit(1);
  }

  printf("Connection established.\n");
  printf("Authenticated as user.\n");
  printf("Selected mailbox: %s\n", mailbox);

  return 0;
}