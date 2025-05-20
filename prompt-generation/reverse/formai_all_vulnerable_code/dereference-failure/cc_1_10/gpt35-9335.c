//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

void error(char *msg)
{
   perror(msg);
   exit(1);
}

void usage()
{
   fprintf(stderr, "Usage: ./qos_monitor <host> <port>\n");
   exit(1);
}

void get_qos(char* host, int port)
{
   int sockfd, n;
   struct sockaddr_in serv_addr;
   struct hostent* server;
   char buffer[BUFSIZE];
   
   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0)
      error("ERROR opening socket");

   server = gethostbyname(host);
   if (server == NULL)
      error("ERROR, no such host");

   memset((void *)&serv_addr, 0, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   serv_addr.sin_port = htons(port);
   memcpy((void *)&serv_addr.sin_addr.s_addr, (void *)server->h_addr, server->h_length);

   if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
      error("ERROR connecting");
   
   n = write(sockfd, "GET / HTTP/1.0\r\n\r\n", strlen("GET / HTTP/1.0\r\n\r\n"));
   if (n < 0)
      error("ERROR writing to socket");

   memset(buffer, 0, BUFSIZE);
   n = read(sockfd, buffer, BUFSIZE);
   if (n < 0)
      error("ERROR reading from socket");

   printf("QoS: %s\n", buffer);

   close(sockfd);
}

int main(int argc, char *argv[])
{
   if (argc != 3)
      usage();

   char* host = argv[1];
   int port = atoi(argv[2]);

   printf("Monitoring QoS for %s:%d...\n", host, port);

   while (1)
   {
      get_qos(host, port);
      sleep(10);
   }
   
   return 0;
}