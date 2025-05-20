//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>

#define BUF_LEN 1024

int main(int argc, char **argv)
{
  int sockfd, ret;
  struct sockaddr_in serv_addr;
  char buf[BUF_LEN];

  if (argc != 3) {
    printf("Usage: %s <ip> <port>\n", argv[0]);
    return -1;
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
  serv_addr.sin_port = htons(atoi(argv[2]));

  ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
  if (ret == -1) {
    perror("connect");
    close(sockfd);
    return -1;
  }

  SSL_CTX *ctx;
  SSL *ssl;

  SSL_library_init();
  SSL_load_error_strings();

  ctx = SSL_CTX_new(TLSv1_2_client_method());

  ssl = SSL_new(ctx);
  if (ssl == NULL) {
    ERR_print_errors_fp(stderr);
    SSL_CTX_free(ctx);
    close(sockfd);
    return -1;
  }

  ret = SSL_set_fd(ssl, sockfd);
  if (ret == 0) {
    ERR_print_errors_fp(stderr);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return -1;
  }

  ret = SSL_connect(ssl);
  if (ret != 1) {
    ERR_print_errors_fp(stderr);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return -1;
  }

  while (1) {
    printf("> ");
    memset(buf, 0, BUF_LEN);
    fgets(buf, BUF_LEN, stdin);

    ret = SSL_write(ssl, buf, strlen(buf));
    if (ret <= 0) {
      ERR_print_errors_fp(stderr);
      SSL_free(ssl);
      SSL_CTX_free(ctx);
      close(sockfd);
      return -1;
    }

    memset(buf, 0, BUF_LEN);
    ret = SSL_read(ssl, buf, BUF_LEN);
    if (ret <= 0) {
      ERR_print_errors_fp(stderr);
      SSL_free(ssl);
      SSL_CTX_free(ctx);
      close(sockfd);
      return -1;
    }

    printf("%s\n", buf);
  }

  SSL_free(ssl);
  SSL_CTX_free(ctx);
  close(sockfd);

  return 0;
}