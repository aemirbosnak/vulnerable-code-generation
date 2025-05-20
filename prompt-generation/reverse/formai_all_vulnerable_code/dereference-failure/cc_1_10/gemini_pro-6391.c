//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define PORT 21

struct ftp_client {
  int sockfd;
  struct sockaddr_in serv_addr;
  char *host;
  char *user;
  char *pass;
  char *cwd;
};

struct ftp_client *ftp_client_new(char *host, char *user, char *pass) {
  struct ftp_client *client = malloc(sizeof(struct ftp_client));
  client->host = host;
  client->user = user;
  client->pass = pass;
  client->cwd = "/";
  return client;
}

void ftp_client_free(struct ftp_client *client) {
  close(client->sockfd);
  free(client);
}

int ftp_client_connect(struct ftp_client *client) {
  struct hostent *hostent = gethostbyname(client->host);
  if (hostent == NULL) {
    perror("gethostbyname");
    return -1;
  }

  client->sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (client->sockfd == -1) {
    perror("socket");
    return -1;
  }

  client->serv_addr.sin_family = AF_INET;
  client->serv_addr.sin_port = htons(PORT);
  client->serv_addr.sin_addr = *((struct in_addr *)hostent->h_addr);

  if (connect(client->sockfd, (struct sockaddr *)&client->serv_addr, sizeof(client->serv_addr)) == -1) {
    perror("connect");
    return -1;
  }

  return 0;
}

int ftp_client_login(struct ftp_client *client) {
  char buf[1024];
  int n;

  n = recv(client->sockfd, buf, sizeof(buf), 0);
  if (n == -1) {
    perror("recv");
    return -1;
  }

  if (strncmp(buf, "220", 3) != 0) {
    fprintf(stderr, "FTP server did not respond with a 220 welcome message: %s\n", buf);
    return -1;
  }

  snprintf(buf, sizeof(buf), "USER %s\r\n", client->user);
  n = send(client->sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    perror("send");
    return -1;
  }

  n = recv(client->sockfd, buf, sizeof(buf), 0);
  if (n == -1) {
    perror("recv");
    return -1;
  }

  if (strncmp(buf, "331", 3) != 0) {
    fprintf(stderr, "FTP server did not respond with a 331 username OK message: %s\n", buf);
    return -1;
  }

  snprintf(buf, sizeof(buf), "PASS %s\r\n", client->pass);
  n = send(client->sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    perror("send");
    return -1;
  }

  n = recv(client->sockfd, buf, sizeof(buf), 0);
  if (n == -1) {
    perror("recv");
    return -1;
  }

  if (strncmp(buf, "230", 3) != 0) {
    fprintf(stderr, "FTP server did not respond with a 230 login successful message: %s\n", buf);
    return -1;
  }

  return 0;
}

int ftp_client_cwd(struct ftp_client *client, char *path) {
  char buf[1024];
  int n;

  snprintf(buf, sizeof(buf), "CWD %s\r\n", path);
  n = send(client->sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    perror("send");
    return -1;
  }

  n = recv(client->sockfd, buf, sizeof(buf), 0);
  if (n == -1) {
    perror("recv");
    return -1;
  }

  if (strncmp(buf, "250", 3) != 0) {
    fprintf(stderr, "FTP server did not respond with a 250 CWD successful message: %s\n", buf);
    return -1;
  }

  client->cwd = path;

  return 0;
}

int ftp_client_list(struct ftp_client *client) {
  char buf[1024];
  int n;

  snprintf(buf, sizeof(buf), "LIST\r\n");
  n = send(client->sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    perror("send");
    return -1;
  }

  while ((n = recv(client->sockfd, buf, sizeof(buf), 0)) > 0) {
    printf("%s", buf);
  }

  if (n == -1) {
    perror("recv");
    return -1;
  }

  return 0;
}

int ftp_client_retr(struct ftp_client *client, char *path) {
  char buf[1024];
  int n;

  snprintf(buf, sizeof(buf), "RETR %s\r\n", path);
  n = send(client->sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    perror("send");
    return -1;
  }

  FILE *f = fopen(path, "w");
  if (f == NULL) {
    perror("fopen");
    return -1;
  }

  while ((n = recv(client->sockfd, buf, sizeof(buf), 0)) > 0) {
    fwrite(buf, 1, n, f);
  }

  if (n == -1) {
    perror("recv");
    return -1;
  }

  fclose(f);

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s host user pass\n", argv[0]);
    return 1;
  }

  struct ftp_client *client = ftp_client_new(argv[1], argv[2], argv[3]);

  if (ftp_client_connect(client) == -1) {
    fprintf(stderr, "ftp_client_connect failed\n");
    return 1;
  }

  if (ftp_client_login(client) == -1) {
    fprintf(stderr, "ftp_client_login failed\n");
    return 1;
  }

  if (ftp_client_cwd(client, "/pub") == -1) {
    fprintf(stderr, "ftp_client_cwd failed\n");
    return 1;
  }

  if (ftp_client_list(client) == -1) {
    fprintf(stderr, "ftp_client_list failed\n");
    return 1;
  }

  if (ftp_client_retr(client, "README.txt") == -1) {
    fprintf(stderr, "ftp_client_retr failed\n");
    return 1;
  }

  ftp_client_free(client);

  return 0;
}