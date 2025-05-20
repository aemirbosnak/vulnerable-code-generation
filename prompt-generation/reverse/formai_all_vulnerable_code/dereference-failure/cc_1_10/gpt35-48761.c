//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <openssl/ssl.h>

#define IMAP_PORT 143

int main(void) {
  printf("Welcome to my IMAP client!\n");

  // Connect to server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    printf("Error creating socket\n");
    return 1;
  }

  char *imap_server = "mail.example.com"; // Replace with actual server
  struct hostent *server = gethostbyname(imap_server);
  if (server == NULL) {
    printf("Error finding server\n");
    return 1;
  }

  struct sockaddr_in serv_addr = {0};
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(IMAP_PORT);
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    printf("Error connecting to server\n");
    return 1;
  }

  printf("Connected to server\n");

  // SSL setup
  SSL_library_init();
  SSL_CTX *ssl_ctx = SSL_CTX_new(SSLv23_client_method());
  SSL *ssl = SSL_new(ssl_ctx);
  SSL_set_fd(ssl, sockfd);

  if (SSL_connect(ssl) < 1) {
    printf("Error establishing SSL connection\n");
    return 1;
  }

  printf("SSL connection established\n");

  // Login
  char *login_cmd = "a001 LOGIN username password\r\n";
  SSL_write(ssl, login_cmd, strlen(login_cmd));

  char response[1024] = {0};
  int bytes = SSL_read(ssl, response, sizeof(response));
  response[bytes] = '\0'; // Null-terminate the response string
  printf("%s", response);

  // Select mailbox
  char *select_cmd = "a002 SELECT INBOX\r\n";
  SSL_write(ssl, select_cmd, strlen(select_cmd));

  bytes = SSL_read(ssl, response, sizeof(response));
  response[bytes] = '\0';
  printf("%s", response);

  // Fetch messages
  char *fetch_cmd = "a003 FETCH 1:* BODY[HEADER.FIELDS (FROM SUBJECT)]\r\n";
  SSL_write(ssl, fetch_cmd, strlen(fetch_cmd));

  int remaining = 0; // Remainder of the message to read
  while (bytes = SSL_read(ssl, response + remaining, sizeof(response) - remaining)) {
    remaining = parse_response(response, &bytes); // Parse messages and update remaining bytes to read
    printf("%s", response); // Display the parsed response
  }

  // Logout
  char *logout_cmd = "a004 LOGOUT\r\n";
  SSL_write(ssl, logout_cmd, strlen(logout_cmd));

  bytes = SSL_read(ssl, response, sizeof(response));
  response[bytes] = '\0';
  printf("%s", response);

  // Cleanup
  SSL_shutdown(ssl); // Gracefully close SSL connection
  SSL_free(ssl); // Free SSL object
  SSL_CTX_free(ssl_ctx); // Free SSL context
  close(sockfd); // Close socket

  printf("Goodbye!\n");

  return 0;
}

int parse_response(char *response, int *size) {
  int i, j;

  // Find the end of the last complete message
  for (i = *size - 1; i >= 0; i--) {
    if (response[i] == '\n' && response[i - 1] == '\r' &&
        response[i - 3] == 'O' && response[i - 2] == 'K') {
      i += 2; // Include the CRLF at the end of the OK line
      break;
    }
  }

  // Parse remaining messages
  for (j = i; j < *size; j++) {
    if (response[j] == '\n' && response[j - 1] == '\r') {
      printf("%.*s\n", j - i - 1, response + i); // Display the message
      i = j + 1; // Move i past the end of the message
    }
  }

  // Copy remaining bytes to the beginning of the buffer
  *size -= i;
  memmove(response, response + i, *size);

  return *size;
}