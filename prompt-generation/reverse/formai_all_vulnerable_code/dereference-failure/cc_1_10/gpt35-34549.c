//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>

void error(char *msg) {
 perror(msg);
 exit(0);
}

int main(int argc, char *argv[]) {
 int sockfd, portno, n;
 struct sockaddr_in serv_addr;
 struct hostent *server;

 char buffer[256];
 if (argc < 3) {
  fprintf(stderr,"usage %s hostname port\n", argv[0]);
  exit(0);
 }
 portno = atoi(argv[2]);
 sockfd = socket(AF_INET, SOCK_STREAM, 0);
 if (sockfd < 0) 
  error("ERROR opening socket");

 server = gethostbyname(argv[1]);
 if (server == NULL) {
  fprintf(stderr,"ERROR, no such host\n");
  exit(0);
 }

 bzero((char *) &serv_addr, sizeof(serv_addr));
 serv_addr.sin_family = AF_INET;
 bcopy((char *)server->h_addr, 
      (char *)&serv_addr.sin_addr.s_addr,
      server->h_length);
 serv_addr.sin_port = htons(portno);

 if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
  error("ERROR connecting");

 // SMTP protocol starts here
 char ehlo[] = "EHLO smtp.gmail.com\r\n";
 char mail_from[] = "MAIL FROM:<johndoe@gmail.com>\r\n";
 char rcpt_to[] = "RCPT TO:<janedoe@gmail.com>\r\n";
 char data[] = "DATA\r\n";
 char message[] = "Subject: Greetings!\nThis is an example email message.\n.\r\n";
 char quit[] = "QUIT\r\n";

 // EHLO
 bzero(buffer,256);
 n = read(sockfd,buffer,255);
 if (n < 0) 
  error("ERROR reading from socket");
 printf("%s",buffer);

 bzero(buffer,256);
 strcpy(buffer, ehlo);
 n = write(sockfd, buffer, strlen(buffer));
 if (n < 0) 
  error("ERROR writing to socket");

 bzero(buffer,256);
 n = read(sockfd, buffer, 255);
 if (n < 0) 
  error("ERROR reading from socket");
 printf("%s",buffer);

 // MAIL FROM
 bzero(buffer,256);
 strcpy(buffer, mail_from);
 n = write(sockfd, buffer, strlen(buffer));
 if (n < 0) 
  error("ERROR writing to socket");

 bzero(buffer,256);
 n = read(sockfd, buffer, 255);
 if (n < 0) 
  error("ERROR reading from socket");
 printf("%s",buffer);

 // RCPT TO
 bzero(buffer,256);
 strcpy(buffer, rcpt_to);
 n = write(sockfd, buffer, strlen(buffer));
 if (n < 0) 
  error("ERROR writing to socket");

 bzero(buffer,256);
 n = read(sockfd, buffer, 255);
 if (n < 0) 
  error("ERROR reading from socket");
 printf("%s",buffer);

 // DATA
 bzero(buffer,256);
 strcpy(buffer, data);
 n = write(sockfd, buffer, strlen(buffer));
 if (n < 0) 
  error("ERROR writing to socket");

 bzero(buffer,256);
 n = read(sockfd, buffer, 255);
 if (n < 0) 
  error("ERROR reading from socket");
 printf("%s",buffer);

 // Message
 bzero(buffer,256);
 strcpy(buffer, message);
 n = write(sockfd, buffer, strlen(buffer));
 if (n < 0) 
  error("ERROR writing to socket");

 bzero(buffer,256);
 n = read(sockfd, buffer, 255);
 if (n < 0) 
  error("ERROR reading from socket");
 printf("%s",buffer);

 // Quit
 bzero(buffer,256);
 strcpy(buffer, quit);
 n = write(sockfd, buffer, strlen(buffer));
 if (n < 0) 
  error("ERROR writing to socket");

 bzero(buffer,256);
 n = read(sockfd, buffer, 255);
 if (n < 0) 
  error("ERROR reading from socket");
 printf("%s",buffer);

 close(sockfd);
 return 0;
}