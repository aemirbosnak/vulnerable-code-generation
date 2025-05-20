//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// SMTP commands
#define HELO "HELO %s\r\n"
#define MAIL_FROM "MAIL FROM: <%s>\r\n"
#define RCPT_TO "RCPT TO: <%s>\r\n"
#define DATA "DATA\r\n"
#define QUIT "QUIT\r\n"

// SMTP response codes
#define OK "250"
#define ERROR "500"

// Maximum length of a line
#define MAX_LINE_LENGTH 1024

// Configuration structure
typedef struct {
  char *smtp_server;
  int smtp_port;
  char *sender;
  char *recipient;
  char *message;
} config_t;

// Parse command line arguments and store them in the configuration structure
bool parse_args(int argc, char *argv[], config_t *config) {
  if (argc != 7) {
    printf("Usage: %s <smtp-server> <smtp-port> <sender> <recipient> <message>\n", argv[0]);
    return false;
  }

  config->smtp_server = argv[1];
  config->smtp_port = atoi(argv[2]);
  config->sender = argv[3];
  config->recipient = argv[4];
  config->message = argv[5];

  return true;
}

// Connect to the SMTP server
int connect_server(config_t *config) {
  int sockfd;
  struct sockaddr_in server_addr;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return -1;
  }

  // Set server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(config->smtp_port);
  server_addr.sin_addr.s_addr = inet_addr(config->smtp_server);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    return -1;
  }

  return sockfd;
}

// Send a command to the SMTP server and receive the response
int send_command(int sockfd, char *command) {
  char response[MAX_LINE_LENGTH];

  // Send the command
  if (send(sockfd, command, strlen(command), 0) < 0) {
    perror("send");
    return -1;
  }

  // Receive the response
  if (recv(sockfd, response, MAX_LINE_LENGTH, 0) < 0) {
    perror("recv");
    return -1;
  }

  // Check the response code
  if (strncmp(response, OK, 3) != 0) {
    printf("Error: %s", response);
    return -1;
  }

  return 0;
}

// Send an email message
int send_email(int sockfd, config_t *config) {
  char line[MAX_LINE_LENGTH];

  // Send HELO command
  if (send_command(sockfd, HELO) < 0) {
    return -1;
  }

  // Send MAIL FROM command
  snprintf(line, MAX_LINE_LENGTH, MAIL_FROM, config->sender);
  if (send_command(sockfd, line) < 0) {
    return -1;
  }

  // Send RCPT TO command
  snprintf(line, MAX_LINE_LENGTH, RCPT_TO, config->recipient);
  if (send_command(sockfd, line) < 0) {
    return -1;
  }

  // Send DATA command
  if (send_command(sockfd, DATA) < 0) {
    return -1;
  }

  // Send the message
  if (send(sockfd, config->message, strlen(config->message), 0) < 0) {
    perror("send");
    return -1;
  }

  // Send a period to indicate the end of the message
  if (send(sockfd, "\r\n.\r\n", 5, 0) < 0) {
    perror("send");
    return -1;
  }

  // Send QUIT command
  if (send_command(sockfd, QUIT) < 0) {
    return -1;
  }

  return 0;
}

int main(int argc, char *argv[]) {
  config_t config;
  int sockfd;

  // Parse command line arguments
  if (!parse_args(argc, argv, &config)) {
    return EXIT_FAILURE;
  }

  // Connect to the SMTP server
  sockfd = connect_server(&config);
  if (sockfd < 0) {
    return EXIT_FAILURE;
  }

  // Send an email message
  if (send_email(sockfd, &config) < 0) {
    return EXIT_FAILURE;
  }

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}