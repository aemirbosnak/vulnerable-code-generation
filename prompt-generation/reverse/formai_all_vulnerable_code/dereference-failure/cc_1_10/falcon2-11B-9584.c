//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
   if (argc!= 2) {
      fprintf(stderr, "Usage: %s <target IP address>\n", argv[0]);
      exit(1);
   }
   char *targetIP = argv[1];

   int sockfd;
   struct sockaddr_in serv_addr;
   socklen_t len = sizeof(serv_addr);
   struct hostent *host = gethostbyname(targetIP);

   if (host == NULL) {
      fprintf(stderr, "Error: No such host\n");
      exit(1);
   }

   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0) {
      fprintf(stderr, "Error: Failed to create socket\n");
      exit(1);
   }

   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *) host->h_addr, (char *) &serv_addr.sin_addr.s_addr, host->h_length);
   serv_addr.sin_port = htons(22);

   if (connect(sockfd, (struct sockaddr *) &serv_addr, len) < 0) {
      fprintf(stderr, "Error: Failed to connect\n");
      exit(1);
   }

   char message[100];
   bzero(message, sizeof(message));
   snprintf(message, sizeof(message), "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", targetIP);

   if (send(sockfd, message, strlen(message), 0) < 0) {
      fprintf(stderr, "Error: Failed to send message\n");
      exit(1);
   }

   char buffer[1024];
   if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
      fprintf(stderr, "Error: Failed to receive message\n");
      exit(1);
   }

   printf("%s\n", buffer);

   close(sockfd);
   return 0;
}