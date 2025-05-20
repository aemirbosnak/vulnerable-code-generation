//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

// Custom error handler
void error(char *msg, int fd) {
  perror(msg);
  close(fd);
  exit(EXIT_FAILURE);
}

// Read a line from a socket
char *readline(int fd) {
  char *line = NULL;
  size_t len = 0;
  ssize_t nread;

  while ((nread = getline(&line, &len, fd)) != -1) {
    // Remove trailing newline
    if (nread > 0 && line[nread - 1] == '\n') {
      line[nread - 1] = '\0';
    }
    return line;
  }

  // Read error or EOF
  if (nread == -1) {
    error("readline", fd);
  }

  return NULL;
}

// Send a command to a socket
void send_command(int fd, char *cmd) {
  if (send(fd, cmd, strlen(cmd), 0) == -1) {
    error("send", fd);
  }
}

int main(int argc, char *argv[]) {
  // Check usage
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <smtp_server> <port> <message>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Parse arguments
  char *smtp_server = argv[1];
  int port = atoi(argv[2]);
  char *message = argv[3];

  // Create a TCP socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    error("socket", sock);
  }

  // Set up server address
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  if (inet_pton(AF_INET, smtp_server, &server_addr.sin_addr) == -1) {
    error("inet_pton", sock);
  }

  // Connect to server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    error("connect", sock);
  }

  // Read banner
  char *banner = readline(sock);
  if (banner == NULL) {
    error("readline", sock);
  }
  printf("Server banner:\n%s\n", banner);
  free(banner);

  // Send HELO command
  send_command(sock, "HELO localhost\r\n");

  // Read HELO response
  char *helo_response = readline(sock);
  if (helo_response == NULL) {
    error("readline", sock);
  }
  printf("HELO response:\n%s\n", helo_response);
  free(helo_response);

  // Send MAIL FROM command
  send_command(sock, "MAIL FROM: <sender@example.com>\r\n");

  // Read MAIL FROM response
  char *mail_from_response = readline(sock);
  if (mail_from_response == NULL) {
    error("readline", sock);
  }
  printf("MAIL FROM response:\n%s\n", mail_from_response);
  free(mail_from_response);

  // Send RCPT TO command
  send_command(sock, "RCPT TO: <recipient@example.com>\r\n");

  // Read RCPT TO response
  char *rcpt_to_response = readline(sock);
  if (rcpt_to_response == NULL) {
    error("readline", sock);
  }
  printf("RCPT TO response:\n%s\n", rcpt_to_response);
  free(rcpt_to_response);

  // Send DATA command
  send_command(sock, "DATA\r\n");

  // Read DATA response
  char *data_response = readline(sock);
  if (data_response == NULL) {
    error("readline", sock);
  }
  printf("DATA response:\n%s\n", data_response);
  free(data_response);

  // Send message
  send(sock, message, strlen(message), 0);

  // Send dot (.) to end message
  send_command(sock, ".\r\n");

  // Read QUIT response
  char *quit_response = readline(sock);
  if (quit_response == NULL) {
    error("readline", sock);
  }
  printf("QUIT response:\n%s\n", quit_response);
  free(quit_response);

  // Close socket
  close(sock);

  return EXIT_SUCCESS;
}