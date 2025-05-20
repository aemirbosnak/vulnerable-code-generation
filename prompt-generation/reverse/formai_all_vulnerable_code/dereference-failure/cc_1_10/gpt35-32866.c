//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: high level of detail
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <string.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
#include <arpa/inet.h>
#include <netdb.h> 

#define PORT 80    // port number for HTTP

int main(int argc, char *argv[]) {

   if (argc != 2) {   // check if user has entered a domain name as argument
      fprintf(stderr,"usage: %s <url>\n", argv[0]);
      exit(1);
   }

   char *host = argv[1];  // store domain name
   struct hostent *he = gethostbyname(host);  // get host details

   if (he == NULL) {   // check if host is valid
      fprintf(stderr, "Could not resolve %s\n", host);
      exit(1);
   }

   struct sockaddr_in server_addr;
   int sockfd, bytes_received, sent, total_bytes = 0;
   char buffer[2048];

   if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {   // create socket
      perror("Socket");  
      exit(1);
   }

   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons(PORT);
   server_addr.sin_addr = *((struct in_addr *)he->h_addr);
   memset(&(server_addr.sin_zero), 0, 8); 

   if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {   // connect to remote server
      perror("Connect");
      exit(1);
   }

   char *request = "GET / HTTP/1.1\r\nHost: ";
   strcat(request, host);   // build HTTP GET request
   strcat(request, "\r\n\r\n");

   if ((sent = send(sockfd, request, strlen(request), 0)) == -1) {   // send request to server
      perror("Send");
      exit(1);
   }

   while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {   // receive response from server
      total_bytes += bytes_received;
      buffer[bytes_received] = '\0';
      printf("%s", buffer);
   }

   printf("\nReceived %d bytes in total\n", total_bytes);

   close(sockfd);  // close socket

   return 0;
}