//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// IMAP Protocol Constants
#define IMAP_PORT 143
#define IMAP_RESPONSE_LENGTH 4096
#define IMAP_COMMAND_LENGTH 1024

// IMAP Response Constants
#define IMAP_OK "+OK"
#define IMAP_ERROR "-ERR"
#define IMAP_TAG "*"

// IMAP Command Constants
#define IMAP_CMD_LOGIN "LOGIN"
#define IMAP_CMD_SELECT "SELECT"
#define IMAP_CMD_LIST "LIST"
#define IMAP_CMD_FETCH "FETCH"

// Function Prototypes
int connect_to_server(const char* host, int port);
int read_response(int sockfd, char* response);
void send_command(int sockfd, const char* command);
int authenticate(int sockfd, const char* username, const char* password);
int select_mailbox(int sockfd, const char* mailbox);
int list_mailboxes(int sockfd);
int fetch_message(int sockfd, const char* message_id);

int main(int argc, char** argv) {
  const char* host = "mail.example.com";
  const char* username = "user@example.com";
  const char* password = "password";
  const char* mailbox = "inbox";
  const char* message_id = "1";

  int sockfd = connect_to_server(host, IMAP_PORT);
  if (authenticate(sockfd, username, password) == 0) {
    if (select_mailbox(sockfd, mailbox) == 0) {
      list_mailboxes(sockfd);
      fetch_message(sockfd, message_id);
    }
  }

  close(sockfd);

  return 0;
}

/**
 * Connects to an IMAP server at the specified host and port.
 *
 * @param host IMAP server hostname
 * @param port IMAP server port
 *
 * @return Socket file descriptor
 */
int connect_to_server(const char* host, int port) {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);

  struct hostent* server = gethostbyname(host);
  if (server == NULL) {
    fprintf(stderr, "ERROR: Unable to resolve hostname\n");
    exit(1);
  }

  struct sockaddr_in serveraddr;
  memset(&serveraddr, 0, sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  bcopy(server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
  serveraddr.sin_port = htons(port);

  if (connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
    fprintf(stderr, "ERROR: Connection to server failed\n");
    exit(1);
  }

  char response[IMAP_RESPONSE_LENGTH];
  int n = read_response(sockfd, response);
  if (n < 0 || strncmp(response, IMAP_OK, strlen(IMAP_OK)) != 0) {
    fprintf(stderr, "ERROR: Server connection error\n");
    exit(1);
  }

  return sockfd;
}

/**
 * Reads a response from the IMAP server.
 *
 * @param sockfd Socket file descriptor
 * @param response Buffer where the response will be stored
 *
 * @return Number of bytes read
 */
int read_response(int sockfd, char* response) {
  memset(response, 0, IMAP_RESPONSE_LENGTH);

  int n = read(sockfd, response, IMAP_RESPONSE_LENGTH);
  if (n == 0) {
    fprintf(stderr, "ERROR: Server connection closed unexpectedly\n");
    exit(1);
  }

  return n;
}

/**
 * Sends an IMAP command to the server.
 *
 * @param sockfd Socket file descriptor
 * @param command Command to send
 */
void send_command(int sockfd, const char* command) {
  char buffer[IMAP_COMMAND_LENGTH];
  snprintf(buffer, IMAP_COMMAND_LENGTH, "%s\r\n", command);

  int n = write(sockfd, buffer, strlen(buffer));
  if (n < 0) {
    fprintf(stderr, "ERROR: Unable to send IMAP command\n");
    exit(1);
  }
}

/**
 * Authenticates the IMAP client using the specified username and password.
 *
 * @param sockfd Socket file descriptor
 * @param username IMAP username
 * @param password IMAP password
 *
 * @return Authentication status (0 = success, -1 = failure)
 */
int authenticate(int sockfd, const char* username, const char* password) {
  char response[IMAP_RESPONSE_LENGTH];
  memset(response, 0, IMAP_RESPONSE_LENGTH);

  // Send LOGIN command
  send_command(sockfd, IMAP_CMD_LOGIN);
  read_response(sockfd, response);

  // Send username and password
  char command[IMAP_COMMAND_LENGTH];
  snprintf(command, IMAP_COMMAND_LENGTH, "%s %s %s", username, password);
  send_command(sockfd, command);
  int n = read_response(sockfd, response);

  // Check authentication status
  if (n < 0 || strncmp(response, IMAP_OK, strlen(IMAP_OK)) != 0) {
    fprintf(stderr, "ERROR: Authentication failed\n");
    return -1;
  }

  return 0; 
}

/**
 * Selects the specified mailbox.
 *
 * @param sockfd Socket file descriptor
 * @param mailbox Mailbox name
 *
 * @return Selection status (0 = success, -1 = failure)
 */
int select_mailbox(int sockfd, const char* mailbox) {
  char response[IMAP_RESPONSE_LENGTH];
  memset(response, 0, IMAP_RESPONSE_LENGTH);

  // Send SELECT command
  char command[IMAP_COMMAND_LENGTH];
  snprintf(command, IMAP_COMMAND_LENGTH, "%s %s", IMAP_CMD_SELECT, mailbox);
  send_command(sockfd, command);
  int n = read_response(sockfd, response);

  // Check selection status
  if (n < 0 || strncmp(response, IMAP_OK, strlen(IMAP_OK)) != 0) {
    fprintf(stderr, "ERROR: Unable to select mailbox\n");
    return -1;
  }

  return 0;
}

/**
 * Lists all available mailboxes.
 *
 * @param sockfd Socket file descriptor
 *
 * @return List status (0 = success, -1 = failure)
 */
int list_mailboxes(int sockfd) {
  char response[IMAP_RESPONSE_LENGTH];
  memset(response, 0, IMAP_RESPONSE_LENGTH);

  // Send LIST command
  send_command(sockfd, IMAP_CMD_LIST);
  int n = read_response(sockfd, response);

  // Check list status
  if (n >= 0 && strncmp(response, IMAP_OK, strlen(IMAP_OK)) == 0) {
    printf("Available Mailboxes:\n%s\n", response);
    return 0;
  }
  else {
    fprintf(stderr, "ERROR: Unable to list mailboxes\n");
    return -1;
  }
}

/**
 * Fetches a message with the specified ID.
 *
 * @param sockfd Socket file descriptor
 * @param message_id Message ID
 *
 * @return Fetch status (0 = success, -1 = failure)
 */
int fetch_message(int sockfd, const char* message_id) {
  char response[IMAP_RESPONSE_LENGTH];
  memset(response, 0, IMAP_RESPONSE_LENGTH);

  // Send FETCH command
  char command[IMAP_COMMAND_LENGTH];
  snprintf(command, IMAP_COMMAND_LENGTH, "%s %s", IMAP_CMD_FETCH, message_id);
  send_command(sockfd, command);
  int n = read_response(sockfd, response);

  // Check fetch status
  if (n >= 0 && strncmp(response, IMAP_OK, strlen(IMAP_OK)) == 0) {
    printf("Message with ID %s:\n%s\n", message_id, response);
    return 0;
  }
  else {
    fprintf(stderr, "ERROR: Unable to fetch message %s\n", message_id);
    return -1;
  }
}