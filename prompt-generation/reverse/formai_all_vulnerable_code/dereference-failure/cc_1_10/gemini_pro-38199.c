//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define IMAP_PORT 143
#define IMAP_SECURE_PORT 993
#define IMAP_BUFFER_SIZE 1024

typedef struct {
  int sockfd;
  char *hostname;
  int port;
  int is_secure;
  char *username;
  char *password;
} IMAP_CLIENT;

IMAP_CLIENT *imap_client_create(char *hostname, int port, int is_secure, char *username, char *password) {
  IMAP_CLIENT *client = malloc(sizeof(IMAP_CLIENT));
  client->hostname = strdup(hostname);
  client->port = port;
  client->is_secure = is_secure;
  client->username = strdup(username);
  client->password = strdup(password);
  return client;
}

void imap_client_destroy(IMAP_CLIENT *client) {
  free(client->hostname);
  free(client->username);
  free(client->password);
  free(client);
}

int imap_client_connect(IMAP_CLIENT *client) {
  struct sockaddr_in addr;
  int sockfd;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return -1;
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(client->port);
  addr.sin_addr.s_addr = inet_addr(client->hostname);

  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    perror("connect");
    close(sockfd);
    return -1;
  }

  client->sockfd = sockfd;

  return 0;
}

int imap_client_login(IMAP_CLIENT *client) {
  char buffer[IMAP_BUFFER_SIZE];
  int n;

  n = recv(client->sockfd, buffer, IMAP_BUFFER_SIZE - 1, 0);
  if (n == -1) {
    perror("recv");
    return -1;
  }
  buffer[n] = '\0';

  if (strstr(buffer, "* OK") == NULL) {
    printf("Error: %s", buffer);
    return -1;
  }

  snprintf(buffer, IMAP_BUFFER_SIZE, "A1 LOGIN %s %s\r\n", client->username, client->password);
  n = send(client->sockfd, buffer, strlen(buffer), 0);
  if (n == -1) {
    perror("send");
    return -1;
  }

  n = recv(client->sockfd, buffer, IMAP_BUFFER_SIZE - 1, 0);
  if (n == -1) {
    perror("recv");
    return -1;
  }
  buffer[n] = '\0';

  if (strstr(buffer, "* OK") == NULL) {
    printf("Error: %s", buffer);
    return -1;
  }

  return 0;
}

int imap_client_select(IMAP_CLIENT *client, char *mailbox) {
  char buffer[IMAP_BUFFER_SIZE];
  int n;

  snprintf(buffer, IMAP_BUFFER_SIZE, "A2 SELECT %s\r\n", mailbox);
  n = send(client->sockfd, buffer, strlen(buffer), 0);
  if (n == -1) {
    perror("send");
    return -1;
  }

  n = recv(client->sockfd, buffer, IMAP_BUFFER_SIZE - 1, 0);
  if (n == -1) {
    perror("recv");
    return -1;
  }
  buffer[n] = '\0';

  if (strstr(buffer, "* OK") == NULL) {
    printf("Error: %s", buffer);
    return -1;
  }

  return 0;
}

int imap_client_fetch(IMAP_CLIENT *client, char *uid, char *fetch_data) {
  char buffer[IMAP_BUFFER_SIZE];
  int n;

  snprintf(buffer, IMAP_BUFFER_SIZE, "A3 FETCH %s %s\r\n", uid, fetch_data);
  n = send(client->sockfd, buffer, strlen(buffer), 0);
  if (n == -1) {
    perror("send");
    return -1;
  }

  n = recv(client->sockfd, buffer, IMAP_BUFFER_SIZE - 1, 0);
  if (n == -1) {
    perror("recv");
    return -1;
  }
  buffer[n] = '\0';

  if (strstr(buffer, "* OK") == NULL) {
    printf("Error: %s", buffer);
    return -1;
  }

  return 0;
}

int imap_client_close(IMAP_CLIENT *client) {
  char buffer[IMAP_BUFFER_SIZE];
  int n;

  snprintf(buffer, IMAP_BUFFER_SIZE, "A4 LOGOUT\r\n");
  n = send(client->sockfd, buffer, strlen(buffer), 0);
  if (n == -1) {
    perror("send");
    return -1;
  }

  n = recv(client->sockfd, buffer, IMAP_BUFFER_SIZE - 1, 0);
  if (n == -1) {
    perror("recv");
    return -1;
  }
  buffer[n] = '\0';

  if (strstr(buffer, "* OK") == NULL) {
    printf("Error: %s", buffer);
    return -1;
  }

  close(client->sockfd);

  return 0;
}

int main(int argc, char **argv) {
  IMAP_CLIENT *client;
  char *hostname;
  int port;
  int is_secure;
  char *username;
  char *password;
  char *mailbox;
  char *uid;
  char *fetch_data;

  if (argc != 9) {
    printf("Usage: %s hostname port is_secure username password mailbox uid fetch_data\n", argv[0]);
    return 1;
  }

  hostname = argv[1];
  port = atoi(argv[2]);
  is_secure = atoi(argv[3]);
  username = argv[4];
  password = argv[5];
  mailbox = argv[6];
  uid = argv[7];
  fetch_data = argv[8];

  client = imap_client_create(hostname, port, is_secure, username, password);

  if (imap_client_connect(client) == -1) {
    return 1;
  }

  if (imap_client_login(client) == -1) {
    return 1;
  }

  if (imap_client_select(client, mailbox) == -1) {
    return 1;
  }

  if (imap_client_fetch(client, uid, fetch_data) == -1) {
    return 1;
  }

  if (imap_client_close(client) == -1) {
    return 1;
  }

  imap_client_destroy(client);

  return 0;
}