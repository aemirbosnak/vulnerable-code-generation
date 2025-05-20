//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {

  printf("Welcome to the SMTP Client. This program sends emails across the world!\n");

  char from_email[100];
  char to_email[100];
  char subject[100];
  char message[1000];

  printf("Enter your email address: ");
  scanf("%s", from_email);

  printf("Enter the recipient's email address: ");
  scanf("%s", to_email);

  printf("Enter the email subject: ");
  scanf("%s", subject);

  printf("Enter the email message: ");
  scanf("%s", message);

  struct hostent *server;
  struct sockaddr_in serv_addr;
  int sockfd;
  int portno = 25;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  server = gethostbyname("smtp.example.com");

  if (server == NULL) {
    fprintf(stderr,"ERROR, no such host\n");
    exit(0);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
      fprintf(stderr,"ERROR connecting\n");
      exit(1);
  }

  printf("Connected to the email server. Sending email...\n");

  //HELO
  char buffer[1024];
  int n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
  buffer[n] = '\0';
  printf("%s", buffer);
  char helo[50];
  sprintf(helo,"HELO %s\r\n",from_email);
  send(sockfd, helo, strlen(helo), 0);
  n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
  buffer[n] = '\0';
  printf("%s", buffer);

  //MAIL FROM
  char mailfrom[100];
  sprintf(mailfrom,"MAIL FROM:<%s>\r\n",from_email);
  send(sockfd, mailfrom, strlen(mailfrom), 0);
  n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
  buffer[n] = '\0';
  printf("%s", buffer);

  //RCPT TO
  char rcptto[100];
  sprintf(rcptto,"RCPT TO:<%s>\r\n",to_email);
  send(sockfd, rcptto, strlen(rcptto), 0);
  n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
  buffer[n] = '\0';
  printf("%s", buffer);

  //DATA
  char data[] = "DATA\r\n";
  send(sockfd, data, strlen(data), 0);
  n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
  buffer[n] = '\0';
  printf("%s", buffer);

  //message headers
  char message_header[100];
  sprintf(message_header,"From: %s\r\n",from_email);
  send(sockfd, message_header, strlen(message_header), 0);

  sprintf(message_header,"To: %s\r\n", to_email);
  send(sockfd, message_header, strlen(message_header), 0);

  sprintf(message_header,"Subject: %s\r\n\r\n", subject);
  send(sockfd, message_header, strlen(message_header), 0);

  //message body
  send(sockfd, message, strlen(message), 0);

  //end of message
  char end_message[] = "\r\n.\r\n";
  send(sockfd, end_message, strlen(end_message), 0);
  n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
  buffer[n] = '\0';
  printf("%s", buffer);

  //QUIT
  char quit[] = "QUIT\r\n";
  send(sockfd, quit, strlen(quit), 0);
  n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
  buffer[n] = '\0';
  printf("%s", buffer);

  printf("Email sent successfully! Exiting...\n");

  close(sockfd);
  return 0;
}