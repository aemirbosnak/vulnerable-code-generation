//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define IMAP_PORT 143

struct imap_client {
  int sockfd;
  char *host;
  char *username;
  char *password;
};

struct imap_client *imap_client_create(char *host, char *username, char *password) {
  struct imap_client *client = malloc(sizeof(struct imap_client));
  if (!client) {
    return NULL;
  }

  client->host = strdup(host);
  client->username = strdup(username);
  client->password = strdup(password);

  return client;
}

void imap_client_destroy(struct imap_client *client) {
  free(client->host);
  free(client->username);
  free(client->password);
  free(client);
}

int imap_client_connect(struct imap_client *client) {
  struct sockaddr_in servaddr;
  struct hostent *hostinfo;

  if ((client->sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    return -1;
  }

  if ((hostinfo = gethostbyname(client->host)) == NULL) {
    herror("gethostbyname");
    return -1;
  }

  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(IMAP_PORT);
  memcpy(&servaddr.sin_addr, hostinfo->h_addr_list[0], hostinfo->h_length);

  if (connect(client->sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
    perror("connect");
    return -1;
  }

  return 0;
}

int imap_client_login(struct imap_client *client) {
  char buf[1024];
  int len;

  snprintf(buf, sizeof(buf), "a001 LOGIN %s %s\r\n", client->username, client->password);
  len = write(client->sockfd, buf, strlen(buf));
  if (len < 0) {
    perror("write");
    return -1;
  }

  while ((len = read(client->sockfd, buf, sizeof(buf))) > 0) {
    if (strstr(buf, "OK")) {
      return 0;
    }
  }

  return -1;
}

int imap_client_select(struct imap_client *client, char *mailbox) {
  char buf[1024];
  int len;

  snprintf(buf, sizeof(buf), "a002 SELECT %s\r\n", mailbox);
  len = write(client->sockfd, buf, strlen(buf));
  if (len < 0) {
    perror("write");
    return -1;
  }

  while ((len = read(client->sockfd, buf, sizeof(buf))) > 0) {
    if (strstr(buf, "OK")) {
      return 0;
    }
  }

  return -1;
}

int imap_client_fetch(struct imap_client *client, char *uid) {
  char buf[1024];
  int len;

  snprintf(buf, sizeof(buf), "a003 FETCH %s BODY[]\r\n", uid);
  len = write(client->sockfd, buf, strlen(buf));
  if (len < 0) {
    perror("write");
    return -1;
  }

  while ((len = read(client->sockfd, buf, sizeof(buf))) > 0) {
    if (strstr(buf, "OK")) {
      return 0;
    }
  }

  return -1;
}

int imap_client_logout(struct imap_client *client) {
  char buf[1024];
  int len;

  snprintf(buf, sizeof(buf), "a004 LOGOUT\r\n");
  len = write(client->sockfd, buf, strlen(buf));
  if (len < 0) {
    perror("write");
    return -1;
  }

  while ((len = read(client->sockfd, buf, sizeof(buf))) > 0) {
    if (strstr(buf, "OK")) {
      return 0;
    }
  }

  return -1;
}

int main(int argc, char **argv) {
  struct imap_client *client;
  int ret;

  if (argc != 4) {
    fprintf(stderr, "Usage: %s host username password\n", argv[0]);
    return 1;
  }

  client = imap_client_create(argv[1], argv[2], argv[3]);
  if (!client) {
    perror("imap_client_create");
    return 1;
  }

  ret = imap_client_connect(client);
  if (ret < 0) {
    perror("imap_client_connect");
    goto cleanup;
  }

  ret = imap_client_login(client);
  if (ret < 0) {
    perror("imap_client_login");
    goto cleanup;
  }

  ret = imap_client_select(client, "Inbox");
  if (ret < 0) {
    perror("imap_client_select");
    goto cleanup;
  }

  ret = imap_client_fetch(client, "1");
  if (ret < 0) {
    perror("imap_client_fetch");
    goto cleanup;
  }

  ret = imap_client_logout(client);
  if (ret < 0) {
    perror("imap_client_logout");
  }

cleanup:
  imap_client_destroy(client);
  return ret;
}