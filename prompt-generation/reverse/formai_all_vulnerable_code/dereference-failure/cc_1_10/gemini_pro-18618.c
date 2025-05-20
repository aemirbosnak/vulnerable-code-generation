//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>

// Our fearless courier, the SMTP client
typedef struct {
  int socket;
  struct sockaddr_in server_addr;
} smtp_client;

// Establish connection with the SMTP server
smtp_client* connect_server(char* hostname, char* port) {
  // Resolve hostname
  struct hostent *host = gethostbyname(hostname);
  if (!host) {
    perror("gethostbyname");
    return NULL;
  }

  // Create and fill in server address
  smtp_client* client = malloc(sizeof(smtp_client));
  memset(client, 0, sizeof(smtp_client));
  client->server_addr.sin_family = AF_INET;
  client->server_addr.sin_addr.s_addr = ((struct in_addr*)(host->h_addr))->s_addr;
  client->server_addr.sin_port = htons(atoi(port));

  // Open socket and connect
  client->socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client->socket < 0) {
    perror("socket");
    free(client);
    return NULL;
  }

  int conn_res = connect(client->socket, (struct sockaddr*)&client->server_addr, sizeof(client->server_addr));
  if (conn_res < 0) {
    perror("connect");
    close(client->socket);
    free(client);
    return NULL;
  }

  // Read welcome message
  char buffer[1024];
  int bytes_read = recv(client->socket, buffer, sizeof(buffer), 0);
  if (bytes_read < 0) {
    perror("recv");
    close(client->socket);
    free(client);
    return NULL;
  }

  printf("Server greeting: %s\n", buffer);
  return client;
}

void send_email(smtp_client* client, char* from, char* to, char* subject, char* body) {
  // Build email message
  char* email = malloc(strlen(from) + strlen(to) + strlen(subject) + strlen(body) + 1024);
  sprintf(email, "From: %s\nTo: %s\nSubject: %s\n\n%s", from, to, subject, body);

  // Send HELO command
  char helo[] = "HELO localhost\r\n";
  int send_res = send(client->socket, helo, strlen(helo), 0);
  if (send_res < 0) {
    perror("send");
    close(client->socket);
    free(client);
    free(email);
    return;
  }

  // Send MAIL FROM command
  char mail_from[1024];
  sprintf(mail_from, "MAIL FROM: <%s>\r\n", from);
  send_res = send(client->socket, mail_from, strlen(mail_from), 0);
  if (send_res < 0) {
    perror("send");
    close(client->socket);
    free(client);
    free(email);
    return;
  }

  // Send RCPT TO command
  char rcpt_to[1024];
  sprintf(rcpt_to, "RCPT TO: <%s>\r\n", to);
  send_res = send(client->socket, rcpt_to, strlen(rcpt_to), 0);
  if (send_res < 0) {
    perror("send");
    close(client->socket);
    free(client);
    free(email);
    return;
  }

  // Send DATA command
  char data[] = "DATA\r\n";
  send_res = send(client->socket, data, strlen(data), 0);
  if (send_res < 0) {
    perror("send");
    close(client->socket);
    free(client);
    free(email);
    return;
  }

  // Send email body
  send_res = send(client->socket, email, strlen(email), 0);
  if (send_res < 0) {
    perror("send");
    close(client->socket);
    free(client);
    free(email);
    return;
  }

  // Send dot(.) to indicate end of email
  char dot[] = ".\r\n";
  send_res = send(client->socket, dot, strlen(dot), 0);
  if (send_res < 0) {
    perror("send");
    close(client->socket);
    free(client);
    free(email);
    return;
  }

  free(email);
}

int main(int argc, char* argv[]) {
  if (argc < 5) {
    printf("Usage: %s hostname port from to subject body\n", argv[0]);
    return 1;
  }

  // Connect to SMTP server
  smtp_client* client = connect_server(argv[1], argv[2]);
  if (!client) {
    return 1;
  }

  // Send email
  send_email(client, argv[3], argv[4], argv[5], argv[6]);

  // Close connection
  close(client->socket);
  free(client);

  return 0;
}