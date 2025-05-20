//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

#define PORT 110 // POP3 standard port
#define BUFF_SIZE 1024

// Command strings
const char *USER = "USER ";
const char *PASS = "PASS ";
const char *LIST = "LIST\r\n";
const char *RETR = "RETR %d\r\n";
const char *DELE = "DELE %d\r\n";
const char *QUIT = "QUIT\r\n";

// Function declarations
void error(const char *msg);
int connect_to_server(const char *hostname);
int send_command(int sockfd, const char *cmd);
char *recv_response(int sockfd);

// Entry point
int main(int argc, char **argv) {
  // Check arguments
  if (argc != 3) error("Usage: pop3client <hostname> <username>");

  // Connect to the server
  int sockfd = connect_to_server(argv[1]);

  // Send the USER command
  if (send_command(sockfd, USER) != 0) error("USER command failed");
  if (strcmp(recv_response(sockfd), "+OK") != 0) error("USER command failed");

  // Send the PASS command
  if (send_command(sockfd, PASS) != 0) error("PASS command failed");
  if (strcmp(recv_response(sockfd), "+OK") != 0) error("PASS command failed");

  // Send the LIST command
  if (send_command(sockfd, LIST) != 0) error("LIST command failed");

  // Receive the list of emails
  char *response = recv_response(sockfd);
  printf("Email list:\n%s\n", response);

  // Send the RETR command to fetch an email
  int email_num;
  printf("Enter email number to fetch: ");
  scanf("%d", &email_num);
  char cmd[BUFF_SIZE];
  sprintf(cmd, RETR, email_num);
  if (send_command(sockfd, cmd) != 0) error("RETR command failed");

  // Receive the email content
  response = recv_response(sockfd);
  printf("Email content:\n%s\n", response);

  // Send the DELE command to delete an email
  printf("Enter email number to delete: ");
  scanf("%d", &email_num);
  sprintf(cmd, DELE, email_num);
  if (send_command(sockfd, cmd) != 0) error("DELE command failed");

  // Send the QUIT command
  if (send_command(sockfd, QUIT) != 0) error("QUIT command failed");

  // Close the socket
  close(sockfd);

  return 0;
}

// Error handling
void error(const char *msg) {
  perror(msg);
  exit(1);
}

// Connect to the POP3 server
int connect_to_server(const char *hostname) {
  struct hostent *server = gethostbyname(hostname);
  if (server == NULL) error("Error getting host information");

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) error("Error creating socket");

  // Set the server address
  struct sockaddr_in server_addr;
  bzero((char *) &server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
  server_addr.sin_port = htons(PORT);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) error("Error connecting to server");

  return sockfd;
}

// Send a command to the POP3 server
int send_command(int sockfd, const char *cmd) {
  int bytes_sent = send(sockfd, cmd, strlen(cmd), 0);
  if (bytes_sent < 0) return -1;
  return 0;
}

// Receive a response from the POP3 server
char *recv_response(int sockfd) {
  char *response = malloc(BUFF_SIZE);
  int bytes_received = recv(sockfd, response, BUFF_SIZE, 0);
  if (bytes_received < 0) {
    free(response);
    return NULL;
  }
  response[bytes_received] = '\0';
  return response;
}