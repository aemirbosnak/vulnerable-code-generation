//FormAI DATASET v1.0 Category: Email Client ; Style: asynchronous
/*
   C Asynchronous Email Client Example Program
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/select.h>

#define MAX_LEN 1024
#define TIMEOUT 15   // Timeout in seconds

struct timeval tv;

void handle_timeout(int signum) {
  // Handle timeout event
  printf("Timeout reached. Exiting...\n");
  exit(0);
}

void send_email(int sock_fd, char *email_user, char *email_pwd, char *to_addr, char *subject, char *msg) {
  char buf[MAX_LEN];
  int len;
  
  // Set time out
  tv.tv_sec = TIMEOUT;
  tv.tv_usec = 0;
  
  // Set signal
  signal(SIGALRM, handle_timeout);
  
  // Send EHLO command to server
  snprintf(buf, MAX_LEN, "EHLO example.com\r\n");
  len = strlen(buf);
  write(sock_fd, buf, len);
  
  // Wait for response
  alarm(TIMEOUT);
  memset(buf, 0, MAX_LEN);
  len = read(sock_fd, buf, MAX_LEN-1);
  
  // Send STARTTLS command to server
  snprintf(buf, MAX_LEN, "STARTTLS\r\n");
  len = strlen(buf);
  write(sock_fd, buf, len);
  
  // Wait for response
  alarm(TIMEOUT);
  memset(buf, 0, MAX_LEN);
  len = read(sock_fd, buf, MAX_LEN-1);
  
  // Encrypt the connection with SSL
  // ...

  // Send AUTH LOGIN command to server
  snprintf(buf, MAX_LEN, "AUTH LOGIN\r\n");
  len = strlen(buf);
  write(sock_fd, buf, len);

  // Wait for response
  alarm(TIMEOUT);
  memset(buf, 0, MAX_LEN);
  len = read(sock_fd, buf, MAX_LEN-1);

  // Send username to server
  snprintf(buf, MAX_LEN, "%s\r\n", email_user);
  len = strlen(buf);
  write(sock_fd, buf, len);

  // Wait for response
  alarm(TIMEOUT);
  memset(buf, 0, MAX_LEN);
  len = read(sock_fd, buf, MAX_LEN-1);

  // Send password to server
  snprintf(buf, MAX_LEN, "%s\r\n", email_pwd);
  len = strlen(buf);
  write(sock_fd, buf, len);

  // Wait for response
  alarm(TIMEOUT);
  memset(buf, 0, MAX_LEN);
  len = read(sock_fd, buf, MAX_LEN-1);

  // Send MAIL FROM command to server
  snprintf(buf, MAX_LEN, "MAIL FROM:<%s>\r\n", email_user);
  len = strlen(buf);
  write(sock_fd, buf, len);

  // Wait for response
  alarm(TIMEOUT);
  memset(buf, 0, MAX_LEN);
  len = read(sock_fd, buf, MAX_LEN-1);

  // Send RCPT TO command to server
  snprintf(buf, MAX_LEN, "RCPT TO:<%s>\r\n", to_addr);
  len = strlen(buf);
  write(sock_fd, buf, len);

  // Wait for response
  alarm(TIMEOUT);
  memset(buf, 0, MAX_LEN);
  len = read(sock_fd, buf, MAX_LEN-1);

  // Send DATA command to server
  snprintf(buf, MAX_LEN, "DATA\r\n");
  len = strlen(buf);
  write(sock_fd, buf, len);

  // Wait for response
  alarm(TIMEOUT);
  memset(buf, 0, MAX_LEN);
  len = read(sock_fd, buf, MAX_LEN-1);

  // Send message body to server
  snprintf(buf, MAX_LEN, "From: <%s>\r\nTo: <%s>\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", email_user, to_addr, subject, msg);
  len = strlen(buf);
  write(sock_fd, buf, len);

  // Wait for response
  alarm(TIMEOUT);
  memset(buf, 0, MAX_LEN);
  len = read(sock_fd, buf, MAX_LEN-1);

  // Send QUIT command to server
  snprintf(buf, MAX_LEN, "QUIT\r\n");
  len = strlen(buf);
  write(sock_fd, buf, len);

  // Wait for response
  alarm(TIMEOUT);
  memset(buf, 0, MAX_LEN);
  len = read(sock_fd, buf, MAX_LEN-1);

  printf("Mail sent successfully.\n");
}

int main(int argc, char *argv[]) {
  char email_user[MAX_LEN], email_pwd[MAX_LEN], to_addr[MAX_LEN], subject[MAX_LEN], msg[MAX_LEN];
  int sock_fd, port_no;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  // Get user inputs
  printf("Enter your email address: ");
  fgets(email_user, MAX_LEN, stdin);
  email_user[strcspn(email_user, "\n")] = 0;

  printf("Enter your email password: ");
  fgets(email_pwd, MAX_LEN, stdin);
  email_pwd[strcspn(email_pwd, "\n")] = 0;

  printf("Enter recipient's email address: ");
  fgets(to_addr, MAX_LEN, stdin);
  to_addr[strcspn(to_addr, "\n")] = 0;

  printf("Enter email subject: ");
  fgets(subject, MAX_LEN, stdin);
  subject[strcspn(subject, "\n")] = 0;

  printf("Enter email message: ");
  fgets(msg, MAX_LEN, stdin);
  msg[strcspn(msg, "\n")] = 0;

  printf("Enter the email server port number: ");
  scanf("%d", &port_no);

  // Create a TCP socket
  if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Socket error");
    exit(1);
  }

  // Get IP address of the email server
  if ((server = gethostbyname("smtp.gmail.com")) == NULL) {
    perror("Unknown email server");
    exit(1);
  }

  // Configure the server address structure
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr = *((struct in_addr *) server->h_addr);
  serv_addr.sin_port = htons(port_no);

  // Connect to the email server
  if (connect(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("Connect error");
    exit(1);
  }

  // Send email using asynchronous style
  send_email(sock_fd, email_user, email_pwd, to_addr, subject, msg);
  
  return 0;
}