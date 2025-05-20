//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>

#define DEFAULT_PORT 465

int main(int argc, char **argv) {
  int sockfd;
  struct sockaddr_in servaddr;
  SSL *ssl;
  SSL_CTX *ctx;

  // Check command-line arguments
  if (argc != 3) {
    fprintf(stderr, "Usage: %s hostname message\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Create a TCP socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Initialize the server address structure
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(DEFAULT_PORT);
  if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    fprintf(stderr, "Invalid hostname: %s\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  // Initialize the SSL library
  SSL_library_init();

  // Create an SSL context
  ctx = SSL_CTX_new(TLS_client_method());
  if (ctx == NULL) {
    ERR_print_errors_fp(stderr);
    exit(EXIT_FAILURE);
  }

  // Create an SSL connection
  ssl = SSL_new(ctx);
  if (ssl == NULL) {
    ERR_print_errors_fp(stderr);
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Associate the socket with the SSL connection
  SSL_set_fd(ssl, sockfd);

  // Perform the SSL handshake
  if (SSL_connect(ssl) != 1) {
    ERR_print_errors_fp(stderr);
    exit(EXIT_FAILURE);
  }

  // Send the message to the server
  if (SSL_write(ssl, argv[2], strlen(argv[2])) == -1) {
    ERR_print_errors_fp(stderr);
    exit(EXIT_FAILURE);
  }

  // Close the SSL connection
  SSL_shutdown(ssl);

  // Close the socket
  close(sockfd);

  // Free the SSL context
  SSL_CTX_free(ctx);

  return 0;
}