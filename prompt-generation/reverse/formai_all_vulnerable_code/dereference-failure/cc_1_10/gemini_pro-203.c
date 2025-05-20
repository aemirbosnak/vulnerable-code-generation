//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>

int main() {
  int sock, rc;
  struct sockaddr_in server_addr;
  char buf[2048];
  char *hostname = "imap.example.com";
  int port = 993;

  OpenSSL_add_all_algorithms();
  SSL_load_error_strings();
  SSL_library_init();

  SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());
  if (ctx == NULL) {
    printf("Failed to create SSL context\n");
    exit(1);
  }

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    printf("Failed to create socket\n");
    exit(1);
  }

  struct hostent *he = gethostbyname(hostname);
  if (he == NULL) {
    printf("Failed to resolve hostname\n");
    exit(1);
  }

  struct in_addr **addr_list = (struct in_addr **)he->h_addr_list;

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  memcpy(&server_addr.sin_addr.s_addr, *addr_list, sizeof(server_addr.sin_addr.s_addr));

  rc = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
  if (rc < 0) {
    printf("Failed to connect to server\n");
    exit(1);
  }

  SSL *ssl = SSL_new(ctx);
  SSL_set_fd(ssl, sock);
  rc = SSL_connect(ssl);
  if (rc != 1) {
    printf("Failed to establish SSL connection\n");
    exit(1);
  }

  SSL_write(ssl, "A001 LOGIN username password\r\n", strlen("A001 LOGIN username password\r\n"));
  SSL_read(ssl, buf, sizeof(buf));
  printf("%s", buf);

  SSL_write(ssl, "A002 SELECT inbox\r\n", strlen("A002 SELECT inbox\r\n"));
  SSL_read(ssl, buf, sizeof(buf));
  printf("%s", buf);

  SSL_write(ssl, "A003 FETCH 1 (RFC822)\r\n", strlen("A003 FETCH 1 (RFC822)\r\n"));
  SSL_read(ssl, buf, sizeof(buf));
  printf("%s", buf);

  SSL_write(ssl, "A004 LOGOUT\r\n", strlen("A004 LOGOUT\r\n"));
  SSL_read(ssl, buf, sizeof(buf));
  printf("%s", buf);

  SSL_shutdown(ssl);
  SSL_free(ssl);
  SSL_CTX_free(ctx);
  close(sock);

  return 0;
}