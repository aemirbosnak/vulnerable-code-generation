//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

typedef struct {
  char *host;
  int port;
  char *username;
  char *password;
  char *from;
  char *to;
  char *subject;
  char *body;
} smtp_client_t;

int smtp_client_init(smtp_client_t *client, char *host, int port, char *username, char *password, char *from, char *to, char *subject, char *body) {
  client->host = host;
  client->port = port;
  client->username = username;
  client->password = password;
  client->from = from;
  client->to = to;
  client->subject = subject;
  client->body = body;
  return 0;
}

int smtp_client_connect(smtp_client_t *client) {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    return -1;
  }

  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(client->port);
  serv_addr.sin_addr.s_addr = inet_addr(client->host);

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
    return -1;
  }

  return sockfd;
}

int smtp_client_send(smtp_client_t *client, int sockfd) {
  char buf[1024];
  int n;

  // HELO
  sprintf(buf, "HELO %s\r\n", client->host);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    return -1;
  }
  if (recv(sockfd, buf, sizeof(buf), 0) <= 0) {
    return -1;
  }

  // AUTH LOGIN
  sprintf(buf, "AUTH LOGIN\r\n");
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    return -1;
  }
  if (recv(sockfd, buf, sizeof(buf), 0) <= 0) {
    return -1;
  }

  // USERNAME
  sprintf(buf, "%s\r\n", client->username);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    return -1;
  }
  if (recv(sockfd, buf, sizeof(buf), 0) <= 0) {
    return -1;
  }

  // PASSWORD
  sprintf(buf, "%s\r\n", client->password);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    return -1;
  }
  if (recv(sockfd, buf, sizeof(buf), 0) <= 0) {
    return -1;
  }

  // MAIL FROM
  sprintf(buf, "MAIL FROM: <%s>\r\n", client->from);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    return -1;
  }
  if (recv(sockfd, buf, sizeof(buf), 0) <= 0) {
    return -1;
  }

  // RCPT TO
  sprintf(buf, "RCPT TO: <%s>\r\n", client->to);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    return -1;
  }
  if (recv(sockfd, buf, sizeof(buf), 0) <= 0) {
    return -1;
  }

  // DATA
  sprintf(buf, "DATA\r\n");
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    return -1;
  }
  if (recv(sockfd, buf, sizeof(buf), 0) <= 0) {
    return -1;
  }

  // SUBJECT
  sprintf(buf, "Subject: %s\r\n", client->subject);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    return -1;
  }

  // BODY
  sprintf(buf, "%s\r\n", client->body);
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    return -1;
  }

  // QUIT
  sprintf(buf, "QUIT\r\n");
  n = send(sockfd, buf, strlen(buf), 0);
  if (n == -1) {
    return -1;
  }
  if (recv(sockfd, buf, sizeof(buf), 0) <= 0) {
    return -1;
  }

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc != 10) {
    printf("Usage: %s host port username password from to subject body\n", argv[0]);
    return 1;
  }

  smtp_client_t client;
  smtp_client_init(&client, argv[1], atoi(argv[2]), argv[3], argv[4], argv[5], argv[6], argv[7], argv[8]);
  int sockfd = smtp_client_connect(&client);
  if (sockfd == -1) {
    perror("smtp_client_connect");
    return 1;
  }
  if (smtp_client_send(&client, sockfd) == -1) {
    perror("smtp_client_send");
    return 1;
  }
  close(sockfd);

  return 0;
}