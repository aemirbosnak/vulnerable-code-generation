//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

int main(int argc, char *argv[]) {

   if (argc != 3) {
      printf("Usage: ./client SMTP_SERVER_NAME PORT\n");
      exit(1);
   }

   int sockfd, portno, n;
   struct sockaddr_in serv_addr;
   struct hostent *server;

   char buffer[256];
   portno = atoi(argv[2]);

   sockfd = socket(AF_INET, SOCK_STREAM, 0);

   if (sockfd < 0) {
      perror("Error opening socket");
      exit(1);
   }

   server = gethostbyname(argv[1]);

   if (server == NULL) {
      printf("Error, no such host\n");
      exit(0);
   }

   bzero((char *) &serv_addr, sizeof(serv_addr));

   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
   serv_addr.sin_port = htons(portno);

   if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
      perror("Error connecting to SMTP server");
      exit(1);
   }

   printf("Connected to SMTP Server %s:%s\n", argv[1], argv[2]);

   n = recv(sockfd, buffer, sizeof(buffer)-1, 0);

   if (n < 0) {
      perror("Error receiving data");
      exit(1);
   }

   buffer[n] = '\0';

   printf("%s\n",buffer);

   char username[256];
   char password[256];
   char recipient[256];
   char subject[256];
   char message[256];

   printf("Enter email address of recipient: ");
   scanf("%s", recipient);

   printf("Enter email subject: ");
   scanf("%s", subject);

   printf("Enter message to be sent: ");
   scanf("%s", message);

   printf("Enter SMTP username: ");
   scanf("%s", username);

   printf("Enter SMTP password: ");
   scanf("%s", password);

   printf("\n\nSending email...\n\n");

   char messageBuffer[1024];

   sprintf(messageBuffer, "EHLO %s\n", argv[1]);
   send(sockfd, messageBuffer, strlen(messageBuffer), 0);
   n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
   buffer[n] = '\0';

   sprintf(messageBuffer, "AUTH LOGIN\n");
   send(sockfd, messageBuffer, strlen(messageBuffer), 0);
   n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
   buffer[n] = '\0';

   sprintf(messageBuffer, "%s\n", username);
   send(sockfd, messageBuffer, strlen(messageBuffer), 0);
   n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
   buffer[n] = '\0';

   sprintf(messageBuffer, "%s\n", password);
   send(sockfd, messageBuffer, strlen(messageBuffer), 0);
   n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
   buffer[n] = '\0';

   sprintf(messageBuffer, "MAIL FROM: <%s>\n", username);
   send(sockfd, messageBuffer, strlen(messageBuffer), 0);
   n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
   buffer[n] = '\0';

   sprintf(messageBuffer, "RCPT TO: <%s>\n", recipient);
   send(sockfd, messageBuffer, strlen(messageBuffer), 0);
   n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
   buffer[n] = '\0';

   sprintf(messageBuffer, "DATA\n");
   send(sockfd, messageBuffer, strlen(messageBuffer), 0);
   n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
   buffer[n] = '\0';

   sprintf(messageBuffer, "From: %s\nTo: %s\nSubject: %s\n%s\n.\n", username, recipient, subject, message);
   send(sockfd, messageBuffer, strlen(messageBuffer), 0);
   n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
   buffer[n] = '\0';

   sprintf(messageBuffer, "QUIT\n");
   send(sockfd, messageBuffer, strlen(messageBuffer), 0);
   n = recv(sockfd, buffer, sizeof(buffer)-1, 0);
   buffer[n] = '\0';

   close(sockfd);

   printf("Email sent successfully!\n");

   return 0;
}