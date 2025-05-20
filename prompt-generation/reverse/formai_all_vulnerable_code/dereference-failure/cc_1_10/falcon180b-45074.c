//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

int main(int argc, char *argv[]) {
   int sockfd, newsockfd, portno;
   struct sockaddr_in serv_addr, cli_addr;
   struct hostent *server;
   char buffer[1024];
   int n;
   char *message = "The quick brown fox jumps over the lazy dog ";
   
   if (argc < 3) {
      fprintf(stderr, "Usage: %s <IP> <port>\n", argv[0]);
      exit(1);
   }
   
   portno = atoi(argv[2]);
   server = gethostbyname(argv[1]);
   
   if (server == NULL) {
      fprintf(stderr, "No such host\n");
      exit(1);
   }
   
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0) {
      fprintf(stderr, "socket failed\n");
      exit(1);
   }
   
   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
   serv_addr.sin_port = htons(portno);
   
   if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
      fprintf(stderr, "connect failed\n");
      exit(1);
   }
   
   while (1) {
      bzero(buffer, 1024);
      if ((n = read(sockfd, buffer, 1024)) < 0) {
         fprintf(stderr, "read failed\n");
         exit(1);
      }
      buffer[n] = '\0';
      printf("Message from server: %s\n", buffer);
      
      if (send(sockfd, message, strlen(message), 0) < 0) {
         fprintf(stderr, "send failed\n");
         exit(1);
      }
   }
   
   close(sockfd);
   exit(0);
}