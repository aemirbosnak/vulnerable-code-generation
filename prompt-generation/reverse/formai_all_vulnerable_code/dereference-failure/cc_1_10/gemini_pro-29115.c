//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

// Let's set up our SMTP constants
#define SMTP_PORT 25
#define MAIL_FROM "you@example.com"
#define MAIL_TO "recipient@example.com"
#define SUBJECT "Greetings from the C SMTP Client!"

int main() {
  // Let's connect to the SMTP server!
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Ouch! Socket creation failed.");
    return 1;
  }
  
  struct hostent *server = gethostbyname("smtp.example.com");
  if (server == NULL) {
    perror("D'oh! Couldn't find the server!");
    return 1;
  }
  
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  serv_addr.sin_port = htons(SMTP_PORT);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("Alas! Connection failed.");
    return 1;
  }
  
  // Yay! We're connected. Let's start chatting with the server.
  char buf[1024];
  
  // 1. Say hello to the server
  memset(buf, 0, sizeof(buf));
  sprintf(buf, "HELO example.com\r\n");
  send(sockfd, buf, strlen(buf), 0);
  
  // 2. Identify ourselves as the sender
  memset(buf, 0, sizeof(buf));
  sprintf(buf, "MAIL FROM: %s\r\n", MAIL_FROM);
  send(sockfd, buf, strlen(buf), 0);
  
  // 3. Specify the recipient
  memset(buf, 0, sizeof(buf));
  sprintf(buf, "RCPT TO: %s\r\n", MAIL_TO);
  send(sockfd, buf, strlen(buf), 0);
  
  // 4. Prepare the email's contents
  memset(buf, 0, sizeof(buf));
  sprintf(buf, "Subject: %s\r\n", SUBJECT);
  send(sockfd, buf, strlen(buf), 0);
  send(sockfd, "\r\nThis is the email body.\r\n.\r\n", strlen("\r\nThis is the email body.\r\n.\r\n"), 0);
  
  // 5. Say goodbye to the server
  memset(buf, 0, sizeof(buf));
  strcpy(buf, "QUIT\r\n");
  send(sockfd, buf, strlen(buf), 0);
  
  // Mission accomplished! Let's close the connection.
  close(sockfd);
  
  printf("Ta-da! Your email has been sent. Hooray for C and SMTP!\n");
  return 0;
}