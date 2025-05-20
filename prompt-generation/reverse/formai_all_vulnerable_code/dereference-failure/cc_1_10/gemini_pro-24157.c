//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXLINE 1024
#define PORT 143

// This function gets the address of the server from the hostname.
struct sockaddr_in *get_server_address(char *hostname) {
  struct addrinfo hints, *res;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;

  if (getaddrinfo(hostname, NULL, &hints, &res) != 0) {
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
    exit(1);
  }

  struct sockaddr_in *addr = (struct sockaddr_in *)res->ai_addr;
  freeaddrinfo(res);

  return addr;
}

// This function creates a socket and connects to the server.
int connect_to_server(struct sockaddr_in *addr) {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr *)addr, sizeof(*addr)) == -1) {
    perror("connect");
    exit(1);
  }

  return sockfd;
}

// This function sends a command to the server.
void send_command(int sockfd, char *command) {
  if (send(sockfd, command, strlen(command), 0) == -1) {
    perror("send");
    exit(1);
  }
}

// This function receives a response from the server.
char *receive_response(int sockfd) {
  char *response = malloc(MAXLINE);
  if (response == NULL) {
    perror("malloc");
    exit(1);
  }

  if (recv(sockfd, response, MAXLINE, 0) == -1) {
    perror("recv");
    exit(1);
  }

  return response;
}

// This function logs in to the server.
void login(int sockfd, char *username, char *password) {
  send_command(sockfd, "LOGIN ");
  send_command(sockfd, username);
  send_command(sockfd, " ");
  send_command(sockfd, password);
  send_command(sockfd, "\r\n");

  char *response = receive_response(sockfd);
  if (strncmp(response, "+OK LOGIN completed", 18) != 0) {
    fprintf(stderr, "Error: %s\n", response);
    exit(1);
  }
}

// This function lists the mailboxes on the server.
void list_mailboxes(int sockfd) {
  send_command(sockfd, "LIST \"\" *\r\n");

  char *response = receive_response(sockfd);
  while (strncmp(response, "+OK", 3) == 0) {
    printf("%s\n", response);
    response = receive_response(sockfd);
  }

  if (strncmp(response, "-ERR", 4) == 0) {
    fprintf(stderr, "Error: %s\n", response);
    exit(1);
  }
}

// This function selects a mailbox.
void select_mailbox(int sockfd, char *mailbox) {
  send_command(sockfd, "SELECT ");
  send_command(sockfd, mailbox);
  send_command(sockfd, "\r\n");

  char *response = receive_response(sockfd);
  if (strncmp(response, "+OK", 3) != 0) {
    fprintf(stderr, "Error: %s\n", response);
    exit(1);
  }
}

// This function fetches a message.
void fetch_message(int sockfd, char *message_id) {
  send_command(sockfd, "FETCH ");
  send_command(sockfd, message_id);
  send_command(sockfd, " (RFC822)\r\n");

  char *response = receive_response(sockfd);
  while (strncmp(response, "+OK", 3) == 0) {
    printf("%s\n", response);
    response = receive_response(sockfd);
  }

  if (strncmp(response, "-ERR", 4) == 0) {
    fprintf(stderr, "Error: %s\n", response);
    exit(1);
  }
}

// This function closes the connection to the server.
void close_connection(int sockfd) {
  send_command(sockfd, "LOGOUT\r\n");
  close(sockfd);
}

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
    exit(1);
  }

  char *hostname = argv[1];
  char *username = argv[2];
  char *password = argv[3];

  struct sockaddr_in *addr = get_server_address(hostname);
  int sockfd = connect_to_server(addr);

  login(sockfd, username, password);
  list_mailboxes(sockfd);
  select_mailbox(sockfd, "Inbox");
  fetch_message(sockfd, "1");
  close_connection(sockfd);

  return 0;
}