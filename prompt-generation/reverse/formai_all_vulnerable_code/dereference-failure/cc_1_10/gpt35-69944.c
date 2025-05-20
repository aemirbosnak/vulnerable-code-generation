//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

void error(char *msg)
{
  perror(msg);
  exit(1);
}

int main(int argc, char *argv[])
{
  int sockfd, portno, n, i;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];
  char command[256];
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
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);
  if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
      error("ERROR connecting");
  bzero(buffer,256);
  n = read(sockfd,buffer,255);
  if (n < 0)
      error("ERROR reading from socket");
  printf("%s\n",buffer);
  
  // SMTP Protocol
  // EHLO Command
  sprintf(command,"EHLO hostname\r\n");
  n = write(sockfd,command,strlen(command));
  if (n < 0)
    error("ERROR writing to socket");
  
  // Recieve response
  bzero(buffer,256);
  n = read(sockfd,buffer,255);
  if (n < 0)
      error("ERROR reading from socket");
  printf("%s",buffer);

  // MAIL FROM Command
  sprintf(command,"MAIL FROM:<johndoe@gmail.com>\r\n");
  n = write(sockfd,command,strlen(command));
  if (n < 0)
    error("ERROR writing to socket");

  // Recieve response
  bzero(buffer,256);
  n = read(sockfd,buffer,255);
  if (n < 0)
      error("ERROR reading from socket");
  printf("%s",buffer);

  // RCPT TO Command
  sprintf(command,"RCPT TO:<janedoe@gmail.com>\r\n");
  n = write(sockfd,command,strlen(command));
  if (n < 0)
    error("ERROR writing to socket");

  // Recieve response
  bzero(buffer,256);
  n = read(sockfd,buffer,255);
  if (n < 0)
      error("ERROR reading from socket");
  printf("%s",buffer);

  // DATA Command
  sprintf(command,"DATA\r\n");
  n = write(sockfd,command,strlen(command));
  if (n < 0)
    error("ERROR writing to socket");

  // Recieve response
  bzero(buffer,256);
  n = read(sockfd,buffer,255);
  if (n < 0)
      error("ERROR reading from socket");
  printf("%s",buffer);

  // Email message
  sprintf(command,"From:johndoe@gmail.com\r\nTo:janedoe@gmail.com\r\nSubject:Test Email\r\n\r\nHello, this is an example email message.\r\n.\r\n");
  n = write(sockfd,command,strlen(command));
  if (n < 0)
    error("ERROR writing to socket");

  // Recieve response
  bzero(buffer,256);
  n = read(sockfd,buffer,255);
  if (n < 0)
      error("ERROR reading from socket");
  printf("%s",buffer);

  // QUIT Command
  sprintf(command,"QUIT\r\n");
  n = write(sockfd,command,strlen(command));
  if (n < 0)
    error("ERROR writing to socket");

  // Recieve response
  bzero(buffer,256);
  n = read(sockfd,buffer,255);
  if (n < 0)
      error("ERROR reading from socket");
  printf("%s",buffer);

  close(sockfd);
  return 0;
}