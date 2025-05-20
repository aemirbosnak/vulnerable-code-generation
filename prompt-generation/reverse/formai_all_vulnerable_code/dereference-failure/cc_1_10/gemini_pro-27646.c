//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: lively
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024

// Connect to the POP3 server
int connect_to_server(const char *host, int port) {
  struct sockaddr_in server_addr;
  int sockfd;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  struct hostent *server = gethostbyname(host);
  if (server == NULL) {
    perror("gethostbyname");
    exit(EXIT_FAILURE);
  }
  memcpy(&server_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  return sockfd;
}

// Send a command to the POP3 server and receive the response
char *send_command(int sockfd, const char *command) {
  char buffer[MAX_BUFFER_SIZE];
  int bytes_received;

  send(sockfd, command, strlen(command), 0);
  recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);

  return strdup(buffer);
}

// Retrieve the number of emails on the server
int get_email_count(int sockfd) {
  char *response = send_command(sockfd, "STAT\r\n");
  char *email_count_str = strtok(response, " ");
  return atoi(email_count_str);
}

// Retrieve the contents of an email
char *get_email(int sockfd, int email_number) {
  char buffer[MAX_BUFFER_SIZE];
  int bytes_received;

  sprintf(buffer, "RETR %d\r\n", email_number);
  send(sockfd, buffer, strlen(buffer), 0);

  // Read the email line by line until we reach the end of the message
  char *email = malloc(MAX_BUFFER_SIZE);
  email[0] = '\0';
  while ((bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
    strcat(email, buffer);
    if (strstr(buffer, "\r\n.\r\n") != NULL) {
      break;
    }
  }

  return email;
}

// Disconnect from the POP3 server
void disconnect_from_server(int sockfd) {
  send(sockfd, "QUIT\r\n", 6, 0);
  close(sockfd);
}

int main(int argc, char **argv) {
  // Check if the correct number of arguments is provided
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Connect to the POP3 server
  int sockfd = connect_to_server(argv[1], atoi(argv[2]));

  // Get the number of emails on the server
  int email_count = get_email_count(sockfd);

  // Retrieve and print the contents of each email
  for (int i = 1; i <= email_count; i++) {
    char *email = get_email(sockfd, i);
    printf("Email %d:\n%s\n", i, email);
    free(email);
  }

  // Disconnect from the POP3 server
  disconnect_from_server(sockfd);

  return 0;
}