//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: expert-level
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<unistd.h>

#define SERVER_PORT 25
#define CLIENT_PORT 2500
#define SERVER_NAME "smtp.gmail.com"
#define CLIENT_NAME "localhost"
#define MAX_MSG_LENGTH 4096

int main(int argc, char *argv[]) {

  int client_socket, server_socket;
  struct sockaddr_in client_address, server_address;
  char buffer[MAX_MSG_LENGTH];
  char *msg = "EHLO gmail.com\r\n";
  char *to_email = "your_email@gmail.com";
  char *from_email = "sender_email@gmail.com";
  char *subject = "Test Email";
  char *body = "Hello,\n\nThis is a test email sent using SMTP client in C programming language.\n\nRegards,\nYour Name";

  // Create client socket
  client_socket = socket(AF_INET, SOCK_STREAM, 0);

  // Set client address
  memset(&client_address, 0, sizeof(client_address));
  client_address.sin_family = AF_INET;
  client_address.sin_port = htons(CLIENT_PORT);
  inet_pton(AF_INET, "127.0.0.1", &client_address.sin_addr);

  // Bind client socket to client address
  bind(client_socket, (struct sockaddr *) &client_address, sizeof(client_address));

  // Set server address
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(SERVER_PORT);

  // Get server IP address
  struct hostent *he = gethostbyname(SERVER_NAME);
  inet_pton(AF_INET, he->h_addr, &server_address.sin_addr);

  // Connect to server
  connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address));

  // Receive greeting message from server
  recv(client_socket, buffer, MAX_MSG_LENGTH, 0);
  printf("%s\n", buffer);

  // Send EHLO message to server
  send(client_socket, msg, strlen(msg), 0);
  recv(client_socket, buffer, MAX_MSG_LENGTH, 0);
  printf("%s\n", buffer);

  // Send MAIL FROM message to server
  char mail_from[MAX_MSG_LENGTH];
  snprintf(mail_from, sizeof mail_from, "MAIL FROM:<%s>\r\n", from_email);
  send(client_socket, mail_from, strlen(mail_from), 0);
  recv(client_socket, buffer, MAX_MSG_LENGTH, 0);
  printf("%s\n", buffer);

  // Send RCPT TO message to server
  char rcpt_to[MAX_MSG_LENGTH];
  snprintf(rcpt_to, sizeof rcpt_to, "RCPT TO:<%s>\r\n", to_email);
  send(client_socket, rcpt_to, strlen(rcpt_to), 0);
  recv(client_socket, buffer, MAX_MSG_LENGTH, 0);
  printf("%s\n", buffer);

  // Send DATA message to server
  char data[] = "DATA\r\n";
  send(client_socket, data, strlen(data), 0);
  recv(client_socket, buffer, MAX_MSG_LENGTH, 0);
  printf("%s\n", buffer);

  // Send email header to server
  char header[MAX_MSG_LENGTH];
  snprintf(header, sizeof header, "From: <%s>\r\nTo: <%s>\r\nSubject: %s\r\n", from_email, to_email, subject);
  send(client_socket, header, strlen(header), 0);

  // Send email body to server
  send(client_socket, body, strlen(body), 0);

  // Send QUIT message to server
  char quit[] = "QUIT\r\n";
  send(client_socket, quit, strlen(quit), 0);
  recv(client_socket, buffer, MAX_MSG_LENGTH, 0);
  printf("%s\n", buffer);

  // Close sockets
  close(client_socket);

  return 0;
}