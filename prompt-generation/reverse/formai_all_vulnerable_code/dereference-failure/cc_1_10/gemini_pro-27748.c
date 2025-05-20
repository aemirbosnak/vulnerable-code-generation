//GEMINI-pro DATASET v1.0 Category: Cryptographic hash function ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/sha.h>

#define PORT 8080

typedef struct {
  int sockfd;
  struct sockaddr_in addr;
  char *buf;
  size_t buflen;
  SHA256_CTX ctx;
} client_t;

void client_init(client_t *client) {
  client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (client->sockfd < 0) {
    perror("socket");
    exit(1);
  }

  client->addr.sin_family = AF_INET;
  client->addr.sin_port = htons(PORT);
  client->addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  if (connect(client->sockfd, (struct sockaddr *)&client->addr, sizeof(client->addr)) < 0) {
    perror("connect");
    exit(1);
  }

  client->buf = malloc(1024);
  if (client->buf == NULL) {
    perror("malloc");
    exit(1);
  }

  client->buflen = 0;

  SHA256_Init(&client->ctx);
}

void client_process(client_t *client) {
  int n;

  n = recv(client->sockfd, client->buf, client->buflen, 0);
  if (n < 0) {
    perror("recv");
    exit(1);
  }

  client->buflen += n;

  SHA256_Update(&client->ctx, client->buf, client->buflen);
}

void client_finish(client_t *client) {
  unsigned char digest[SHA256_DIGEST_LENGTH];

  SHA256_Final(digest, &client->ctx);

  printf("SHA256 digest: ");
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    printf("%02x", digest[i]);
  }
  printf("\n");

  close(client->sockfd);
  free(client->buf);
}

int main(int argc, char **argv) {
  client_t client;

  client_init(&client);

  while (1) {
    client_process(&client);
  }

  client_finish(&client);

  return 0;
}