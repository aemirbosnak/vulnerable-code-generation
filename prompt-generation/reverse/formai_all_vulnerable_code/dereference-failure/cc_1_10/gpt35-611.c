//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int createSocket(char *hostname, char *port) {
  int sockfd;
  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  getaddrinfo(hostname, port, &hints, &res);
  sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
    perror("connect");
    exit(EXIT_FAILURE);
  }
  freeaddrinfo(res);
  return sockfd;
}

int main(void) {
  SSL_CTX *ctx;
  SSL *ssl;
  char *hostname = "imap.gmail.com";
  char *port = "993";
  char buffer[BUFFER_SIZE];
  int sockfd = createSocket(hostname, port);

  SSL_library_init();
  SSL_load_error_strings();
  OpenSSL_add_all_algorithms();
  ctx = SSL_CTX_new(TLSv1_2_client_method());
  ssl = SSL_new(ctx);
  SSL_set_fd(ssl, sockfd);
  SSL_connect(ssl);

  printf("%s\n", SSL_get_cipher(ssl));

  SSL_write(ssl, "A1 LOGIN username password\r\n", strlen("A1 LOGIN username password\r\n"));
  SSL_read(ssl, buffer, BUFFER_SIZE);
  printf("%s", buffer);

  SSL_write(ssl, "A2 LIST \"\" *\r\n", strlen("A2 LIST \"\" *\r\n"));
  SSL_read(ssl, buffer, BUFFER_SIZE);
  printf("%s", buffer);

  SSL_write(ssl, "A3 LOGOUT\r\n", strlen("A3 LOGOUT\r\n"));
  SSL_read(ssl, buffer, BUFFER_SIZE);
  printf("%s", buffer);

  SSL_shutdown(ssl);
  SSL_free(ssl);
  SSL_CTX_free(ctx);
  close(sockfd);
  return 0;
}