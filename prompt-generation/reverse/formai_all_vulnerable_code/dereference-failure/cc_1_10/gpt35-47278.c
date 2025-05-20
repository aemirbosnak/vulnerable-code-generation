//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
   int sockfd, port, n;
   struct sockaddr_in serv_addr;
   struct hostent *server;

   char buffer[4096] = {0};

   if (argc < 3) {
      printf("\nUsage: %s <hostname> <port>\n", argv[0]);
      exit(1);
   }

   port = atoi(argv[2]);

   // create the socket
   sockfd = socket(AF_INET, SOCK_STREAM, 0);

   if (sockfd < 0) {
      printf("\nError: Could not create socket!\n");
      exit(1);
   }

   server = gethostbyname(argv[1]);

   if (server == NULL) {
      printf("\nError: No such host!\n");
      exit(1);
   }

   memset(&serv_addr, 0, sizeof(serv_addr));

   serv_addr.sin_family = AF_INET;
   serv_addr.sin_port = htons(port);
   serv_addr.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*) server->h_addr_list[0]));

   if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
      printf("\nError: Could not connect to server!\n");
      exit(1);
   }

   // Sending a GET request
   char *req = "GET / HTTP/1.1\r\nHost: localhost:8000\r\nUser-Agent: HTTPClient/1.0\r\n\r\n";
   send(sockfd, req, strlen(req), 0);

   while ((n = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
      buffer[n] = 0;
      printf("%s", buffer);
   }

   if (n < 0) {
      printf("\nError: Could not read from the socket!\n");
      exit(1);
   }

   close(sockfd);

   return 0;
}