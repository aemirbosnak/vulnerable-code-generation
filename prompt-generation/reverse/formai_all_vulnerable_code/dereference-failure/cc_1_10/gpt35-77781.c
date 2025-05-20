//FormAI DATASET v1.0 Category: Email Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 587
#define SERVER "smtp.gmail.com"

int send_email(const char *from, const char *to, const char *subject, const char *body);

int main() {
  char from[] = "example@gmail.com";
  char to[] = "recipient@example.com";
  char subject[] = "Test Email";
  char body[] = "This is a test email sent from my C email client.\n";
  
  int sent = send_email(from, to, subject, body);
  
  if(sent) {
    printf("Email sent successfully!\n");
  } else {
    printf("Failed to send email.\n");
  }
  
  return 0;
}

int send_email(const char *from, const char *to, const char *subject, const char *body) {
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("Socket creation error");
    return 0;
  }
  
  struct hostent *server = gethostbyname(SERVER);
  if(server == NULL) {
    perror("Host not found");
    return 0;
  }
  
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  
  if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Connection error");
    return 0;
  }
  
  char buffer[1024];
  memset(buffer, 0, 1024);
  recv(sockfd, buffer, 1024, 0);
  
  char login[] = "AUTH LOGIN\n";
  send(sockfd, login, strlen(login), 0);
  memset(buffer, 0, 1024);
  recv(sockfd, buffer, 1024, 0);
  
  char username[] = "example@gmail.com\n";
  send(sockfd, username, strlen(username), 0);
  memset(buffer, 0, 1024);
  recv(sockfd, buffer, 1024, 0);
  
  char password[] = "password123\n"; // Enter your email account password here
  send(sockfd, password, strlen(password), 0);
  memset(buffer, 0, 1024);
  recv(sockfd, buffer, 1024, 0);
  
  char mail[] = "MAIL FROM: <example@gmail.com>\n";
  send(sockfd, mail, strlen(mail), 0);
  memset(buffer, 0, 1024);
  recv(sockfd, buffer, 1024, 0);
  
  char rcpt[100];
  sprintf(rcpt, "RCPT TO: <%s>\n", to);
  send(sockfd, rcpt, strlen(rcpt), 0);
  memset(buffer, 0, 1024);
  recv(sockfd, buffer, 1024, 0);
  
  char data[] = "DATA\n";
  send(sockfd, data, strlen(data), 0);
  memset(buffer, 0, 1024);
  recv(sockfd, buffer, 1024, 0);
  
  char email[1024];
  sprintf(email, "From: <%s>\r\nTo: <%s>\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", from, to, subject, body);
  send(sockfd, email, strlen(email), 0);
  memset(buffer, 0, 1024);
  recv(sockfd, buffer, 1024, 0);
  
  char quit[] = "QUIT\n";
  send(sockfd, quit, strlen(quit), 0);
  memset(buffer, 0, 1024);
  recv(sockfd, buffer, 1024, 0);
  
  close(sockfd);
  return 1;
}